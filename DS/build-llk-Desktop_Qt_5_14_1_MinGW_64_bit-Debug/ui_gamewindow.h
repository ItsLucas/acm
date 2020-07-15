/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameWindow
{
public:
    QWidget *centralwidget;
    QLabel *scoreLabel;
    QPushButton *continueButton;
    QPushButton *resetButton;
    QPushButton *tipsButton;
    QLabel *timeLabel;
    QPushButton *exitButton;
    QWidget *widget;
    QPushButton *pauseButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *gameWindow)
    {
        if (gameWindow->objectName().isEmpty())
            gameWindow->setObjectName(QString::fromUtf8("gameWindow"));
        gameWindow->resize(1123, 567);
        gameWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(gameWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        scoreLabel = new QLabel(centralwidget);
        scoreLabel->setObjectName(QString::fromUtf8("scoreLabel"));
        scoreLabel->setGeometry(QRect(860, 30, 101, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Black"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        scoreLabel->setFont(font);
        continueButton = new QPushButton(centralwidget);
        continueButton->setObjectName(QString::fromUtf8("continueButton"));
        continueButton->setEnabled(false);
        continueButton->setGeometry(QRect(860, 190, 93, 28));
        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setGeometry(QRect(860, 250, 93, 28));
        tipsButton = new QPushButton(centralwidget);
        tipsButton->setObjectName(QString::fromUtf8("tipsButton"));
        tipsButton->setGeometry(QRect(860, 310, 93, 28));
        timeLabel = new QLabel(centralwidget);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        timeLabel->setGeometry(QRect(730, 420, 101, 41));
        timeLabel->setFont(font);
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(860, 370, 93, 28));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 40, 661, 461));
        pauseButton = new QPushButton(centralwidget);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));
        pauseButton->setGeometry(QRect(860, 130, 91, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(840, 120, 127, 54));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\345\275\251\344\272\221"));
        font1.setPointSize(14);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("image:\n"
"url(:/button/buttons/button.png)"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(840, 180, 127, 54));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("image:\n"
"url(:/button/buttons/button.png)"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(840, 240, 127, 54));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("image:\n"
"url(:/button/buttons/button.png)"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(840, 300, 127, 54));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("image:\n"
"url(:/button/buttons/button.png)"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(840, 360, 127, 54));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("image:\n"
"url(:/button/buttons/button.png)"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(800, 30, 127, 54));
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("image:\n"
"url(:/button/buttons/button.png)"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(710, 420, 127, 54));
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("image:\n"
"url(:/button/buttons/button.png)"));
        gameWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(gameWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1123, 22));
        gameWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(gameWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        gameWindow->setStatusBar(statusbar);

        retranslateUi(gameWindow);

        QMetaObject::connectSlotsByName(gameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *gameWindow)
    {
        gameWindow->setWindowTitle(QCoreApplication::translate("gameWindow", "\350\277\236\350\277\236\347\234\213", nullptr));
        scoreLabel->setText(QCoreApplication::translate("gameWindow", "\345\210\206\346\225\260\357\274\232", nullptr));
        continueButton->setText(QCoreApplication::translate("gameWindow", "\347\273\247\347\273\255", nullptr));
        resetButton->setText(QCoreApplication::translate("gameWindow", "\351\207\215\347\275\256", nullptr));
        tipsButton->setText(QCoreApplication::translate("gameWindow", "\346\217\220\347\244\272", nullptr));
        timeLabel->setText(QCoreApplication::translate("gameWindow", "\346\227\266\351\227\264\357\274\232", nullptr));
        exitButton->setText(QCoreApplication::translate("gameWindow", "\351\200\200\345\207\272", nullptr));
        pauseButton->setText(QCoreApplication::translate("gameWindow", "\346\232\202\345\201\234", nullptr));
        label->setText(QCoreApplication::translate("gameWindow", "        \346\232\202\345\201\234", nullptr));
        label_2->setText(QCoreApplication::translate("gameWindow", "        \347\273\247\347\273\255", nullptr));
        label_3->setText(QCoreApplication::translate("gameWindow", "        \351\207\215\347\275\256", nullptr));
        label_4->setText(QCoreApplication::translate("gameWindow", "        \346\217\220\347\244\272", nullptr));
        label_5->setText(QCoreApplication::translate("gameWindow", "        \351\200\200\345\207\272", nullptr));
        label_6->setText(QCoreApplication::translate("gameWindow", "        \345\210\206\346\225\260\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("gameWindow", "        \346\227\266\351\227\264\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gameWindow: public Ui_gameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
