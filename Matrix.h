#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <iomanip>
#include <random>
#include <vector>
using namespace std;

class Matrix{
    private:
    int n;
    vector<vector<int>> matrix;

    public:
    Matrix(int size);
    static Matrix identity(int size);
    static Matrix zero(int size);
    int getSize() const {return n;}
    void printMatrix() const;
    void populateMatrix(const string& filename);
    Matrix naiveMult(const Matrix& matrixB) const;
    Matrix divConqMult(const Matrix& matrixB) const;
    Matrix strassenMult(const Matrix& matrixB) const;










    //void userInMatrix(cin)


};