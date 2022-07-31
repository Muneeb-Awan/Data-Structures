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
	node * head;
	
	
	void enqueue(int val){	
		node * n = new node(val);
		if (head==NULL){
		head = n;
		return;
		}
		node* temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=n;
	}
	
	bool isEmpty(node* head){
		return (head==NULL);
	}
	bool dequeue(){
			node* temp = head;
			head = temp->next;
			delete temp;
			return true;
	}
	int front(){
		if(head==NULL) return -99;
		return head->data;
	}
	
	int main(){
		enqueue(7);
		enqueue(8);
		enqueue(9);
		enqueue(10);
		dequeue();
		dequeue();
		dequeue();
		dequeue();
		
		cout<<front();
	
			
	}
