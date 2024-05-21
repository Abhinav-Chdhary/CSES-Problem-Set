#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
 Intuition: Use map to keep track of prev values

 Time-complexity: O(nlogn)
 Space-complexity: O(1)
*/
pair<int, int> suminator(vector<int> &arr, const int &n, const int &x)
{
    map<int, int> needed;
    for (int i = 0; i < n; i++)
    {
        if (needed.find(arr[i]) != needed.end())
            return {needed[arr[i]] + 1, i + 1};
        needed[x - arr[i]] = i;
    }
    return {-1, -1};
}

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    auto ans = suminator(arr, n, x);
    if (ans.first == -1 and ans.first == ans.second)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << ans.first << " " << ans.second << endl;

    return 0;
}