#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    int n;
   // ifstream file("temp.txt");

    char data[100];

        // while(file.getline(data,100))
        //      cout<<endl<<data;
        // int count = 0;
        //   while(file>>data)
        //   count++;

        // cout<<"Total words : "<<count;

        ofstream file("temp.txt");
        file<<"Hello i am a coder";
        file<<"replaced";

        file.close();

        char arr[100];

        ifstream fille("temp.txt");
        while(fille.getline(arr,100))
        cout<<endl<<arr;


    fille.close();

    ofstream filee("temp.txt",ios::app);
    filee<<"\n"<<"Replace hogya ";
    filee.close();

    ifstream fle("temp.txt");
    while(fle.getline(data,100))
    cout<<endl<<data;
    fle.close();



}