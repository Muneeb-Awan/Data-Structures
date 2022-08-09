#include <iostream>
#include <deque>
using namespace std;
int main(){
	deque<int> dq;
	dq.push_back(2);
	dq.push_back(3);
	dq.push_back(4);
	dq.push_back(5);
	dq.pop_front();
	cout << dq.front()<<endl;
	cout<<dq.size()<<endl;;
	cout<<dq.empty() <<endl;
	deque<int>::iterator it;
	for(it=dq.begin(); it!=dq.end(); it++){
		cout <<*it <<" ";
	}
}
