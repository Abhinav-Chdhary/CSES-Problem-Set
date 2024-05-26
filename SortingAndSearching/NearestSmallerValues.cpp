#include <iostream>
#include <vector>
#include <stack>
#define ll long long

using namespace std;

/*
 Intuition: Use a monotonic stack approach
 Time-complexity: O(n)
 Space-complexity: O(n)
*/
void nearestSmallinator(vector<int> &arr, const int &n)
{
    // to store index that have smaller value to the left
    stack<int> stk;

    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && arr[stk.top()] >= arr[i])
            stk.pop();
        if (stk.empty())
            cout << 0 << " ";
        else
            cout << stk.top()+1 << " ";
        stk.push(i);
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    nearestSmallinator(arr, n);

    return 0;
}