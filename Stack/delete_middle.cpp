#include <iostream>
#include <stack>

using namespace std;

void delete_middle(stack <int>*s,int count,int size){
		int temp;

	if(count ==size/2){
		s->pop();
		return;
	}
	temp=s->top();
	s->pop();
	
	delete_middle(s,count+1,size);
	s->push(temp);
	
		
	
}

int main(){
	stack <int >s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	delete_middle(&s,0,5);
	for(int i=0;i<5;i++){
		cout<<s.top()<<" ";
		s.pop();	}
}
