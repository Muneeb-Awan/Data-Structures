#include <iostream>
using namespace std;
class node{
	public:
	int data;
	node * next;
	node * prev;
	node(int val){
		data = val;
		next = NULL;
		prev = NULL;
	}	
};

int previous_of(node* head,int x){
	if (head->data==x) return -1;
	node* temp=head;
	while(temp->data!=x) temp=temp->next;
	return temp->prev->data;
}

bool insert_at_tail(node* &head,int val){
	node * n = new node(val);
	if (head == NULL ){
		head = n;
		return true;
	}
	node * temp = head;
	while (temp->next != NULL){
		temp=temp->next;
	}
	temp->next = n;
	n->prev = temp;
	return true;
}
void display(node* head){
	node* temp=head;
	cout << " NULL <==> ";
	while (temp!=NULL){
	cout << temp->data << " <==> "; 
	temp=temp->next;
	}
	cout <<"NULL";	
	}
int main(){
	node * head= NULL;
	insert_at_tail(head,2);
	insert_at_tail(head,7);
	insert_at_tail(head,6);
	insert_at_tail(head,9);
	
	cout <<head->next->next->next->prev->prev->next->prev->prev->next->next->data;
		
	}
