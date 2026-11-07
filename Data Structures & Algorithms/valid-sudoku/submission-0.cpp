class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9 + 1, vector<int>(9 + 1));
        vector<vector<int>> clm(9 + 1, vector<int>(9 + 1));
        vector<vector<int>> mat(9 + 1, vector<int>(9 + 1));
        int n = board.size();
        int m = board[0].size();
        cout << "board[2][2] = " << board[2][2] << endl;
        cout << "board[2][2] ASCII = " << int(board[2][2]) << endl;
        for (int j = 0; j < 9; j++) {
            cout << board[2][j] << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '.') continue;
                int group = (i + 3) / 3;
                int grp = (group - 1) * 3;
                int put = grp + (j + 3) / 3;

                int num = board[i][j] - '0';
                if (mat[put][num] > 0 || row[i + 1][num] > 0 || clm[j + 1][num] > 0) {
                    return false;
                }
                mat[put][num]++;
                row[i + 1][num]++;
                clm[j + 1][num]++;
            }
        }

        return true;
    }
};
