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
            matrix[i][j] = GetRandomNumber(1, 100);
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

bool IsMatrixScalar(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (i == j && matrix[i][j] != matrix[0][0])
                return false;
            if (i != j && matrix[i][j] != 0)
                return false;
        }
    }
    return true;
}

int main()
{
    srand((unsigned)time(NULL));

    int matrix[3][3] = { {8,0,0},{0,8,0},{0,0,8} };
    PrintMatrix(matrix, 3, 3);

    if (IsMatrixScalar(matrix, 3, 3))
    {
        cout << "Matrix is scalar\n\n";
    }
    else
        cout << "Matrix is not scalar\n\n";

    system("pause");
}