#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for (int i=0; i<asteroids.size(); i++) {
            if (asteroids[i] > 0) {
                result.push_back(asteroids[i]);
            }
            else if (result.empty() || result.back() < 0) {
                result.push_back(asteroids[i]);
            }
            else if (result.back() <= -asteroids[i]) {
                if (result.back() < -asteroids[i]) {
                    i--;
                }
                result.pop_back();
            }
        }
        return result;
    }
};