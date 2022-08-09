#include<iostream>
#include<set>
using namespace std;
int main(){
	int arr[]={1,2,1,1,4,5,6,7,8,2,3,5,8,9,4,2,6,6,0};
	int size = 20;
	set<int> s;
	
	for(int i=0;i < 20 ; i++ ){
		s.insert(arr[i]);
	}
	
	set<int>::iterator i;
	for(i = s.begin(); i != s.end() ; i++){
		cout << *i <<" ";
	}
	cout <<endl << s.size();
	cout <<endl << s.empty();
}
