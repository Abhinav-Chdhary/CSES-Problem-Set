#include <iostream>
#include <vector>
#include <unordered_map>
#define ll long long

using namespace std;

/*
 Intuition: Use a sliding window approach with hashmap
 to track all target sum subarrays ending at i
 Time-complexity: O(n)
 Space-complexity: O(n)
*/
void suminator(vector<int> &arr, const int &n, const int &t)
{
    unordered_map<ll, int> subs;
    ll sum = 0, cnt = 0;
    int r = 0;
    subs[0] = 1; // for subarray starting at 0
    for (; r < n; r++)
    {
        sum += arr[r];
        if (subs.find(sum - t) != subs.end())
            cnt += subs[sum - t];
        ++subs[sum];
    }

    cout << cnt << endl;
}

int main()
{
    int n, t;
    cin >> n >> t;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    suminator(arr, n, t);

    return 0;
}