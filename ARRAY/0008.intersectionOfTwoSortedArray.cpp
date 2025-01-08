// You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively. Both these arrays are sorted in non-decreasing order. You have to find the intersection of these two arrays.
// Intersection of two arrays is an array that consists of all the common elements occurring in both arrays.

// Constraints :
// 1 <= T <= 100
// 1 <= N, M <= 10^4
// 0 <= A[i] <= 10^5
// 0 <= B[i] <= 10^5

// Time Limit: 1 sec
// Sample Input 1 :
// 2
// 6 4
// 1 2 2 2 3 4
// 2 2 3 3
// 3 2
// 1 2 3
// 3 4  
// Sample Output 1 :
// 2 2 3
// 3   
// Explanation for Sample Input 1 :
// For the first test case, the common elements are 2 2 3 in both the arrays, so we print it.

// For the second test case, only 3 is common so we print 3.
// Sample Input 2 :
// 2
// 3 3 
// 1 4 5
// 3 4 5
// 1 1
// 3
// 6
// Sample Output 2 :
// 4 5
// -1

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	vector<int>v;
	int i=0 , j=0;
	while(i<n && j<m)
	{

		if(arr1[i]==arr2[j])
		{
          v.push_back(arr1[i]);
		  i++;
		  j++;
		}
		else if(arr1[i]>arr2[j])
			j++;
		else
			i++;
	}
	return v;
}