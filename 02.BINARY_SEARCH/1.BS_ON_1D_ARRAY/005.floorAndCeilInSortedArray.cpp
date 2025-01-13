// FLOOR : largest index such that arr[index] <= x
// CEIL : smallest index such that arr[index] >= x

// IS Q me bs floor nikalna h
// Given a sorted array arr[] (with unique elements) and an integer k, find the index (0-based) of the largest element in arr[] that is less than or equal to k. This element is called the "floor" of k. If such an element does not exist, return -1.

// Example 1 : 
// Input: arr[] = [1, 2, 8, 10, 11, 12, 19], k = 0
// Output: -1
// Explanation: No element less than 0 is found. So output is -1.

// Example 2 : 
// Input: arr[] = [1, 2, 8, 10, 11, 12, 19], k = 5
// Output: 1
// Explanation: Largest Number less than 5 is 2 , whose index is 1.

// Example 3 : 
// Input: arr[] = [1, 2, 8], k = 1
// Output: 0
// Explanation: Largest Number less than or equal to  1 is 1 , whose index is 0.

// Constraints:
// 1 ≤ arr.size() ≤ 106
// 1 ≤ arr[i] ≤ 106
// 0 ≤ k ≤ arr[n-1]

int findFloor(vector<int>& arr, int k) 
{
    int low = 0, high = n-1 , mid , ans = -1;
    while (low <= high) 
    {
        mid = low + (high - low) / 2;
        if (arr[mid] <= x) 
        {
            ans = arr[mid];
            low = mid + 1;
        } 
        else 
            high = mid - 1;
    }
    return ans;
}