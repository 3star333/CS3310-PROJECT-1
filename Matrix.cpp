#include "Matrix.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

Matrix::Matrix (int size) : n(size), matrix(size, vector<int>(size, 0)) {

}
int Matrix::getSize() const {
    return n;
}

//populate matrix using data from file, format is 1st line = n (n x n size), rest of the lines are matrix data separated by whitespace 
void Matrix::populateMatrix(const string& filename) {
    ifstream mxdat(filename);
    if (!mxdat) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    mxdat >> n;  // Read matrix size
    matrix.assign(n, vector<int>(n, 0));  // Resize matrix to match file data

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!(mxdat >> matrix[i][j])) { 
                cerr << "Error: Invalid matrix format in file!" << endl;
                return;
            }
        }
    }

    mxdat.close();
}

void Matrix::printMatrix() const {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}