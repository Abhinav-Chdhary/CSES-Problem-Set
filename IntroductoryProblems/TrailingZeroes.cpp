#include <iostream>

using namespace std;

/*
 Intuition: 0s come from 2*5
 In any factorail if we find the number of 2*5 pairs
 that would be the answer
 Number of 2s is always more than number of 5s in n
 So just count 5s

 Time-complexity: O(log n) (base 5)
 Space-complexity: O(1)
*/
const int MOD = 1e9 + 7;
int findinator(int n)
{
    int ans = 0;
    while (n > 0)
    {
        ans += n / 5;
        n /= 5;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    cout << findinator(n) << endl;

    return 0;
}