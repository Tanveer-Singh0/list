#include "hash.h"
#include<iostream>
using namespace std;
int main(){
    Hash<int> h;
    h.add(1,5);
    h.add(2,10);
    h.add(3,20);
    h.add(4,30);
    h.add(5,40);
    h.add(23,25);
    cout<<endl<<h.get(5)<<endl;
    cout<<endl<<h.get(2)<<endl;
    cout<<endl<<h.get(23)<<endl;
    cout<<endl<<h.get(9);
    h.dellete(3,20);
    cout<<endl<<h.get(3)<<endl;
    
}

