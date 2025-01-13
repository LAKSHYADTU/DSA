// Given an increasing sorted rotated array arr of distinct integers. The array is right-rotated k times. Find the value of k.
// Let's suppose we have an array arr = [2, 4, 6, 9], so if we rotate it by 2 times so that it will look like this:
// After 1st Rotation : [9, 2, 4, 6]
// After 2nd Rotation : [6, 9, 2, 4]

// Example 1 : 
// Input: arr = [5, 1, 2, 3, 4]
// Output: 1
// Explanation: The given array is 5 1 2 3 4. The original sorted array is 1 2 3 4 5. We can see that the array was rotated 1 times to the right.

// Example 2 : 
// Input: arr = [1, 2, 3, 4, 5]
// Output: 0
// Explanation: The given array is not rotated.

// Expected Time Complexity: O(log(n))
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= n <=105
// 1 <= arri <= 107

int findKRotation(vector<int> &arr) 
{
    int n = arr.size();
    int low = 0 , high = n-1;
    int ans = INT_MAX , index = -1;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(arr[low] <= arr[high])
        {
            if(arr[low] < ans)
            {
                ans = arr[low];
                index = low;
            }
            break;
        }
        if(arr[low] <= arr[mid])  // left sorted
        {
            if(arr[low] < ans)
            {
                ans = arr[low];
                index = low;
            }
            low = mid+1;
        }
        else  // right sorted
        {
            if(arr[mid] < ans)
            {
                ans = arr[mid];
                index = mid;
            }
            high = mid-1;
        }
    }
    return index;
}