#include "lpk.h"
#include <io.h>
#include <fstream>
using namespace std;

lpk::lpk(const QString &path,const QString &target)
{
    beginpath=path;
    fileName=target;
}

lpk::lpk(const QString &target)
{
    fileName=target;
}

void lpk::unpack() {
    QFile file(fileName);
    file.open(QFile::ReadOnly);
    QByteArray arr = file.readLine();
    QDir dir(".\\");
    dir.mkdir(fileName+"_d");
    dir.cd(fileName+"_d");
    for(;;) {
        QByteArray arr = file.readLine();
        if(arr.toStdString()=="LPKDIR_\n") {
            arr = file.readLine();
            dir.mkdir(arr.simplified());
            dir.cd(arr.simplified());
        }
        if(arr.contains("1KPL")) {
            break;
        }
        if(arr.toStdString()=="LPKDIR_E\n") {
            dir.cdUp();
        }
        if(arr.toStdString()=="LPKF_\n") {
            arr = file.readLine();
            handle = new QFile(dir.path()+"\\"+QString(arr).simplified());
            //createFile(dir.currentPath(),QString(arr));
            arr = file.readLine();
            int size = arr.toUInt();
            arr = file.read(size);
            handle->open(QIODevice::WriteOnly|QIODevice::Truncate);
            handle->write(arr);
            handle->close();
            delete handle;
        }
    }
}

void lpk::commit() {
    handle = new QFile(fileName);
    handle->open(QIODevice::WriteOnly|QIODevice::Truncate);
    handle->write("LPK1");
    handle->write("\n");
    findFile(beginpath);
    handle->write("1KPL");
    handle->close();
}

bool lpk::findFile(const QString &path)
{
    QDir dir(path);
    if(!dir.exists())
    {
        return false;
    }
    dir.setFilter(QDir::Dirs | QDir::Files);
    dir.setSorting(QDir::DirsFirst);
    QFileInfoList list = dir.entryInfoList();
    int i = 0;

    bool bIsDir;
    do
    {
        QFileInfo fileInfo = list.at(i);
        if((fileInfo.fileName() == "." )| (fileInfo.fileName() == ".."))
        {
            ++i;
            continue;
        }
        bIsDir = fileInfo.isDir();
        if(bIsDir)
        {
            handle->write("LPKDIR_\n");
            handle->write(fileInfo.fileName().toStdString().c_str());
            handle->write("\n");
            findFile(fileInfo.filePath());
            handle->write("LPKDIR_E\n");
        }
        else
        {
            handle->write("LPKF_\n");
            handle->write(fileInfo.fileName().toStdString().c_str());
            handle->write("\n");
            handle->flush();
            QFile file(fileInfo.absoluteFilePath());
            file.open(QFile::ReadOnly);
            QByteArray arr = file.readAll();
            handle->write(QString::number(arr.length()).toStdString().c_str());
            handle->write("\n");
            handle->write(arr);
            file.close();
            handle->flush();
        }
        ++i;
    }while(i < list.size());

    return true;
}

