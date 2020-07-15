/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculator
{
public:
    QAction *actionAbout;
    QAction *actionExit;
    QAction *actionBIN;
    QAction *actionOCT;
    QAction *actionDEC;
    QAction *actionHEX;
    QAction *actiontan;
    QAction *actioncot;
    QWidget *centralwidget;
    QLineEdit *result;
    QPushButton *btn_go;
    QPushButton *btn_7;
    QPushButton *btn_8;
    QPushButton *btn_6;
    QPushButton *btn_9;
    QPushButton *btn_1;
    QPushButton *btn_4;
    QPushButton *btn_5;
    QPushButton *btn_3;
    QPushButton *btn_2;
    QPushButton *btn_mul;
    QPushButton *btn_lc;
    QPushButton *btn_minus;
    QPushButton *btn_div;
    QPushButton *btn_plus;
    QPushButton *btn_rc;
    QPushButton *btn_rev;
    QPushButton *btn_pow;
    QPushButton *btn_ans;
    QPushButton *btn_dot;
    QPushButton *btn_0;
    QPushButton *btn_log;
    QPushButton *btn_clr;
    QPushButton *btn_sin;
    QPushButton *btn_cos;
    QPushButton *btn_neg;
    QLabel *label;
    QListWidget *listWidget;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuConvert;
    QMenu *menuMisc;

    void setupUi(QMainWindow *Calculator)
    {
        if (Calculator->objectName().isEmpty())
            Calculator->setObjectName(QString::fromUtf8("Calculator"));
        Calculator->resize(1042, 578);
        actionAbout = new QAction(Calculator);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionExit = new QAction(Calculator);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionBIN = new QAction(Calculator);
        actionBIN->setObjectName(QString::fromUtf8("actionBIN"));
        actionOCT = new QAction(Calculator);
        actionOCT->setObjectName(QString::fromUtf8("actionOCT"));
        actionDEC = new QAction(Calculator);
        actionDEC->setObjectName(QString::fromUtf8("actionDEC"));
        actionHEX = new QAction(Calculator);
        actionHEX->setObjectName(QString::fromUtf8("actionHEX"));
        actiontan = new QAction(Calculator);
        actiontan->setObjectName(QString::fromUtf8("actiontan"));
        actioncot = new QAction(Calculator);
        actioncot->setObjectName(QString::fromUtf8("actioncot"));
        centralwidget = new QWidget(Calculator);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        result = new QLineEdit(centralwidget);
        result->setObjectName(QString::fromUtf8("result"));
        result->setGeometry(QRect(40, 30, 661, 41));
        result->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        result->setReadOnly(true);
        btn_go = new QPushButton(centralwidget);
        btn_go->setObjectName(QString::fromUtf8("btn_go"));
        btn_go->setGeometry(QRect(560, 450, 61, 51));
        btn_7 = new QPushButton(centralwidget);
        btn_7->setObjectName(QString::fromUtf8("btn_7"));
        btn_7->setGeometry(QRect(40, 90, 141, 81));
        btn_8 = new QPushButton(centralwidget);
        btn_8->setObjectName(QString::fromUtf8("btn_8"));
        btn_8->setGeometry(QRect(220, 90, 141, 81));
        btn_6 = new QPushButton(centralwidget);
        btn_6->setObjectName(QString::fromUtf8("btn_6"));
        btn_6->setGeometry(QRect(390, 200, 141, 81));
        btn_9 = new QPushButton(centralwidget);
        btn_9->setObjectName(QString::fromUtf8("btn_9"));
        btn_9->setGeometry(QRect(390, 90, 141, 81));
        btn_1 = new QPushButton(centralwidget);
        btn_1->setObjectName(QString::fromUtf8("btn_1"));
        btn_1->setGeometry(QRect(40, 310, 141, 81));
        btn_4 = new QPushButton(centralwidget);
        btn_4->setObjectName(QString::fromUtf8("btn_4"));
        btn_4->setGeometry(QRect(40, 200, 141, 81));
        btn_5 = new QPushButton(centralwidget);
        btn_5->setObjectName(QString::fromUtf8("btn_5"));
        btn_5->setGeometry(QRect(220, 200, 141, 81));
        btn_3 = new QPushButton(centralwidget);
        btn_3->setObjectName(QString::fromUtf8("btn_3"));
        btn_3->setGeometry(QRect(390, 310, 141, 81));
        btn_2 = new QPushButton(centralwidget);
        btn_2->setObjectName(QString::fromUtf8("btn_2"));
        btn_2->setGeometry(QRect(220, 310, 141, 81));
        btn_mul = new QPushButton(centralwidget);
        btn_mul->setObjectName(QString::fromUtf8("btn_mul"));
        btn_mul->setGeometry(QRect(560, 270, 61, 51));
        btn_lc = new QPushButton(centralwidget);
        btn_lc->setObjectName(QString::fromUtf8("btn_lc"));
        btn_lc->setGeometry(QRect(560, 150, 61, 51));
        btn_minus = new QPushButton(centralwidget);
        btn_minus->setObjectName(QString::fromUtf8("btn_minus"));
        btn_minus->setGeometry(QRect(640, 210, 61, 51));
        btn_div = new QPushButton(centralwidget);
        btn_div->setObjectName(QString::fromUtf8("btn_div"));
        btn_div->setGeometry(QRect(640, 270, 61, 51));
        btn_plus = new QPushButton(centralwidget);
        btn_plus->setObjectName(QString::fromUtf8("btn_plus"));
        btn_plus->setGeometry(QRect(560, 210, 61, 51));
        btn_rc = new QPushButton(centralwidget);
        btn_rc->setObjectName(QString::fromUtf8("btn_rc"));
        btn_rc->setGeometry(QRect(640, 150, 61, 51));
        btn_rev = new QPushButton(centralwidget);
        btn_rev->setObjectName(QString::fromUtf8("btn_rev"));
        btn_rev->setGeometry(QRect(640, 90, 61, 51));
        btn_pow = new QPushButton(centralwidget);
        btn_pow->setObjectName(QString::fromUtf8("btn_pow"));
        btn_pow->setGeometry(QRect(560, 90, 61, 51));
        btn_ans = new QPushButton(centralwidget);
        btn_ans->setObjectName(QString::fromUtf8("btn_ans"));
        btn_ans->setGeometry(QRect(390, 420, 141, 81));
        btn_dot = new QPushButton(centralwidget);
        btn_dot->setObjectName(QString::fromUtf8("btn_dot"));
        btn_dot->setGeometry(QRect(220, 420, 141, 81));
        btn_0 = new QPushButton(centralwidget);
        btn_0->setObjectName(QString::fromUtf8("btn_0"));
        btn_0->setGeometry(QRect(40, 420, 141, 81));
        btn_log = new QPushButton(centralwidget);
        btn_log->setObjectName(QString::fromUtf8("btn_log"));
        btn_log->setGeometry(QRect(640, 330, 61, 51));
        btn_clr = new QPushButton(centralwidget);
        btn_clr->setObjectName(QString::fromUtf8("btn_clr"));
        btn_clr->setGeometry(QRect(560, 330, 61, 51));
        btn_sin = new QPushButton(centralwidget);
        btn_sin->setObjectName(QString::fromUtf8("btn_sin"));
        btn_sin->setGeometry(QRect(640, 390, 61, 51));
        btn_cos = new QPushButton(centralwidget);
        btn_cos->setObjectName(QString::fromUtf8("btn_cos"));
        btn_cos->setGeometry(QRect(640, 450, 61, 51));
        btn_neg = new QPushButton(centralwidget);
        btn_neg->setObjectName(QString::fromUtf8("btn_neg"));
        btn_neg->setGeometry(QRect(560, 390, 61, 51));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(710, 10, 72, 15));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(710, 30, 321, 471));
        Calculator->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Calculator);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Calculator->setStatusBar(statusbar);
        menuBar = new QMenuBar(Calculator);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1042, 26));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuConvert = new QMenu(menuBar);
        menuConvert->setObjectName(QString::fromUtf8("menuConvert"));
        menuMisc = new QMenu(menuBar);
        menuMisc->setObjectName(QString::fromUtf8("menuMisc"));
        Calculator->setMenuBar(menuBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuConvert->menuAction());
        menuBar->addAction(menuMisc->menuAction());
        menuMenu->addAction(actionAbout);
        menuMenu->addSeparator();
        menuMenu->addAction(actionExit);
        menuConvert->addAction(actionBIN);
        menuConvert->addAction(actionOCT);
        menuConvert->addAction(actionDEC);
        menuConvert->addAction(actionHEX);
        menuMisc->addAction(actiontan);
        menuMisc->addAction(actioncot);

        retranslateUi(Calculator);

        QMetaObject::connectSlotsByName(Calculator);
    } // setupUi

    void retranslateUi(QMainWindow *Calculator)
    {
        Calculator->setWindowTitle(QCoreApplication::translate("Calculator", "Calculator", nullptr));
        actionAbout->setText(QCoreApplication::translate("Calculator", "About", nullptr));
        actionExit->setText(QCoreApplication::translate("Calculator", "Exit", nullptr));
        actionBIN->setText(QCoreApplication::translate("Calculator", "BIN", nullptr));
        actionOCT->setText(QCoreApplication::translate("Calculator", "OCT", nullptr));
        actionDEC->setText(QCoreApplication::translate("Calculator", "DEC", nullptr));
        actionHEX->setText(QCoreApplication::translate("Calculator", "HEX", nullptr));
        actiontan->setText(QCoreApplication::translate("Calculator", "tan", nullptr));
        actioncot->setText(QCoreApplication::translate("Calculator", "cot", nullptr));
        btn_go->setText(QCoreApplication::translate("Calculator", "=", nullptr));
        btn_7->setText(QCoreApplication::translate("Calculator", "7", nullptr));
        btn_8->setText(QCoreApplication::translate("Calculator", "8", nullptr));
        btn_6->setText(QCoreApplication::translate("Calculator", "6", nullptr));
        btn_9->setText(QCoreApplication::translate("Calculator", "9", nullptr));
        btn_1->setText(QCoreApplication::translate("Calculator", "1", nullptr));
        btn_4->setText(QCoreApplication::translate("Calculator", "4", nullptr));
        btn_5->setText(QCoreApplication::translate("Calculator", "5", nullptr));
        btn_3->setText(QCoreApplication::translate("Calculator", "3", nullptr));
        btn_2->setText(QCoreApplication::translate("Calculator", "2", nullptr));
        btn_mul->setText(QCoreApplication::translate("Calculator", "*", nullptr));
        btn_lc->setText(QCoreApplication::translate("Calculator", "(", nullptr));
        btn_minus->setText(QCoreApplication::translate("Calculator", "-", nullptr));
        btn_div->setText(QCoreApplication::translate("Calculator", "/", nullptr));
        btn_plus->setText(QCoreApplication::translate("Calculator", "+", nullptr));
        btn_rc->setText(QCoreApplication::translate("Calculator", ")", nullptr));
        btn_rev->setText(QCoreApplication::translate("Calculator", "1/x", nullptr));
        btn_pow->setText(QCoreApplication::translate("Calculator", "^", nullptr));
        btn_ans->setText(QCoreApplication::translate("Calculator", "C", nullptr));
        btn_dot->setText(QCoreApplication::translate("Calculator", ".", nullptr));
        btn_0->setText(QCoreApplication::translate("Calculator", "0", nullptr));
        btn_log->setText(QCoreApplication::translate("Calculator", "log", nullptr));
        btn_clr->setText(QCoreApplication::translate("Calculator", "CE", nullptr));
        btn_sin->setText(QCoreApplication::translate("Calculator", "sin", nullptr));
        btn_cos->setText(QCoreApplication::translate("Calculator", "cos", nullptr));
        btn_neg->setText(QCoreApplication::translate("Calculator", "--", nullptr));
        label->setText(QCoreApplication::translate("Calculator", "History", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("Calculator", "Menu", nullptr));
        menuConvert->setTitle(QCoreApplication::translate("Calculator", "Convert", nullptr));
        menuMisc->setTitle(QCoreApplication::translate("Calculator", "Misc", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calculator: public Ui_Calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
