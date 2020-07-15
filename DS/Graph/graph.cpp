#include "graph.h"
#include <QSql>
#include <QApplication>
#include <QSqlDatabase>
#include <QObject>
#include <QMessageBox>
#include <QString>
#include <QSqlQuery>
#define inf 19260817
static constexpr int maxn = 25;
int g[maxn][maxn]; // the graph
int mst[maxn];     // save mst
int d[maxn];       // mark
int n, m;          // number of vertex and edge
vector<pair<int,int>> mg;
int prim(int x) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        d[i] =
            g[x][i]; // init the mark with the weight of directly connected edge
        mst[i] = x;  // the mst contains only vertex x at beginning
    }
    d[x] = -1; // mark x
    for (int i = 1; i <= n - 1; i++) {
        int w = inf,
            u = 0; // w means the weight of the chosen edge in current phase
        for (int j = 1; j <= n; j++) { // search for any edge shorter
            if (d[j] < w && d[j] != -1) {
                w = d[j]; // update
                u = j;
            }
        }
        sum += w; // update the total length of mst
        d[u] = -1;
        if (g[mst[u]][u] > 0) { // if edge exists, print the mst
            printf("%d %d\n", mst[u], u);
            mg.push_back(make_pair(mst[u],u));
        }
        for (int i = 1; i <= n; i++) {
            if (d[i] > g[u][i]) {
                d[i] = g[u][i]; // update
                mst[i] = u;     // update path
            }
        }
    }
    return sum;
}
int dis[20];
bool vis[20];
vector<int> graph::dijkstra(int x,int t) {
    cout<<"Target:"<<x<< " "<<t<<endl;
    priority_queue<node> q;
    memset(pre,0,sizeof(pre));
    memset(dis,0x7f7f7f7f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[x]=0;
    q.push(node(x,0));
    while(!q.empty()) {
        auto i = q.top();
        q.pop();
        int v = i.v;
        if(vis[v]) continue;
        vis[v]=true;
        for(auto x:G2[v]) {
            int v2 = x.v;
            int len = x.w;
            if(!vis[v2]&&dis[v2]>dis[v]+len) {
                dis[v2]=dis[v]+len;
                pre[v2]=v;
                q.push(node(v2,dis[v2]));
            }
        }
    }
    vector<int> ans;
    int x2 = t;
    while(true) {
        ans.push_back(x2);
        x2=pre[x2];
        if(x2==0) break;
    }
    for(auto i:ans) {
        cout<<i<<" ";
    }
    cout<<endl;
    dans = dis[t];
    return ans;
}
string qstr2str(const QString qstr)
{
    QByteArray cdata = qstr.toLocal8Bit();
    return string(cdata);
}

graph::graph()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QApplication::applicationDirPath()+"/map.sqlite");
    if (!db.open()) {
            QMessageBox::information(NULL,0, QObject::tr("Database Error"));
     }
    QSqlQuery query;
    /*
    query.exec("CREATE TABLE scenes ("
                       "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                       "name VARCHAR(40) NOT NULL, "
                       "px INTEGER NOT NULL, "
                       "py INTEGER NOT NULL, "
                       "desc VARCHAR(40) NOT NULL)");
    query.exec("CREATE TABLE roads ("
                       "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                       "length INTEGER NOT NULL, "
                       "u INTEGER NOT NULL, "
                       "v INTEGER NOT NULL)");
                       */
    //ifstream fin;
    //fin.open("data.txt");
    //fin>>n;
    n=17;
    query.exec("select * from scenes");
    for(int i=1;i<=17;i++) {
        query.next();
        QString s = query.value(1).toString();
        int id=query.value(0).toInt(),x=query.value(2).toInt(),y=query.value(3).toInt();
        scenes[id].id=id;
        scenes[id].name=s;
        scenes[id].px=x;
        scenes[id].py=y;
    }
    m=22;
    for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = inf; // graph init
            }
        }
    query.exec("select * from roads");
    for(int i=1;i<=m;i++) {
        query.next();
        int u=query.value(2).toInt(),v=query.value(3).toInt(),id=query.value(0).toInt(),w=query.value(1).toInt();
        G[u].push_back(road(id,w,scenes[v],scenes[u]));
        G[v].push_back(road(id,w,scenes[u],scenes[v]));
        G2[u].push_back(node(v,w));
        G2[v].push_back(node(u,w));
        g[u][v]=w;
        g[v][u]=w;
        roads[id].u=scenes[u];
        roads[id].v=scenes[v];
        roads[id].id=id;
        roads[id].length=w;
    }
    /*
    query.clear();
    query.prepare("INSERT INTO scenes (name,px,py,desc) "
                      "VALUES (:name, :px, :py, :desc)");
    for(int i=1;i<=17;i++) {
        query.bindValue(":name",QString::fromStdString(scenes[i].name));
        query.bindValue(":px",scenes[i].px);
        query.bindValue(":py",scenes[i].py);
        query.bindValue(":desc",QString::fromStdString(scenes[i].name));
        query.exec();
    }
    query.clear();
    query.prepare("INSERT INTO roads (length,u,v) "
                   "VALUES (:length, :u, :v)");
 for(int i=1;i<=22;i++) {
     query.bindValue(":length",roads[i].length);
     query.bindValue(":u",roads[i].u.id);
     query.bindValue(":v",roads[i].v.id);
     query.exec();
 }
 query.clear();
 */
   db.close();
}

void graph::printg() {
    int sum = prim(1);
    cout<<sum<<endl;
}

pair<int,int> graph::getloc(int id) {
    return make_pair(scenes[id].px,scenes[id].py);
}

road* graph::getroads() {
    return roads;
}

vector<pair<int,int>> graph::getmst() {
    sum = 0;
    sum = prim(1);
    return mg;
}

QString graph::getDesc(int id) {
    return scenes[id].desc;
}

QString graph::getName(int id) {
    return scenes[id].name;
}
