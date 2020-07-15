#include "calculator.h"
#include "ui_calculator.h"
#include "engine.h"
#include <iostream>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QListWidget>
#include <QRegExp>
#include <QStringList>
#include <QInputDialog>
#include <cmath>

using namespace std;

bool number = false;
QString lastans;
QString _eq;
QString eq;
QMap<QString,QString> historyMap;
Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
    number=true;
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::on_btn_0_clicked() {
    eq.append("0");
    if (number) {
        _eq.append("0");
    } else {
        _eq.append(" 0");
    }
    ui->result->setText(eq);
    number = true;
}
void Calculator::on_btn_1_clicked() {
    eq.append("1");
    if (number) {
        _eq.append("1");
    } else {
        _eq.append(" 1");
    }
    ui->result->setText(eq);
    number = true;
}
void Calculator::on_btn_2_clicked() {
    eq.append("2");
    if (number) {
        _eq.append("2");
    } else {
        _eq.append(" 2");
    }
    ui->result->setText(eq);
    number = true;
}
void Calculator::on_btn_3_clicked() {
    eq.append("3");
    if (number) {
        _eq.append("3");
    } else {
        _eq.append(" 3");
    }
    ui->result->setText(eq);
    number = true;
}
void Calculator::on_btn_4_clicked() {
    eq.append("4");
    if (number) {
        _eq.append("4");
    } else {
        _eq.append(" 4");
    }
    ui->result->setText(eq);
    number = true;
}
void Calculator::on_btn_5_clicked() {
    eq.append("5");
    if (number) {
        _eq.append("5");
    } else {
        _eq.append(" 5");
    }
    ui->result->setText(eq);
    number = true;
}
void Calculator::on_btn_6_clicked() {
    eq.append("6");
    if (number) {
        _eq.append("6");
    } else {
        _eq.append(" 6");
    }
    ui->result->setText(eq);
    number = true;
}
void Calculator::on_btn_7_clicked() {
    eq.append("7");
    if (number) {
        _eq.append("7");
    } else {
        _eq.append(" 7");
    }
    ui->result->setText(eq);
    number = true;
}
void Calculator::on_btn_8_clicked() {
    eq.append("8");
    if (number) {
        _eq.append("8");
    } else {
        _eq.append(" 8");
    }
    ui->result->setText(eq);
    number = true;
}
void Calculator::on_btn_9_clicked() {
    eq.append("9");
    if (number) {
        _eq.append("9");
    } else {
        _eq.append(" 9");
    }
    ui->result->setText(eq);
    number = true;
}

void Calculator::on_btn_plus_clicked()
{
    eq.append("+");
    _eq.append(" +");
    ui->result->setText(eq);
    number=false;
}

void Calculator::on_btn_dot_clicked()
{
    eq.append(".");
    _eq.append(".");
    ui->result->setText(eq);
    number=true;
}

void Calculator::on_btn_go_clicked()
{
    QString resultb = eq;
    eq.clear();
    _eq.append(" =");
    //cout<<_eq.toStdString()<<endl;
    Engine engine = Engine(_eq.toStdString());
    string s = engine.calc();
    ui->result->setText(QString(s.c_str()));
    lastans = QString(s.c_str());
    resultb.append(" = ");
    resultb.append(lastans);
    historyMap.insert(resultb,_eq);
    _eq.clear();
    number=true;
    ui->listWidget->addItem(resultb);
}

void Calculator::on_btn_minus_clicked()
{
    eq.append("-");
    _eq.append(" -");
    ui->result->setText(eq);
    number=false;
}

void Calculator::on_btn_mul_clicked()
{
    eq.append("*");
    _eq.append(" *");
    ui->result->setText(eq);
    number=false;
}

void Calculator::on_btn_div_clicked()
{
    eq.append("/");
    _eq.append(" /");
    ui->result->setText(eq);
    number=false;
}

void Calculator::on_btn_lc_clicked()
{
    eq.append("(");
    _eq.append(" (");
    ui->result->setText(eq);
    number=false;
}

void Calculator::on_btn_rc_clicked()
{
    eq.append(")");
    _eq.append(" )");
    ui->result->setText(eq);
    number=false;
}

