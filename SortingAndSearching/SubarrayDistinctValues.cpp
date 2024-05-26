#include <iostream>
#include <vector>
#include <unordered_map>
#define ll long long

using namespace std;

/*
 Intuition: Use a sliding window approach
 Time-complexity: O(n)
 Space-complexity: O(n)
*/
ll distinctinator(vector<int> &arr, const int &n, int k)
{
    int l = 0, r = 0;
    ll res = 0;
    unordered_map<int, int> um;
    for (; r < n; r++)
    {
        // if did not exist before then one more distinct
        if (!um[arr[r]]++)
            k--;
        // we don't want more than k distinct values
        while (k < 0)
        {
            if (--um[arr[l]] == 0)
                k++;
            l++;
        }
        // count all the subarrays between r and l
        res += r - l + 1;
    }
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << distinctinator(arr, n, k) << endl;

    return 0;
}