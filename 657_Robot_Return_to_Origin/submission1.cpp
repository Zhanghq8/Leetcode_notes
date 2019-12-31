#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        if (moves.size()%2 == 1) {
            return false;
        }
        int horizontal = 0;
        int vertical = 0;
        for (int i=0; i<moves.size(); i++) {
            if (moves[i] == 'U') {
                horizontal++;
            } else if (moves[i] == 'D') {
                horizontal--;
            } else if (moves[i] == 'R') {
                vertical++;
            } else {
                vertical--;
            }
        }
        return horizontal == 0 && vertical == 0;
    }
};