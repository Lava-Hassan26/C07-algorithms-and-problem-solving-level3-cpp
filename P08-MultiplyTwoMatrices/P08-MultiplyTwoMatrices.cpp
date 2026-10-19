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

void MultiplyTwoMatrices(int matrix1[3][3], int matrix2[3][3], int resultMatrix[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            resultMatrix[i][j] = matrix1[i][j] * matrix2[i][j];
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int matrix1[3][3];
    int matrix2[3][3];
    int resultMatrix[3][3];

    FillMatrixByRandomNumbers(matrix1, 3, 3);
    cout << "Matrix 1 Elements:\n";
    PrintMatrix(matrix1, 3, 3);

    FillMatrixByRandomNumbers(matrix2, 3, 3);
    cout << "Matrix 2 Elements:\n";
    PrintMatrix(matrix2, 3, 3);

    MultiplyTwoMatrices(matrix1, matrix2, resultMatrix, 3, 3);
    cout << "The Result of Multiplying of the Two Matrices:\n";
    PrintMatrix(resultMatrix, 3, 3);
    system("pause");
}