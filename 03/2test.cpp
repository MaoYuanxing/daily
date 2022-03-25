#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution1
{
public:
    int lengthOfLastWord(string s)
    {
        int res = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] != ' ')
            {
                while (s[i] != ' ' && i >= 0)
                {
                    res++;
                    i--;
                }
                break;
            }
        }
        return res;
    }
};
class Solution2
{
    vector<vector<int>> res;
    vector<int> path;
    vector<int> help;
    int n;
    void backtrace(int idx)
    {
        if (path.size() == n)
        {
            res.push_back(path);
            return;
        }
        for (int i = idx; i < n; i++)
        {
            path.push_back(help[i]);
            backtrace(i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        n = nums.size();
        help = nums;
        backtrace(0);
        return res;
    }
};

class Solution3
{
    vector<vector<string>> res;
    vector<string> path;
    int nn;
    void backtrace(int record[], int depth)
    {
        if (depth == nn)
        {
            res.push_back(generateBoard(record));
            return;
        }
        for (int col = 0; col < nn; col++)
        {
            if (isVaild(record, depth, col))
            {
                record[depth] = col;
                backtrace(record, depth + 1);
            }
        }
    }
    bool isVaild(int record[], int i, int j)
    {
        for (int k = 0; k < i; k++)
        {
            if (record[k] == j || abs(record[k] - j) == abs(i - k))
                return false;
        }
        return true;
    }
    vector<string> generateBoard(int record[])
    {
        vector<string> res;
        for (int i = 0; i < nn; i++)
        {
            string s(nn, '.');
            s[record[i]] = 'Q';
            res.push_back(s);
        }
        return res;
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        int record[n];
        nn = n;
        memset(record, 1, sizeof(record));
        return res;
    }
};

class Solution4
{
    int n;
    int backtrace(int record[], int i)
    {
        if (i == n)
            return 1;
        int res = 0;
        for (int j = 0; j < n; j++)
        {
            if (isValid(record, i, j))
            {
                record[i] = j;
                res += backtrace(record, i + 1);
            }
        }
        return res;
    }
    bool isValid(int record[], int i, int j)
    {
        for (int k = 0; k < i; k++)
        { //只需要看以放皇后的位置
            if (j = record[k] || abs(j - record[k]) == abs(i - k))
                return false;
        }
        return true;
    }

public:
    int totalNQueens(int nn)
    {
        n = nn;
        int record[nn];
        memset(record, 0, sizeof(record));
        return backtrace(record, 0);
    }
};
class Solution
{
    bool col[9][9], row[9][9], sq[3][3][9];
    void backtrace(vector<vector<char>> &board, int i)
    {
        if (i == 9)
            return;
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                for (int num = 0; num < 9; num++)
                {
                    if (!col[j][num] && !row[i][num] && !sq[i / 3][j / 3][num])
                    {
                        board[i][j] = num + '1';
                        col[j][num] = !col[j][num], row[i][num] = !row[i][num], sq[i / 3][j / 3][num] = !sq[i / 3][j / 3][num];
                        backtrace(board, i + 1);
                        col[j][num] = !col[j][num], row[i][num] = !row[i][num], sq[i / 3][j / 3][num] = !sq[i / 3][j / 3][num];
                        board[i][j] = '.';
                    }
                }
            }
        }
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {

        memset(col, 0, sizeof(col));
        memset(row, 0, sizeof(row));
        memset(sq, 0, sizeof(sq));
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int index = board[i][j] - '1';
                    col[j][index] = 1;
                    row[i][index] = 1;
                    sq[i / 3][j / 3][index] = 1;
                }
            }
        }
        backtrace(board, 0);
    }
};
int main()
{
    Solution a;
    vector<vector<char>> n = {initializer_list{"5", "3", ".", ".", "7", ".", ".", ".", "."}, initializer_list{"6", ".", ".", "1", "9", "5", ".", ".", "."}, initializer_list{".", "9", "8", ".", ".", ".", ".", "6", "."}, initializer_list{"8", ".", ".", ".", "6", ".", ".", ".", "3"}, initializer_list{"4", ".", ".", "8", ".", "3", ".", ".", "1"}, initializer_list{"7", ".", ".", ".", "2", ".", ".", ".", "6"}, initializer_list{".", "6", ".", ".", ".", ".", "2", "8", "."}, initializer_list{".", ".", ".", "4", "1", "9", ".", ".", "5"}, initializer_list{".", ".", ".", ".", "8", ".", ".", "7", "9"}};
    a.solveSudoku(n);
    return 0;
}