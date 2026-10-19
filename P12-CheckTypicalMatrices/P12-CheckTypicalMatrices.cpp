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

bool IsMatricesEqual(int matrix1[3][3], int matrix2[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (matrix1[i][j] != matrix2[i][j])
                return false;
        }
    }
    return true;
}

int main()
{
    srand((unsigned)time(NULL));

    int matrix1[3][3];
    int matrix2[3][3];

    FillMatrixByRandomNumbers(matrix1, 3, 3);
    cout << "Matrix1:\n";
    PrintMatrix(matrix1, 3, 3);

    FillMatrixByRandomNumbers(matrix2, 3, 3);
    cout << "Matrix2:\n";
    PrintMatrix(matrix2, 3, 3);

    if (IsMatricesEqual(matrix1, matrix2, 3, 3))
    {
        cout << "Matrices are equal\n";
    }
    else
        cout << "Matrices are not equal\n";

    system("pause");
}