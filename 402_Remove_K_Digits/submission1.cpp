#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";
        for (int i = 0; i < num.size(); i++) {
            while (k > 0 && (!result.empty()) && result.back() > num[i]) {
                result.pop_back();
                k--;
            }
            result.push_back(num[i]);
        }
        while (k > 0 && (!result.empty())) {
            result.pop_back();
            k--;
        }
        while (result.size() && result[0] == '0') {
            result.erase(result.begin());
        }
        return result.empty() ? "0" : result;
    }
};