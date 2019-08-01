#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i=0; i<flowerbed.size(); i++) {
            if (flowerbed[i] == 0) {
                bool canPlant = true;
                if (i > 0 && flowerbed[i-1] == 1) {
                    canPlant = false;
                }
                if (i < flowerbed.size()-1 && flowerbed[i+1] == 1) {
                    canPlant = false;
                }
                if (canPlant == true) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        if (n <= 0) {
            return true;
        }
        return false;
    }
};