#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void FillMatrixByOrderedNumbers(int matrix[3][3], short rows, short cols)
{
    short counter = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            counter++;
            matrix[i][j] = counter;
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

void TransposeMatrix(int matrix[3][3], int transposedMatrix[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transposedMatrix[i][j] = matrix[j][i];
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int matrix[3][3];
    int transposedMatrix[3][3];

    FillMatrixByOrderedNumbers(matrix, 3, 3);
    PrintMatrix(matrix, 3, 3);

    cout << "\nTransposed matrix\n";
    TransposeMatrix(matrix, transposedMatrix, 3, 3);
    PrintMatrix(transposedMatrix, 3, 3);

    system("pause");
}