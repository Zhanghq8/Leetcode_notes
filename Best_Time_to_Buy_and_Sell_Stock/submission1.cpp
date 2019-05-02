#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
        {
            return 0;
        }
        int max_profit = 0;
        int buy_price = prices[0];
        for (int i=0; i<prices.size(); i++)
        {
            if (buy_price > prices[i])
            {
                buy_price = prices[i];
            }
            else if (max_profit < prices[i]-buy_price)
            {
                max_profit = prices[i]-buy_price;
            }
        }
        return max_profit;
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

