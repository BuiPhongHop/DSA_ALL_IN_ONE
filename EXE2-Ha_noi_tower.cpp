#include<iostream>
using namespace std;

int countStep = 0;

void solve_Hanoi_tower(int n, char startPoint, char endPoint, char spare){
    if(n == 1){
        cout << "Move disk from " << startPoint << " to " << endPoint << endl;
        countStep++;
        return;
    }

    // n >= 2
    solve_Hanoi_tower(n - 1, startPoint, spare, endPoint);

    // solve_Hanoi_tower(1, startPoint, endPoint, spare);
    cout << "Move disk from " << startPoint << " to " << endPoint << endl;
    countStep++;

    solve_Hanoi_tower(n - 1, spare, endPoint, startPoint);
}

int main(){
    int numberOfDisk;
    cout << "Please input the number of disk: ";
    cin >> numberOfDisk;
    solve_Hanoi_tower(numberOfDisk, '1', '2', '3');
    cout << "Number of step: " << countStep;
    return 0;
}