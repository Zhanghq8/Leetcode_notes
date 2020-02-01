#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12) {
            return {};
        }
        vector<string> result;
        helper(s, "", result, 4, 0);
        return result;      
    }
    
private:
    void helper(string s, string solution, vector<string>& result, int numDots, int index){
        if (numDots == 0 && solution.size() - s.size() == 3) {
            result.emplace_back(solution);
        } 
        if (numDots == 0) {
            return;
        }
        for (int i = 1; i <= 3; i++) {
            if (index + i >  s.size()) {
                return;
            }
            if ((i == 3 && stoi(s.substr(index, i)) > 255) || (i > 1 && s.substr(index, i)[0] == '0')) {
                return;
            }
            if (numDots == 1) {
                helper(s, solution + s.substr(index, i), result, numDots - 1, index + i);
            } else {
                helper(s, solution + s.substr(index, i) + '.', result, numDots - 1, index + i);
            }
        }
    }
};