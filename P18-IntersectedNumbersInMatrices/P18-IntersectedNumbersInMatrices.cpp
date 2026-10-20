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

bool IsNumberExistsInMatrix(int matrix[3][3], short rows, short cols, int numberToCheck)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == numberToCheck)
                return true;
        }
    }
    return false;;
}

void PrintIntersectedNumbersInMatrices(int matrix1[3][3], int matrix2[3][3], short rows, short cols)
{
    cout << "Interscted numbers: ";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (IsNumberExistsInMatrix(matrix2, rows, cols, matrix1[i][j]))
                cout << left << setw(5) << matrix1[i][j];
        }
    }
    cout << "\n\n";
}

int main()
{
    srand((unsigned)time(NULL));

    int matrix1[3][3];
    FillMatrixByRandomNumbers(matrix1, 3, 3);
    PrintMatrix(matrix1, 3, 3);

    int matrix2[3][3];
    FillMatrixByRandomNumbers(matrix2, 3, 3);
    PrintMatrix(matrix2, 3, 3);

    PrintIntersectedNumbersInMatrices(matrix1, matrix2, 3, 3);
    system("pause");
}