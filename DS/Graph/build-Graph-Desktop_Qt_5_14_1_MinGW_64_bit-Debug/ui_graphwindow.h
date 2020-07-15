/********************************************************************************
** Form generated from reading UI file 'graphwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHWINDOW_H
#define UI_GRAPHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *locButton;
    QPushButton *locButton_2;
    QPushButton *locButton_3;
    QPushButton *locButton_4;
    QPushButton *locButton_5;
    QPushButton *locButton_6;
    QPushButton *locButton_7;
    QPushButton *locButton_8;
    QPushButton *locButton_9;
    QPushButton *locButton_10;
    QPushButton *locButton_11;
    QPushButton *locButton_12;
    QPushButton *locButton_13;
    QPushButton *locButton_14;
    QPushButton *locButton_15;
    QPushButton *locButton_16;
    QPushButton *locButton_17;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *locName;
    QLabel *locDesc;
    QPushButton *refreshButton;
    QPushButton *sButton;
    QPushButton *tButton;
    QPushButton *mstButton;
    QPushButton *allPath;
    QPushButton *bestPath;
    QLabel *disLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *GraphWindow)
    {
        if (GraphWindow->objectName().isEmpty())
            GraphWindow->setObjectName(QString::fromUtf8("GraphWindow"));
        GraphWindow->resize(1918, 917);
        centralwidget = new QWidget(GraphWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 1641, 841));
        locButton = new QPushButton(centralwidget);
        buttonGroup = new QButtonGroup(GraphWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(locButton);
        locButton->setObjectName(QString::fromUtf8("locButton"));
        locButton->setGeometry(QRect(390, 500, 31, 28));
        locButton_2 = new QPushButton(centralwidget);
        buttonGroup->addButton(locButton_2);
        locButton_2->setObjectName(QString::fromUtf8("locButton_2"));
        locButton_2->setGeometry(QRect(750, 830, 31, 28));
        locButton_3 = new QPushButton(centralwidget);
        buttonGroup->addButton(locButton_3);
        locButton_3->setObjectName(QString::fromUtf8("locButton_3"));
        locButton_3->setGeometry(QRect(780, 830, 31, 28));
        locButton_4 = new QPushButton(centralwidget);
        buttonGroup->addButton(locButton_4);
        locButton_4->setObjectName(QString::fromUtf8("locButton_4"));
        locButton_4->setGeometry(QRect(790, 840, 31, 28));
        locButton_5 = new QPushButton(centralwidget);
        buttonGroup->addButton(locButton_5);
        locButton_5->setObjectName(QString::fromUtf8("locButton_5"));
        locButton_5->setGeometry(QRect(800, 850, 31, 28));
        locButton_6 = new QPushButton(centralwidget);
        buttonGroup->addButton(locButton_6);
        locButton_6->setObjectName(QString::fromUtf8("locButton_6"));
        locButton_6->setGeometry(QRect(810, 860, 31, 28));
        locButton_7 = new QPushButton(centralwidget);
        buttonGroup->addButton(locButton_7);
        locButton_7->setObjectName(QString::fromUtf8("locButton_7"));
        locButton_7->setGeometry(QRect(820, 870, 31, 28));
        locButton_8 = new QPushButton(centralwidget);
        buttonGroup->addButton(locButton_8);
        locButton_8->setObjectName(QString::fromUtf8("locButton_8"));
        locButton_8->setGeometry(QRect(830, 880, 31, 28));
        locButton_9 = new QPushButton(centralwidget);
        buttonGroup->addButton(locButton_9);
        locButton_9->setObjectName(QString::fromUtf8("locButton_9"));
        locButton_9->setGeometry(QRect(840, 890, 31, 28));
        locButton_10 = new QPushButton(centralwidget);
        buttonGroup->addButton(locButton_10);
        locButton_10->setObjectName(QString::fromUtf8("locButton_10"));
        locButton_10->setGeometry(QRect(850, 900, 31, 28));
        locButton_11 = new QPushButton(centralwidget);
        buttonGroup->addButton(locButton_11);
        locButton_11->setObjectName(QString::fromUtf8("locButton_11"));
        locButton_11->setGeometry(QRect(860, 910, 31, 28));
        locButton_12 = new QPushButton(centralwidget);
        buttonGroup->addButton(locButton_12);
        locButton_12->setObjectName(QString::fromUtf8("locButton_12"));
        locButton_12->setGeometry(QRect(860, 910, 31, 28));
        locButton_13 = new QPushButton(centralwidget);
        buttonGroup->addButton(locButton_13);
        locButton_13->setObjectName(QString::fromUtf8("locButton_13"));
        locButton_13->setGeometry(QRect(860, 910, 31, 28));
        locButton_14 = new QPushButton(centralwidget);
        buttonGroup->addButton(locButton_14);
        locButton_14->setObjectName(QString::fromUtf8("locButton_14"));
        locButton_14->setGeometry(QRect(860, 910, 31, 28));
        locButton_15 = new QPushButton(centralwidget);
        buttonGroup->addButton(locButton_15);
        locButton_15->setObjectName(QString::fromUtf8("locButton_15"));
        locButton_15->setGeometry(QRect(860, 910, 31, 28));
        locButton_16 = new QPushButton(centralwidget);
        buttonGroup->addButton(locButton_16);
        locButton_16->setObjectName(QString::fromUtf8("locButton_16"));
        locButton_16->setGeometry(QRect(860, 910, 31, 28));
        locButton_17 = new QPushButton(centralwidget);
        buttonGroup->addButton(locButton_17);
        locButton_17->setObjectName(QString::fromUtf8("locButton_17"));
        locButton_17->setGeometry(QRect(860, 910, 31, 28));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1740, 10, 72, 15));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1670, 40, 72, 15));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1670, 60, 72, 15));
        locName = new QLabel(centralwidget);
        locName->setObjectName(QString::fromUtf8("locName"));
        locName->setGeometry(QRect(1740, 40, 72, 15));
        locDesc = new QLabel(centralwidget);
        locDesc->setObjectName(QString::fromUtf8("locDesc"));
        locDesc->setGeometry(QRect(1740, 60, 72, 15));
        refreshButton = new QPushButton(centralwidget);
        refreshButton->setObjectName(QString::fromUtf8("refreshButton"));
        refreshButton->setGeometry(QRect(1660, 130, 93, 71));
        sButton = new QPushButton(centralwidget);
        sButton->setObjectName(QString::fromUtf8("sButton"));
        sButton->setGeometry(QRect(1800, 130, 93, 71));
        tButton = new QPushButton(centralwidget);
        tButton->setObjectName(QString::fromUtf8("tButton"));
        tButton->setGeometry(QRect(1800, 220, 93, 71));
        mstButton = new QPushButton(centralwidget);
        mstButton->setObjectName(QString::fromUtf8("mstButton"));
        mstButton->setGeometry(QRect(1660, 220, 93, 71));
        allPath = new QPushButton(centralwidget);
        allPath->setObjectName(QString::fromUtf8("allPath"));
        allPath->setGeometry(QRect(1660, 310, 93, 71));
        bestPath = new QPushButton(centralwidget);
        bestPath->setObjectName(QString::fromUtf8("bestPath"));
        bestPath->setGeometry(QRect(1800, 310, 93, 71));
        disLabel = new QLabel(centralwidget);
        disLabel->setObjectName(QString::fromUtf8("disLabel"));
        disLabel->setGeometry(QRect(1690, 590, 181, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(22);
        disLabel->setFont(font);
        disLabel->setTextFormat(Qt::AutoText);
        GraphWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GraphWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1918, 26));
        GraphWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(GraphWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        GraphWindow->setStatusBar(statusbar);

        retranslateUi(GraphWindow);

        QMetaObject::connectSlotsByName(GraphWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GraphWindow)
    {
        GraphWindow->setWindowTitle(QCoreApplication::translate("GraphWindow", "GraphWindow", nullptr));
        locButton->setText(QCoreApplication::translate("GraphWindow", "1", nullptr));
        locButton_2->setText(QCoreApplication::translate("GraphWindow", "2", nullptr));
        locButton_3->setText(QCoreApplication::translate("GraphWindow", "3", nullptr));
        locButton_4->setText(QCoreApplication::translate("GraphWindow", "4", nullptr));
        locButton_5->setText(QCoreApplication::translate("GraphWindow", "5", nullptr));
        locButton_6->setText(QCoreApplication::translate("GraphWindow", "6", nullptr));
        locButton_7->setText(QCoreApplication::translate("GraphWindow", "7", nullptr));
        locButton_8->setText(QCoreApplication::translate("GraphWindow", "8", nullptr));
        locButton_9->setText(QCoreApplication::translate("GraphWindow", "9", nullptr));
        locButton_10->setText(QCoreApplication::translate("GraphWindow", "10", nullptr));
        locButton_11->setText(QCoreApplication::translate("GraphWindow", "11", nullptr));
        locButton_12->setText(QCoreApplication::translate("GraphWindow", "12", nullptr));
        locButton_13->setText(QCoreApplication::translate("GraphWindow", "13", nullptr));
        locButton_14->setText(QCoreApplication::translate("GraphWindow", "14", nullptr));
        locButton_15->setText(QCoreApplication::translate("GraphWindow", "15", nullptr));
        locButton_16->setText(QCoreApplication::translate("GraphWindow", "16", nullptr));
        locButton_17->setText(QCoreApplication::translate("GraphWindow", "17", nullptr));
        label->setText(QCoreApplication::translate("GraphWindow", "\345\275\223\345\211\215\345\234\260\347\202\271", nullptr));
        label_2->setText(QCoreApplication::translate("GraphWindow", "\345\234\260\347\202\271\345\220\215\345\255\227\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("GraphWindow", "\345\234\260\347\202\271\347\256\200\344\273\213\357\274\232", nullptr));
        locName->setText(QString());
        locDesc->setText(QString());
        refreshButton->setText(QCoreApplication::translate("GraphWindow", "\345\210\267\346\226\260\345\234\260\345\233\276", nullptr));
        sButton->setText(QCoreApplication::translate("GraphWindow", "\351\200\211\346\213\251\350\265\267\347\202\271", nullptr));
        tButton->setText(QCoreApplication::translate("GraphWindow", "\351\200\211\346\213\251\347\273\210\347\202\271", nullptr));
        mstButton->setText(QCoreApplication::translate("GraphWindow", "\345\205\250\346\231\257\347\202\271\350\267\257\345\276\204", nullptr));
        allPath->setText(QCoreApplication::translate("GraphWindow", "\346\211\200\346\234\211\350\267\257\345\276\204", nullptr));
        bestPath->setText(QCoreApplication::translate("GraphWindow", "\351\200\211\346\213\251\346\234\200\344\274\230\350\267\257\345\276\204", nullptr));
        disLabel->setText(QCoreApplication::translate("GraphWindow", "0m", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GraphWindow: public Ui_GraphWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHWINDOW_H
