#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 Intuition:
 Sum over the last number used to create x, it was some number between 1 and 6.
 For example, the number of ways to make sum x ending with a 3 is dp[x-3].
 Summing over the possibilities gives dp[x] = dp[x-1] + dp[x-2] + dp[x-3] + dp[x-4] + dp[x-5] + dp[x-6].
 We initialize by dp[0] = 1, saying there is one way with sum zero (the empty set).

 Time-complexity: O(n)
 Space-complexity: O(n)
*/
int dice[6] = {1, 2, 3, 4, 5, 6};
const int MOD = 1e9 + 7;

int wayinator(int n, vector<int> &dp)
{
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int ans = 0;
        for (int d = 0; d < 6; d++)
        {
            if (dice[d] <= i)
                ans = (ans % MOD + dp[i - dice[d]]) % MOD;
        }
        dp[i] = ans % MOD;
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    cout << wayinator(n, dp) << endl;

    return 0;
}