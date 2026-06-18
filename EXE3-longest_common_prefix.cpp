#include<bits/stdc++.h>
using namespace std;

string longestPrefix(string x, string y){
    int smallerSize = min(x.size() , y.size());
    int index = 0;
    string result = "";
    while(index < smallerSize){
        if(x[index] != y[index]) break;
        else{
            result += x[index];
            index++;
        }
    }
    return result;
}

string longest_common_prefix(string arr[] , int l , int r){
    // base case
    if(l == r) return arr[l];

    // recursive step
    int mid = l + (r - l) / 2;
    string left_string = longest_common_prefix(arr, l, mid);
    string right_string = longest_common_prefix(arr, mid + 1, r);
    return longestPrefix(left_string , right_string);
}

int main(){
    string array[4] = {"apple" , "app" , "apply" , "approve"};
    cout << longest_common_prefix(array , 0 , 3);
}

/*
Complexity of time: O(m * n)
m: max length of a string
n: the initial size of array
*/
