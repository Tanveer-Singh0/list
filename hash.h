#ifndef HashMap_H
#define HashMap_H

#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T key;
    T val;
    Node<T> *next;

    Node()
    {
        key = 0;
        val = 0;
        next = NULL;
    }
};

template <typename T>
class Hash
{
    Node<T> *arr[21];
    int size = 21;

public:
    Hash()
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = new Node<T>();
        }
    }

    int hashValue(T key)
    {
        return key % size;
    }

    void add(T key, T val)
    {
        int index = hashValue(key);
        Node<T> *n = arr[index];
        while (n->next != NULL)
        {
            if (n->key == key)
            {
                n->val = val;
                return;
            }
            n = n->next;
        }
        Node<T> *temp = new Node<T>();
        temp->key = key;
        temp->val = val;
        n->next = temp;
    }
                                                  
    int get(T key)
    {
        int index = hashValue(key);
        Node<T> *n = arr[index];
        while (n != NULL)
        {
            if (n->key == key)
            {
                return n->val;
            }
            n = n->next;
        }
        return -1;
    }

    void dellete(int key, T value)
    {
        int index = hashValue(key);
        Node<T> *n = arr[index];
        Node<T> *prev = NULL;
        while (n != NULL)
        {
            if (n->key == key && n->val == value)
            {
                if (prev == NULL)
                {
                    arr[index] = n->next;
                }
                else
                {
                    prev->next = n->next;
                }
                delete n;
                return;
            }
            prev = n;
            n = n->next;
        }
    }
      
    void sizeIncrease()
    {
        this.size = this.size * 2;
        Node<T> **temp = arr;
        Node<T> **arr = new node<T> *[this.size]();

        for (int i = 0; i < this.size; i++)
        {
            Node<T> store = temp[i];
            while (store)
            {
                Node<T> *n = arr[i];
                n->key = store->key;
                n->val = store->val;
                n->next = NULL;
                store = store->next;
            }
        }
    }
};
#endif
                                 
// current++;
// int sze = increase_Size(size,current);
// if(sze != -1){
// int temp_size = size;
// size = sze;
// create_Array(sze,temp_size);

//     int increase_Size(int size,int current){
//         int max = (size/2)/2;

//         int actual = size-max;

//         if(current>actual){
//         cout<<"\n"<<"Space increasd "<<"\n";
//         return size*2;
//         }
//         else
//         return -1;
//     }
//     void create_Array(int sze,int size){

//         Node<T>** temp = new Node<T>*[sze];

//         for(int i=0;i<size;i++){
//             Node<T>* store = arr[i];
//             T key = store->key;
//             int index = hashValue(key,sze);

//             while(store !=NULL){

//                 Node<T>* next = store->next;
//                 temp[index]->next = next;
//                 store = next;
//             }
//         }
//         delete[] arr;
//         arr = temp;

//     }
// };