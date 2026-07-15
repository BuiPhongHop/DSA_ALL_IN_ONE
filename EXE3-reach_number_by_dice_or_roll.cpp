#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

/*
Count the total number of ways to reach a number by roll the balanced dice 
*/
int reach_number_by_dice(int n){
	int way_dice[n + 1] = {0};
	// base case (there is one way to have 0 - do not roll the dice)
	way_dice[0] = 1;

	// recursive step 
	// if n >= 6 then way_dice[n] = way_dice[n - 1] + way_dice[n - 2] +...+ way_dice[n - 6]
	for(int number = 1; number <= n; number++){
		for(int dice_face = 1; dice_face <= 6; dice_face++){
			if(dice_face <= number){
				way_dice[number] += way_dice[number - dice_face];
			}
		}
	}
	return way_dice[n];
}
// Time complexity: O(n)


/*
Count the total number of ways to reach a number by sum of some positive numbers of an array,
The order is important.
*/
int reach_number_by_sum_1(int arr[], int size, int n){
	int dp_sum[n + 1] = {0};

	// base case
	dp_sum[0] = 1;
	
	// recursive step
	for(int number = 1; number <= n; number++){
		for(int index = 0; index <= size; index++){
			if(number >= arr[index]){
				dp_sum[number] += dp_sum[number - arr[index]];
			}
		}
	}

	return dp_sum[n];
}
// Time complexity: O(size * n)


/*
Count the total number of ways to reach a number by sum of some positive numbers of an array,
The order is "not" important.
*/
int reach_number_by_sum_2(int arr[], int size, int n){
	int dp_sum[n + 1] = {0};

	// base case
	dp_sum[0] = 1;
	
	// recursive step (change the order of two loops)
	for(int index = 0; index <= size; index++){
		for(int number = arr[index]; number <= n; number++){
			dp_sum[number] += dp_sum[number - arr[index]];
		}
	}

	return dp_sum[n];
}
// Time complexity: O(n * size)


/*
Given an array a with n elements,
print all possible numbers that can be formed such that each number 
is the sum of any subarray of a.
*/
int all_sum_subarray(int arr[], int n){
	// calculate the sum of all elements of array to create new array for recursion
	int max_sum = 0;
	for(int index = 0; index < n; index++){
		max_sum += arr[index];
	}

	// dp_count_sum[j]: check is the sum = j be calculated before
	bool dp_count_sum[max_sum + 1] = {false};
	dp_count_sum[0] = true;
	
	// recursive step
	for(int index = 0; index < n; index++){
		for(int sum = max_sum; sum >= arr[index]; sum--){
			if(dp_count_sum[sum - arr[index]]){
				dp_count_sum[sum] = true;
			}
		}
	}

	// count total number of possible sum
	int count = 0;
	for(int index = 0; index < max_sum + 1; index++){
		if(dp_count_sum[index]){
			count++;
		}
	}

	return count;
}
// Time complexity: O(n * sum)