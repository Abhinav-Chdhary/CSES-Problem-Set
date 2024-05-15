#include <iostream>
#include <vector>

using namespace std;

/*
 Intuition: Check freq of chars,
 only one odd frequency allowed
 start assigning to a new string

 Time-complexity: O(n) where n is length of string
 Space-complexity: O(1)
*/

string palindrinator(string s, int n)
{
    // get frequencies
    vector<int> freq(26, 0);
    for (char c : s)
        ++freq[c - 'A'];

    int oddCnt = 0;    // how many are odd?
    char oddOne = '$'; // this will store the odd char if present

    // check if frequencies are valid
    for (char c = 'A'; c <= 'Z'; c++)
    {
        if (freq[c - 'A'] % 2)
        {
            ++oddCnt;
            oddOne = c;
        }
    }
    if (oddCnt > 1)
        return "NO SOLUTION";

    // now form the answer
    string ans(n, '$');
    // if we have odd length palindrome
    if (oddOne != '$')
    {
        ans[n / 2] = oddOne;
        --freq[oddOne - 'A'];
    }
    int i = 0;
    for (char c = 'A'; c <= 'Z'; c++)
    {
        while (freq[c - 'A'] > 0)
        {
            ans[i] = ans[n - i - 1] = c;
            freq[c - 'A'] -= 2;
            ++i;
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;

    cout << palindrinator(s, s.size()) << endl;

    return 0;
}