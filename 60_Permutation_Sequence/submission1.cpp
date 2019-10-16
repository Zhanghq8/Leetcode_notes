#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string element = "123456789";
        string result = "";
        vector<int> num_kinds(n, 1);
        for (int i=1; i<n; i++) {
            num_kinds[i] = num_kinds[i-1] * i; 
        }
        k--;
        for (int i=0; i<n; i++) {
            int num = k / num_kinds[n-i-1];
            result.push_back(element[num]);
            element.erase(num, 1);
            k = k % num_kinds[n-i-1];
        }
        return result;
    }
};
