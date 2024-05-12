#include <iostream>
#define ll long long

using namespace std;

/*
 Intuition: Total possible positions = ((k^2)*(k^2-1))/2
 2 knights can attack each other in 2 positions in a
 2*3 block as well as a 3*2 block
 So find the number of such blocks
 ans = total - attacking Blocks*2

 Time-complexity: O(k)
 Space-complexity: O(1)
*/

ll checkinator(ll k)
{
    ll total = ((k * k) * (k * k - 1)) / 2;
    ll atckBlocks = (k - 1) * (k - 2) * 2 * 2;
    // 3 by 2, 2 by 3 and each block has two
    return total - atckBlocks;
}

int main()
{
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++)
        cout << checkinator(i) << endl;

    return 0;
}