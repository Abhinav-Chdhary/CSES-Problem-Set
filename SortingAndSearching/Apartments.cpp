#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 Intuition: put all the elements in an unordered set

 Time-complexity: O(nlogn)
 Space-complexity: O(1)
*/

int brokerinator(vector<int> &people, vector<int> &places, int n, int m, int k)
{
    sort(people.begin(), people.end());
    sort(places.begin(), places.end());

    int i = 0, j = 0, cnt = 0;
    for (; i < n && j < m;)
    {
        if (abs(people[i] - places[j]) <= k)
        {
            ++i;
            ++j;
            ++cnt;
        }
        else if (people[i] < places[j])
            ++i;
        else
            ++j;
    }
    return cnt;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> people(n), places(m);

    for (int i = 0; i < n; i++)
        cin >> people[i];
    for (int i = 0; i < m; i++)
        cin >> places[i];
    cout << brokerinator(people, places, n, m, k) << endl;

    return 0;
}