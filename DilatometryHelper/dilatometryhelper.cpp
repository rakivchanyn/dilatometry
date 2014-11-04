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

void DilatometryHelper::processFiles()
{
    QFile file(ui->leTempr->text());
    file.open(QIODevice::ReadOnly);
    if (!file.isOpen())
    {
        QMessageBox::information(this, "Помилка", "Неможливо відкрити файл з температурою!\n"
                                 "Перевірьте чи правильно введене ім'я файлу.");
    }
    QTextStream strim(&file);
    QString temper;
    temper.append(strim.readAll());
    QString temp;
    foreach (char c, temper)
    {
        if (c == '<')
        {
            temp.append(c);
            continue;
        }
        if (c == '>')
        {
            temp.append(c);
            continue;
        }

    }
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
    processFiles();
}
