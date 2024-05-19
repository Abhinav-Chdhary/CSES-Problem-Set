#include <iostream>
#include <set>

using namespace std;

/*
 Intuition: put all the elements in an unordered set

 Time-complexity: O(nlogn)
 Space-complexity: O(n)
*/
int main()
{
    int n;
    cin >> n;

    set<int> us;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        us.insert(x);
    }
    cout << us.size() << endl;

    return 0;
}