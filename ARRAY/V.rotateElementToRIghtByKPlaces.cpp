// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

// Example 1:
// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]

// Example 2:
// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]

// Constraints:
// 1 <= nums.length <= 105
// -231 <= nums[i] <= 231 - 1
// 0 <= k <= 105

// APP 1 : ------------------------------------------------
void rotate(vector<int>& nums, int k) 
{
    int n = nums.size();
    k = k%n;

    vector<int>temp(k+1);
    for(int i=n-k ; i<n ; i++)
        temp[i-(n-k)] = nums[i];
    
    // nums = [1,2,3,4,5,6,7], k = 3
    // yha 1 3 postn shift krne pr 4 ki jgh a rha h 
    for(int i=n-k-1 ; i>=0 ; i--) 
        nums[i+k] = nums[i];
    
    for(int i=0 ; i<k ; i++)
        nums[i] = temp[i];
}

// APP 2 : ------------------------------------------------
void rotate(vector<int>& nums, int k) 
{
    int n = nums.size();
    k = k%n;                                    // nums = [1,2,3,4,5,6,7], k = 3
    reverse(nums.begin() , nums.begin()+(n-k));  // 4 3 2 1 5 6 7
    reverse(nums.begin()+(n-k) , nums.end());  // 4 3 2 1 7 6 5
    reverse(nums.begin() , nums.end());  // 5 6 7 1 2 3 4
}
