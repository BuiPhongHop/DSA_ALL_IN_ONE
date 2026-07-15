#include<iostream>
#include<algorithm>
using namespace std;

/*
Given a rectangle n x m, a cell has value 0 or 1.
Find the size of the largest square composed entirely of 1,
and the number of squares that have this maximum size.
*/
pair<int,int> number_largest_square(int** matrix, int n, int m){
    // dp_square[i][j]: the size of largest square composed entiredly of 1 and the bottom right corner is (i,j)
    int dp_square[n][m] = {0};  // (0 <= i < n , 0 <= j < m)

    int max_size = 0;   // the size of the largest square
    int count = 0;      // the number of squares that have this maximum size 
    
    // recursive step
    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            if(matrix[row][col] == 1){
                // all elements in the first row or first col
                if(row == 0 || col == 0){
                    dp_square[row][col] = matrix[row][col];
                }
                // recursive formula
                else{
                    dp_square[row][col] = min(dp_square[row - 1][col], dp_square[row][col - 1], dp_square[row - 1][col - 1]) + 1;
                }

                // update the max_size and count
                if(dp_square[row][col] > max_size){
                    max_size = dp_square[row][col];
                    count = 1;
                }
                else if(dp_square[row][col] == max_size){
                    count++;
                }
            }
        }
    }
    return {max_size , count};
}