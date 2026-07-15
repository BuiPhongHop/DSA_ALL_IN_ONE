#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

/*Leetcode647:
Count the number of palindromic substrings
*/
// A character 'x' is the center of substring (index i), if s[i - 1] == s[i + 1] then the number of palindromic substring add 1.
// Two characters 'xx' is the center of substring (index i and i + 1), if s[i - 1] == s[i + 2] then the number of palindromic substring add 1.
// helper function that count 
int expandAroundCenter(string s, int left, int right){
	int count = 0;
	while(left >= 0 && right < (int)s.size() && s[left] == s[right]){
		count++;
		left--;
		right++;
	}
	return count;
}
int countSubstrings(string s){
	int result = 0;
	for(int i = 0; i < (int)s.size(); i++){
		// center is a character
		result += expandAroundCenter(s, i, i);
		// center is two characters
		result += expandAroundCenter(s, i, i + 1);
	}
	return result;
}
// Time complexity: O(N^2)