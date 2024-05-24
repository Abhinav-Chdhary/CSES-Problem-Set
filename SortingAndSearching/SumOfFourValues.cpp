#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

/*
 Intuition: Sort, then fix the first number
 and second number search for other two numbers

 Time-complexity: O(n^3)
 Space-complexity: O(1)
*/
vector<int> suminator(vector<vector<int>> &arr, const int &n, const int &target)
{
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            int lo = j + 1, hi = n - 1;
            while (lo < hi)
            {
                ll sum = arr[i][0] + arr[j][0] + arr[lo][0] + arr[hi][0];
                int prevlo = lo, prevhi = hi;
                if (sum == target)
                    return {arr[i][1], arr[j][1], arr[lo][1], arr[hi][1]};
                else if (sum < target)
                {
                    lo++;
                    while (lo < hi && arr[lo][0] == arr[prevlo][0])
                        lo++;
                }
                else
                {
                    hi--;
                    while (hi > lo && arr[hi][0] == arr[prevhi][0])
                        hi--;
                }
            }
        }
    }
    return {-1};
}

int main()
{
    int n, t;
    cin >> n >> t;

    vector<vector<int>> arr(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0];
        arr[i][1] = i + 1;
    }
    vector<int> ans = suminator(arr, n, t);
    if (ans[0] == -1)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;

    return 0;
}