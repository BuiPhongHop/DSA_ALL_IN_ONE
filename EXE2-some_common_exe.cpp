#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

/* find the smallest or largest value to do something*/

/*
Leetcode746: 
Array cost[n]: cost[i] is the cost to go to i_th stair
At a turn, a person can just climb one or two stairs
Return the smallest cost to go to the top (position after the last stair)
*/
int minCostClimbingStairs1(int cost[], int size){
    int dp_cost[size]; // array to save the minimum value of cost[i]
    dp_cost[0] = cost[0];
    dp_cost[1] = cost[1];

    for(int i = 2; i < size; i++){
        dp_cost[i] = min(dp_cost[i - 1] , dp_cost[i - 2]) + cost[i];
    }
    return min(dp_cost[size - 1] , dp_cost[size - 2]);
}


/* find the number of ways to do something*/

/*
Leetcode70: 
There are n stairs,
At a turn, a person can just climb one or two stairs,
How many ways are there to go up the stairs.
*/
int climbingStair(int n){
	// Create array to save the total way to go tho i_th stair
	int dp_way[n];
	
	// base case
	dp_way[0] = 1;
	dp_way[1] = 2;
	
	// recursive step
	for(int i = 2; i < n; i++){
		dp_way[i] = dp_way[i - 1] + dp_way[i - 2];
	}
	return dp_way[n - 1];
}


/*Combine some values to create the smallest or largest result*/

/*
Leetcode1130: 
Given an array contains n integer numbers,
Choose a full 2-ary tree satisfies:
	+ a leaf contains a number in the given array so that the order is
correct when traversing the tree in-order,
	+ an internal node contains the value equal to the product of
leaf has the largest value in the left side and rigt side,
Find the tree with the smallest total number of internal nodes. 
*/
int mctFromLeafValue(int arr[], int n){
	// problem becomes: choose two adjacent elements to product and remove the element that has smaller value
	// Do this activity until the given array has one element left
	int dp[n][n] = {0};			// dp[i][j] is the smallest total number of elements in (i , j)
	int max_val[n][n] = {0};	// max_val[i][j] is the element that has the largest value in (i , j)
	
	// update the value of matrix max_val (by recursion)
	for(int i = 0; i < n; i++){
		max_val[i][i] = arr[i];
		for(int j = i + 1; j < n; j++){
			max_val[i][j] = max(max_val[i][j - 1] , arr[j]);
		}
	}
	
	// Recursive step
	for(int len = 2; len < n; len++){
		for(int i = 0; i < n - len; i++){
			int j = i + len - 1;
			dp[i][j] = INT_MAX;
			for(int k = i; k < j; k++){
				// total number of a child tree (3 internal node) = total number of left tree + total number of right tree 
				// + (max_value of left tree * max_value of right tree)
				int cost = dp[i][k] + dp[k + 1][j] + (max_val[i][k] * max_val[k + 1][j]);
				dp[i][j] = min(dp[i][j] , cost);
			}
		}
	}	
	
	return dp[0][n - 1];
}
// Time complexity: O(n^3)

/*
Given an array has n numbers,
Find the largest sum of a subarray of given array.
*/
// Kadane algorithm
int largest_sum_subarray(int arr[], int n){
	// base case
	int max_so_far = arr[0];	// save the final max, always save the largest value
	int current_max = arr[0];	// save the max of current subarray

	// recursive step
	for(int index = 1; index < n; index++){
		// if current_max < 0 then change to the new subarray begin at arr[index]
		current_max = max(arr[index] , current_max + arr[index]);
		max_so_far = max(max_so_far , current_max);
	}
	return max_so_far;
}
// Time complexity: O(n)


/*
Given bag has a capacity of S,
Given n objects, each object have mass wi and value vi.
Find a way to select items to put into the bag such that the total value is maximized,
while the total weight of the selected items does not exceed the capacity of the bag.
Print the maximum total value.
*/
int maximum_Knapsack(int mass[], int val[], int n, int S){
	// dp_max_val[j]: the largest value when the weight is j
	int dp_max_val[S + 1] = {0};
	
	// recursive step
	// traversing through all elements
	for(int index = 0; index < n; index++){
		for(int weight = S; weight >= mass[index]; weight--){
			dp_max_val[weight] = max(dp_max_val[weight] , dp_max_val[weight - mass[index]] + val[index]);
		}
	}
	return dp_max_val[S];
}