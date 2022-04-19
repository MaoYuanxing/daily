#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;
int isWin(vector<string> &grid, vector<string> &col_grid)
{
    for (string a : grid)
    {
        if (a.find("rrrr") != a.end())
            return 1;
        if (a.find("pppp"))
            return 0;
    }
    for (string a : col_grid)
    {
        if (a.find("rrrr"))
            return 1;
        if (a.find("pppp"))
            return 0;
    }
    return 2;
}

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    string s(m, '1');
    vector<string> grid(n, s);
    for (string &a : grid)
    {
        for (char &c : a)
        {
            cin >> c;
        }
    }
    string ss(n, '1');
    vector<string> col_grid(m, ss);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            col_grid[j][i] = grid[i][j];
        }
    }

    for (string &a : col_grid)
    {
        for (char &c : a)
        {
            cout << c;
        }
        cout << endl;
    }

    if (isWin(grid, col_grid) == 1)
        cout << "kou";
    else if (isWin(grid, col_grid) == 0)
        cout << "yukari";
    else
        cout << "to be continued";
}
