#include <iostream>
using namespace std;
class node{	
	public:
		int data;
		node * next;
		node(int val){
		data=val;
		next = NULL;
		}
	};
	node * head = NULL;
	node * top = NULL;
	void push(int val){	
		node * n = new node(val);
		if (head==NULL){
		head = n;
		top = n;
		return;
		}
		node* temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=n;
		top = n;
	}
	
	bool isEmpty(node* head){
		return (head==NULL);
	}
	bool pop(){
		node* temp = head;
		if(temp==top){
			top = NULL;
			delete temp;
		}
		while(temp->next!=top){
			temp=temp->next;
		}
		top = temp;
		delete temp->next;
		return true;
	}
	int Attop(){
		if(top==NULL) return -99;
		return top->data;
	}
	
	int main(){
		push(7);
		push(9);
		push(90);
		pop();
		pop();
		cout<<Attop();	
		
		
	}
