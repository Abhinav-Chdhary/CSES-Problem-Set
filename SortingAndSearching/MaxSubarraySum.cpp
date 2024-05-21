#include <iostream>
#include <vector>
#include <climits>
#define ll long long

using namespace std;

/*
 Intuition: Kadane's algo

 Time-complexity: O(n)
 Space-complexity: O(1)
*/

ll maxinator(vector<int> &arr, const int &n)
{
    ll ans = LLONG_MIN, cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur += arr[i];
        ans = max(cur, ans);
        if (cur < 0)
            cur = 0;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << maxinator(arr, n) << endl;

    return 0;
}