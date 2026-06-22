#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

/* Question 1 */
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


/* Question 2 */
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
// Time complexity: O(n)


/* Question 3 */
int findMax(int *arr , int length){
    // base case
    if(length == 1) return arr[0];

    // recursive step
    return max(arr[length - 1] , findMax(arr , length - 1));
}
// Time complexity: O(n)


/* Question 5 */
// This algorithm call Euclidiean algorithm: GCD(a , b) = GCD(b , a % b)
int findGCD(int a , int b){
    // base case
    if(b == 0) return a;
    
    // recursive step
    return findGCD(b , a % b);
}
// Time complexity: O(log(min(a , b)))
// BONUS: find the LCM (Lowest Common Multiple)
// LCM(a , b) = (a * b) / GCD(a , b)
int findLCM(int a , int b){
    // Divide first to collect the smaller number before product
    return (a / findGCD(a , b)) * b;
}


/* Question 6 */
string expand_support(string s , int &index){
    string result = "";

    while(index < (int)s.size() && s[index] != ')'){
        // if the character is a number -> recursive step
        if(isdigit(s[index])){
            // number of repeating sequences
            int numberStep = s[index] - '0';
            index += 2; // point to the character after '('

            // save the string inside()
            string tmp = expand_support(s , index);

            while(numberStep-- > 0){
                result += tmp;
            }

            index++; // point to the character ')'
        }

        // if the character is lowercase word
        else if(s[index] >= 'a' && s[index] <= 'z'){
            result += s[index];
            index++;
        }
    }    
    return result;
}
string expand(string s){
    int index = 0;
    return expand_support(s , index);
}
// Time complexity: O(|s|), s is the length of the output string


/* Question 7 */
// Hailstone string
void printHailstone(int number){
    cout << number << " ";

    if(number == 1){
        return;
    }

    if(number % 2 == 0){
        number /= 2;
        printHailstone(number);
    }

    else{
        number = number * 3 + 1;
        printHailstone(number);
    }
}


/* Question 10 */
int solve(string s, int index, int open_needed, int added) {
    // base case
    if(index == s.length()) {
        return open_needed + added;
    }
    
    // recursive step
    if(s[index] == '('){
        return solve(s, index + 1, open_needed + 1, added);
    }
    else{
        if (open_needed > 0){
            return solve(s, index + 1, open_needed - 1, added);
        } 

        else{
            return solve(s, index + 1, open_needed, added + 1);
        }
    }
}
int mininumBracketAdd(string s) {
    return solve(s, 0, 0, 0);
}