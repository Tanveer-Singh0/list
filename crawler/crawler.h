// 


#include<iostream>
using namespace std;
#include<cstdlib>
#include<direct.h>
#include<ctime>
#include<string.h>

class File{
    char folderPath[100];
    char filename[100];
    char fullPath[1000];

    void intToChar(int num,char* str)
    {
        int i=0;
        if(num == 0){
        str[i++] = '0';
        str[i] = '\0';
        return;
        }
        char rev[20];
        while(num>0){
            rev[i++] = (num%10)+'0';
            num = num/10;
        }
        int j=0;
        while(j < i){
            str[j++] = rev[--i];
        }
        str[j] = '\0';
    }

    void folder( char* folderName){
        _getcwd(folderPath, sizeof(folderPath));
        strcat(folderPath, "\\");
        strcat(folderPath, folderName);
        _mkdir(folderPath);
    }

    void file()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        char day[20];
        char hour[20];
        char minute[20];
        char second[20];
        
        intToChar(ltm->tm_mday, day);
        intToChar(ltm->tm_hour,hour);
        intToChar(ltm->tm_min,minute);
        intToChar(ltm->tm_sec,second);
        strcpy(filename,"File_");
        strcat(filename, day);
        strcat(filename,"_");
        strcat(filename,hour);
        strcat(filename,minute);
        strcat(filename,second);
        strcat(filename,".html");
    }

    void fullpath()
    {
        strcpy(fullPath,folderPath);
        strcat(fullPath,"\\");
        strcat(fullPath,filename);
    }


    public:
    
    void download(char *url,char *folderName)
    {
       folder(folderName);
       file();
       fullpath();
       char command[1000] = "wget \"";
       strcat(command,url);
       strcat(command,"\" -O \"");
       strcat(command,fullPath);
       strcat(command,"\"");
       cout<<"Running Command : "<<command<<endl;
       system(command);
    }
    const char* getFullPath()
    {
        return fullPath;
    }

};