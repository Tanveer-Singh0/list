#include<iostream>
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
	
	void add_Beg(T value){
		node<T>* nayi = new node<T>(value);
		nayi->next = head;
		head = nayi;
	}
	void add_Mid(T value,int indx){
		node<T>* nayi = new node<T>(value);
		node<T>* temp = head;
		
		for(int i=0;i<indx-1;i++){
			temp = temp->next;
		}
		
		nayi->next = temp->next;
		temp->next = nayi;
		
	}
	void add_End(T value){
		node<T>* nayi = new node<T>(value);
		
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
	
	void print_Node(){
		node<T>* temp = head;
		
		while(temp != NULL){
			cout<<"data :- "<<temp->data;
			temp = temp->next;
		}
	}
};

int main(){
	linked<int> obj;
	obj.add_Beg(10);
	obj.add_End(20);
	obj.add_Beg(30);
	obj.add_Beg(40);
	obj.add_Mid(50,1);
	obj.delete_Node(3);

	obj.print_Node();
	
	
	return 0;
}
