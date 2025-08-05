#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template<typename T>
class node{
	public : 
	T data;
	node<T>* next;
	
	node(T value){
		data = value;
		next = NULL;
	}
	
};

//node call hone par nayi node milje gi

template<typename T>
class linked{
	node<T>* head;
	public:
	linked(){
		head = NULL;
	}

	node<T>* createNode(T value){
		node<T>* temp = new node<T>(value);
		return temp;
	}
	
	void add_Beg(T value){
	    node<T>* nayi = createNode(value);
		nayi->next = head;
		head = nayi;
	}
	void add_Mid(T value,int indx){
		node<T>* nayi = createNode(value);
		node<T>* temp = head;
		
		for(int i=0;i<indx-1;i++){
			temp = temp->next;
		}
		
		nayi->next = temp->next;
		temp->next = nayi;
		
	}

	
	node<T>* get_Node(int indx){
		node<T>* temp = head;
		for(int i=0;i<indx-1;i++){
			temp = temp->next;
			}
			return temp;
	}


	void add_End(T value){
		node<T>* nayi = createNode(value);
		
		if(head)
		{
			node<T>* temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = nayi;
		}
		else
		head = nayi;
	}
	
	void delete_Node(int index){
		node<T>* temp = head;
		for(int i=0;i<index-1;i++){
			temp = temp->next;
		}
		temp->next = temp->next->next;
		cout<<'\n'<<'\n'<<"Node Deleted"<<'\n';
	}

	void delete_Big(){
		node<T>* temp = head;
		temp->next = temp->next->next;
	}
	
	void delete_End(){
		node<T>* temp = head;
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		temp = NULL;
	}

	
	void print_Node(){
		node<T>* temp = head;
		
		while(temp != NULL){
			cout<<"  data :- "<<temp->data;
			temp = temp->next;
		}
	}

};


#endif