#include <iostream>
#include "matrix.hpp"

int main() {
    int numOfRows = 3;
    int numOfColumns = 4;

    auto **value = new int*[numOfRows];
    for(int i = 0; i < numOfRows; i++) {
        value[i] = new int[numOfColumns];
        for(int j = 0; j < numOfColumns; j++)
            value[i][j] = i + j + 1;
    }

    auto matrix1 = Matrix('1', numOfRows, numOfColumns, value);
    std::cout << matrix1;
    return 0;
}
