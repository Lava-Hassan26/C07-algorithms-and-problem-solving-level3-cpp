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
    cout << "\nThe following are matrix elements:\n";
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

int SumColumn(int matrix[3][3], short rows, short colNumber)
{
    int colSum = 0;
    for (int i = 0; i < rows; i++)
    {
        colSum += matrix[i][colNumber];
    }
    return colSum;
}

void PrintSumEachColumnInMatrix(int matrix[3][3], short rows, short cols)
{
    cout << "\nThe following are the sum of each column in the matrix:\n";
    for (int j = 0; j < cols; j++)
    {
        cout << "Column " << j + 1 << " sum= " << SumColumn(matrix, rows, j) << endl;
    }
    cout << "\n\n";
}

int main()
{
    srand((unsigned)time(NULL));

    int matrix[3][3];
    FillMatrixByRandomNumbers(matrix, 3, 3);
    PrintMatrix(matrix, 3, 3);

    PrintSumEachColumnInMatrix(matrix, 3, 3);
    system("pause");
}