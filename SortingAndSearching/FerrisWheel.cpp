#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 Intuition: sort and take the lightest and heaviest child
 at a time

 Time-complexity: O(nlogn)
 Space-complexity: O(1)
*/

int wheelinator(vector<int> &children, const int &n, const int &x)
{
    sort(children.begin(), children.end());

    int i = 0, j = n - 1, cnt = 0;
    for (; i <= j;)
    {
        if (children[i] + children[j] <= x)
        {
            ++i; --j; ++cnt;
        }
        else
        {
            --j; ++cnt;
        }
    }
    return cnt;
}

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> children(n);

    for (int i = 0; i < n; i++)
        cin >> children[i];

    cout << wheelinator(children, n, x) << endl;

    return 0;
}