#include <iostream>
#include <vector>

using namespace std;

/*
 Intuition:
 Start with a list of strings {"0", "1"}
 append it's reverse and add '0' to the first half
 '1' to the second half, repeat n times

 Time-complexity: O(n*(2^n))
 Space-complexity: O(1)
*/

vector<string> grayCodeInator(int n)
{
    vector<string> res = {"0", "1"};
    while (n > 1)
    {
        for (int i = res.size() - 1; i >= 0; i--)
        {
            res.push_back(res[i]);
        }
        int nsz = res.size();
        int i = 0;
        for (; i < nsz / 2; i++)
        {
            res[i] += '0';
        }
        for (; i < nsz; i++)
        {
            res[i] += '1';
        }
        --n;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    vector<string> ans = grayCodeInator(n);
    for (string s : ans)
    {
        cout << s << endl;
    }

    return 0;
}