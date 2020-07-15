/********************************************************************************
** Form generated from reading UI file 'huffmanwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HUFFMANWINDOW_H
#define UI_HUFFMANWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HuffmanWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HuffmanWindow)
    {
        if (HuffmanWindow->objectName().isEmpty())
            HuffmanWindow->setObjectName(QString::fromUtf8("HuffmanWindow"));
        HuffmanWindow->resize(466, 202);
        centralwidget = new QWidget(HuffmanWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 50, 161, 28));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 90, 161, 28));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(260, 50, 161, 28));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(260, 90, 161, 28));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 10, 161, 28));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(260, 10, 161, 28));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 120, 72, 15));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(310, 120, 72, 15));
        HuffmanWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HuffmanWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 466, 26));
        HuffmanWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(HuffmanWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        HuffmanWindow->setStatusBar(statusbar);

        retranslateUi(HuffmanWindow);

        QMetaObject::connectSlotsByName(HuffmanWindow);
    } // setupUi

    void retranslateUi(QMainWindow *HuffmanWindow)
    {
        HuffmanWindow->setWindowTitle(QCoreApplication::translate("HuffmanWindow", "HuffmanWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("HuffmanWindow", "Compress Folder", nullptr));
        pushButton_2->setText(QCoreApplication::translate("HuffmanWindow", "Uncompress", nullptr));
        pushButton_3->setText(QCoreApplication::translate("HuffmanWindow", "Compress Folder", nullptr));
        pushButton_4->setText(QCoreApplication::translate("HuffmanWindow", "Uncompress", nullptr));
        pushButton_5->setText(QCoreApplication::translate("HuffmanWindow", "Compress File", nullptr));
        pushButton_6->setText(QCoreApplication::translate("HuffmanWindow", "Compress File", nullptr));
        label->setText(QCoreApplication::translate("HuffmanWindow", "Huffman", nullptr));
        label_2->setText(QCoreApplication::translate("HuffmanWindow", "Super", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HuffmanWindow: public Ui_HuffmanWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HUFFMANWINDOW_H
