#ifndef HUFFMANWINDOW_H
#define HUFFMANWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class HuffmanWindow; }
QT_END_NAMESPACE

class HuffmanWindow : public QMainWindow
{
    Q_OBJECT

public:
    HuffmanWindow(QWidget *parent = nullptr);
    ~HuffmanWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::HuffmanWindow *ui;
};
#endif // HUFFMANWINDOW_H
