#include<bits/stdc++.h>
using namespace std;

/*Find the max(aj-ai) with 0 <= i <= j <= n*/

// Solve by recursion
int findMax(int arr[], int l , int r){
    int max_element = INT_MIN;
    for(int i = l ; i <= r ; i++){
        if(arr[i] > max_element){
            max_element = arr[i];
        }
    }
    return max_element;
}
int findMin(int arr[], int l , int r){
    int min_element = INT_MAX;
    for(int i = l ; i <= r ; i++){
        if(arr[i] < min_element){
            min_element = arr[i];
        }
    }
    return min_element;
}
int solveDiffProblem1(int arr[] , int l, int r){
    // implement
    // base case (if the size of the array is 1)
    if(l == r) return 0;

    // recursive step
    int mid = l + (r - l) / 2; // divide array in half array1, array2
    int left_max = solveDiffProblem1(arr, l, mid); // max(aj - ai) of array1
    int right_max = solveDiffProblem1(arr, mid + 1, r); // max(aj - ai) of array2
    // max(aj - ai) of both array1 and array2 but i <= j
    int minOfLeft = findMin(arr, l, mid);
    int maxOfRight = findMax(arr, mid + 1, r);
    int both_max = maxOfRight - minOfLeft;

    // return result
    return max({left_max, right_max, both_max});
}
// Complexity of time: O(nlogn)


// Solve by a better way (but not use D&C)
int solveDiffProblem2(int arr[] , int size){
    if(size <= 1) return 0;

    int result /*max(aj - ai)*/ = INT_MIN;
    int min_val = arr[0]; // varable to save the value of smallest element from begin to current index
    for(int i = 1 ; i < size ; i++){
        min_val = min(min_val , arr[i]);
        result = max(result , arr[i] - min_val);
    }

    return result;
}
// Complexity of time: O(n)


int main(){
    int array[2] = {7, 1};
    cout << solveDiffProblem2(array, 2);
}