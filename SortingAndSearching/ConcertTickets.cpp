#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/*
 Intuition: Make a min heap of tickets
 and assign as people arrive

 Time-complexity: O(nlogn)
 Space-complexity: O(1)
*/

void ticketinator(multiset<int> &prices, vector<int> &people, const int &n, const int &m)
{

    vector<int> ans(m, -1);
    for (int i = 0; i < m; i++)
    {
        auto it = prices.upper_bound(people[i]);
        if (it == prices.begin())
            ans[i] = -1;
        else
        {
            ans[i] = *(--it);
            prices.erase(it);
        }
    }
    for (int i : ans)
    {
        cout << i << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    multiset<int> prices;
    vector<int> people(m);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        prices.insert(x);
    }
    for (int i = 0; i < m; i++)
        cin >> people[i];
    ticketinator(prices, people, n, m);

    return 0;
}