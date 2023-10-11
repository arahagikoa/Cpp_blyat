#include <iostream>
#include <vector>
int main() {
    int rows, cols;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    // Create a 2D array (matrix)
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));

    // Initialize the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << "Enter the element at position (" << i << ", " << j << "): ";
            std::cin >> matrix[i][j];
        }
    }

    // Print the matrix
    std::cout << "Matrix:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}