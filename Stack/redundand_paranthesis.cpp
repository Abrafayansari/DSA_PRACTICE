#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool redundand(string st,stack <char>*s,int i){
	int flag=0;
	bool stop=true;
	if(i==st.length()-1)return false;
	if(st[i]=='('||st[i]=='['||st[i]=='{'||st[i]=='+'||st[i]=='*'||st[i]=='/'||st[i]=='-'){
		s->push(st[i]);
	}else{
		if(st[i]==')'||st[i]=='}'||st[i]==']'){
			if(!s->empty()){
				do{
				if(s->top()=='('||s->top()=='['||s->top()=='{'){
						flag=1;
						stop=false;
					
					}
						s->pop();
				}	while(stop);
				
					
				
				if(flag==1)return true;
				
			}
			//else{
//				return false;
//			}
		}
	}
	if(!redundand(st,s,i+1))return true;
	return false;
}

int main(){
	string st;
	stack <char>s;
	cout<<"Enter a string :";
	cin>>st;
	if(redundand(st,&s,0)){
		cout<<"yes";
	}else{
		cout<<"no";
	}
}

