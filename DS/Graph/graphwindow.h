#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QMainWindow>
#include "graph.h"
QT_BEGIN_NAMESPACE
namespace Ui { class GraphWindow; }
QT_END_NAMESPACE

class GraphWindow : public QMainWindow
{
    Q_OBJECT

public:
    GraphWindow(QWidget *parent = nullptr);
    ~GraphWindow();

private slots:
    void on_pushButton_clicked();

    void on_locButton_clicked();

    void on_locButton_2_clicked();

    void on_locButton_4_clicked();

    void on_locButton_15_clicked();

    void on_locButton_3_clicked();

    void on_locButton_5_clicked();

    void on_locButton_6_clicked();

    void on_locButton_7_clicked();

    void on_locButton_8_clicked();

    void on_locButton_9_clicked();

    void on_locButton_10_clicked();

    void on_locButton_11_clicked();

    void on_locButton_12_clicked();

    void on_locButton_13_clicked();

    void on_locButton_14_clicked();

    void on_locButton_16_clicked();

    void on_locButton_17_clicked();

    void on_pushButton_2_clicked();

    void on_refreshButton_clicked();

    void on_mstButton_clicked();

    void on_allPath_clicked();

    void on_sButton_clicked();

    void on_tButton_clicked();

    void on_bestPath_clicked();

private:
    Ui::GraphWindow *ui;
    graph g;
    bool selected[18] = {false};
    void paintEvent(QPaintEvent *event);
    void universalListener(int id);
    int u;
    int v;
    int sel;
};
#endif // GRAPHWINDOW_H
