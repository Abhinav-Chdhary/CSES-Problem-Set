#include <iostream>

using namespace std;

/*
 Intuition: Trying a bunch of inputs,
 I observed that only when (a+b) is divisible by 3
 we can reduce the piles to empty. But that did not work
 So tried simultaneous linear equations
 X * 2 + Y * 4 = 2 * A
 X * 2 + Y * 1 = B
 3 * Y = 2 * A - B
 Y = (2 * A - B)/3

 X + Y * 2 = A
 4 * X + 2 * Y = 2 * B
 -3 * X = A - 2 * B
 X = (2 * B - A) / 3

 if (2*A-B) is not divisible by 3 or is less than 0
 or if (2*B-A) is not divisible by 3 or is less than 0
 Then ans = NO


 Time-complexity: O(1)
 Space-complexity: O(1)
*/

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int a, b;
        cin >> a >> b;
        if ((2 * a - b) % 3 || (2 * a - b < 0) || (2 * b - a) % 3 || 2 * b - a < 0)
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}