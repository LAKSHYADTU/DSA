// LOWER BOUND : smallest index such that arr[index] >= x

// arr[] = [3 , 5 , 8 , 15 , 19 , 19 , 19]
//          0   1   2   3    4    5    6
//  x=8  ,  x=9  ,  x=16  ,  x=19
// lb=2    lb=3    lb=4     lb=4

// Given a sorted array arr[] and a number target, the task is to find the lower bound of the target in this given array. The lower bound of a number is defined as the smallest index in the sorted array where the element is greater than or equal to the given number.
// Note: If all the elements in the given array are smaller than the target, the lower bound will be the length of the array. 

// Example 1 :
// Input:  arr[] = [2, 3, 7, 10, 11, 11, 25], target = 9
// Output: 3
// Explanation: 3 is the smallest index in arr[] where element (arr[3] = 10) is greater than or equal to 9.

// Example 2 :
// Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 11
// Output: 4
// Explanation: 4 is the smallest index in arr[] where element (arr[4] = 11) is greater than or equal to 11.

// Example 3 :
// Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 100
// Output: 7
// Explanation: As no element in arr[] is greater than 100, return the length of array.

// Constraints:
// 1 ≤ arr.size() ≤ 106
// 1 ≤ arr[i] ≤ 106
// 1 ≤ target ≤ 106

// APP 1 : --------------------------------------------
int lowerBound(vector<int>& arr, int target) 
{
    int n = arr.size();
    int low = 0 , high = n-1;
    int ans = n;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid] >= target)
        {
            ans = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return ans;
}

// APP 2 : --------------------------------------------
int lowerBound(vector<int>& arr, int target) 
{
    return lower_bound(arr.begin() , arr.end() , target) - arr.begin();
}