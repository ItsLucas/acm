#include "graphwindow.h"
#include "ui_graphwindow.h"
#include "graph.h"
#include <QGraphicsScene>
#include <QPoint>
#include <QMouseEvent>
GraphWindow::GraphWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GraphWindow)
{
    ui->setupUi(this);
    for(auto b : ui->buttonGroup->buttons()) {
        b->hide();
    }
    g = graph();
    QGraphicsScene* orig = new QGraphicsScene(this);
    ui->graphicsView->setScene(orig);
    QPixmap* pix = new QPixmap("map.png");
    orig->addPixmap(*pix);
    ui->graphicsView->show();
    for(auto b : ui->buttonGroup->buttons()) {
        int id = b->text().toInt();
        pair<int,int> loc = g.getloc(id);
        b->setGeometry(loc.first,loc.second,30,30);
        b->show();
    }
}

GraphWindow::~GraphWindow()
{
    delete ui;
}

QPoint ps[45];

void GraphWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    for(int i=1;i<=44;i+=2) {
        painter.drawLine(ps[i],ps[i+1]);
    }
}

void GraphWindow::on_pushButton_clicked()
{
    auto orig = ui->graphicsView->scene();
    vector<pair<int,int>> mst = g.getmst();
    for(auto x:mst) {
        pair<int,int> locx = g.getloc(x.first);
        pair<int,int> locy = g.getloc(x.second);
        QPoint px(locx.first,locx.second);
        QPoint py(locy.first,locy.second);
        orig->addLine(QLine(px,py),QPen(Qt::PenStyle::SolidLine));
    }
    ui->graphicsView->update();
}

void GraphWindow::universalListener(int id) {
    selected[id]=true;
    cout<<"Selected "<<id<<endl;
    ui->locName->setText(g.getName(id));
    ui->locDesc->setText(g.getName(id));
    sel=id;
}
void GraphWindow::on_locButton_clicked()
{
    QPushButton *but = qobject_cast<QPushButton*>(sender());
    universalListener(but->text().toInt());
}

void GraphWindow::on_locButton_2_clicked()
{
    QPushButton *but = qobject_cast<QPushButton*>(sender());
    universalListener(but->text().toInt());
}

void GraphWindow::on_locButton_4_clicked()
{
    QPushButton *but = qobject_cast<QPushButton*>(sender());
    universalListener(but->text().toInt());
}

void GraphWindow::on_locButton_15_clicked()
{
    QPushButton *but = qobject_cast<QPushButton*>(sender());
    universalListener(but->text().toInt());
}

void GraphWindow::on_locButton_3_clicked()
{
    QPushButton *but = qobject_cast<QPushButton*>(sender());
    universalListener(but->text().toInt());
}

void GraphWindow::on_locButton_5_clicked()
{
    QPushButton *but = qobject_cast<QPushButton*>(sender());
    universalListener(but->text().toInt());
}

void GraphWindow::on_locButton_6_clicked()
{
    QPushButton *but = qobject_cast<QPushButton*>(sender());
    universalListener(but->text().toInt());
}

void GraphWindow::on_locButton_7_clicked()
{
    QPushButton *but = qobject_cast<QPushButton*>(sender());
    universalListener(but->text().toInt());
}

void GraphWindow::on_locButton_8_clicked()
{
    QPushButton *but = qobject_cast<QPushButton*>(sender());
    universalListener(but->text().toInt());
}

void GraphWindow::on_locButton_9_clicked()
{
    QPushButton *but = qobject_cast<QPushButton*>(sender());
    universalListener(but->text().toInt());
}

void GraphWindow::on_locButton_10_clicked()
{
    QPushButton *but = qobject_cast<QPushButton*>(sender());
    universalListener(but->text().toInt());
}

void GraphWindow::on_locButton_11_clicked()
{
    QPushButton *but = qobject_cast<QPushButton*>(sender());
    universalListener(but->text().toInt());
}

