#include<iostream>
#include<cstring>

int N;

void print(int **board)
{
    static int count = 1;
    std::cout << "Solution no :- " << count++ << std::endl;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool isSafe(int **board, int row, int col)
{
    for(int i = 0; i < col; i++)
    {
        if(board[row][i] == 1)
        {
            return false;
        }
    }

    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if(board[i][j] == 1)
        {
            return false;
        }
    }

    for(int i = row, j = col; i < N && j >= 0; i++, j--)
    {
        if(board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}

bool Solution(int **board, int col)
{
    if(col == N)
    {
        print(board);
        return true;
    }

    bool result = false;

    for(int i = 0; i < N; i++)
    {
        if(isSafe(board, i, col) == true)
        {
            board[i][col] = 1;
            result = Solution(board, col+1) || result;
            board[i][col] = 0;
        }
    }
    return result;
}

int main()
{
    std::cout << "Enter the row and column number of the board :- ";
    std::cin >> N;
    int **board;
    board = new int *[10];
    for(int i = 0; i < N; i++)
    {
        board[i] = new int[10];
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }

    if(Solution(board, 0) == false)
    {
        std::cout << "No Solution exists." << std::endl;
    }
}
