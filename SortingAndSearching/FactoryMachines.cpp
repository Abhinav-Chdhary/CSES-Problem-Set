#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

/*
 Intuition: Binary search over the range
 0 to 1^18 
 if we can make t products in y1 time
 then we make t products in y2 time where y2>y1

 Time-complexity: O(nlogn)
 Space-complexity: O(n)
*/

void allocatinator(vector<int> &machines, int &n, int &t)
{
    ll l = 0, r = 1e18;
    ll latestTime = 0;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += (mid / machines[i]);
            if (sum >= t)
                break;
        }
        if (sum >= t)
        {
            latestTime = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << latestTime << endl;
}

int main()
{
    int n, t;
    cin >> n >> t;

    vector<int> machines(n);
    for (int i = 0; i < n; i++)
    {
        cin >> machines[i];
    }
    allocatinator(machines, n, t);
    return 0;
}