#include <iostream>
#include "matrix.hpp"

int main() {
    int numOfRows = 3;
    int numOfColumns = 5;

    auto **value = new int*[numOfRows];
    for(int i = 0; i < numOfRows; i++) {
        value[i] = new int[numOfColumns];
        for(int j = 0; j < numOfColumns; j++)
            value[i][j] = i + j + 1;
    }

    auto matrix1 = Matrix('1', numOfRows, numOfColumns, value);
    std::cout << matrix1;

    for(int i = 0; i < numOfRows; i++)
        delete [] value[i];
    delete [] value;

    auto matrix2 = Matrix(matrix1);
    matrix2.setName('2');
    std::cout << "\nКонструктор копирования:\n" << matrix2;

    auto matrix3 = matrix2;
    matrix3.setName('3');
    std::cout << "\nОператор присваивания:\n" << matrix3;

    auto matrix4 = matrix3 * -1;
    matrix4.setName('4');
    std::cout << "\nУмножение на число -1 (оператор *):\n" << matrix4;

    matrix4 *= -1;
    std::cout << "\nУмножение на число -1 (оператор *=):\n" << matrix4;

    auto matrix5 = matrix4 + matrix3;
    matrix5.setName('5');
    std::cout << "\nСложение матриц (оператор +)\n" << matrix5;

    matrix5 += matrix2;
    std::cout << "\nСложение матриц (оператор +=)\n" << matrix5;

    ++matrix5;
    std::cout << "\nПрефксный инкремент (оператор ++)\n" << matrix5;

    return 0;
}
