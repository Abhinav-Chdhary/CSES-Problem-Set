#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

/*
 Intuition: sort and sum the values
 starting from the smallest
 Check if sum+1 can be formed using next value
 if not return sum+1

 Time-complexity: O(nlogn)
 Space-complexity: O(1)
*/
ll mininator(vector<int> &arr, const int &n)
{
    sort(arr.begin(), arr.end());
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > sum + 1)
            break;
        sum += arr[i];
    }
    return sum + 1;
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