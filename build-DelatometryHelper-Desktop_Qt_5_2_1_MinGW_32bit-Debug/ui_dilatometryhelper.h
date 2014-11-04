/********************************************************************************
** Form generated from reading UI file 'dilatometryhelper.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DILATOMETRYHELPER_H
#define UI_DILATOMETRYHELPER_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DilatometryHelper
{
public:
    QWidget *centralWidget;
    QPushButton *pbStartProcess;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *leTempr;
    QPushButton *pbOpenTempr;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *leDilat;
    QPushButton *pbOpenDilat;
    QWidget *widget1;
    QFormLayout *formLayout;
    QLineEdit *leFinalValueDilat;
    QLabel *label_3;
    QLineEdit *leStartHight;
    QLabel *label_4;
    QLineEdit *leFinHight;
    QLabel *label_5;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *DilatometryHelper)
    {
        if (DilatometryHelper->objectName().isEmpty())
            DilatometryHelper->setObjectName(QStringLiteral("DilatometryHelper"));
        DilatometryHelper->resize(400, 295);
        DilatometryHelper->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        centralWidget = new QWidget(DilatometryHelper);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pbStartProcess = new QPushButton(centralWidget);
        pbStartProcess->setObjectName(QStringLiteral("pbStartProcess"));
        pbStartProcess->setGeometry(QRect(100, 240, 201, 28));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 381, 115));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        leTempr = new QLineEdit(widget);
        leTempr->setObjectName(QStringLiteral("leTempr"));

        horizontalLayout_2->addWidget(leTempr);

        pbOpenTempr = new QPushButton(widget);
        pbOpenTempr->setObjectName(QStringLiteral("pbOpenTempr"));

        horizontalLayout_2->addWidget(pbOpenTempr);


        verticalLayout->addLayout(horizontalLayout_2);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        leDilat = new QLineEdit(widget);
        leDilat->setObjectName(QStringLiteral("leDilat"));

        horizontalLayout_3->addWidget(leDilat);

        pbOpenDilat = new QPushButton(widget);
        pbOpenDilat->setObjectName(QStringLiteral("pbOpenDilat"));

        horizontalLayout_3->addWidget(pbOpenDilat);


        verticalLayout->addLayout(horizontalLayout_3);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 140, 381, 82));
        formLayout = new QFormLayout(widget1);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        leFinalValueDilat = new QLineEdit(widget1);
        leFinalValueDilat->setObjectName(QStringLiteral("leFinalValueDilat"));

        formLayout->setWidget(0, QFormLayout::LabelRole, leFinalValueDilat);

        label_3 = new QLabel(widget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label_3);

        leStartHight = new QLineEdit(widget1);
        leStartHight->setObjectName(QStringLiteral("leStartHight"));

        formLayout->setWidget(1, QFormLayout::LabelRole, leStartHight);

        label_4 = new QLabel(widget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(1, QFormLayout::FieldRole, label_4);

        leFinHight = new QLineEdit(widget1);
        leFinHight->setObjectName(QStringLiteral("leFinHight"));

        formLayout->setWidget(2, QFormLayout::LabelRole, leFinHight);

        label_5 = new QLabel(widget1);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(2, QFormLayout::FieldRole, label_5);

        DilatometryHelper->setCentralWidget(centralWidget);
        leTempr->raise();
        pbOpenTempr->raise();
        pbOpenDilat->raise();
        leDilat->raise();
        leTempr->raise();
        leDilat->raise();
        pbOpenTempr->raise();
        pbOpenDilat->raise();
        label->raise();
        pbOpenTempr->raise();
        pbOpenDilat->raise();
        label->raise();
        label_2->raise();
        leFinalValueDilat->raise();
        label_3->raise();
        leFinalValueDilat->raise();
        label_3->raise();
        pbStartProcess->raise();
        menuBar = new QMenuBar(DilatometryHelper);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 26));
        DilatometryHelper->setMenuBar(menuBar);

        retranslateUi(DilatometryHelper);

        QMetaObject::connectSlotsByName(DilatometryHelper);
    } // setupUi

    void retranslateUi(QMainWindow *DilatometryHelper)
    {
        DilatometryHelper->setWindowTitle(QApplication::translate("DilatometryHelper", "DilatometryHelper", 0));
        pbStartProcess->setText(QApplication::translate("DilatometryHelper", "\320\236\320\261\321\200\320\276\320\261\320\270\321\202\320\270 \321\204\320\260\320\271\320\273\320\270", 0));
        label->setText(QApplication::translate("DilatometryHelper", "\320\244\320\260\320\271\320\273 \320\267 \321\202\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\275\320\270\320\274\320\270 \320\277\320\276\320\272\320\260\320\267\320\260\320\274\320\270", 0));
        pbOpenTempr->setText(QApplication::translate("DilatometryHelper", "\320\222\321\226\320\264\320\272\321\200\320\270\321\202\320\270 \321\204\320\260\320\271\320\273", 0));
        label_2->setText(QApplication::translate("DilatometryHelper", "\320\244\320\260\320\271\320\273 \320\267 \320\277\320\276\320\272\320\260\320\267\320\260\320\260 \320\264\320\270\320\273\320\260\321\202\320\276\320\274\320\265\321\202\321\200\320\260", 0));
        pbOpenDilat->setText(QApplication::translate("DilatometryHelper", "\320\222\321\226\320\264\320\272\321\200\320\270\321\202\320\270 \321\204\320\260\320\271\320\273", 0));
        label_3->setText(QApplication::translate("DilatometryHelper", "\320\232\321\226\320\275\321\206\320\265\320\262\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\275\321\217 \320\277\320\276\320\272\320\260\320\267\321\226\320\262 \320\264\320\270\320\273\320\260\321\202\320\276\320\274\320\265\321\202\321\200\320\260", 0));
        label_4->setText(QApplication::translate("DilatometryHelper", "\320\222\320\270\321\201\320\276\321\202\320\260 \320\267\321\200\320\260\320\267\320\272\320\260 \320\264\320\276 \320\262\321\226\320\264\320\277\320\260\320\273\321\203, \320\274\320\274", 0));
        label_5->setText(QApplication::translate("DilatometryHelper", "\320\222\320\270\321\201\320\276\321\202\320\260 \320\267\321\200\320\260\320\267\320\272\320\260 \320\277\321\226\321\201\320\273\321\217 \320\262\321\226\320\264\320\277\320\260\320\273\321\203, \320\274\320\274", 0));
    } // retranslateUi

};

namespace Ui {
    class DilatometryHelper: public Ui_DilatometryHelper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DILATOMETRYHELPER_H
