// You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:
// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

// Example 1:
// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

// Example 2:
// Input: nums = [2,3,0,1,4]
// Output: 2
 
// Constraints:
// 1 <= nums.length <= 104
// 0 <= nums[i] <= 1000
// It's guaranteed that you can reach nums[n - 1].


// APP 1 : TLE ----------------------------------------------
int n;
vector<vector<int>>dp;
int solve(vector<int>& nums , int idx , int jumps)
{
    if(idx >= n-1)
        return jumps;
    if(dp[idx][jumps] != -1)
        return dp[idx][jumps];
    int mini = INT_MAX;
    for(int i=1 ; i<=nums[idx] ; i++)
        mini = min(mini , solve(nums , idx+i , jumps+1));
    return dp[idx][jumps] = mini;
}

int jump(vector<int>& nums) 
{
    n = nums.size();
    dp.assign(n , vector<int>(n, -1));
    return solve(nums , 0 , 0);   
}

// APP 2 : TC = O(n) ------------------------------------------
int jump(vector<int>& nums) 
{
    int n = nums.size();
    int jumps=0 , l=0 , r=0;
    while(r < n-1)
    {
        int farthest = 0;
        for(int i=l ; i<=r ; i++)
            farthest = max(farthest , i+nums[i]);
        l = r+1;
        r = farthest;
        jumps = jumps + 1;
    }
    return jumps;
}