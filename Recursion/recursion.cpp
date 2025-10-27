#include <iostream>
#include <vector>
using namespace std;

//nontail
int facttail(int n){

	if(n==0)return 1;
	return n*facttail(n-1);
}

//tail

	void factnontail(int n){
		static int fact=1;
		if (n==0){
			cout<<fact;
			return;
		}
		fact=fact*n;
		factnontail(n-1);
	}
	
	//reverse array
	void reverse(int arr[],int i,int j){
		if(i==j){
			return;	
		}
		swap(arr[i],arr[j]);
		reverse(arr,i+1,j-1);
	}
	
	//pallindrome check
	
	void pallindrome(string arr,int i){
		int n=arr.length();
		
		if(i>=n/2){
			cout<<"\n pallindrome";
			return;
		}
		if(arr[i]==arr[n-i-1]){
			pallindrome(arr,i+1);
		}else{
			cout<<"\n not a pallindrome";
			return;
		}
		
	}
	
	//fibonacci
	
	int fibo(int n){
		if(n==0){
			return 0;
		}
		if(n==1){
			return 1;
		}
		return fibo(n-1)+fibo(n-2);
	}
	
	
	//printing subsets
	void subset(int arr[],vector <int>v,int i,int n){
		if(i>=n){
			 cout <<"{ ";
	  for (int j = 0; j < v.size(); j++) {
            cout << v[j] << " ";
        }cout<< " } ";
        cout << endl;
        return;
    }
		v.push_back(arr[i]);//inclusion
		subset(arr,v,i+1,n);
		v.pop_back();//exclusion and backtracking
		subset(arr,v,i+1,n);
	}
	
	//printing subset of sum k
	
		void subset(int arr[],vector <int>v,int i,int n,int sum,int k){
		if(i>=n){
			 if(k==sum){
			 	cout <<"{ ";
	  for (int j = 0; j < v.size(); j++) {
            cout << v[j] << " ";
        }cout<< " } ";
        cout << endl;
			 }
        return;
    }
		v.push_back(arr[i]);//inclusion
		sum=sum+arr[i];
		subset(arr,v,i+1,n,sum,k);
		
		v.pop_back();//exclusion and backtracking
		sum=sum-arr[i];
		subset(arr,v,i+1,n,sum,k);
	}
	
	
	//printing only one subset of sum k
	
		bool subset1(int arr[],vector <int>v,int i,int n,int sum,int k){
		if(i>=n){
			 if(k==sum){
			 	cout <<"{ ";
	  for (int j = 0; j < v.size(); j++) {
            cout << v[j] << " ";
        }cout<< " } ";
        cout << endl;
        return true;
			 }
			 return false;
        
    }
		v.push_back(arr[i]);//inclusion
		sum=sum+arr[i];
		if(subset1(arr,v,i+1,n,sum,k))return true;
		
		v.pop_back();//exclusion and backtracking
		sum=sum-arr[i];
		if(subset1(arr,v,i+1,n,sum,k))return true;
		
		return false;
	}
	
	
	//counting the number of subsets
	
	
		//printing only one subset of sum k
	
		int subset2(int arr[],vector <int>v,int i,int n,int sum,int k){
		if(i>=n){
			if(sum==k){
			 return 1; 	
			}
          return 0; 
    }
    
	v.push_back(arr[i]);//inclusion
		sum=sum+arr[i];
	int l=	subset2(arr,v,i+1,n,sum,k);
		
		v.pop_back();//exclusion and backtracking
		sum=sum-arr[i];
	int r=	subset2(arr,v,i+1,n,sum,k);
		
		return l+r;
	} 
	
	
	
int main(){
	int arr[]={3,1,2,7,3};                                                                                     
	string arr2="madam";  
	vector <int>v;                         
	reverse(arr,0,4);
	for(int i=0;i<5;i++){
		cout<<arr[i];
	}
	cout<<endl;
	pallindrome(arr2,0);
		cout<<endl;

	factnontail(4);
	cout <<endl;
	cout<<fibo(9);
		cout <<endl;
		int arr1[]={1,2,2};
//subset(arr1,v,0,sizeof(arr1)/sizeof(arr1[0]),0,3);
//subset1(arr1,v,0,sizeof(arr1)/sizeof(arr1[0]),0,3);
subset(arr1,v,0,sizeof(arr1)/sizeof(arr1[0]));

//cout<<endl<<subset2(arr1,v,0,sizeof(arr1)/sizeof(arr1[0]),0,3);


}
