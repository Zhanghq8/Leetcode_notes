#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> result;
        multimap<double, pair<int, int>> mmap;
        for (int i=0; i<points.size(); i++) {
            double dis = pow(points[i][0]*points[i][0] + points[i][1]*points[i][1], 0.5);
            mmap.insert({dis, {points[i][0], points[i][1]}});
        }
        for (auto it=mmap.begin(); it!=mmap.end(); it++) {
            result.push_back({it->second.first, it->second.second});
            K--;
            if (K <= 0) {
                return result;
            }
        }
        return result;
    }
};