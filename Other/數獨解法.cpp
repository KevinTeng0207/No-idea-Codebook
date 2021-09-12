int getSquareIndex(int row, int column, int n)
{
    return row / n * n + column / n;
}

bool backtracking(vector<vector<int>> &board, vector<vector<bool>> &rows, vector<vector<bool>> &cols,
                  vector<vector<bool>> &boxs, int index, int n)
{
    int n2 = n * n;
    int rowNum = index / n2, colNum = index % n2;
    if (index >= n2 * n2)
        return true;

    if (board[rowNum][colNum] != 0)
        return backtracking(board, rows, cols, boxs, index + 1, n);

    for (int i = 1; i <= n2; i++)
    {
        if (!rows[rowNum][i] && !cols[colNum][i] && !boxs[getSquareIndex(rowNum, colNum, n)][i])
        {
            rows[rowNum][i] = true;
            cols[colNum][i] = true;
            boxs[getSquareIndex(rowNum, colNum, n)][i] = true;
            board[rowNum][colNum] = i;
            if (backtracking(board, rows, cols, boxs, index + 1, n))
                return true;
            board[rowNum][colNum] = 0;
            rows[rowNum][i] = false;
            cols[colNum][i] = false;
            boxs[getSquareIndex(rowNum, colNum, n)][i] = false;
        }
    }
    return false;
}
/*用法 main*/
int n = sqrt(數獨邊長大小) /*e.g. 9*9 n=3*/
vector<vector<int>> board(n * n + 1, vector<int>(n * n + 1, 0));
vector<vector<bool>> isRow(n * n + 1, vector<bool>(n * n + 1, false));
vector<vector<bool>> isColumn(n * n + 1, vector<bool>(n * n + 1, false));
vector<vector<bool>> isSquare(n * n + 1, vector<bool>(n * n + 1, false));

for (int i = 0; i < n * n; ++i)
{
    for (int j = 0; j < n * n; ++j)
    {
        int number;
        cin >> number;
        board[i][j] = number;
        if (number == 0)
            continue;
        isRow[i][number] = true;
        isColumn[j][number] = true;
        isSquare[getSquareIndex(i, j, n)][number] = true;
    }
}
if (backtracking(board, isRow, isColumn, isSquare, 0, n))
    /*有解答*/
else
    /*解答*/