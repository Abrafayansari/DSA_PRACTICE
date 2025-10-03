#include <iostream>
#include <vector>
using namespace std;


bool combination(int i,int arr[],int target,vector <int>v,int n){
	if(target==0&&i<=n){
		cout <<"{ ";
	  for (int j = 0; j < v.size(); j++) {
            cout << v[j] << " ";
        }cout<< " } ";
        cout << endl;
		return true;
	}
	
	if(target<0||i>n){
		return false;
	}
		//include
		v.push_back(arr[i]);
	combination(i,arr,target-arr[i],v,n);
	
	
	//exclude
	v.pop_back();
	combination(i+1,arr,target,v,n);
	}


int main(){
int arr[4]={2,3,1,6};
vector <int>v;
combination(0,arr,7,v,4);	
}
