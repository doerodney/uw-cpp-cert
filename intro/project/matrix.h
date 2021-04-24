#ifndef INC_MATRIX_H
#define INC_MATRIX_H

#include <cstddef>
#include <memory>
#include <vector>

class Matrix {
public:
    //Matrix() = delete;
    Matrix(std::size_t nRows, std::size_t nCols);
    //Matrix(const Matrix& src) = default;
    //~Matrix() = default;

    double Get(std::size_t row, std::size_t col) const;
    void Set(std::size_t row, std::size_t col, double value);
    std::size_t Size() const { return m_data.size(); }
    std::size_t NRows() const { return m_nRows; }
    std::size_t NCols() const { return m_nCols; }


private:
    std::size_t getIndex(std::size_t row, std::size_t col) const;
    std::size_t m_nRows;
    std::size_t m_nCols;

    std::vector<double> m_data;
};



#endif