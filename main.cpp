#include <iostream>
#include <fstream>

const int MAX_SIZE = 100;
//max size of the square matrices defined as a static constant 100 

// functional prototypes
void readMatrix(int matrixa[MAX_SIZE][MAX_SIZE], int matrixb[MAX_SIZE][MAX_SIZE], int& size, const std::string& filename);
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size);
void addMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void multiplyMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void subtractMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);

int main() {
    std::cout << "Tejaswi Nimmagadda" << std::endl;
    std::cout << "Lab #6: Matrix manipulation" << std::endl;
    std::cout << "\n";

    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int size;

    readMatrix(matrixA, matrixB, size, "matrix_input.txt");

    std::cout << "Matrix A:" << std::endl;
    printMatrix(matrixA, size);
    std::cout << "\n";

    std::cout << "Matrix B:" << std::endl;
    printMatrix(matrixB, size);
    std::cout << "\n";

    addMatrices(matrixA, matrixB, result, size);
    std::cout << "Matrix Sum (A + B):" << std::endl;
    printMatrix(result, size);
    std::cout << "\n";
  
    multiplyMatrices(matrixA, matrixB, result, size);
    std::cout << "Matrix Product (A * B):" << std::endl;
    printMatrix(result, size);
    std::cout << "\n";
  
    subtractMatrices(matrixA, matrixB, result, size);
    std::cout << "Matrix Difference (A - B):" << std::endl;
    printMatrix(result, size);

    return 0;
}

// reads matrix data from a specified file and stores it in a 2D array
void readMatrix(int matrixa[MAX_SIZE][MAX_SIZE], int matrixb[MAX_SIZE][MAX_SIZE], int& size, const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> size;
        for (int i = 0; i < 2*size; i++) {
          if (i < size) {
            for (int j = 0; j < size; j++) {
                file >> matrixa[i][j];
            }
          }
          else{
             for (int j = 0; j < size; j++) {
               file >> matrixb[i-size][j];
             }
          }
        }
        file.close();
    } else {
        std::cerr << "Unable to open file! " << filename << std::endl;
    }
}

// displays a matrix in a user-friendly format
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << "  " << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

// adds two matrices and stores the result in a third matrix
void addMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// multiplies two matrices and places the result in a third matrix
void multiplyMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

// subtracts one matrix from another and stores the result in a third matrix
void subtractMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}
