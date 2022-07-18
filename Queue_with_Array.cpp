#include <iostream>
using namespace std;
class Queue{
	int arr[100];
	int size;
	int back;
	int front;
	public:
		Queue(){
			size=0;
			back=-1;
			front=-1;
	}
	bool enqueue(int x){
		if(front==-1) front++;
		arr[size]=x;
		size++;
		back++;
	}
	bool dequeue(){
		if(size==99 || front > back ) return false;
		front++;
		return true;
	}
	int atFront(){
		return arr[front];
	}
	bool isEmpty(){
		if(front > back) return true;
		return !size;
	}
	bool isFull(){
		return (size==99);
	}	
};
int main(){
	Queue q;
	q.enqueue(10);
	q.enqueue(100);
	cout<<q.atFront();
	cout<<endl<<q.isEmpty();
}
