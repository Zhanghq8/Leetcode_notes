#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long result = 0;
        while (x != 0)
        {
            result = result * 10 + x % 10;
            x = x/10;
        }
        if (result<INT_MIN || result>INT_MAX)
        {
            return 0;
        }
        else
        {
            return (int)result;
        } 
    }
};

int main()
{
	Solution temp;
    int num = 123;
	int result = temp.reverse(num);
	cout << "The reverse of " << num << " is: " << result << endl;
}
