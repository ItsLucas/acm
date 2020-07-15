#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void on_pushButton_clicked();

    void on_btn_0_clicked();

    void on_btn_9_clicked();

    void on_btn_dot_clicked();

    void on_btn_1_clicked();

    void on_btn_4_clicked();

    void on_btn_2_clicked();

    void on_btn_3_clicked();

    void on_btn_5_clicked();

    void on_btn_6_clicked();

    void on_btn_7_clicked();

    void on_btn_8_clicked();

    void on_btn_plus_clicked();

    void on_btn_go_clicked();

    void on_btn_minus_clicked();

    void on_btn_mul_clicked();

    void on_btn_div_clicked();

    void on_btn_lc_clicked();

    void on_btn_rc_clicked();

    void on_btn_pow_clicked();

    void on_btn_rev_clicked();

    void on_btn_ans_clicked();

    void on_btn_clr_clicked();

    void on_btn_log_clicked();

    void on_btn_neg_clicked();

    void on_btn_sin_clicked();

    void on_btn_cos_clicked();

    void on_actionAbout_triggered();

    void on_actionExit_triggered();

    void on_listWidget_currentTextChanged(const QString &currentText);

    void on_btn_tan_clicked();
    
    void on_btn_cot_clicked();
    
    void on_actiontan_triggered();

    void on_actioncot_triggered();

    void on_actionBIN_triggered();

    void on_actionOCT_triggered();

    void doConvert(int predix, int radix);

    void on_actionDEC_triggered();

    void on_actionHEX_triggered();

private:
    Ui::Calculator *ui;
};
#endif // CALCULATOR_H
