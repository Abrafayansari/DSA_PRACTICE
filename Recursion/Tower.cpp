#include <iostream>
#include <stack>
#include <string>
using namespace std;

long long count = 0;
long long limit = 0;

void force(stack<int> &A,stack<int> &C) {
    stack<int> t;
    while (!A.empty()) {
        t.push(A.top());
        A.pop();
    }
    while (!t.empty()) {
        C.push(t.top());
        t.pop();
    }
}


int countfrombottom(stack<int> C,int n) {
    stack<int> t;
    while (!C.empty()) {
        t.push(C.top());
        C.pop();
    }
    int expected= n,correct =0;
    while (!t.empty()) {
        int val = t.top();
        t.pop();
        if (val == expected) {
            correct++;
            expected--;
        } else break;
    }
    return correct;
}

string toBinary(long long num) {
    if (num ==0) return "0";
    string s ="";
    while (num >0) {
        s = char('0'+(num%2))+s;
        num /=2;
        
    }
    return s;
}

void solve(stack<int> &A,stack<int> &B,stack<int> &C,int n) {
    if (n==0||count>=limit) return;
    solve(A,C,B,n-1);
    if (count >= limit) return;
    if (!A.empty()) {
        C.push(A.top());
        A.pop();
        count++;
    }
    if (count >= limit) return;
    solve(B,A,C,n-1);
}


int calculate(stack<int> &C, int n, long long k){
	 int right=countfrombottom(C, n);
    int wrong =n-right;
    long long rem;
    if (wrong == 0)rem = 0;
    else {
        long long num =(1LL << wrong)-1;
        if (k>0 &&right==0) rem=num- 1;
        else rem =num;
        if (rem <0) rem=0;
    }
    return rem;
}

int main() {
    int n;
    string kstr;
    cin >> n >> kstr;

    long long k=0;
    for (int j=0;j<(int)kstr.size();j++) {
        k =k*2+(kstr[j]-'0');
    }

    stack<int> A, B, C;
    for (int i=n;i>=1;i--) {
    	A.push(i);
	}

    limit = k;
    
    count = 0;

    solve(A,B,C, n);
      force(A, C);

  long long rem = calculate(C,n,k);
    cout <<toBinary(rem)<< "\n";

    return 0;
}

