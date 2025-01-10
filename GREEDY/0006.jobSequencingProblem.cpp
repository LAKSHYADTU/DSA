// You are given three arrays: id, deadline, and profit, where each job is associated with an ID, a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.
// Your task is to find:
// The maximum number of jobs that can be completed within their deadlines.
// The total maximum profit earned by completing those jobs.

// Example 1 :
// Input: id = [1, 2, 3, 4], deadline = [4, 1, 1, 1], profit = [20, 1, 40, 30]
// Output: [2, 60]
// Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).

// Example 2 :
// Input: id = [1, 2, 3, 4, 5], deadline = [2, 1, 2, 1, 1], profit = [100, 19, 27, 25, 15]
// Output: [2, 127]
// Explanation: Job1 and Job3 can be done with maximum profit of 127 (100+27).

// Example 3 :
// Input: id = [1, 2, 3, 4], deadline = [3, 1, 2, 2], profit = [50, 10, 20, 30]
// Output: [3, 100]
// Explanation: Job1, Job3 and Job4 can be completed with a maximum profit of 100 (50 + 20 + 30).

// Constraints:
// 1 <=  id.size() == deadline.size() == profit.size() <= 105
// 1 <= id[i], deadline[i] <= id.size()
// 1 <= profit <= 500

// TC : O(nlogn) + O(n * maxDeadline)
class Job
{
    public : 
    int profit , deadline , id;
    Job(int id , int profit , int deadline)
    {
        this->id = id;
        this->profit = profit;
        this->deadline = deadline;
    }
};

static bool comp (Job a , Job b)
{
    return a.profit > b.profit;
}

vector<int> JobSequencing(vector<int> &id, vector<int> &deadline, vector<int> &profit) 
{
    int n = id.size();
    int maxDeadline = *max_element(deadline.begin() , deadline.end());
    
    vector<int>days(maxDeadline+1 , -1);
    int maxProfit = 0 , count = 0;
    vector<Job>jb;
    
    for(int i=0 ; i<n ; i++)
        jb.push_back(Job(id[i] , profit[i] , deadline[i]));
    
    sort(jb.begin() , jb.end() , comp);
    
    for(int i=0 ; i<n ; i++)
    {
        int time = jb[i].deadline;
        
        while(time>0 && days[time]!=-1)
            time--;
        
        if(time > 0)
        {
            days[time] = jb[i].id;
            maxProfit += jb[i].profit;
            count++;
        }
    }
    return {count , maxProfit};
}