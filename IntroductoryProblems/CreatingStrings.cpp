#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 Intuition: Using stl library to generate
 permutations

 Time-complexity: O(n!)
 Space-complexity: O(1)
*/
int fact(int n)
{
    int ans = 1;
    for (int i = 2; i <= n; i++)
        ans *= i;
    return ans;
}
void permutinator(string s, int n)
{
    vector<int> freq(26, 0);
    int dup = 1;
    for (char c : s)
        ++freq[c - 'a'];
    for (int i : freq)
    {
        if (i > 1)
            dup *= fact(i);
    }
    int permuts = fact(n) / dup;
    cout << permuts << endl;
    sort(s.begin(), s.end());
    for (int i = 0; i < permuts; i++)
    {
        cout << s << endl;
        next_permutation(s.begin(), s.end());
    }
}

int main()
{
    string s;
    cin >> s;

    permutinator(s, s.size());

    return 0;
}