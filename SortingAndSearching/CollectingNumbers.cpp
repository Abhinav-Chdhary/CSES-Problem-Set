#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 Intuition: if a[i] occured before a[i]+1
 then we can collect them in one round
 if a[i] occured after a[i]+1
 then we increment

 Time-complexity: O(n)
 Space-complexity: O(n)
*/

int collectinator(vector<int> &arr, const int &n)
{
    unordered_map<int, bool> occured;
    int ans = 1;
    for (int i : arr)
    {
        if (occured.find(i + 1) != occured.end())
            ++ans;
        occured[i] = true;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << collectinator(arr, n) << endl;

    return 0;
}