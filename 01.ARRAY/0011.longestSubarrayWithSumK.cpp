// Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. It is guaranteed that a valid subarray exists.

// Example 1 :
// Input: arr[] = [10, 5, 2, 7, 1, 9], k = 15
// Output: 4
// Explanation: The subarray [5, 2, 7, 1] has a sum of 15 and length 4.

// Example 2 :
// Input: arr[] = [-1, 2, -3], k = -2
// Output: 3
// Explanation: The subarray [-1, 2, -3] has a sum of -2 and length 3.

// Example 3 :
// Input: arr[] = [1, -1, 5, -2, 3], k = 3
// Output: 4
// Explanation: The subarray [1, -1, 5, -2] has a sum of 3 and a length 4.

// Example 4 :  ***** IMP EXAMPLE ******
// Input: arr[] = [2, 0, 0, 3], k = 3
// Output: 3
// Explanation: The subarray [1, -1, 5, -2] has a sum of 3 and a length 4.

// Constraints:
// 1 ≤ arr.size() ≤ 106
// -109 ≤ arr[i], k ≤ 109

// APP 1 : TC = O(n^3) TLE
int lenOfLongestSubarr(vector<int>& arr, int k)  
{
    int n = arr.size();
    int len = 0;
    
    for(int i=0 ; i<n ; i++)
    {
        for(int j=i ; j<n ; j++)
        {
            int sum = 0;
            for(int k=i ; k<=j ; k++)
                sum += arr[k];
            if(sum == k)
                len = max(len , j-i+1);
        }
    }
    return len;
}

// APP 2 : TC = O(n^2)
int lenOfLongestSubarr(vector<int>& arr, int k)  
{
    int n = arr.size();
    int len = 0;
    
    for(int i=0 ; i<n ; i++)
    {   
        int sum = 0;
        for(int j=i ; j<n ; j++)
        {
            sum += arr[j];
            if(sum == k)
                len = max(len , j-i+1);
        }
    }
    return len;
}

// APP 3 : TC = O(N)
int lenOfLongestSubarr(vector<int>& arr, int k)  
{
    int n = arr.size();
    unordered_map<int,int>preSumMap;  // <sum , indexUptoWhichPrefixSum>
    int sum = 0;
    int maxLen = 0;
    
    for(int i=0 ; i<n ; i++)
    {
        sum += arr[i];
        if(sum == k)
            maxLen = i+1;
            
        if(preSumMap.find(sum-k) != preSumMap.end())
        {
            int len = i-preSumMap[sum-k];
            maxLen = max(maxLen , len);
        }
        if(preSumMap.find(sum) == preSumMap.end())  // This is done for imp example
            preSumMap[sum] = i;
    }
    return maxLen;
}