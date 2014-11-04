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
    bool processFiles(std::vector<double>& aData, QString aFileName);

private slots:
    void on_pbOpenTempr_clicked();

    void on_pbOpenDilat_clicked();

    void on_pbStartProcess_clicked();

    void on_leFinalValueDilat_editingFinished();

    void on_leStartHight_editingFinished();

    void on_leFinHight_editingFinished();

private:
    Ui::DilatometryHelper *ui;
};

#endif // DILATOMETRYHELPER_H
