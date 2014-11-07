#include "dilatometryhelper.h"
#include "ui_dilatometryhelper.h"

#include <QFileDialog>
#include <Qfile>
#include <QTextStream>
#include <QIODevice>
#include <QMessageBox>
#include <QClipboard>

DilatometryHelper::DilatometryHelper(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DilatometryHelper)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
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
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"), "./", "Text File (*.txt)");
    ui->leTempr->setText(fileName);
}

void DilatometryHelper::on_pbOpenDilat_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"), "./", "Text File (*.txt)");
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

    //Processing data:
    QLocale ukr(QLocale::Ukrainian);

    if (ui->leFinalValueDilat->text().isEmpty())
    {
        QMessageBox::warning(this, "Неправильно введені дані", "Введіть кінцеве значення показів дилатометра!");
        return;
    }
    double finDilatData = (ukr.toDouble(ui->leFinalValueDilat->text()) < 0.0) ?
                            (ukr.toDouble(ui->leFinalValueDilat->text()) * (-1.0)) :
                            ukr.toDouble(ui->leFinalValueDilat->text());

    if (ui->leStartHight->text().isEmpty())
    {
        QMessageBox::warning(this, "Неправильно введені дані", "Введіть початкову висоту зразка!");
        return;
    }
    double sHight = ukr.toDouble(ui->leStartHight->text());

    if (ui->leFinHight->text().isEmpty())
    {
        QMessageBox::warning(this, "Неправильно введені дані", "Введіть кінцеву висоту зразка!");
        return;
    }
    double fHight = ukr.toDouble(ui->leFinHight->text());

    double ratio = (sHight - fHight) / sHight;
    double firstDilVal = dilatometry.front();
    double rphight = ratio / (finDilatData + firstDilVal);
    for (auto& it : dilatometry)
    {
           double t = it;
           it = (t - firstDilVal) * rphight;
    }
    //End processing data

    //Saving data
    QFile file("output.txt");
    if (file.exists())
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Файл вже існує!",
                                      "Такий файл вже існує, чи хочете Ви продовжити обробку даних?\n"
                                      "При цьому попередні дані будуть втрачені!",
                                        QMessageBox::Yes|QMessageBox::No);
        if(reply == QMessageBox::No)
        {
          return;
        }
    }
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        QMessageBox::warning(this, "Помилка!", "Неможливо створити файл чи отримати доступ до файлу output.txt");
        return;
    }
    QTextStream out(&file);
    QString data;
    for (std::vector<double>::iterator t = temperature.begin(), d = dilatometry.begin();
         t != temperature.end() || d != dilatometry.end();
         ++t, ++d)
    {
        out << *t << "\t" << *d << "\n";
        data += (QString::number(*t) + "\t" + QString::number(*d) + "\n"); //saving data to clipboard
    }
    file.close();
    QClipboard* clipboard = QApplication::clipboard();
    clipboard->setText(data);
    QMessageBox::information(this, "Статус задачі", "Робота закінчена\n"
                             "Дані записані в файл \"output.txt.\" та скопійовані в буфер обміну");
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
