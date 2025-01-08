// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// Find the maximum profit you can achieve. You may complete at most two transactions.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Example 1:
// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
// Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

// Example 2:
// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.

// Example 3:
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.
 
// Constraints:
// 1 <= prices.length <= 105
// 0 <= prices[i] <= 105

// APP 1 (TOP DOWN) : -------------------------------------------------------------------------------------
vector<vector<vector<int>>>t;
int solve(int i , int buy , int cap , vector<int>&prices , int n)
{
    if(i==n || cap==0)
        return 0;
    if(t[i][buy][cap] != -1)
        return t[i][buy][cap];
    int profit = 0;
    if(buy)
        profit = max((-prices[i] + solve(i+1 , 0 , cap , prices , n)) , 0 + solve(i+1 , 1 , cap , prices , n));
    else
        profit = max((prices[i] + solve(i+1 , 1 , cap-1 , prices , n)) , 0 + solve(i+1 , 0 , cap , prices , n));
    return t[i][buy][cap] = profit;
}
int maxProfit(vector<int>& prices) 
{
    int n = prices.size();
    t.assign(n , vector<vector<int>>(2 , vector<int>(3 , -1)));    
    return solve(0 , 1 , 2 , prices , n);
}

// APP 2 (BOTTOM UP) : -------------------------------------------------------------------------------------
int maxProfit(vector<int>& prices) 
{
    int n = prices.size();
    vector<vector<int>>prev(2 , vector<int>(3 , 0)) , curr(2 , vector<int>(3 , 0));

    for(int i=n-1 ; i>=0; i--)
    {
        for(int buy=0 ; buy<=1 ; buy++)
        {
            for(int cap=1 ; cap<=2 ; cap++)
            {
                int profit = 0;
                if(buy)
                    profit = max((-prices[i] + prev[0][cap]) , (0 + prev[1][cap]));
                else
                    profit = max((prices[i] + prev[1][cap-1]) , (0 + prev[0][cap]));
                curr[buy][cap] = profit;
                prev = curr;
            }
        }
    }
    return prev[1][2];
}

// APP 3 (SPACE OPTIMIZATION) : -------------------------------------------------------------------------------------
vector<vector<int>>t;
int solve(int i , int transNo , int cap , vector<int>&prices , int n)
{
    if(i==n || transNo==2*cap)
        return 0;
    if(t[i][transNo] != -1)
        return t[i][transNo];
    int profit = 0;
    if(transNo%2 == 0)
        profit = max((-prices[i] + solve(i+1 , transNo+1 , cap , prices , n)) , 0 + solve(i+1 , transNo , cap , prices , n));
    else
        profit = max((prices[i] + solve(i+1 , transNo+1 , cap , prices , n)) , 0 + solve(i+1 , transNo , cap , prices , n));
    return t[i][transNo] = profit;
}
int maxProfit(vector<int>& prices) 
{
    int n = prices.size();
    t.assign(n , vector<int>(2*2 , -1));    
    return solve(0 , 0 , 2 , prices , n);
}