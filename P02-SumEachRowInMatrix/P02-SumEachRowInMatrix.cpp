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

int SumRow(int matrix[3][3], short rowNumber, short cols)
{
    int rowSum = 0;
    for (int j = 0; j < cols; j++)
    {
        rowSum += matrix[rowNumber][j];
    }
    return rowSum;
}

void PrintEachRowSum(int matrix[3][3], short rows, short cols)
{  
    cout << "\nThe following are the sum of each row in the matrix:\n";

    for (int i = 0; i < rows; i++)
    {
        cout << "Row " << i + 1 << " sum= " << SumRow(matrix, i, cols) << endl;
    }
    cout << "\n\n";
}

int main()
{
    srand((unsigned)time(NULL));

    int matrix[3][3];
    FillMatrixByRandomNumbers(matrix, 3, 3);
    PrintMatrix(matrix, 3, 3);

    PrintEachRowSum(matrix, 3, 3);
    system("pause");
}