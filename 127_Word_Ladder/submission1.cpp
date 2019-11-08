#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int step = 0;
        unordered_set<string> uset(wordList.begin(), wordList.end());
        if (!uset.count(endWord)) {
            return step;
        }
        unordered_map<string, int> umap;
        umap[beginWord] = -1;
        queue<string> Q;
        Q.push(beginWord);
        while (!Q.empty()) {
            int length = Q.size();
            step++;
            while (length > 0) {
                string cur = Q.front();
                Q.pop();
                for (int i=0; i<beginWord.size(); i++) {
                    if (i == umap[cur]) {
                        continue;
                    }
                    char c = cur[i];
                    for (int j='a'; j<'z'; j++) {
                        cur[i] = j;
                        if (cur == endWord) {
                            return step+1;
                        }
                        if (!uset.count(cur)) {
                            continue;
                        }
                        umap[cur] = i;
                        uset.erase(cur);
                        Q.push(cur);
                    }
                    cur[i] = c;
                }
                length--;
            }
        }
        return 0;
    }
};