// Given an array arr, use selection sort to sort arr[] in increasing order.

// Example 1 :
// Input: arr[] = [4, 1, 3, 9, 7]
// Output: [1, 3, 4, 7, 9]
// Explanation: Maintain sorted (in bold) and unsorted subarrays. Select 1. Array becomes 1 4 3 9 7. Select 3. Array becomes 1 3 4 9 7. Select 4. Array becomes 1 3 4 9 7. Select 7. Array becomes 1 3 4 7 9. Select 9. Array becomes 1 3 4 7 9.

// Example 2 : 
// Input: arr[] = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
// Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

// Constraints:
// 1 ≤ arr.size() ≤ 103
// 1 ≤ arr[i] ≤ 106

// SELECTION SORT : ----------------------------------------------------
void selectionSort(int arr[], int n)  // TC = O(n^2)
{
    for(int i=0 ; i<n-1 ; i++)
    {   int min=i;
        for(int j=i+1 ; j<n ; j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        swap(arr[i] , arr[min]);
    }
}

// BUBBLE SORT : ----------------------------------------------------
void bubbleSort(int arr[], int n)  // TC = O(n^2)
{ 
    int swapped=1;
    for(int i=0 ; i<n && swapped ; i++)
    {   swapped=0;
        for(int j=0 ; j<n-1-i ; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped=1;
            }
        }
        if(swapped == 0)
            return ;
    }
}

// INSERTION SORT : ----------------------------------------------------
void insertionSort(int arr[], int n)  // TC = O(n^2)
{
    for(int i=1 ; i<n ; i++)
    {   
        int v=arr[i];
        int j=i;
        while(arr[j-1]>v && j>=1)
        {
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=v;
    }
}

// MERGE SORT : ----------------------------------------------------
void merge(int arr[], int l, int m, int r)  // TC = O(nlogn)
{
    int n1 = m-l+1;
    int n2 = r-m;  //r-(m+1)+1
    int L[n1] , R[n2];
    int k = l;
    for(int i=0 ; i<n1 ; i++)  //fill L[i]
    {
        L[i] = arr[k];
        k++;
    }
    for(int i=0 ; i<n2 ; i++)
    {
        R[i] = arr[k];
        k++;
    }
    
    int i=0 , j=0;
    k = l;
    while(i<n1 && j<n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    while(l >= r)
        return;
    int mid = l+(r-l)/2;
    mergeSort(arr , l , mid);
    mergeSort(arr , mid+1 , r);
    merge(arr , l , mid , r);
}

// QUICK SORT : ----------------------------------------------------
int partition(int arr[], int low, int high)  // TC = O(n^2)
{
    int pivot = arr[high];
    int pi = low;
    for(int i=low ; i<high ; i++)
    {
        if(arr[i] < pivot)
        {
            swap(arr[i] , arr[pi]);
            pi++;
        }
    }
    swap(arr[pi] , arr[high]);  //here pivotindex would be at corret position
    return pi;
}
void quickSort(int arr[], int low, int high)
{
    if(low >= high)
        return;
    int pi = partition(arr , low , high);
    quickSort(arr , low , pi-1);
    quickSort(arr , pi+1 , high);
}
