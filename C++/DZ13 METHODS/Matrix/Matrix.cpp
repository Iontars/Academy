#include <iostream>
#include <time.h>
using namespace std;

template <typename T> void FillRand(T** matrix, int squareSize);
template <typename T> void CreateMatrix(T** matrix, int squareSize);
template <typename T> void DisplayMatrix(T** matrix, int squareSize);
template <typename T> T** SumMatrix(T** matrix, T** matrix2, int squareSize);
template <typename T> T** SubMatrix(T** matrix, T** matrix2, int squareSize);
template <typename T> T** MultMatrix(T** matrix, T** matrix2, int squareSize);
template <typename T> int Determinant(T** matrix, int squareSize);
template <typename T> void CalculateMatrix(T** matrix, int squareSize, T** insideTempMatrix, int horizontalIndex, int verticalIndex);
template <typename T> void Transposition(T** matrix, T** tempReverseMatrix, int n);

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int squareSize;
    int det;
    cout << "Ввести размер матрицы:";
    cout << endl;
    cin >> squareSize;
    int** matrix = new int* [squareSize];
    int** matrix_2 = new int* [squareSize];
    double** reverseMatrix = new double* [squareSize];
    double** tempReverseMatrix = new double* [squareSize];


    CreateMatrix(matrix, squareSize);
    CreateMatrix(matrix_2, squareSize);
    CreateMatrix(reverseMatrix, squareSize);
    CreateMatrix(tempReverseMatrix, squareSize);
    FillRand(matrix, squareSize);
    FillRand(matrix_2, squareSize);
    cout << endl;
    cout << "Вывод матрицы_1" << endl;
    DisplayMatrix(matrix, squareSize);
    cout << endl << "Вывод матрицы_2" << endl;
    DisplayMatrix(matrix_2, squareSize);
    cout << endl;
    int** sum_matrix = SumMatrix(matrix, matrix_2, squareSize);
    int** sub_matrix = SubMatrix(matrix, matrix_2, squareSize);
    int** mul_matrix = MultMatrix(matrix, matrix_2, squareSize);

    DisplayMatrix(sum_matrix, squareSize);
    DisplayMatrix(sub_matrix, squareSize);
    DisplayMatrix(mul_matrix, squareSize);

    cout << "Определитель матрицы 1 равен: " << Determinant(matrix, squareSize) << endl;
    cout << "Определитель матрицы 2 равен: " << Determinant(matrix_2, squareSize) << endl;

    for (int i = 0; i < squareSize; i++)
    {
        for (int j = 0; j < squareSize; j++)
        {
            int m = squareSize - 1;
            int** insideTempMatrix = new int* [m];
            for (int k = 0; k < m; k++) insideTempMatrix[k] = new int[m];
            CalculateMatrix(matrix, squareSize, insideTempMatrix, i, j);
            reverseMatrix[i][j] = pow(-1.0, i + j + 2) * Determinant(insideTempMatrix, m) / Determinant(matrix, squareSize); // ?
        }
    }
    Transposition(reverseMatrix, tempReverseMatrix, squareSize);

    cout << endl << "Обратная матрица матрице 1: " << endl;
    DisplayMatrix(tempReverseMatrix, squareSize);

}

template <typename T> T** SumMatrix(T** matrix, T** matrix2, int squareSize)
{
    //cout << "Сумма матриц равна: " << endl;
    T** resultMAtrix = new T * [squareSize];
    CreateMatrix(resultMAtrix, squareSize);
    for (int i = 0; i < squareSize; i++)
    {
        for (int j = 0; j < squareSize; j++) resultMAtrix[i][j] = matrix[i][j] + matrix2[i][j];
    }
    //DisplayMatrix(resultMAtrix, squareSize);
    //cout << endl;
    return resultMAtrix;
}

template <typename T> T** SubMatrix(T** matrix, T** matrix2, int squareSize)
{
    //cout << "Разница матриц равна: " << endl;
    T** resultMAtrix = new T * [squareSize];
    CreateMatrix(resultMAtrix, squareSize);
    for (int i = 0; i < squareSize; i++)
    {
        for (int j = 0; j < squareSize; j++) resultMAtrix[i][j] = matrix[i][j] - matrix2[i][j];
    }
    //DisplayMatrix(resultMAtrix, squareSize);
    //cout << endl;
    return resultMAtrix;
}
template <typename T> T** MultMatrix(T** matrix, T** matrix2, int squareSize)
{
    //cout << "Произведение матриц равно: " << endl;
    T** resultMAtrix = new T * [squareSize];
    CreateMatrix(resultMAtrix, squareSize);
    for (int i = 0; i < squareSize; i++)
    {
        for (int j = 0; j < squareSize; j++) resultMAtrix[i][j] = matrix[i][j] * matrix2[i][j];
    }
    //DisplayMatrix(resultMAtrix, squareSize);
    //cout << endl;
    return resultMAtrix;
}

template <typename T> void CreateMatrix(T** matrix, int squareSize)
{
    for (int i = 0; i < squareSize; i++)  matrix[i] = new T[squareSize];
}

template <typename T> void FillRand(T** a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) a[i][j] = rand() % 100;
    }
}

template <typename T> void DisplayMatrix(T** matrix, int squareSize)
{
    for (int i = 0; i < squareSize; i++)
    {
        cout << "|";
        for (int j = 0; j < squareSize; j++)
        {
            if (matrix[i][j] < 10)
            {
                cout << matrix[i][j] << "  ";
            }
            else
            {
                cout << matrix[i][j] << " ";
            }
        }
        cout << "|" << endl;
    }
}

template <typename T> int Determinant(T** matrix, int squareSize)
{
    if (squareSize == 1) return matrix[0][0];
    else if (squareSize == 2) return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    else
    {
        int result = 0;
        for (int i = 0; i < squareSize; i++)
        {
            int** tempMatrix = new int* [squareSize - 1];
            for (int j = 0; j < squareSize - 1; j++)
            {
                tempMatrix[j] = new int[squareSize - 1];
            }
            for (int k = 1; k < squareSize; k++)
            {
                for (int z = 0; z < squareSize; z++)
                {
                    if (z == k) continue;
                    else if (z < k) tempMatrix[k - 1][z] = matrix[k][z];
                    else tempMatrix[k - 1][z - 1] = matrix[k][z];
                }
            }
            result += (-1 ^ i + 2) * matrix[0][i] * Determinant(tempMatrix, squareSize - 1);
        }
        return result;
    }
}

template <typename T> void CalculateMatrix(T** matrix, int squareSize, T** insideTempMatrix, int horizontalIndex, int verticalIndex)
{
    int index_1 = 0;
    for (int i = 0; i < squareSize; i++) {
        if (i != horizontalIndex) {
            for (int j = 0, index_2 = 0; j < squareSize; j++) {
                if (j != verticalIndex) {
                    insideTempMatrix[index_1][index_2] = matrix[i][j];
                    index_2++;
                }
            }
            index_1++;
        }
    }
}

template <typename T> void Transposition(T** matrix, T** tempReverseMatrix, int squareSize) {//
    for (int i = 0; i < squareSize; i++)
    {
        for (int j = 0; j < squareSize; j++) tempReverseMatrix[j][i] = matrix[i][j];
    }
}
