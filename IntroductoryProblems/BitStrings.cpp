#include <iostream>

using namespace std;

/*
 Intuition: The answer will be 2^n
 To calculate it we can use the recursive pow function
 or use a loop

 Time-complexity: O(log n)
 Space-complexity: O(1)
*/
const int MOD = 1e9 + 7;
int powinator(int N)
{
    int ans = 1;
    int base = 2;

    while (N > 0)
    {
        if (N & 1)
        {
            ans = (1LL * ans * base) % MOD;
        }
        base = (1LL * base * base) % MOD;
        N >>= 1;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    cout << powinator(n) << endl;

    return 0;
}