#include <iostream>
 using namespace std;
 
 bool issafe(int x,int y,int n,int board[9][9]){
 	for(int i=0;i<9;i++){
 	if(board[x][i]==n)return false;
 	if(board[i][y]==n)return false;
 	
	 }
	  // Check 3x3 subgrid
    int startRow = x - x % 3;
    int startCol = y - y % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == n)
                return false;
        }
    }
    return true;
 }
 
 bool solve(int board[9][9]){
 	for(int i=0;i<9;i++){
 			for(int j=0;j<9;j++){
 				if(board[i][j]==0){
 			for(int k=1;k<=9;k++){
 					
 				if(issafe(i,j,k,board)){
 					board[i][j]=k;
 					if(solve(board))return true;
					 else board[i][j]=0;//backtrack;
				 }
			 }
			 return false;
			 }
			 }
		 
	 }
	 return true;
 }
 
 void printBoard(int board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
	}
 
 int main(){
 	 int board[9][9] = {
        {5,3,0, 0,7,0, 0,0,0},
        {6,0,0, 1,9,5, 0,0,0},
        {0,9,8, 0,0,0, 0,6,0},

        {8,0,0, 0,6,0, 0,0,3},
        {4,0,0, 8,0,3, 0,0,1},
        {7,0,0, 0,2,0, 0,0,6},

        {0,6,0, 0,0,0, 2,8,0},
        {0,0,0, 4,1,9, 0,0,5},
        {0,0,0, 0,8,0, 0,7,9}
    };

    if (solve(board))
        printBoard(board);
    else
        cout << "No solution exists." << endl;

    return 0;
}
