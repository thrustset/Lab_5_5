#pragma once
#include <iostream>

class Matrix {
private:
    char name;
    int numOfRows;
    int numOfColumns;
    int **value;
public:
    Matrix();
    Matrix(char name, int numOfRows, int numOfColumns, int **value);
    Matrix(Matrix const &source);
    ~Matrix();

    auto operator=(Matrix const &source) -> Matrix &;

    friend auto operator<<(std::ostream &os, Matrix const &matrix) -> std::ostream &;

    auto setName(char newName) -> void;
};