#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
 Intuition: Sort by end times

 Time-complexity: O(nlogn)
 Space-complexity: O(1)
*/
static bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

int maxinator(vector<pair<int, int>> &movies)
{

    sort(movies.begin(), movies.end(), cmp);
    long long curTime = 0, res = 0;
    for (auto movie : movies)
    {
        if (curTime > movie.second or movie.first < curTime)
            continue;
        curTime = movie.second;
        ++res;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> vec;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        vec.push_back({a, b});
    }

    cout << maxinator(vec) << endl;
    return 0;
}