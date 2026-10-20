#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int GetRandomNumber(int from, int to)
{
    int randNumber = rand() % (to - from + 1) + from;
    return randNumber;
}

void FillMatrixByRandomNumbers(int matrix[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = GetRandomNumber(1, 10);
        }
    }
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    cout << "\nThe following are the matrix elements:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << left << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
    cout << "\n\n";
}

int CountNumberInMatrix(int matrix[3][3], short rows, short cols, int numberToCount)
{
    short counter = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == numberToCount)
                counter++;
        }
    }
    return counter;
}

bool CheckSparseMatrix(int matrix[3][3], short rows, short cols)
{
    return CountNumberInMatrix(matrix, rows, cols, 0) >= (rows * cols) / 2;
}

int main()
{
    srand((unsigned)time(NULL));
    int matrix[3][3] = { {0,0,36},{99,0,0},{0,0,0} };
    PrintMatrix(matrix, 3, 3);

    if (CheckSparseMatrix(matrix, 3, 3))
        cout << "It is a sparse matrix\n\n";
    else
        cout << "It is not a sparse matrix\n\n";
    system("pause");
}