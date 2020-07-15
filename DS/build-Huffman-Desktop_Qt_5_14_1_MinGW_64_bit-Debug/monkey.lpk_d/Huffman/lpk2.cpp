#include "lpk2.h"
#include <iostream>
#include <io.h>
#include <vector>
#include <fstream>
using namespace std;

lpk2::lpk2()
{

}
void GetAllSubFiles(string path, vector<string>& files)
{
    long hFile = 0;
    struct _finddata_t fileinfo;
    string p;
    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
    {
        do
        {
            if ((fileinfo.attrib &  _A_SUBDIR))
            {
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                {
                    files.push_back(p.assign(path).append("\\").append(fileinfo.name));
                    GetAllSubFiles(p.assign(path).append("\\").append(fileinfo.name), files);
                }
            }
            else
            {
                files.push_back(p.assign(path).append("\\").append(fileinfo.name));
            }

        } while (_findnext(hFile, &fileinfo) == 0);

        _findclose(hFile);

    }
}

bool PackFileAndDirectory(const vector<string>& files, const vector<string>& directories, const string& outputfilename) //打包：写文件的过程
{
    FILE *wfp = NULL;
    wfp = fopen(outputfilename.c_str(), "wb");
    if (wfp == NULL)
    {

    }

    /************************第一个参数：文件vector**********************/

    int fileCount = files.size();
    fwrite(&fileCount, sizeof(fileCount), 1, wfp);

    for (size_t i = 0; i < fileCount; i++)
    {
        struct FileInfo file;

        string path = files[i]; //双斜杠路径名
        string filename = getFileNameFromPath(path);//根据路径获取文件名
        strcpy(file.FileName, filename.c_str());
        file.fileNameLen = strlen(filename.c_str());

        ifstream fin;
        fin.open(path, ios::binary);

        fin.seekg(0, ios::end);
        streampos sp = fin.tellg();
        file.fileSize = sp; //文件的size

        fwrite(&file, sizeof(file), 1, wfp);
        cout << "filename:" << file.FileName << ";  filenameLength:" << file.fileNameLen << ";  fileSize:" << file.fileSize << endl;

        FILE *files = fopen(path.c_str(), "rb");
        eachFile = new unsigned char[file.fileSize];
        fileBuffer.push_back(eachFile);
        fread(fileBuffer[i], file.fileSize, 1, files);

        fwrite(fileBuffer[i], file.fileSize, 1, wfp);
    }
}
