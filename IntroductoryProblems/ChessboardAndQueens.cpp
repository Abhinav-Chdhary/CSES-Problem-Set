#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 Intuition: We can use backtracking
 with naive checking each row and column
 This problem is the one extended to famous
 N queens problem on leetcode

 Time-complexity: O(n^n) each node in the recursive tree
 will have approximately n subtrees, and n level tree will
 be generated
 Space-complexity: O(n*n)
*/

bool isSafe(int i, int j, vector<string> &board)
{
    // check row
    int row = i, col = j;
    for (; col >= 0; col--)
    {
        if (board[row][col] == 'Q')
            return false;
    }
    // check col
    col = j;
    for (; row >= 0; row--)
    {
        if (board[row][col] == 'Q')
            return false;
    }
    // check upper left diagonal
    row = i, col = j;
    for (; row >= 0 and col >= 0; row--, col--)
    {
        if (board[row][col] == 'Q')
            return false;
    }
    // check upper right diagonal
    row = i, col = j;
    for (; row >= 0 and col >= 0; row--, col++)
    {
        if (board[row][col] == 'Q')
            return false;
    }
    return true;
}
void placinator(int n, int &res, vector<string> board, int row)
{
    if (row >= n)
    {
        ++res;
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (board[row][col] != '*' && isSafe(row, col, board))
        {
            board[row][col] = 'Q';
            placinator(n, res, board, row + 1);
            board[row][col] = '.';
        }
    }
}

int solveNQueens(vector<string> &initial)
{
    int res = 0;
    placinator(8, res, initial, 0);
    return res;
}

int main()
{
    vector<string> initial(8);
    for (int i = 0; i < 8; i++)
    {
        string s;
        getline(cin, s);
        initial[i] = s;
    }
    cout << solveNQueens(initial) << endl;

    return 0;
}