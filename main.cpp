#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <vector>
#include "Matrix.h"
using namespace std;
void genRdMatrixDat(int n);
void PrintStartMenu();
void PrtintDatamenu();

int main(){
//main will show the menu with options for given inputs, as well as creating data sets for testing cases and such
//each algorithm will have it's own class
//TODO: make class for each algorithm, wrap up matrix class

//genRdMatrixDat(4);
printStartMenu();
PrintDatMenu();

}

void printStartMenu(){
    cout << "Analysis of Matrix Multiplication Alogrithms";
    cout <<"-----------------------------------------------"<<endl;
    cout << "[1]. Naive Matrix Multiplication"<< endl;
    cout << "[2]. Divide and Conquer Matrix Multiplication"<< endl;
    cout << "[3]. Strassen's Matrix Multiplication"<< endl;
}

void PrintDatMenu(){
    cout << "Select data input method.";
    cout <<"------------------------------";
    cout <<"[1]. Use randomly generated data using Mersenne's Twister"<< endl;
    cout <<"[2]. Input Matrix A and matrix B from file"<< endl;
    cout <<"[3]. Input matrix A row-wise, followed by matrix B"<< endl;
}

void genRdMatrixDat(int n) {
    random_device rd;
    mt19937 gen(rd()); 
    uniform_int_distribution<int> dist(-100, 100);
    
    // File names
    ofstream fileA("matrixDatA.txt");
    ofstream fileB("matrixDatB.txt");
    
    if (!fileA || !fileB) {
        cerr << "Error opening output files!" << endl;
        return;
    }

    fileA << n << endl;
    fileB << n << endl;
    
    // Write matrix data
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fileA << dist(gen) << " ";
            fileB << dist(gen) << " ";
        }
        fileA << endl;
        fileB << endl;
    }
    
    // Close files
    fileA.close();
    fileB.close();
}

