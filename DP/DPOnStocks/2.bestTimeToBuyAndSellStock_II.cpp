// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
// Find and return the maximum profit you can achieve.

// Example 1:
// Input: prices = [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Total profit is 4 + 3 = 7.

// Example 2:
// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Total profit is 4.

// Example 3:
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

// Constraints:
// 1 <= prices.length <= 3 * 104
// 0 <= prices[i] <= 104

// APP 1 (TOP DOWN) : ------------------------------------------------------------------------------
vector<vector<int>>t;
int solve(int i , vector<int>&prices , int buy , int n)
{
    if(i == n)
        return 0;

    int profit = 0;

    if(t[i][buy] != -1)
        return t[i][buy];

    if(buy)
        profit = max((-prices[i] + solve(i+1 , prices , 0 , n)) , 0 + solve(i+1 , prices , 1 , n));
    else
        profit = max((prices[i] + solve(i+1 , prices , 1 , n)) , 0 + solve(i+1 , prices , 0 , n));
    return t[i][buy] = profit;
}
int maxProfit(vector<int>& prices) 
{
    int n = prices.size();
    t.assign(n , vector<int>(2 , -1));
    return solve(0 , prices , 1 , n);
}

// APP 2 (BOTTOM UP) : ------------------------------------------------------------------------------
int maxProfit(vector<int>& prices) 
{
    int n = prices.size();
    vector<vector<int>>t(n+1 , vector<int>(2 , 0));
    t[n][0] = t[n][1] = 0;

    for(int i=n-1 ; i>=0 ; i--)
    {
        for(int buy=0 ; buy<=1 ; buy++)
        {
            int profit = 0;
            if(buy)
                profit = max((-prices[i] + t[i+1][0]) , 0 + t[i+1][1]);
            else
                profit = max((prices[i] + t[i+1][1]) , 0 + t[i+1][0]);
            t[i][buy] = profit;
        }
    }

    return t[0][1];
}

// APP 3 (SPACE OPTIMIZATION) : ------------------------------------------------------------------
int maxProfit(vector<int>& prices) 
{
    int n = prices.size();
    vector<int>prev(2 , 0) , curr(2 , 0);
    prev[0] = prev[1] = 0;

    for(int i=n-1 ; i>=0 ; i--)
    {
        for(int buy=0 ; buy<=1 ; buy++)
        {
            int profit = 0;
            if(buy)
                profit = max((-prices[i] + prev[0]) , 0 + prev[1]);
            else
                profit = max((prices[i] + prev[1]) , 0 + prev[0]);
            curr[buy] = profit;
        }
        prev = curr;
    }

    return prev[1];
}