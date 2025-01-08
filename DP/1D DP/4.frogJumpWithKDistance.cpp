// There is an array arr of heights of stone and Geek is standing at the first stone and can jump to one of the following: Stone i+1, i+2, ... i+k stone, where k is the maximum number of steps that can be jumped and cost will be |hi-hj| is incurred, where j is the stone to land on. Find the minimum possible total cost incurred before the Geek reaches the last stone.

// Example 1 :
// Input: k = 3, arr[]= [10, 30, 40, 50, 20]
// Output: 30
// Explanation: Geek will follow the path 1->2->5, the total cost would be | 10-30| + |30-20| = 30, which is minimum

// Example 2 :
// Input: k = 1, arr[]= [10, 20, 10]
// Output: 20
// Explanation: Geek will follow the path 1->2->3, the total cost would be |10 - 20| + |20 - 10| = 20.

// Expected Time Complexity: O(n*k)
// Expected Auxilary Space: O(n)

// Constraint:
// 1<= arr.size() <=104
// 1 <= k <= 100
// 1 <= arr[i] <= 104

// APP 1 (TOP DOWN) : // TC = O(n*k) ----------------------------------------------
vector<int> t;
int solve(vector<int> &arr, int n, int k)
{
    if (n == 0)
        return 0;
    if (t[n] != -1)
        return t[n];
    int minm = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
            minm = min(minm, abs(arr[n] - arr[n - i]) + solve(arr, n - i, k));
    }
    return t[n] = minm;
}

int minimizeCost(vector<int> &arr, int &k)
{
    int n = arr.size();
    t.assign(n, -1);
    return solve(arr, n - 1, k);
}

// APP 2 (BOTTOM UP) : // TC = O(n*k) ----------------------------------------------------
int minimizeCost(vector<int> &arr, int &k)
{
    int n = arr.size();
    vector<int> t(n, -1);
    t[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int minm = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
                minm = min(minm, abs(arr[i] - arr[i - j]) + t[i - j]);
            t[i] = minm;
        }
    }
    return t[n - 1];
}