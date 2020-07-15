#include "park.h"
#include "ui_park.h"
#include <QRandomGenerator>
#include <sstream>
#include <QTimer>
#include <thread>
#include <fstream>
using namespace std;

Park::Park(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Park)
{
    ui->setupUi(this);
    initCars();
}

Park::~Park()
{
    delete ui;
}

void Park::initCars() {
    assignImg(ui->car);
    q.push(ui->car);
    assignImg(ui->car_2);
    q.push(ui->car_2);
    assignImg(ui->car_3);
    q.push(ui->car_3);
    assignImg(ui->car_4);
    q.push(ui->car_4);
    assignImg(ui->car_5);
    q.push(ui->car_5);
    assignImg(ui->car_6);
    q.push(ui->car_6);
    assignImg(ui->car_7);
    q.push(ui->car_7);
    assignImg(ui->car_8);
    q.push(ui->car_8);
    assignImg(ui->car_9);
    q.push(ui->car_9);
    assignImg(ui->car_10);
    q.push(ui->car_10);
    assignImg(ui->car_11);
    q.push(ui->car_11);
    assignImg(ui->car_12);
    q.push(ui->car_12);
    assignImg(ui->car_13);
    q.push(ui->car_13);
    assignImg(ui->car_14);
    q.push(ui->car_14);
    assignImg(ui->car_15);
    q.push(ui->car_15);
    assignImg(ui->car_q);
    run(ui->car_q,queue2,queue2,queue2,queue2);
}

void Park::tol(QLabel *label, int start, int end){
    QPropertyAnimation *animation = new QPropertyAnimation(label, "rotation");
    animation->setDuration(500);
    animation->setStartValue(start);
    animation->setEndValue(end);
    animation->setLoopCount(1);
}

void Park::tor(QLabel *label, int start, int end){
    QPropertyAnimation *animation = new QPropertyAnimation(label, "rotation");
    animation->setDuration(500);
    animation->setStartValue(end);
    animation->setEndValue(start);
    animation->setLoopCount(1);
}

void Park::assignImg(QLabel *label) {
    QImage *img=new QImage;
    if(!(img->load("icon.png"))){
         delete img;
         return;
    }
    QImage imgScaled;
    imgScaled=img->scaled(121,121);
    label->setPixmap(QPixmap::fromImage(imgScaled));
    run(label,wait1,wait1,wait1,wait1);
}

void Park::run(QObject *target,QRect start,QRect mid1,QRect mid2,QRect end)
{
    QPropertyAnimation *animation = new QPropertyAnimation(target,"geometry");
    animation->setDuration(2000);
    animation->setStartValue(start);
    if(mid2.x()==0&&mid2.y()==0)
    animation->setKeyValueAt(0.5,mid1);
    else {
        animation->setKeyValueAt(0.333,mid1);
        animation->setKeyValueAt(0.666,mid2);
    }
    animation->setEndValue(end);
    animation->start();
}

void Park::on_pushButton_clicked()
{
    int n = ui->nline->text().toInt();
    int m = ui->mline->text().toInt();
    for(int i=1;i<=n;i++) {
        lot.enabled[i]=true;
    }
    lot.waitq.setsize(m);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(eventloop()));
    timer->start(1000);
}

string genrngstring() {
    stringstream ss;
    for(int i=1;i<=6;i++)
    ss<<(char)QRandomGenerator::global()->bounded(65,90);
    return ss.str();
}

void Park::assignpn(car &c) {
    for(int i=1;i<=10;i++) {
        if(!lot.vis[i]&&lot.enabled[i]) {
            c.pn=i;
            cout<<c.cnum<<" "<<c.eta<<endl;
            break;
        }
        else continue;
    }
}

car Park::rngCar(){
    int x = QRandomGenerator::global()->bounded(0,100);
    car c;
    if(x<21) {
        c.cnum=genrngstring();
        c.eta=QRandomGenerator::global()->bounded(1,60);
        c.generated=true;
        if(q.empty()) {
            c.label=NULL;
            c.generated=false;
        }
        else {
            c.label=q.top();
            q.pop();
            assignpn(c);
        }
    }
    return c;
}

QRect* Park::getanim(int id) {
    switch(id) {
    case 1:
        return p1;
        break;
    case 2:
        return p2;
        break;
    case 3:
        return p3;
        break;
    case 4:
        return p4;
        break;
    case 5:
        return p5;
        break;
    case 6:
        return p6;
        break;
    case 7:
        return p7;
        break;
    case 8:
        return p8;
        break;
    case 9:
        return p9;
        break;
    case 10:
        return p10;
        break;
    default:
        return NULL;
        break;
    }
}

