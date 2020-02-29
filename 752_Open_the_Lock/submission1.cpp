#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadendsCopy(deadends.begin(), deadends.end());
        if (deadendsCopy.count(target) || deadendsCopy.count("0000")) {
            return -1;
        }
        if (target == "0000") {
            return 0;
        }
        int result = -1;
        queue<string> Q;
        Q.push("0000");
        unordered_set<string> visited;
        visited.insert("0000");
        while (!Q.empty()) {
            result++;
            for (int i = Q.size(); i > 0; i--) {
                string str = Q.front();
                if (str == target) {
                    return result;
                }
                Q.pop();
                for (int j = 0; j < 4; j++) {
                    for (int k = -1; k <= 1; k += 2) {
                        string next = str;
                        next[j] = (next[j] - '0' + k + 10) % 10 + '0';
                        if (deadendsCopy.count(next) || visited.count(next)) {
                            continue;
                        } 
                        Q.push(next);
                        visited.insert(next);
                    }
                }
            }
        }
        return -1;
    }
};