/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_startWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *gameMode;
    QPushButton *startGame;
    QPushButton *setting;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *startWindow)
    {
        if (startWindow->objectName().isEmpty())
            startWindow->setObjectName(QString::fromUtf8("startWindow"));
        startWindow->resize(1120, 520);
        centralwidget = new QWidget(startWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(870, 110, 127, 54));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\345\275\251\344\272\221"));
        font.setPointSize(12);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("image: url(:/button/buttons/button.png);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(870, 190, 127, 54));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/button/buttons/button.png);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(870, 280, 127, 54));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/button/buttons/button.png);"));
        gameMode = new QPushButton(centralwidget);
        gameMode->setObjectName(QString::fromUtf8("gameMode"));
        gameMode->setGeometry(QRect(870, 110, 127, 54));
        startGame = new QPushButton(centralwidget);
        startGame->setObjectName(QString::fromUtf8("startGame"));
        startGame->setGeometry(QRect(870, 190, 127, 54));
        setting = new QPushButton(centralwidget);
        setting->setObjectName(QString::fromUtf8("setting"));
        setting->setGeometry(QRect(870, 280, 127, 54));
        startWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(startWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1120, 22));
        startWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(startWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        startWindow->setStatusBar(statusbar);

        retranslateUi(startWindow);

        QMetaObject::connectSlotsByName(startWindow);
    } // setupUi

    void retranslateUi(QMainWindow *startWindow)
    {
        startWindow->setWindowTitle(QCoreApplication::translate("startWindow", "\350\277\236\350\277\236\347\234\213", nullptr));
        label->setText(QCoreApplication::translate("startWindow", "        \346\270\270\346\210\217\346\250\241\345\274\217", nullptr));
        label_2->setText(QCoreApplication::translate("startWindow", "        \345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        label_3->setText(QCoreApplication::translate("startWindow", "        \350\256\276\347\275\256", nullptr));
        gameMode->setText(QString());
        startGame->setText(QString());
        setting->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class startWindow: public Ui_startWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
