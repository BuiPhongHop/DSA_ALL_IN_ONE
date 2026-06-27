#include<iostream>
using namespace std;

/*Find the smallest index i that satisfies a[i] = i with O(logn)*/
// The elements of array are arranged in ascending order.
int find_index_similarity(int arr[], int l, int r){
    int result = -1;
    // base case (cannot find)
    if(l > r) return result;

    // recursive step
    int mid = l + (r - l) / 2;
    // if array[mid] < mid
    if(arr[mid] < mid){
        result = find_index_similarity(arr, mid + 1, r);
    }

    // if array[mid] > mid
    else if(arr[mid] > mid){
        result = find_index_similarity(arr, l, mid - 1);
    }

    // if array[mid] = mid
    else if(arr[mid] == mid){
        result = mid;
    }
    return result;
}


/*Count the number of (i ; j) that satisfies i < j and a[i] > a[j] with */
// merge_sort + count : make the array with elements are arranged in ascending order.
int the_way_count(int arr[] , int tmp[] , int l, int m, int r){
    int count_tmp = 0;
    int i = l , j = m + 1;
    int index_tmp = l;
    while(i <= m && j <= r){
        if(arr[i] < arr[j]){
            tmp[index_tmp++] = arr[i++];
        }
        else{
            tmp[index_tmp++] = arr[j++];
            count_tmp += m - i + 1;     // another elements of the left array are higher arr[j]
        }
    }
    while(j <= r){
        tmp[index_tmp++] = arr[j++];
    }
    while(i <= m){
        tmp[index_tmp++] = arr[i++];
    }
    for(int index = l; index <= r; index++){
        arr[index] = tmp[index];
    }
    return count_tmp;
}
int number_pair_index(int arr[], int tmp[], int l, int r){
    int count = 0;
    // base case
    if(l == r) return 0;

    // recursive step
    int mid = l + (r - l) / 2;
    count += number_pair_index(arr, tmp, l, mid);       // count satisfied (i ; j) in the left array
    count += number_pair_index(arr, tmp, mid + 1, r);   // count satisfiled (i ; j) in the right array
    count += the_way_count(arr, tmp, l, mid, r);        // count satisfiled (i ; j) in the both array
}
// Time complexity: O(nlogn)