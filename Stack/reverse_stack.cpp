#include <iostream>
#include <stack>

using namespace std;

void place_at_bottom(stack <int>*s,int x){
		int temp;

	if(s->size()==0){
		s->push(x);
		return;
	}
	temp=s->top();
	s->pop();
	
	place_at_bottom(s,x);
	s->push(temp);
	
		
	
}


void reverse_stack(stack <int>*s){
		int temp;

	if(s->size()==0){
		
		return;
	}
	temp=s->top();
	s->pop();
	
	reverse_stack(s);
	place_at_bottom(s,temp);
	
	
		
	
}

int main(){
	stack <int >s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	reverse_stack(&s);
	for(int i=0;i<5;i++){
		cout<<s.top()<<" ";
		s.pop();	}
}