void Calculator::on_btn_pow_clicked()
{
    eq.append("^");
    _eq.append(" ^");
    ui->result->setText(eq);
    number=false;
}

void Calculator::on_btn_rev_clicked()
{
    eq.append("|(");
    _eq.append(" | (");
    ui->result->setText(eq);
    number=false;
}

void Calculator::on_btn_ans_clicked()
{
    eq.chop(1);
    _eq.chop(1);
    while(_eq.back()==" ") {
        _eq.chop(1);
    }
    ui->result->setText(eq);
    number=_eq.back().isDigit()?true:false;
}

void Calculator::on_pushButton_clicked() {}
void Calculator::on_btn_clr_clicked()
{
    eq.clear();
    _eq.clear();
    ui->result->setText(eq);
    number=true;
}

void Calculator::on_btn_log_clicked()
{
    eq.append("log(");
    _eq.append(" l (");
    ui->result->setText(eq);
    number=false;
}

void Calculator::on_btn_neg_clicked()
{
    eq.append("--(");
    _eq.append(" _ ( ");
    ui->result->setText(eq);
    number=true;
}

void Calculator::on_btn_sin_clicked()
{
    eq.append("sin(");
    _eq.append(" s ( ");
    ui->result->setText(eq);
    number=true;
}

void Calculator::on_btn_cos_clicked()
{
    eq.append("cos(");
    _eq.append(" c ( ");
    ui->result->setText(eq);
    number=true;
}

void Calculator::on_actionAbout_triggered()
{
    QMessageBox::about(NULL,"Calculator","Simple calculator made by ItsLucas");
}

void Calculator::on_actionExit_triggered()
{
    QApplication::exit(0);
}


void Calculator::on_listWidget_currentTextChanged(const QString &currentText)
{
    QRegExp tagExp("=");
    eq.clear();
    _eq.clear();
    QStringList l = currentText.split(tagExp);
    QString showString = l.first().simplified();
    eq.append(showString);
    ui->result->setText(eq);
    l = historyMap.value(currentText).split(tagExp);
    _eq.append(l.first().simplified());
}

void Calculator::on_btn_tan_clicked()
{
    eq.append("tan(");
    _eq.append(" t ( ");
    ui->result->setText(eq);
    number=true;
}

void Calculator::on_btn_cot_clicked()
{
    eq.append("cot(");
    _eq.append(" o ( ");
    ui->result->setText(eq);
    number=true;
}

void Calculator::on_actiontan_triggered()
{
    eq.append("tan(");
    _eq.append(" t ( ");
    ui->result->setText(eq);
    number=true;
}

void Calculator::on_actioncot_triggered()
{
    eq.append("cot(");
    _eq.append(" o ( ");
    ui->result->setText(eq);
    number=true;
}

void Calculator::doConvert(int predix,int radix) {
    QString resultb = eq;
    eq.clear();
    Engine engine = Engine(_eq.toStdString());
    string s = engine.convert(predix,radix);
    ui->result->setText(QString(s.c_str()));
    lastans = QString(s.c_str());
    resultb.append(" = ");
    resultb.append(lastans);
    historyMap.insert(resultb,_eq);
    _eq.clear();
    number=true;
    ui->listWidget->addItem(resultb);
    _eq.append(s.c_str());
}

void Calculator::on_actionBIN_triggered()
{
    int p = QInputDialog::getInt(NULL,
                                 "Convert",
                                 "Please input source hex:",
                                 10,
                                 0,
                                 16,
                                 1);
    doConvert(p,2);
}

void Calculator::on_actionOCT_triggered()
{
    int p = QInputDialog::getInt(NULL,
                                 "Convert",
                                 "Please input source hex:",
                                 10,
                                 0,
                                 16,
                                 1);
    doConvert(p,8);
}

void Calculator::on_actionDEC_triggered()
{
    int p = QInputDialog::getInt(NULL,
                                 "Convert",
                                 "Please input source hex:",
                                 10,
                                 0,
                                 16,
                                 1);
    doConvert(p,10);
}

void Calculator::on_actionHEX_triggered()
{
    int p = QInputDialog::getInt(NULL,
                                 "Convert",
                                 "Please input source hex:",
                                 10,
                                 0,
                                 16,
                                 1);
    doConvert(p,16);
}
