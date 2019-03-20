#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n==1) {
            return 1;
        }
        vector<int> distinctways(n+1);
        distinctways[0] = 1;
        distinctways[1] = 1;
        distinctways[2] = 2;
        for (int i=3; i<n+1; i++) {
            distinctways[i] = distinctways[i-1] + distinctways[i-2];
        } 
        return distinctways[n];
    }
};

int main()
{   
    int value;
    Solution test;
    while (true) {
        cout << "Enter the stairs you want to climb: ";
        cin >> value;
        int result = test.climbStairs(value);
        cout << "There are " << result << " ways to climb " << value << " stairs.\n";    
    }
}

