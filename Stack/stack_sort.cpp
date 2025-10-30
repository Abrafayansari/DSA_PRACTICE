#include <iostream>
#include <stack>

using namespace std;

void sorted_insert(stack <int>*s,int x){
		int temp;

	if(s->size()==0){
		s->push(x);
		return;
	}
	
	if(x<s->top()){
		temp=s->top();
		s->pop();
		sorted_insert(s,x);
		s->push(temp);
	}else{
	s->push(x);	
	}
	return;
	
		
	
}


void sort_stack(stack <int>*s){
		int temp;

	if(s->size()==0){
		
		return;
	}
	temp=s->top();
	s->pop();
	
	sort_stack(s);
	sorted_insert(s,temp);
	
	
		
	
}

int main(){
	stack <int >s;
	s.push(1);
	s.push(7);
	s.push(4);
	s.push(3);
	s.push(-3);
	sort_stack(&s);
	for(int i=0;i<5;i++){
		cout<<s.top()<<" ";
		s.pop();	}
}
