#include<iostream>
using namespace std;
class stack{
	int arr[100];
	int top;
	int size;
	public:
	stack(){
		top=-1;
		size=0;
	}
	bool isEmpty(){
		return !size;
	}
	bool isFull(){
		return (size==99);
	}
	bool push(int x){
		if(size<=100){
			arr[size]=x;
			top++;
			size++;
			return true;
		}
		return false;
	}
	bool pop(){
		if (size==0) return false;
		top--;
		size--;
		return true;
	}
	int atTop(){
		if(size==0) return -99; 
		return arr[top];
	}
};
int main(){
	stack s;
	s.push(10);
	cout <<s.atTop();
	cout<<endl<<s.isEmpty();	
}
