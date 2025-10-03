#include <iostream>
using namespace std;
#define N 5
void printSolution(int sol[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

bool issafe(int x,int y,int arr[N][N],int sol[N][N]){
	return(x>=0&&y>=0&&x<N&&y<N&&arr[x][y]==1&&sol[x][y]==0);
}


bool maze(int arr[N][N],int sol[N][N],int x,int y){
	if(x==N-1&&y==N-1&&arr[x][y]==1){
		sol[x][y]=1;
		return true;
	}
	if(issafe(x,y,arr,sol)){
		sol[x][y]=1;
		//drul
		if(maze(arr,sol,x+1,y))return true;
		if(maze(arr,sol,x,y-1))return true;
		if(maze(arr,sol,x,y+1))return true;
		
		if(maze(arr,sol,x-1,y))return true;

		sol[x][y]=0;
		return false;
	}
	
	
	return false;
}

int main(){
	int arr[N][N] = {
        {1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1}
    };
    int sol[N][N] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    
    if(!maze(arr,sol,0,0)){
    cout<<"No path found";	
	}else{
		printSolution(sol);
	}
}
