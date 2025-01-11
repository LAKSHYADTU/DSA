// There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
// You are giving candies to these children subjected to the following requirements:
// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// Return the minimum number of candies you need to have to distribute the candies to the children.

// Example 1:
// Input: ratings = [1,0,2]
// Output: 5
// Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

// Example 2:
// Input: ratings = [1,2,2]
// Output: 4
// Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
// The third child gets 1 candy because it satisfies the above two conditions.
 
// Constraints:
// n == ratings.length
// 1 <= n <= 2 * 104
// 0 <= ratings[i] <= 2 * 104


// APP 3 : 
int candy(vector<int>& ratings) 
{
    int n = ratings.size();
    vector<int>left(n , 1);
    vector<int>right(n ,1);

    for(int i=1 ; i<n ; i++)  // comparing curr value with just left neightbour
    {
        if(ratings[i] > ratings[i-1])
            left[i] = left[i-1]+1;
    }

    for(int i=n-2 ; i>=0 ; i--)  // comparing curr value with just left neightbour
    {
        if(ratings[i] > ratings[i+1])
            right[i] = right[i+1]+1;
    }

    int sum = 0;
    for(int i=0 ; i<n ; i++)
        sum = sum + max(left[i] , right[i]);
    return sum;
}

// APP 2 : 
int candy(vector<int>& ratings) 
{
    int n = ratings.size();
    vector<int>count(n , 1);

    for(int i=1 ; i<n ; i++)  // comparing curr value with just left neightbour
    {
        if(ratings[i] > ratings[i-1])
            count[i] = count[i-1]+1;
    }

    int sum = count[n-1];
    for(int i=n-2 ; i>=0 ; i--)  // comparing curr value with just left neightbour
    {
        if(ratings[i] > ratings[i+1])
            count[i] = max(count[i] , count[i+1]+1);
        sum = sum + count[i];
    }
    return sum;
}

// APP 3 : TC = O(n) , SC = O(n)
// arr = [0 , 2 , 4 , 7 , 6 , 5 , 4 , 3 , 2 , 1 , 1 , 1 , 2 , 3 , 4 , 2 , 1 , 1 , 1]

//             .4
//         .3      .1
//     .2              .2
// .  1                    .3                              .4
//                             .4                      . 3     .1
//                                 .5              .2              .   .   .
//                                     .   .   .                   2   1   1
//                                     6   1   1
// sum = 1 + 2 + 3 + 4 + 1 + 2 + 3 + 4 + 5 + 6 + (7-4) + 1 + 1 + 2 + 3  + 4 + 1 + 2 + 1 + 1

int candy(vector<int>& ratings)
{
    int n = ratings.size();
    int sum = 1 , i = 1;
    while(i < n)
    {
        if(ratings[i] == ratings[i-1])  // slope = 0
        {
            sum = sum+1;
            i++;
            continue;
        }
        int peak = 1;
        while(i<n && ratings[i]>ratings[i-1])  // slope > 0
        {
            peak = peak+1;
            sum += peak;
            i++;
        }
        int down = 1;
        while(i<n && ratings[i]<ratings[i-1])  // slope < 0
        {
            sum += down;
            i++;
            down++;
        }
        if(down > peak)
            sum += down-peak;
    }
    return sum;
}