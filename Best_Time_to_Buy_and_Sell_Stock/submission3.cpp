#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        if (length <= 1) {
            return 0;
        }
        vector<int> buy(length);
        vector<int> dp(length);
        buy[0] = prices[0];
        dp[0] = 0;
        for (int i=1; i<length; i++) {
            buy[i] = min(buy[i - 1], prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - buy[i - 1]);
        }
        return dp[length-1];
    }
};

int main()
{   
    vector<int> stock_price;
    stock_price.push_back(7);
    stock_price.push_back(1);
    stock_price.push_back(5);
    stock_price.push_back(3);
    stock_price.push_back(6);
    stock_price.push_back(4);

    Solution test;
    cout << "The price on each day is: ";
    int result = test.maxProfit(stock_price);
    for (int i=0; i<stock_price.size(); i++)
    {
        cout << stock_price[i] << " ";
    }
    cout << "." << endl;
    cout << "And the maximum profit you can get is: " << result << ".\n"; 
}

