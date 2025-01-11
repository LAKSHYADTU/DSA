// Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
// The following rules define a valid string:
// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 
// Example 1:
// Input: s = "()"
// Output: true

// Example 2:
// Input: s = "(*)"
// Output: true

// Example 3:
// Input: s = "(*))"
// Output: true

// Constraints:
// 1 <= s.length <= 100
// s[i] is '(', ')' or '*'.

// APP 1 : ---------------------------------------------------------------------------
vector<vector<int>>dp;
bool solve(string &s , int idx , int count)
{
    if(count < 0)
        return false;
    if(idx == s.size())
        return count == 0;

    if(dp[idx][count] != -1)
        return dp[idx][count];

    if(s[idx] == '(')
        return dp[idx][count] = solve(s , idx+1 , count+1);
    if(s[idx] == ')')
        return dp[idx][count] = solve(s , idx+1 , count-1);
    return dp[idx][count] = solve(s , idx+1 , count+1) || solve(s , idx+1 , count-1) || solve(s , idx+1 , count);
}
bool checkValidString(string s) 
{
    int n = s.size();
    dp.assign(n , vector<int>(n , -1));
    return solve(s , 0 , 0); 
}

// APP 2 : ---------------------------------------------------------------------------
bool checkValidString(string s) 
{
    int n = s.length();
    int minm = 0 , maxm = 0;
    for(int i=0 ; i<n ; i++)
    {
        if(s[i] == '(')
        {
            minm++;
            maxm++;
        }
        else if(s[i] == ')')
        {
            minm--;
            maxm--;
        }
        else
        {
            minm--;
            maxm++;
        }
        if(minm < 0)
            minm = 0;
        if(maxm < 0)  // ex : ')' or '())'
            return false;
    }
    return minm == 0;
}