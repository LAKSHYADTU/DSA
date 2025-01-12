// Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[]. 

// Example 1 :
// Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
// Output: 4
// Explanation: target = 2 occurs 4 times in the given array so the output is 4.

// Example 2 :
// Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 4
// Output: 0
// Explanation: target = 4 is not present in the given array so the output is 0.

// Example 3 :
// Input: arr[] = [8, 9, 10, 12, 12, 12], target = 12
// Output: 3
// Explanation: target = 12 occurs 3 times in the given array so the output is 3.

// Constraints:
// 1 ≤ arr.size() ≤ 106
// 1 ≤ arr[i] ≤ 106
// 1 ≤ target ≤ 106

int first(vector<int>& arr, int target) 
{
    int n = arr.size();
    int low = 0 , high = n-1;
    int ans = -1;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid] == target)
        {
            ans = mid;
            high = mid-1;
        }
        else if(arr[mid] < target)
            low = mid+1;
        else
            high = mid-1;
    }
    return ans;
}

int last(vector<int>& arr, int target) 
{
    int n = arr.size();
    int low = 0 , high = n-1;
    int ans = -1;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid] == target)
        {
            ans = mid;
            low = mid+1;
        }
        else if(arr[mid] < target)
            low = mid+1;
        else
            high = mid-1;
    }
    return ans;
}

int countFreq(vector<int>& arr, int target) 
{
    int n = arr.size();
    int f = first(arr , target);
    if(f == -1)
        return 0;
    return last(arr , target) - f + 1;
}