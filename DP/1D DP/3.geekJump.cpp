// Geek wants to climb from the 0th stair to the (n-1)th stair. 
// At a time the Geek can climb either one or two steps. A height[N] array is also given.
// Whenever the geek jumps from stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. return the minimum energy that can be used by the Geek to jump from stair 0 to stair N-1.

// Example:
// Input: n = 4, height = {10 20 30 10}
// Output: 20
// Explanation: Geek jump from 1st to 2nd stair(|20-10| = 10 energy lost). 
// Then a jump from the 2nd to the last stair(|10-20| = 10 energy lost). So, total energy lost is 20 which is the minimum.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function MinimumEnergy() which takes the array height, and integer n, and returns the minimum energy that is lost.

// Expected Time Complexity: O(n)
// Expected Space Complexity: O(n)

// Constraint:
// 1<=n<=100000
// 1<=height[i]<=1000

// APP 1 (TOP DOWN) : ---------------------------------------------------
vector<int> t;
int solve(vector<int> &height, int n)
{
    if (n == 0)
        return 0;
    if (t[n] != -1)
        return t[n];
    int oneStep = abs(height[n] - height[n - 1]) + solve(height, n - 1);
    int twoStep = INT_MAX;
    if (n > 1)
        twoStep = abs(height[n] - height[n - 2]) + solve(height, n - 2);
    return t[n] = min(oneStep, twoStep);
}

int minimumEnergy(vector<int> &height, int n)
{
    t.assign(n, -1);
    return solve(height, n - 1);
}

// APP 2 (BOTTOM UP) : ----------------------------------------------------
int minimumEnergy(vector<int> &height, int n)
{
    vector<int> t(n, 0);
    t[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int oneStep = abs(height[i] - height[i - 1]) + t[i - 1];
        int twoStep = INT_MAX;
        if (i > 1)
            twoStep = abs(height[i] - height[i - 2]) + t[i - 2];
        t[i] = min(oneStep, twoStep);
    }
    return t[n - 1];
}

// APP 3 (SPACE OPTIMIZATION) : -------------------------------------------
int minimumEnergy(vector<int> &height, int n)
{
    int prev2 = 0, prev = 0;
    for (int i = 1; i < n; i++)
    {
        int oneStep = abs(height[i] - height[i - 1]) + prev;
        int twoStep = INT_MAX;
        if (i > 1)
            twoStep = abs(height[i] - height[i - 2]) + prev2;
        int curr = min(oneStep, twoStep);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
