// Given two arrays, val[] and wt[], representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.
// Return the maximum value as a double, rounded to 6 decimal places.

// Example 1 :
// Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
// Output: 240.000000
// Explanation: Take the item with value 60 and weight 10, value 100 and weight 20 and split the third item with value 120 and weight 30, to fit it into weight 20. so it becomes (120/30)*20=80, so the total value becomes 60+100+80.0=240.0 Thus, total maximum value of item we can have is 240.00 from the given capacity of sack. 

// Example 2 :
// Input: val[] = [60, 100], wt[] = [10, 20], capacity = 50
// Output: 160.000000
// Explanation: Take both the items completely, without breaking. Total maximum value of item we can have is 160.00 from the given capacity of sack.

// Example 3 :
// Input: val[] = [10, 20, 30], wt[] = [5, 10, 15], capacity = 100
// Output: 60.000000
// Explanation: In this case, the knapsack capacity exceeds the combined weight of all items (5 + 10 + 15 = 30). Therefore, we can take all items completely, yielding a total maximum value of 10 + 20 + 30 = 60.000000.

// Constraints:
// 1 <= val.size=wt.size <= 105
// 1 <= capacity <= 109
// 1 <= val[i], wt[i] <= 104

class item
{
    public : 
    int value;
    int weight;
    item(int value , int weight)
    {
        this->value = value;
        this->weight = weight;
    }
};

static bool comp(item a , item b)
{
    return ((double)a.value/a.weight) >= ((double)b.value/b.weight);
}

double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) 
{
    int n = val.size();
    vector<item>v;
    
    for(int i=0 ; i<n ; i++)
        v.push_back(item(val[i] , wt[i]));
        
    sort(v.begin() , v.end() , comp);
    
    double totalVal = 0;
    
    for(int i=0 ; i<n ; i++)
    {
        if(v[i].weight <= capacity)
        {
            totalVal += v[i].value;
            capacity -= v[i].weight;
        }
        else
        {
            totalVal += ((double)v[i].value/v[i].weight)*capacity;
            break;
        }
    }
    return totalVal;
}