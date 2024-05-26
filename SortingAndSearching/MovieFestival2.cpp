#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/*
 Intuition: Sort by end times
 and then use multiset to assign

 Time-complexity: O(nlogn)
 Space-complexity: O(1)
*/
static bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

int maxinator(vector<pair<int, int>> &movies, int n, int k)
{

    sort(movies.begin(), movies.end(), cmp);
    int res = 0;
    multiset<int> members; // k members with their end time
    for (int i = 0; i < k; i++)
    {
        members.insert(0);
    }
    for (int i = 0; i < n; i++)
    {
        // find the first person who cannot watch the movie
        auto it = members.upper_bound(movies[i].first);
        // if everyone is too late
        if (it == members.begin())
            continue;
        // the person before this can watch
        members.erase(--it);
        // add his new end time
        members.insert(movies[i].second);
        ++res;
    }
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> vec;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        vec.push_back({a, b});
    }

    cout << maxinator(vec, n, k) << endl;
    return 0;
}