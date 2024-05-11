#include <iostream>
#include <vector>
#define ll long long

using namespace std;

ll mininator(vector<int> &given, int n)
{
    ll res = 0;
    int prev = given[0];
    for (int i = 1; i < n; i++)
    {
        if (given[i] < prev)
            res += prev - given[i];
        else
            prev = given[i];
    }
    return res;
}

int main()
{
    int n, a;
    cin >> n;

    vector<int> given(n);
    int i = 0;
    while (cin >> a)
    {
        given[i++] = a;
    }
    cout << mininator(given, n) << endl;
    return 0;
}