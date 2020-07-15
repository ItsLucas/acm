#ifndef MONKEYGUI_H
#define MONKEYGUI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MonkeyGUI; }
QT_END_NAMESPACE

class MonkeyGUI : public QMainWindow
{
    Q_OBJECT

public:
    MonkeyGUI(QWidget *parent = nullptr);
    ~MonkeyGUI();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MonkeyGUI *ui;
};
#endif // MONKEYGUI_H
