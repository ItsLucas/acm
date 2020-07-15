#include "monkeygui.h"
#include "ui_monkeygui.h"
#include "monkey.h"

MonkeyGUI::MonkeyGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MonkeyGUI)
{
    ui->setupUi(this);
}

MonkeyGUI::~MonkeyGUI()
{
    delete ui;
}


void MonkeyGUI::on_pushButton_clicked()
{
    ui->resultBox->clear();
    monkey mo = monkey(ui->monkeyNum->text().toInt(),ui->monkeyPop->text().toInt());
    while(!(mo.isempty())) {
    ui->resultBox->append(QString("The following monkey is out: ")+QString::number(mo.next()));
    }
    ui->resultBox->append(QString("The king is ")+QString::number(mo.king()));
}

