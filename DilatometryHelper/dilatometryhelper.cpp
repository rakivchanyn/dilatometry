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

void DilatometryHelper::processFiles(std::vector <double>& aData, QString aFileName)
{
    QFile file(aFileName);
    file.open(QIODevice::ReadOnly);
    if (!file.isOpen())
    {
        QMessageBox::information(this, "Помилка", "Неможливо відкрити файл з температурою!\n"
                                 "Перевірьте чи правильно введене ім'я файлу.");
    }
    QTextStream strim(&file);
    QString temper;
    temper.append(strim.readAll());
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
    processFiles(temperature, ui->leTempr->text());
    std::vector <double> dilatometry;
    processFiles(dilatometry, ui->leDilat->text());
//    for
}
