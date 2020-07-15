#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPropertyAnimation>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QPushButton button("Animated Button");

    button.show();

    QPropertyAnimation *animation = new QPropertyAnimation(&button, "geometry");
        animation->setDuration(10000);
        animation->setStartValue(QRect(0, 0, 100, 30));
        animation->setEndValue(QRect(250, 250, 100, 30));

        animation->start();
}
