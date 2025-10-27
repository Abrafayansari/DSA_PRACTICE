#include <iostream>
#include <vector>
using namespace std;
void subset(int i,int arr[3],vector <int> v,vector <int>* ans,int n,int sum){
	if(i>=n){
		ans->push_back(sum);
		return;
	}
	v.push_back(arr[i]);
	sum+=arr[i];
	subset(i+1,arr,v,ans,n,sum);
	v.pop_back();
	sum-=arr[i];
	subset(i+1,arr,v,ans,n,sum);
}

int main(){
	vector <int>v;
		vector <int>ans;
		int arr[3]={3,2,1};
		subset(0,arr,v,&ans,3,0);
			for(int i=0;i<ans.size();i++){
			cout<<ans[i]<<" ";
		}
		

}
