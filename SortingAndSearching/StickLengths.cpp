#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

/*
 Intuition: make all sticks equal to
 median length

 Time-complexity: O(nlogn)
 Space-complexity: O(1)
*/
ll mininator(vector<int> &arr, const int &n)
{
    sort(arr.begin(), arr.end());

    ll cost = 0, med = arr[n / 2];
    for (int i : arr)
    {
        cost += abs(i - med);
    }
    return cost;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << mininator(arr, n) << endl;

    return 0;
}