// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Example 1:
// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps

// Example 2:
// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step
 
// Constraints:
// 1 <= n <= 45

// APP 1 (TOP DOWN) : ----------------------------------------------
int t[46];
int solve(int n)
{
    if (n == 0 || n==1)
        return 1;
    if (t[n] != -1)
        return t[n];
    return t[n] = solve(n - 1) + solve(n - 2);
}
int climbStairs(int n)
{
    memset(t, -1, sizeof(t));
    return solve(n);
}

// APP 2 (BOTTOM UP) : -----------------------------------------------
int climbStairs(int n)
{
    if (n == 0 || n == 1)
        return n;
    vector<int> t(n + 1, -1);
    t[0] = 0;  //not any use of t[0] in loop
    t[1] = 1;
    t[2] = 2;
    for (int i = 3; i <= n; i++)
        t[i] = t[i - 1] + t[i - 2];  //no. of ways to climb i stairs 
    return t[n];
}

// APP 3 : ----------------------------------------------------------
int climbStairs(int n)
{
    if (n == 0 || n == 1 || n == 2)
        return n;
    int a = 1; // t[1]
    int b = 2; // t[2]
    int c, temp;
    for (int i = 3; i <= n; i++)
    {
        c = b + a;
        temp = b;
        b = c;
        a = temp;
    }
    return c;
}