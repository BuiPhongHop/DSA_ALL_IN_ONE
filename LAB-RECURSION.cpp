#include<iostream>
using namespace std;

/* Function to print 0 -> n */
void printArray(int n){
    // base case
    if(n == 0){
        cout << 0;
        return;
    }

    // recursive step
    printArray(n - 1);
    cout << ", " << n;
}
// Time complexity: O(n)


/*
Print follow pattern: n = 16
Output: 16 11 6 1 -4 1 11 16
*/
void printPatten(int n){
    // base case
    if(n <= 0){
        cout << n << " ";
        return;
    }

    // recursive step
    cout << n << " ";
    printPatten(n - 5);
    cout << n << " "; 
}


/* find the largest element by recursion */
int findMax(int *arr , int length){
    
}
 

int main(){
    printPatten(16);
}