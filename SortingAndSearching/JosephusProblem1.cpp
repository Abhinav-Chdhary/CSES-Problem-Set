#include <iostream>
#include <queue>

using namespace std;

/*
 Intuition: Initialize a queue and simulate the process

 Time-complexity: O(n)
 Space-complexity: O(n)
*/

void playinator(const int &n)
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        q.push(i);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (q.empty())
        {
            cout << cur << endl;
            break;
        }
        cout << q.front() << " ";
        q.pop();
        q.push(cur);
    }
}

int main()
{
    int n;
    cin >> n;

    playinator(n);

    return 0;
}