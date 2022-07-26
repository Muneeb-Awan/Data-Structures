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
class LinkedList{
	node * head = NULL;
	public:
	void insert_at_head(int val){
		node * temp = new node(val);
		temp->next=head;
		head=temp;
	}	
	bool search(int n){
		node* temp=head;
		while (temp!=NULL){
			if(temp->data==n) return true;
			temp=temp->next;
		}
		return false;	
	}
	void insert_at_tail(int val){	
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
	
	void display(){
	node* temp=head;
	while (temp!=NULL){
	cout << temp->data <<" --> ";
	temp=temp->next;
	}
	cout <<"NULL";	
	}
	bool isEmpty(){
		return (head==NULL);
	}
	bool delete_node(int x){
		node* del = NULL;
		node* temp = head;
		if(temp->data==x){
			del = temp;
			head = temp->next;
			delete del;
			return true;
		}
		while(temp->next->data!=x){
			temp=temp->next;
		}
		del = temp->next;
		temp->next=temp->next->next;
		delete del;
		return true;
	}
};
	int main(){
		LinkedList L1;
		L1.insert_at_tail(1);
		L1.insert_at_tail(23);
		L1.insert_at_tail(24);
		L1.insert_at_tail(25);
		L1.insert_at_tail(26);
		L1.display();
		cout<<endl;
		L1.delete_node(1);
		L1.delete_node(23);
		L1.delete_node(24);
		L1.delete_node(25);
		L1.delete_node(26);
		cout<<"IsEmpty List: "<<L1.isEmpty()<<endl;
		L1.display();
		
		
	}
