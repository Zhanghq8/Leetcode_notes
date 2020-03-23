#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        helper(rooms, visited, 0);
        return visited.size() == rooms.size();
    }
private:
    void helper(vector<vector<int>>& rooms, unordered_set<int>& visited, int roomId) {
        if (visited.count(roomId)) {
            return;
        }
        visited.insert(roomId);
        for (int i = 0; i < rooms[roomId].size(); i++) {    
            helper(rooms, visited, rooms[roomId][i]);
        }
    }
};