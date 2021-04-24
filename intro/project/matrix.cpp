#include "matrix.h"

Matrix::Matrix(std::size_t nRows, std::size_t nCols) :
m_nRows(nRows), m_nCols(nCols), 
m_data(std::vector<double>(nRows * nCols)) {

}

std::size_t Matrix::getIndex(std::size_t row, std::size_t col) const {
    auto r = row < m_nRows ? row : m_nRows - 1;
    auto c = col < m_nCols ? col : m_nCols - 1;
    auto i = r * m_nCols + c;
    return i;
}

double Matrix::Get(std::size_t row, std::size_t col) const {
    auto idx = this->getIndex(row, col);
    return m_data[idx];
}


void Matrix::Set(std::size_t row, std::size_t col, double value) {
    auto idx = this->getIndex(row, col);
    m_data[idx] = value;
}