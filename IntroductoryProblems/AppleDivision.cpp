#include <iostream>
#include <vector>
#include <math.h>
#define ll long long

using namespace std;

/*
 Intuition: Try all possible groups
 We can use DP too,
 but with the given contraints it fits in
 time -limit

 Time-complexity: O(2^n)
 Space-complexity: O(1)
*/
ll divinator(vector<int> &apples, int ind, ll g1, ll g2, const int &n)
{
    if (ind >= n)
        return abs((ll)g1 - (ll)g2);
    g1 += apples[ind];
    ll takeInG1 = divinator(apples, ind + 1, g1, g2, n);
    g1 -= apples[ind];
    g2 += apples[ind];
    ll takeInG2 = divinator(apples, ind + 1, g1, g2, n);
    return min((ll)takeInG1, (ll)takeInG2);
}

int main()
{
    int n;
    cin >> n;

    vector<int> apples(n);
    for (int i = 0; i < n; i++)
    {
        cin >> apples[i];
    }

    cout << divinator(apples, 0, 0ULL, 0ULL, n) << endl;

    return 0;
}