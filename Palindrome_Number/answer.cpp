#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        return x == revertedNumber || x == revertedNumber/10;

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
