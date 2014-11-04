#ifndef DILATOMETRYHELPER_H
#define DILATOMETRYHELPER_H

#include <QMainWindow>

namespace Ui {
class DilatometryHelper;
}

class DilatometryHelper : public QMainWindow
{
    Q_OBJECT

public:
    explicit DilatometryHelper(QWidget *parent = 0);
    ~DilatometryHelper();

private:
    void processFiles();

private slots:
    void on_pbOpenTempr_clicked();

    void on_pbOpenDilat_clicked();

    void on_pbStartProcess_clicked();

private:
    Ui::DilatometryHelper *ui;
};

#endif // DILATOMETRYHELPER_H
