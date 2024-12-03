#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Вывод матрицы
void printMatrix(int rows, int cols, float** matrix) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Генерация случайной матрицы
void generateRandomMatrix(int rows, int cols, float** matrix, int min, int max) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (rand() % (max - min + 1)) + min;
        }
    }
}

// Поиск минимального элемента и его позиции
void findMatrixMin(int rows, int cols, float** matrix, int* minRow, int* minCol) {
    float min = matrix[0][0];
    *minRow = 0;
    *minCol = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
                *minRow = i;
                *minCol = j;
            }
        }
    }
}

// Умножение квадрата на число и вычисление суммы
float processSquare(int size, float** square, float multiplier) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            square[i][j] *= multiplier;
            sum += square[i][j];
        }
    }
    return sum;
}

// Выделение памяти для матрицы
float** allocateMatrix(int rows, int cols) {
    float** matrix = (float**) malloc(rows * sizeof(float*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (float*) malloc(cols * sizeof(float));
    }
    return matrix;
}

// Освобождение памяти
void freeMatrix(int rows, float** matrix) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Получить квадрат, начиная с минимального элемента в правом верхнем углу
void getMinSquare(int rows, int cols, float** matrix, int* squareSize, float*** square) {
    int minRow, minCol;
    findMatrixMin(rows, cols, matrix, &minRow, &minCol);

    // Определяем размер квадрата
    *squareSize = (rows - minRow < cols - minCol) ? (rows - minRow) : (cols - minCol);

    // Если квадрат слишком маленький (меньше 3x3), расширим его до 3x3
    if (*squareSize < 3) {
        *squareSize = 3;
    }

    // Выделяем память для квадрата
    *square = allocateMatrix(*squareSize, *squareSize);

    // Заполняем квадрат элементами из матрицы с минимальным элементом в правом верхнем углу
    for (int i = 0; i < *squareSize; i++) {
        for (int j = 0; j < *squareSize; j++) {
            // Правильное извлечение квадрата с минимальным элементом в правом верхнем углу
            if (minRow + i < rows && minCol - j >= 0) {
                (*square)[i][j] = matrix[minRow + i][minCol - j];
            } else {
                (*square)[i][j] = 1;  // Заполняем единицами, если выходит за пределы
            }
        }
    }
}

int main() {
    int size = 3;
    srand(time(NULL));

    // Выделяем память для матрицы
    float** matrix = allocateMatrix(size, size);
    generateRandomMatrix(size, size, matrix, -20, 20);

    printf("Исходная матрица:\n");
    printMatrix(size, size, matrix);

    int squareSize;
    float** square = NULL;

    // Получаем квадрат
    getMinSquare(size, size, matrix, &squareSize, &square);

    printf("Квадрат до обработки:\n");
    printMatrix(squareSize, squareSize, square);

    // Ввод числа для умножения
    float multiplier;
    printf("Введите число для умножения: ");
    scanf("%f", &multiplier);

    // Умножаем квадрат и вычисляем сумму элементов
    float squareSum = processSquare(squareSize, square, multiplier);
    printf("Квадрат после обработки:\n");
    printMatrix(squareSize, squareSize, square);
    printf("Сумма элементов квадрата: %.2f\n", squareSum);

    // Освобождаем память
    freeMatrix(size, matrix);
    freeMatrix(squareSize, square);

    return 0;
}

