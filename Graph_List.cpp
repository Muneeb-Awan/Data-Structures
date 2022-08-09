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
	node * last;;
	int count;
	node * head;
	public:
		LinkedList(){
			last = NULL;
			count = 0;
			head = NULL;
		}
	int get_first_element(){
		return head->data;
	}
	int get_length(){
		return count;
	}
	int get_last_element(){
		return last->data;
	}
	void insert_at_head(int val){
		node * temp = new node(val);
		temp->next=head;
		head=temp;
		count++;
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
		last = n;
		count++;
		return;
		}
		node* temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=n;
		last = n;
		count++;
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
			count--;
			return true;
		}
		while(temp->next->data!=x){
			temp=temp->next;
		}
		if(temp->next==last) last=temp;
		del = temp->next;
		temp->next=temp->next->next;
		delete del;
		count--;
		return true;
	}
};
class Graph{
	private:
		int vertex;
		LinkedList* l;
		public:
			Graph(int val){
				vertex = val;
				l = new LinkedList[vertex];
			}
		void addEdge(int u,int v){	
			l[u].insert_at_tail(v);
			l[v].insert_at_tail(u);
		}
		void removeEdge(int u, int v){
			l[u].delete_node(v);
			l[v].delete_node(u);
		}
		bool isThereEdge(int u,int v){
			if(l[u].search(v)==true) return true;
			return false;
		}
		void Display(){
			for (int i=0; i<vertex ; i++){
				cout<<i<<" :: ";
				l[i].display();
				cout<<"\n";
			}
		}
};
	int main(){
		Graph g(5);
		g.addEdge(2,3);
		g.addEdge(1,3);
		g.addEdge(3,0);
		g.removeEdge(3,0);
		g.Display();
		
		
		
		
	}
