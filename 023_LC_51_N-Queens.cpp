//
// Created by Zeno on 2020/4/13.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#if 0
vector<string> chessboard;

bool judge(int j, int k)
{
    for (int l = 0; l < max(j, k); l++)
    {
        if ( chessboard[j][l] == 'Q' || chessboard[l][k] == 'Q' )
            return false;
        if (l != 0 && l < j && l < k && chessboard[j - l][k - l] == 'Q')
            return false;
    }

    return true;
}

int main()
{
    int n = 4;
    for (int i = 0; i < n; i++)
    {
        string s;
        for (int j = 0; j < n; j++)
        {
            s += '.';
        }
        chessboard.push_back(s);
    }

    chessboard[0][0] = 'Q';
    chessboard[0][1] = 'Q';

    cout << judge(0, 1) << endl;

    for (int i = 0; i < n; i++)
    {
        string s = chessboard[i];
        cout << s << endl;
    }

    return 0;
}
#endif

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        _n = n;
        tempSol.reserve(_n);
        helper(0);

        return _ret;
    }

private:
    int _n;
    vector<int> tempSol; // 该数组元素下标表示行号，下标上保存的元素代表列号，例如tempSol[1] = 2，则表示在(0,2)位置放了一个Q
    vector<vector<string>> _ret;
    vector<string> _ChessBoard;

    bool isPositionedOkay (int row)
    {
        // 检查有无同列不同行的Q
        for (int i = 0; i < row; ++i)
        {
            if (tempSol[row] == tempSol[i])
                return false;
        }

        for (int i = 0; i < row; i++)
        {
            int height = row - i;
            if (tempSol[row] == tempSol[i] + height || tempSol[row] == tempSol[i] - height)
                return false;
        }

        return true;
    }
    void helper(int row)
    {
       // if (row == _n)
       // {
       //     _ret.push_back(_ChessBoard);
       // }
       // else
       // {
       //     for (int i = 0; i < _n; ++i)
       //     {
       //         int temp = tempSol[row];
       //         tempSol[row] = i;
       //         if (isPositionedOkay(row))
       //             helper(row + 1);
       //         tempSol[row] = temp;
       //     }
       // }
       for (int i = 0; i < _n; i++)
       {
           tempSol[row] = i;
           if (!isPositionedOkay(row))
               continue;
           if (row == _n - 1)
           {
               _ret.push_back(_ChessBoard);
               int size = _ret.size();
               generateChessBoard();
           }
           else
           {
               helper(row + 1);
           }
       }
    }

    void generateChessBoard()
    {
        string s(_n, '.');
        for (int row = 0; row < _n; ++row)
        {
            s[tempSol[row]] = 'Q';
            _ChessBoard.push_back(s);
            s[tempSol[row]] = '.';
        }
    }
};

int main()
{
    Solution s;
    vector<vector<string>> ret = s.solveNQueens(4);

    for (int i = 0; i < ret.size(); i++)
    {
        for (int j = 0; j < ret.size(); j++)
        {
            cout << ret[i][j] << endl;
        }
    }
    return 0;
}