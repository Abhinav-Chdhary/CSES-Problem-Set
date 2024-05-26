#include <iostream>
#include <vector>
#define ll long long

using namespace std;

/*
 Intuition: Use a sliding window approach
 Time-complexity: O(n)
 Space-complexity: O(n)
*/
void suminator(vector<int> &arr, const int &n, const int &t)
{
    ll sum = 0, cnt = 0;
    int l = 0, r = 0;
    for (; r < n; r++)
    {
        sum += arr[r];
        while (l < r && sum > t)
        {
            sum -= arr[l];
            l++;
        }
        if (sum == t)
            ++cnt;
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