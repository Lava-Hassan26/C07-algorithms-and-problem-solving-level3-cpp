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

void PrintMiddleRow(int matrix[3][3], short rows, short cols)
{
    short middleRow = rows / 2;
    for (int j = 0; j < cols; j++)
        cout << left << setw(5) << matrix[middleRow][j];
    cout << "\n\n";
}

void PrintMiddleColumn(int matrix[3][3], short rows, short cols)
{
    short middleColumn = cols / 2;
    for (int i = 0; i < rows; i++)
        cout << left << setw(5) << matrix[i][middleColumn];
    cout << "\n\n";
}

int main()
{
    srand((unsigned)time(NULL));

    int matrix[3][3];
 
    FillMatrixByRandomNumbers(matrix, 3, 3);
    cout << "Matrix Elements:\n";
    PrintMatrix(matrix, 3, 3);

    cout << "Middle Row:\n";
    PrintMiddleRow(matrix, 3, 3);

    cout << "Middle Column:\n";
    PrintMiddleColumn(matrix, 3, 3);

    system("pause");
}