void Park::animate(QObject *target, QRect *anim,int len) {  
     run(target,anim[0],anim[1],anim[2],anim[3]);
}

std::thread Park::animate_t(QObject *target, QRect *anim, int len) {
    return std::thread(&Park::animate,this,target,anim,len);
}

void Park::eventloop() {
    int sec = ui->label_sec->text().toInt();
    int min = ui->label_min->text().toInt();
    int hr = ui->label_hr->text().toInt();
    sec++;
    if(sec>59) {
        sec=0;
        min++;
    }
    if(min>59) {
        min=0;
        hr++;
    }
    ui->label_sec->setText(QString::number(sec));
    ui->label_min->setText(QString::number(min));
    ui->label_hr->setText(QString::number(hr));
    car c = rngCar();
    if(c.generated) {
        if(!lot.waitq.full()) {
            lot.waitq.push(c);
            run(c.label,queue3,queue2,queue2,queue2);
        }
    }
    ui->label_q->setText(QString::number(lot.waitq.getsize()));
    if(!lot.waitq.empty()) {
        car c = lot.waitq.top();
        if(c.pn==-1) {
            assignpn(c);
            if(c.pn!=-1)  {
                lot.waitq.pop();
                ui->label_q->setText(QString::number(lot.waitq.getsize()));
                QRect* anim = getanim(c.pn);
                //std::thread t1 = animate_t(c.label,anim,3);
                //t1.join();
                animate(c.label,anim,3);
                lot.vis[c.pn]=true;
                lot.inslot[c.pn]=c;
            }
        }
        else {
        lot.waitq.pop();
        ui->label_q->setText(QString::number(lot.waitq.getsize()));
        QRect* anim = getanim(c.pn);
        //std::thread t1 = animate_t(c.label,anim,3);
        //t1.join();
        animate(c.label,anim,3);
        lot.vis[c.pn]=true;
        lot.inslot[c.pn]=c;
        }
    }
    for(int i=1;i<=10;i++) {
        if(lot.vis[i]&&lot.enabled[i]) {
            lot.inslot[i].duration++;
        }
    }
    for(int i=1;i<=10;i++) {
        if(lot.vis[i]&&lot.enabled[i]) {
            car x = lot.inslot[i];
        if(x.duration>=x.eta) {
            int inc = x.eta*lot.ppm;
            lot.income+=inc;
            //generate string
            stringstream ss;
            ss<<hr<<":"<<min<<":"<<sec<<" "<<x.cnum<<" leaved, got $"<<inc;
            lot.records.push(ss.str());
            cout<<x.cnum<<endl;
            ui->no_label->setText(QString::fromStdString(x.cnum));
            ui->money_label->setText(QString::number(inc));
            ui->tot_label->setText(QString::number(lot.income));
            QRect* anim = getanim(x.pn);
            QRect tmp[4] = {anim[3],anim[2],anim[1],wait1};
            run(x.label,tmp[0],tmp[1],tmp[2],tmp[3]);
            lot.delay_pool.push(x.label);
            lot.exiting.push(x.pn);
            //FIX: multiple cars into one slot
            lot.enabled[x.pn]=false;
            QTimer::singleShot(2000,this,SLOT(delayed_clear()));
        }
        }
    }
    int cnt = 0;
    for(int i=1;i<=10;i++) {
        if(!lot.vis[i]&&lot.enabled[i]) {
            cnt++;
        }
    }
    ui->label_empty->setText(QString::number(cnt));
}

void Park::delayed_clear() {
    if(!lot.exiting.empty()) {
        int id = lot.exiting.top();
        lot.exiting.pop();
        cout<<"Delayed clear of "<<id<<endl;
        lot.vis[id]=false;
        lot.enabled[id]=true;
    }
    if(!lot.delay_pool.empty()) {
        QLabel* l = lot.delay_pool.top();
        lot.delay_pool.pop();
        q.push(l);
    }
}
void Park::on_saveButton_clicked()
{
    ofstream fout;
    fout.open("record.txt");
    while(!lot.records.empty()) {
        string s = lot.records.top();
        lot.records.pop();
        fout<<s<<endl;
    }
    fout<<"Total income: $"<<lot.income<<endl;
    fout.close();
}
