#include "dilatometryhelper.h"
#include "ui_dilatometryhelper.h"

#include <QFileDialog>
#include <Qfile>
#include <QTextStream>
#include <QIODevice>
#include <QMessageBox>

DilatometryHelper::DilatometryHelper(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DilatometryHelper)
{
    ui->setupUi(this);
}

DilatometryHelper::~DilatometryHelper()
{
    delete ui;
}

bool DilatometryHelper::processFiles(std::vector <double>& aData, QString aFileName)
{
    QFile file(aFileName);
    file.open(QIODevice::ReadOnly);
    if (!file.isOpen())
    {
        QMessageBox::warning(this, "Помилка", "Неможливо відкрити файл: \n" + aFileName +
                                 "\nПеревірьте чи правильно введене ім'я файлу.");
        return false;
    }
    QTextStream strim(&file);
    QString temper;
    temper.append(strim.readAll());
    file.close();
    QString tag;
    QString num;
    int i = 0;
    QLocale ukr(QLocale::Ukrainian);
    foreach (QChar c, temper)
    {
        if (c == '<')
        {
            tag.clear();
            tag.append(c);
            continue;
        }
        else if (c == '>')
        {
            tag.append(c);
            if (tag == "</TD>")
            {
                ++i;
                double t = ukr.toDouble(num);
                if (i%2 == 0)
                {

                    aData.push_back(t);
                }
                num.clear();
            }
            continue;
        }
        else
        {
            if (tag == "<TD>")
            {
                num.append(c);
            }
            else
            {
                tag.append(c);
            }
        }
    }
    return true;
}

void DilatometryHelper::on_pbOpenTempr_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"), "..", "Text File (*.txt)");
    ui->leTempr->setText(fileName);
}

void DilatometryHelper::on_pbOpenDilat_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"), "..", "Text File (*.txt)");
    ui->leDilat->setText(fileName);
}

void DilatometryHelper::on_pbStartProcess_clicked()
{
    std::vector <double> temperature;
    if (!processFiles(temperature, ui->leTempr->text()))
        return;
    std::vector <double> dilatometry;
    if (!processFiles(dilatometry, ui->leDilat->text()))
        return;

    QLocale ukr(QLocale::Ukrainian);
    double ratio = (ukr.toDouble(ui->leStartHight->text()) - ukr.toDouble(ui->leFinHight->text())) /
            ukr.toDouble(ui->leStartHight->text());
    double finDilatData = (ukr.toDouble(ui->leFinalValueDilat->text()) < 0.0) ?
                            (ukr.toDouble(ui->leFinalValueDilat->text()) * (-1.0)) :
                            ukr.toDouble(ui->leFinalValueDilat->text());
    double firstDilVal = dilatometry.front();
    double rphight = ratio / (finDilatData + firstDilVal);
    for (auto& it : dilatometry)
    {
           double t = it;
           it = (t - firstDilVal) * rphight;
    }

    QFile file("output.txt");
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Помилка!", "Неможливо створити файл output.txt");
        return;
    }
    QTextStream out(&file);
    unsigned int maxSize = (temperature.size() > dilatometry.size()) ?
                            dilatometry.size() : temperature.size();
    for (std::vector<double>::iterator t = temperature.begin(), d = dilatometry.begin();
         t != temperature.end() || d != dilatometry.end();
         ++t, ++d)
    {
        out << *t << "\t" << *d << "\n";
    }
    file.close();
}

void DilatometryHelper::on_leFinalValueDilat_editingFinished()
{
    QString t = ui->leFinalValueDilat->text();
    t.replace(".", ",");
    ui->leFinalValueDilat->setText(t);
}

void DilatometryHelper::on_leStartHight_editingFinished()
{
    QString t = ui->leStartHight->text();
    t.replace(".", ",");
    ui->leStartHight->setText(t);
}

void DilatometryHelper::on_leFinHight_editingFinished()
{
    QString t = ui->leFinHight->text();
    t.replace(".", ",");
    ui->leFinHight->setText(t);
}
