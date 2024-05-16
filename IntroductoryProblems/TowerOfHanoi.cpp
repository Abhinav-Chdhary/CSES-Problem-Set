#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

/*
 Intuition:
 For odd N we do ops in the following order
 1<->3
 1<->2
 3<->2
 For even N we do ops in the following order
 1<->2
 1<->3
 3<->2

 Time-complexity: O(2^n)
 Space-complexity: O(1)
*/
void hanoiSolver(int n)
{
    stack<int> one, two, three;
    for (int i = n; i >= 1; i--)
        one.push(i);
    cout << pow(2, n) - 1 << endl;
    if (n % 2)
    {
        // odd case
        while ((int)three.size() < n)
        {
            // 1->3
            if (!one.empty() && (three.empty() || (one.top() < three.top())))
            {
                three.push(one.top());
                one.pop();
                cout << 1 << " " << 3 << endl;
                if ((int)three.size() == n)
                    break;
            }
            // 3->1
            else
            {
                one.push(three.top());
                three.pop();
                cout << 3 << " " << 1 << endl;
            }

            // 1->2
            if (!one.empty() && (two.empty() || (one.top() < two.top())))
            {
                two.push(one.top());
                one.pop();
                cout << 1 << " " << 2 << endl;
            }
            // 2->1
            else
            {
                one.push(two.top());
                two.pop();
                cout << 2 << " " << 1 << endl;
            }

            // 2->3
            if (!two.empty() && (three.empty() || (two.top() < three.top())))
            {
                three.push(two.top());
                two.pop();
                cout << 2 << " " << 3 << endl;
                if ((int)three.size() == n)
                    break;
            }
            // 3->2
            else
            {
                two.push(three.top());
                three.pop();
                cout << 3 << " " << 2 << endl;
            }
        }
    }
    else
    {
        // even case
        while ((int)three.size() < n)
        {
            // 1->2
            if (!one.empty() && (two.empty() || (one.top() < two.top())))
            {
                two.push(one.top());
                one.pop();
                cout << 1 << " " << 2 << endl;
            }
            // 2->1
            else
            {
                one.push(two.top());
                two.pop();
                cout << 2 << " " << 1 << endl;
            }
            // 1->3
            if (!one.empty() && (three.empty() || (one.top() < three.top())))
            {
                three.push(one.top());
                one.pop();
                cout << 1 << " " << 3 << endl;
                if ((int)three.size() == n)
                    break;
            }
            // 3->1
            else
            {
                one.push(three.top());
                three.pop();
                cout << 3 << " " << 1 << endl;
            }
            // 2->3
            if (!two.empty() && (three.empty() || (two.top() < three.top())))
            {
                three.push(two.top());
                two.pop();
                cout << 2 << " " << 3 << endl;
                if ((int)three.size() == n)
                    break;
            }
            // 3->2
            else
            {
                two.push(three.top());
                three.pop();
                cout << 3 << " " << 2 << endl;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    hanoiSolver(n);

    return 0;
}