#include <iostream>
#include <vector>
#include <string.h>
#define ll long long

using namespace std;

int findinator(string given, int n)
{
    int res = 1;
    for (int i = 0; i < n;)
    {
        char c = given[i];
        int j = i, cnt = 0;
        while (j < n && given[j] == c)
        {
            ++cnt;
            ++j;
        }
        i = j;
        res = max(cnt, res);
    }
    return res;
}

int main()
{
    char a;

    string given = "";
    cin >> given;
    cout << findinator(given, given.size()) << endl;
    return 0;
}