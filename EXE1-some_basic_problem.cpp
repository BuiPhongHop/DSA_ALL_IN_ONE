#include<iostream>
using namespace std;

/*Factorial n!*/
int calculate_factorial(int n){
    // base case
    if(n == 0 || n == 1) return 1;

    // recursive step
    return n * calculate_factorial(n - 1);
}
// Time complexity: O(n)


/*Fibonacci*/
// 1 <= n <= 20
int calculate_fibonacci1(int n){
    // base case
    if(n == 1 || n == 2) return 1;

    // recursive step
    return calculate_fibonacci1(n - 1) + calculate_fibonacci1(n - 2);
}
// Time complexity: O(2^n)

// 1 <= n <= 10^4
int calculate_fibonacci2(int n){
    int f1 = 1, f2 = 1, f3;
    if(n == 1 || n == 2) return 1;
    
    for(int k = 3 ; k <= n ; k++){
        f3 = f2 + f1;
        f1 = f2;
        f2 = f3;
    }
    return f3;
}
// Time complexity: O(n^2)


/*Calculate combination: C(n,k) = nCk*/
// Theorem: C(n,k) = C(n - 1,k - 1) + C(n - 1,k) (0 < k < n)
int calculate_combination(int n , int k){
    // base case
    if(k == 0 || k == n) return 1;

    // recurive step
    return calculate_combination(n - 1 , k - 1) + calculate_combination(n - 1 , k);
}
// Time complexity: O(2^n)


/*Binary Search*/
// array contains elements that be arranged in non-decreasing order
bool binary_search(int arr[], int size, int x){
    // stop condition
    if(size <= 0) return false;

    // recursive step
    int mid = size / 2;
    if(x == arr[mid]) return true;
    if(x < arr[mid]) return binary_search(arr , mid , x);
    if(x > arr[mid]) return binary_search(&arr[mid + 1], size - mid - 1, x);
    // size - mid - 1 = size - (number of elements in the left) - (element int the index 'mid')

    return false;
}
// Time complexity: O(logn)

