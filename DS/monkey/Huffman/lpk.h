#ifndef LPK_H
#define LPK_H
#include <QDir>
#include <QFileInfoList>
#include <iostream>
#include <QFile>
#include <vector>

using namespace std;

const char LPK_STARTL[2]={0x4C,0x0A};
const char LPK_STARTF[2]={0x4C,0x0B};
const char LPK_ENDF[2]={0x4C,0x0C};
const char LPK_STARTD[2]={0x4C,0x0D};
const char LPK_ENDD[2]={0x4C,0x0E};
const char LPK_ENDL[2]={0x4C,0x0F};
const char LPK_HEADER[4]={0x5F,0x37,0x59,0x0F};

class lpk
{
public:
    lpk(const QString &path,const QString &target);
    lpk(const QString &target);
    void commit();
    void unpack();
    void unpackr(QString path);
private:
    bool findFile(const QString &path);
    QString beginpath;
    QString fileName;
    QFile* handle;
    vector<string> fs;
};

#endif // LPK_H
