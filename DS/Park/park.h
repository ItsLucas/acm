#ifndef PARK_H
#define PARK_H

#include <QMainWindow>
#include <QImage>
#include <QPropertyAnimation>
#include <QPixmap>
#include <QMessageBox>
#include <QSet>
#include "queue.h"
#include <string>
#include <iostream>
#include <QTime>
#include <set>
#include <thread>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class Park; }
QT_END_NAMESPACE

struct car {
    string cnum;
    QLabel* label;
    int duration = 0;
    int eta = 0;
    int pn = -1;
    bool generated = false;
    inline bool operator<(const car &c) const {
        return duration<c.duration;
    }
};

struct parkinglot {
    queue<car> waitq;
    bool vis[11] = {false};
    bool enabled[11]={false};
    car inslot[11];
    int income = 0;
    int ppm = 2;
    bool q1used = false;
    bool q2used = false;
    bool q3used = false;
    queue<string> records;
    queue<int> exiting;
    queue<QLabel*> delay_pool;
};

class Park : public QMainWindow
{
    Q_OBJECT

public:
    Park(QWidget *parent = nullptr);
    ~Park();
    void initCars();
    void assignImg(QLabel* label);
    void run(QObject *target,QRect start,QRect mid1,QRect mid2,QRect end);
    
private slots:
    void on_pushButton_clicked();
    void eventloop();
    void on_saveButton_clicked();
    void delayed_clear();
private:
    Ui::Park *ui;
    queue<QLabel*> q;
    QTimer *timer;
    void tol(QLabel* label,int start,int end);
    void tor(QLabel* label,int start,int end);
    void assignpn(car &c);
    car rngCar();
    QRect* getanim(int id);
    void animate(QObject* target,QRect* anim,int len);
    std::thread animate_t(QObject* target,QRect* anim,int len);
    parkinglot lot;
    QRect queue1 = QRect(235,235,200,200);
    QRect queue2 = QRect(235,365,200,200);
    QRect queue3 = QRect(235,495,200,200);
    QRect park1 = QRect(390,55,200,200);
    QRect park2 = QRect(390,455,200,200);
    QRect park3 = QRect(550,55,200,200);
    QRect park4 = QRect(550,455,200,200);
    QRect park5 = QRect(710,55,200,200);
    QRect park6 = QRect(710,455,200,200);
    QRect park7 = QRect(860,55,200,200);
    QRect park8 = QRect(860,455,200,200);
    QRect park9 = QRect(1012,55,200,200);
    QRect park10 = QRect(1012,455,200,200);
    QRect wait1 = QRect(20,499,0,0);
    QRect stop1 = QRect(235,235,200,200);
    QRect stop2 = QRect(390,235,200,200);
    QRect stop3 = QRect(550,235,200,200);
    QRect stop4 = QRect(710,235,200,200);
    QRect stop5 = QRect(860,235,200,200);
    QRect stop6 = QRect(1012,235,200,200);
    QRect p1[4] = {queue2,queue1,stop2,park1};
    QRect p2[4] = {queue2,queue1,stop2,park2};
    QRect p3[4] = {queue2,queue1,stop3,park3};
    QRect p4[4] = {queue2,queue1,stop3,park4};
    QRect p5[4] = {queue2,queue1,stop4,park5};
    QRect p6[4] = {queue2,queue1,stop4,park6};
    QRect p7[4] = {queue2,queue1,stop5,park7};
    QRect p8[4] = {queue2,queue1,stop5,park8};
    QRect p9[4] = {queue2,queue1,stop6,park9};
    QRect p10[4] = {queue2,queue1,stop6,park10};
};
#endif // PARK_H
