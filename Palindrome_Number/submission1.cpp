#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        if (temp < 0) {
            return false;
        }
        long result = 0;
        while (temp != 0) {
            result = result * 10 + temp % 10;
            temp = temp/10;
        }
        if (result<INT_MIN || result>INT_MAX) {
            return false;
        }
        else {
            if (x == result) {
                return true;
            }
            else {
                return false;
            }
        } 

    }
};

int main()
{
	Solution temp;
    int num;
    while (1) {
        cout << "Enter the number you want to test: \n";
        cin >> num;
        bool result = temp.isPalindrome(num);
        if (result == true) {
            cout << num << " is a Palindrome number" << endl;
        }
        else {
            cout << num << " is not a Palindrome number" << endl;
        }
    }
}
