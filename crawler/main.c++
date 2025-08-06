// #include "linked.h"
// int main()
// {
//     linked<int> list;

//     list.add_End(10);
//     list.add_End(20);
//     list.add_Beg(5);
//     list.add_Mid(15, 2);

//     list.print_Node();

//     list.delete_Node(3);
//     list.print_Node();

//     return 0;
// }

#include<iostream>
#include<fstream>
#include"crawler2.h"
#include"crawler.h"
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Usage: " << argv[0] << " <url> <foldername>" << endl;
        return 1;
    }
    File D;
    D.download(argv[1], argv[2]);
    const char *filepath = D.getFullPath();
    ifstream file(filepath);
    if (!file)
    {
        cout << "Error opening file: " << filepath << endl;
        return 1;
    }

    char html[10000];
    file.read(html, sizeof(html));
    int len = file.gcount();
    html[len] = '\0';
    file.close();

    
    cout << argv[1];
    cout << "\nStarting DFS Crawl\n"
         << endl;
    crawlFromHTML(argv[1], html);
    

    return 0;

}