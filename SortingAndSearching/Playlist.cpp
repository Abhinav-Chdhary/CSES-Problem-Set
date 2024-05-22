#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

/*
 Intuition: A sliding window approach
 using map

 Time-complexity: O(nlogn)
 Space-complexity: O(n)
*/

int playinator(vector<int> &songs, const int &n)
{
    map<long long, int> um;
    int l = 0, r = 0, ans = 0;
    for (; r < n; r++)
    {
        ++um[songs[r]];
        while (l < n and um[songs[r]] > 1)
        {
            --um[songs[l++]];
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> songs(n);

    for (int i = 0; i < n; i++)
    {
        cin >> songs[i];
    }

    cout << playinator(songs, n) << endl;

    return 0;
}