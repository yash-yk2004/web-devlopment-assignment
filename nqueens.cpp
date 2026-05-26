#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:

    bool isSafe(int row, int col, vector<string>& board, int n) {

        int x = row;
        int y = col;

        // Upper diagonal
        while (x >= 0 && y >= 0) {

            if (board[x][y] == 'Q') {
                return false;
            }

            x--;
            y--;
        }

        x = row;
        y = col;

        // Left side
        while (y >= 0) {

            if (board[x][y] == 'Q') {
                return false;
            }

            y--;
        }

        x = row;
        y = col;

        // Lower diagonal
        while (x < n && y >= 0) {

            if (board[x][y] == 'Q') {
                return false;
            }

            x++;
            y--;
        }

        return true;
    }

    void solve(int col,
               vector<vector<string>>& ans,
               vector<string>& board,
               int n) {

        if (col == n) {

            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {

            if (isSafe(row, col, board, n)) {

                board[row][col] = 'Q';

                solve(col + 1, ans, board, n);

                // Backtracking
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n);

        string s(n, '.');

        for (int i = 0; i < n; i++) {
            board[i] = s;
        }

        solve(0, ans, board, n);

        return ans;
    }
};

int main() {

    int n;

    cout << "Enter value of N: ";
    cin >> n;

    Solution obj;

    vector<vector<string>> result = obj.solveNQueens(n);

    cout << "\nTotal Solutions: " << result.size() << endl;

    for (int i = 0; i < result.size(); i++) {

        cout << "\nSolution " << i + 1 << ":\n";

        for (string row : result[i]) {

            cout << row << endl;
        }
    }

    return 0;
}