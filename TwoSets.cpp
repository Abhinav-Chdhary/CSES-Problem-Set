#include <iostream>

using namespace std;

/*
 Intuition:
    we can only make sets if N%4 == 3 or N%4==0
    if N%4==3
    print pairs like, i, N, .... till n/2-1 numbers
    then print N-i
    then again pairs like i, N-i till n/2+1 numbers

    if N%4==0
    then print N/2 numbers in similar pairs
    and N/2 in next line

 Time-complexity: O(N)
 Space-complexity: O(1)
*/

void printinator(int N)
{
    if (N % 4 == 3)
    {
        cout << "YES" << endl;
        int i = 1;
        cout << N / 2 << endl;
        for (int j = 0; j < N / 2 - 1; j += 2)
        {
            cout << N - i + 1 << " " << i << " ";
            i++;
        }
        cout << N - i + 1 << endl;
        cout << N / 2 + 1 << endl;
        for (int j = 0; j < N / 2 + 1; j += 2)
        {
            cout << N - i << " " << i << " ";
            ++i;
        }
    }
    else if (N % 4 == 0)
    {
        cout << "YES" << endl;
        cout << N / 2 << endl;
        int i = 1;
        for (int j = 0; j < N / 2; j += 2)
        {
            cout << N - i + 1 << " " << i << " ";
            i++;
        }
        cout << endl;
        cout << N / 2 << endl;
        for (int j = 0; j < N / 2; j += 2)
        {
            cout << N - i + 1 << " " << i << " ";
            ++i;
        }
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    printinator(n);

    return 0;
}