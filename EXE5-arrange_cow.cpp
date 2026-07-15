#include<iostream>
using namespace std;

/*
Given two numbers n , k:
n is the number of cows, include male cows (bulls) and female cows (cows),
because the bulls are very aggresive, there are at least k cows between any two bulls.
Count the way to arrange the cows.
The order is nor important.
*/
int arrange_cow(int n, int k){
    // dp_arrange_cow[i]: the total number of ways to arrange cows in row of length i
    int dp_arrange_cow[n + 1] = {0};

    // base case
    dp_arrange_cow[0] = 1;

    // recursive step
    for(int length = 1; length <= n; length++){
        /*
        Cannot put two bulls in index "length" and "length - k - 1".
        if put a cow in index "length": the total number of way = dp_arrange_cow[length - 1],
        if put a bull in index "length": the total number of way = 1.
        */
        if(length - k - 1 <= 0){
            dp_arrange_cow[length] = dp_arrange_cow[length - 1] + 1;
        }

        /*
        Can put two bulls in index "length" and "length - k - 1".
        if put a cow in index "length": the total number of way = dp_arrange_cow[length - 1],
        if put a bull in index "length": the total number of way = dp_arrange_cow[length - k - 1]
        (each index from "length - k" to "length - 1" is put a cow)
        */
        else{
            dp_arrange_cow[length] = dp_arrange_cow[length - 1] + dp_arrange_cow[length - k - 1];
        }
    }
    return dp_arrange_cow[n];
}
// Time complexity: O(n)