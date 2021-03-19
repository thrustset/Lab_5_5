#include <iostream>
#include "matrix.hpp"

Matrix::Matrix() :
    name{0},
    numOfRows{0},
    numOfColumns{0},
    value{nullptr}
{}

Matrix::Matrix(char name, int numOfRows, int numOfColumns, int **newValue) :
    name{name},
    numOfRows{numOfRows},
    numOfColumns{numOfColumns},
    value{new int*[numOfRows]}
{
    for(int i = 0; i < this->numOfRows; i++) {
        this->value[i] = new int[this->numOfColumns];
        for(int j = 0; j < this->numOfColumns; j++)
            this->value[i][j] = newValue[i][j];
    }
}

Matrix::Matrix(Matrix const &source) :
    name{source.name},
    numOfRows{source.numOfRows},
    numOfColumns{source.numOfColumns},
    value{new int*[source.numOfRows]}
{
    for(int i = 0; i < numOfRows; i++) {
        value[i] = new int[numOfColumns];
        for(int j = 0; j < numOfColumns; j++)
            value[i][j] = source.value[i][j];
    }
}

Matrix::~Matrix() {
    for(int i = 0; i < numOfRows; i++)
        delete [] value[i];
    delete [] value;
}

auto Matrix::operator=(Matrix const &source) -> Matrix & {
    name = source.name;
    numOfRows = source.numOfRows;
    numOfColumns = source.numOfColumns;

    for(int i = 0; i < numOfRows; i++)
        delete [] value[i];
    delete [] value;

    value = new int*[numOfRows];
    for(int i = 0; i < numOfRows; i++) {
        value[i] = new int[numOfColumns];
        for(int j = 0; j < numOfColumns; j++)
            value[i][j] = source.value[i][j];
    }

    return *this;
}

auto operator<<(std::ostream &os, Matrix const &matrix) -> std::ostream & {
    os << "Matrix " << matrix.name << ":\n";
    for(int i = 0; i < matrix.numOfRows; i++) {
        std::cout << "\t";
        for(int j = 0; j < matrix.numOfColumns; j++)
            std::cout << matrix.value[i][j] << " ";
        std::cout << "\n";
    }
    return os;
}

auto Matrix::setName(char newName) -> void {
    name = newName;
}