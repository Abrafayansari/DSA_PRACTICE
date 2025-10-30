#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool valid(string st,stack <char>*s,int i){

if(st[i]=='['||st[i]=='('||st[i]=='{'){
		s->push(st[i]);
	}
	else{
		if(!s->empty()){
			if(st[i]==']'&&s->top()=='['||st[i]=='}'&&s->top()=='{'||st[i]==')'&&s->top()=='('){
				s->pop();
			}else{
				return false;
			}	
	}else{
		return false;
	}
		}
	if(!valid(st,s,i+1))return false;
	return true;
	
}

int main(){
	string st;
	stack <char>s;
	cout<<"Enter a string :";
	cin>>st;
	if(valid(st,&s,0)){
		cout<<"yes";
	}else{
		cout<<"no";
	}
}
