#include <iostream>
#include <vector>
#include <iomanip>

const unsigned int PRECISION = 10;

class Matrix 
{
    public:
        Matrix();
        Matrix(Matrix& a);
        Matrix(int n, bool isIdentity=false);
        void set(int i, int j, double val);
        double get(int i, int j);
        int getSize();
        friend std::istream& operator>>(std::istream& is, Matrix& matrix);
        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
    private:
        int n;
        std::vector<std::vector<double>> data;
};

Matrix::Matrix() : n(0) {};

Matrix::Matrix(Matrix& a) : n(a.getSize()) 
{
    this->data = a.data;
}

Matrix::Matrix(int n, bool isIdentity) : n(n)
{
    this->data = std::vector<std::vector<double>>(n, std::vector<double>(n, 0));
    if (isIdentity)
    {
        for (int i = 0; i < n; ++i)
        {
            data[i][i] = 1;
        }
    }
}

void Matrix::set(int i, int j, double val)
{
    this->data[i][j] = val;
}

double Matrix::get(int i, int j)
{
    return this->data[i][j];
}

int Matrix::getSize()
{
    return this->n;
}

class LU
{
    public:
        LU(Matrix& a);
        Matrix& getL();
        Matrix& getU();
    private:
        Matrix L;
        Matrix U;
};

LU::LU(Matrix& a)
{
    double current = 0;
    L = Matrix(a.getSize(), true);
    U = Matrix(a.getSize());
    for (int i = 0; i < a.getSize(); ++i)
    {
        U.set(0, i, a.get(0, i));
    }
    for (int i = 1; i < a.getSize(); ++i) 
    {
        for (int j = 0; j < a.getSize(); ++j)
        {
            if (i > j) {
                current = a.get(i, j);
                for (int k = 0; k < j; ++k)
                {
                    current -= L.get(i, k) * U.get(k, j);
                }
                current /= U.get(j, j);
                L.set(i, j, current);
            } else {
                current = a.get(i, j);
                for (int k = 0; k < i; ++k)
                {
                    current -= L.get(i, k) * U.get(k, j);
                }
                U.set(i, j, current);
            }
        }
    }
}

Matrix& LU::getL()
{
    return this->L;
}
Matrix& LU::getU()
{
    return this->U;
}

std::istream& operator>>(std::istream& is, Matrix& matrix)
{
    for (int i = 0; i < matrix.n; ++i)
    {
        for (int j = 0; j < matrix.n; ++j)
        {
            is >> matrix.data[i][j];
        }
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
{
    for (int i = 0; i < matrix.n; ++i)
    {
        for (int j = 0; j < matrix.n; ++j)
        {
            os << std::setprecision(PRECISION) << matrix.data[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}

int main()
{
    int n;
    std::cin >> n;
    Matrix A(n);
    std::cin >> A;
    LU ALU(A);
    std::cout << "L:\n";
    std::cout << ALU.getL();
    std::cout << "U:\n";
    std::cout << ALU.getU();
    return 0;
}