void GraphWindow::on_locButton_12_clicked()
{
    QPushButton *but = qobject_cast<QPushButton*>(sender());
    universalListener(but->text().toInt());
}

void GraphWindow::on_locButton_13_clicked()
{
    QPushButton *but = qobject_cast<QPushButton*>(sender());
    universalListener(but->text().toInt());
}

void GraphWindow::on_locButton_14_clicked()
{
    QPushButton *but = qobject_cast<QPushButton*>(sender());
    universalListener(but->text().toInt());
}

void GraphWindow::on_locButton_16_clicked()
{
    QPushButton *but = qobject_cast<QPushButton*>(sender());
    universalListener(but->text().toInt());
}

void GraphWindow::on_locButton_17_clicked()
{
    QPushButton *but = qobject_cast<QPushButton*>(sender());
    universalListener(but->text().toInt());
}

void GraphWindow::on_pushButton_2_clicked()
{
    graph g = graph();
    QGraphicsScene *orig = ui->graphicsView->scene();
    vector<pair<int,int>> mst = g.getmst();
    for(auto x:mst) {
        pair<int,int> locx = g.getloc(x.first);
        pair<int,int> locy = g.getloc(x.second);
        QPoint px(locx.first,locx.second);
        QPoint py(locy.first,locy.second);
        orig->addLine(QLine(px,py),QPen(Qt::PenStyle::NoPen));
    }
    ui->graphicsView->update();
}

void GraphWindow::on_refreshButton_clicked()
{
    QGraphicsScene* orig = new QGraphicsScene(this);
    ui->graphicsView->setScene(orig);
    QPixmap* pix = new QPixmap("map.png");
    orig->addPixmap(*pix);
    ui->graphicsView->show();
    for(auto b : ui->buttonGroup->buttons()) {
        int id = b->text().toInt();
        pair<int,int> loc = g.getloc(id);
        b->setGeometry(loc.first,loc.second,30,30);
        b->show();
    }
}

void GraphWindow::on_mstButton_clicked()
{
    QGraphicsScene *orig = ui->graphicsView->scene();
    vector<pair<int,int>> mst = g.getmst();
    for(auto x:mst) {
        pair<int,int> locx = g.getloc(x.first);
        pair<int,int> locy = g.getloc(x.second);
        QPoint px(locx.first,locx.second);
        QPoint py(locy.first,locy.second);
        orig->addLine(QLine(px,py),QPen(Qt::PenStyle::SolidLine));
    }
    ui->graphicsView->update();
    ui->disLabel->setText(QString::number(g.sum)+"m");
}

void GraphWindow::on_allPath_clicked()
{
    QGraphicsScene *orig = ui->graphicsView->scene();
    road* r = g.getroads();
    for(int i=1;i<=22;i++) {
        pair<int,int> locx = g.getloc(r[i].u.id);
        pair<int,int> locy = g.getloc(r[i].v.id);
        QPoint px(locx.first,locx.second);
        QPoint py(locy.first,locy.second);
        orig->addLine(QLine(px,py),QPen(Qt::PenStyle::SolidLine));
    }
    ui->graphicsView->update();
}

void GraphWindow::on_sButton_clicked()
{
    u=sel;
}

void GraphWindow::on_tButton_clicked()
{
    v=sel;
}

void GraphWindow::on_bestPath_clicked()
{
    auto vec = g.dijkstra(u,v);
    QGraphicsScene *orig = ui->graphicsView->scene();
    for(auto x = vec.begin();x!=vec.end();) {
        pair<int,int> locx = g.getloc((*x));
        cout<<(*x)<<endl;
        if(x==vec.end()) break;
        x++;
        if(x==vec.end()) break;
        pair<int,int> locy = g.getloc((*x));
        cout<<(*x)<<endl;
        QPoint px(locx.first,locx.second);
        QPoint py(locy.first,locy.second);
        orig->addLine(QLine(px,py),QPen(Qt::PenStyle::SolidLine));
    }
    ui->graphicsView->update();
    ui->disLabel->setText(QString::number(g.dans)+"m");
}
