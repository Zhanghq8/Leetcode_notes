#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> index(primes.size(), 0);
        vector<int> uglylist(1, 1);
        while (uglylist.size() < n) {
            int min_index = -1, min_num = INT_MAX;
            for (int i=0; i<index.size(); i++) {
                int num = uglylist[index[i]] * primes[i];
                if (min_num > num) {
                    min_num = num;
                    min_index = i;
                }
            }
            for (int i=min_index; i<index.size(); i++) {
                if (min_num == uglylist[index[i]] * primes[i]) {
                    index[i]++;
                }
            }
            uglylist.push_back(min_num);
        }
        return uglylist.back();
    }
};