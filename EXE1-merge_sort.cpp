#include<bits/stdc++.h>
using namespace std;

// function to merge the result of subproblem
void mergeSubproblem(int arr[] , int l1, int r1, int l2, int r2){
    // array to save the result
    vector<int> result;

    // implement
    int index2 = l2;
    for(int index1 = l1 ; index1 <= r1 ; index1++){
        while(index2 <= r2 /*put before the compare*/ && arr[index1] > arr[index2]){
            result.push_back(arr[index2]);
            index2++;
        }
        result.push_back(arr[index1]);
    }
    // save elements of array2 that have not yet been added. 
    for(int i = index2 ; i <= r2 ; i++){
        result.push_back(arr[i]);
    }
    // update the initial arr
    for(int i = 0 ; i < result.size(); i++){
        arr[l1 + i] = result[i];
    }
}

// recursive function of merge sort
void mergeSort(int arr[] , int l, int r){
    // base case (the size of array is 1)
    if(l == r) return;

    // recursive step
    // divide the current array in half until the size of array is 1
    int mid = l + (r - l) / 2; // avoid overflow 
    mergeSort(arr , l , mid);
    mergeSort(arr, mid + 1, r);
    // combine the array
    mergeSubproblem(arr, l , mid, mid + 1, r);
}
int main(){
    int arr[11] = {3, 2, 5, 6, 6, 4, 3, 1, 2, 6, 7};
    mergeSort(arr, 0, 10);
    for(int i = 0 ; i < 11; i++)
    {
        cout << arr[i] << " ";
    }
}

// Complexity of time: O(nlogn)