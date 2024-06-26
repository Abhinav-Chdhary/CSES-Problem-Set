#include <iostream>
#include <vector>

using namespace std;

/*
 Intuition: Start at n and assign even numbers to the first half
 serially and odd numbers to the second half serially
 if n is odd then the second half starts at n/2+1
 else n is even the the second half start at n/2

 Time-complexity: O(n) where n is the given number
 Space-complexity: O(1) apart from resultant array
*/

vector<int> perminator(vector<int> &given, int n)
{
    vector<int> res(n, -1);
    int oddStrt = 0, evenStrt = n % 2 == 0 ? n / 2 : n / 2 + 1;
    for (int i = n; i >= 1; i--)
    {
        if (i % 2 == 0)
            res[evenStrt++] = i;
        else
            res[oddStrt++] = i;
    }
    return res;
}

int main()
{
    int n, a;
    cin >> n;
    if (n == 1)
        cout << 1 << endl;
    else if (n <= 3)
        cout << "NO SOLUTION" << endl;
    else
    {
        vector<int> given(n);
        int i = 0;
        while (cin >> a)
        {
            given[i++] = a;
        }
        vector<int> ans = perminator(given, n);
        for (int a : ans)
        {
            cout << a << " ";
        }
    }
    return 0;
}