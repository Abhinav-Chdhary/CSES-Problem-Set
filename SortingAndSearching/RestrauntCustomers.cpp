#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/*
 Intuition: Create an array of arrival and
 departure times, get max

 Time-complexity: O(nlogn)
 Space-complexity: O(n)
*/

int maxinator(vector<vector<int>> &people, const int &n)
{
    vector<vector<int>> times;
    for (auto item : people)
    {
        times.push_back({item[0], 1});
        times.push_back({item[1], -1});
    }
    sort(times.begin(), times.end());
    int cnt = 0, ans = 0;
    for (auto time : times)
    {
        cnt += time[1];
        ans = max(cnt, ans);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> people(n, vector<int>(2));

    for (int i = 0; i < n; i++)
    {
        cin >> people[i][0] >> people[i][1];
    }

    cout << maxinator(people, n) << endl;
    return 0;
}