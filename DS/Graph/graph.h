#ifndef GRAPH_H
#define GRAPH_H
#include <bits/stdc++.h>
#include <QString>
using namespace std;

struct scene {
    int id;
    QString name;
    int px;
    int py;
    QString desc;
};

struct road {
    int id = 0;
    int length = 0;
    scene v;
    scene u;
    road(int id,int length,scene v,scene u):id(id),length(length),v(v),u(u){};
    road(){};
};

struct node {
    int v,w;
    node(int v=0,int w=0):v(v),w(w){};
    bool operator<(const node &x) const {
        return w<x.w;
    }
};

class graph
{
private:
    vector<road> G[20];
    vector<node> G2[20];
    scene scenes[20];
    road roads[100];
    int pre[20];
public:
    graph();
    void printg();
    pair<int,int> getloc(int id);
    road* getroads();
    vector<pair<int,int>> getmst();
    QString getDesc(int id);
    QString getName(int id);
    vector<int> dijkstra(int x,int t);
    int sum = 0;
    int dans = 0;
};

#endif // GRAPH_H
