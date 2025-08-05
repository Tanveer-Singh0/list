// #include<iostream>
// using namespace std;

// char* strcat(char* dest,char* src){
//     int i=0,j=0;

//     while(dest[i]!='\0'){
//         i++;
//     }
//     while(src[j]!='\0'){
//         dest[i++]=src[j++];
//     }
//     dest[i] = '\0';

//     return dest;
// }

// int main(int argc,char* argv[])
// {
//     cout<<"how many arguments will passed : "<<argc;
//     char command[500];;
//     strcat(command, argv[1]);

//     int result = system(command);

//     if(result == 0)
//     cout<<"Downloaded suceesfuly";
//     else
//     cout<<"Download failed";

//     return 0;

// }
// #include<iostream>
// #include<cstdlib>
// #include<direct.h>
// #include<string.h>
// #include<fstream>
// using namespace std;
// int main(int argc, char* argv[]){
//     if(argc!=3){
//         cout<<"Usage: "<<argv[0]<<" <filename> <download_path>"<<endl;
//         return 1;
//     }
//     char path[1000];
//     _getcwd(path,sizeof(path));
//     strcat(path, "\\");
//     strcat(path, argv[]);
//     if(_mkdir(path)==0){
//         cout<<"Directory created"<<path<<endl;
//     }
//     char a[2000];
//     strcpy(a, "wget \"");
//     strcat(a, argv[1]);
//     strcat(a, "\" -P \"");
//     strcat(a, path);
//     strcat(a, "\"");
//     cout<<"Run Successfully";
//     system(a);
//     return 0;
// }
#include <iostream>
#include <cstdlib>
#include "string_function.h"
#include "linked.h"
#include <fstream>
#include <direct.h> // _mkdir, _getcwd
using namespace std;

int main(int argc, char *argv[])
{

    string_function obj;
    linked<char> list;

    if (argc != 3)
    {
        cout << "Usage: " << argv[0] << " <URL> <download_path>" << endl;
        return 1;
    }

    char path[1000];
    _getcwd(path, sizeof(path));
    char ppth[] = "\\";
    obj.my_strcat(path, ppth);
    obj.my_strcat(path, argv[2]);

    if (_mkdir(path) == 0)
    {
        cout << "Directory created: " << path << endl;
    }

    char a[2000]="";
    char wgeet[40] = "wget \"";
    char para[60] = "\" -P \"";
    char slash[] = "\"";                        
    obj.my_strcat(a, wgeet);
cout << "After strcpy: " << a << endl;

obj.my_strcat(a, argv[1]);
cout << "After adding URL: " << a << endl;

obj.my_strcat(a, para);
cout << "After adding -P: " << a << endl;

obj.my_strcat(a, path);
cout << "After adding path: " << a << endl;

obj.my_strcat(a, slash);
cout << "Final command: " << a << endl;

    cout << "Running: " << a << endl;
    
    system(a);

    cout<<endl<<endl<<endl<<"Yehi to hai file"<<argv[2];

    ifstream file(argv[2]);
    char arr[1000] = {0};
    char link[] = "<a href=";
    while (file >> arr)
    {
        int flag = 1;
        for (int i = 0; i < 8; i++)
        {
            if (arr[i] != link[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            cout<<endl<<'the word is : '<<arr;
        }
    }

    return 0;
}
