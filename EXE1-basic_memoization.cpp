#include<iostream>
using namespace std;

/*Fibonacci*/
int fibonacci_memoization(int n, int fibo_save[]){
    // base case
    if(n == 1 || n == 2) return 1;
    
    // recursive step
    // if the value of n_th fibonacci number is not be saved
    if(fibo_save[n] == 0){
        fibo_save[n] = fibonacci_memoization(n - 1 , fibo_save) + fibonacci_memoization(n - 2 , fibo_save);
    }
    return fibo_save[n];
}
// Time complexity: O(n)


/* C(n,k) */
int combination_memoization(int n, int k, int **arr){
    // base case
    if(k == 0 || k == n) return 1;

    // recursive step
    if(arr[n][k] > 0) return arr[n][k];
    arr[n][k] = combination_memoization(n - 1 , k - 1, arr) + combination_memoization(n - 1 , k, arr);
    return arr[n][k];
}
// Time complexity: O(n * k): arr[i][j] (1 <= n <= i , 1 <= j <= k)