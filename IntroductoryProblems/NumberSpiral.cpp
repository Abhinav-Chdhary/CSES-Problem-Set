#include <iostream>
#include <vector>
#define ll long long

using namespace std;

/*
 Intuition: Every spiral ends at the edge with a perfect square
 this perfect square is n*n where n = max(x, y)
 We can use this perfect square and x,y  coordinates to calculate
 what will be at x, y
 when x<=y then it's the vertical part of the spiral
 when x>y then it's the horizontal part of the spiral

 Time-complexity: O(q) where q is the number of queries
 Space-complexity: O(1)
*/

ll findinator(int x, int y)
{
    ll n = max(x, y), sq = n * n;
    if (n % 2)
    {
        if (x <= y)
            return sq - (x - 1);
        else
            return sq - 2 * n + y + 1;
    }
    else
    {
        if (x <= y)
            return sq - 2 * n + x + 1;
        else
            return sq - (y - 1);
    }
}

int main()
{
    int n, a;
    cin >> n;

    vector<vector<int>> given(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << findinator(x, y) << endl;
    }

    return 0;
}