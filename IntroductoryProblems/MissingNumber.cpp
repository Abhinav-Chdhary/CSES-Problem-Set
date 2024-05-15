#include <iostream>
#include <vector>
#define ll long long

using namespace std;

ll findinator(vector<ll> given, ll n)
{
    ll gsum = 0, nsum = (n * (n + 1)) / 2;
    for (auto a : given)
    {
        gsum += a;
    }
    return nsum - gsum;
}

int main()
{
    ll n, a;
    cin >> n;

    vector<ll> given(n - 1);
    int i = 0;
    while (cin >> a)
    {
        given[i++] = a;
    }
    cout << findinator(given, n) << endl;
    return 0;
}