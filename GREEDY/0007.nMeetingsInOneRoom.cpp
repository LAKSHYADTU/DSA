// You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. 
// Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

// Example 1 : 
// Input: start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
// Output: 4
// Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5,7) and (8,9)

// Example 2 : 
// Input: start[] = [10, 12, 20], end[] = [20, 25, 30]
// Output: 1
// Explanation: Only one meetings can be held with given start and end timings.

// Example 3 : 
// Input: start[] = [1, 2], end[] = [100, 99]
// Output: 1

// Constraints:
// 1 ≤ n ≤ 105
// 0 ≤ start[i] < end[i] ≤ 106

class meeting
{
    public:
    int start , end , pos;
    meeting(int start , int end , int pos)
    {
        this->start = start;
        this->end = end;
        this->pos = pos;
    }
};

static bool comp(meeting a , meeting b)
{
    return a.end < b.end;
}

int maxMeetings(vector<int>& start, vector<int>& end) 
{
    int n = start.size();
    vector<meeting>v;
    
    for(int i=0 ; i<n ; i++)
        v.push_back(meeting(start[i] , end[i] , i+1));
    
    sort(v.begin() , v.end() , comp);
    
    int count=1 , freeTime = v[0].end;
    
    for(int i=1 ; i<n ; i++)
    {
        if(v[i].start > freeTime)
        {
            count++;
            freeTime = v[i].end;
        }
    }
    return count;
}