#include <iostream>

void MultiplyWithOutAMP() {
    int aMatrix[3][3] = {{-5,3, 0}, {4, 7,0}, {0, 0,0},};
    int bMatrix[3][3] = {{9,0, 0}, {2, -5,0}, {0, 0,0},};
    int product[3][3] = {{-0,0, 0}, {0, 0,0}, {0, 0,0},};

    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 2; col++) {
            // Multiply the row of A by the column of B to get the row, column of product.
            for (int inner = 0; inner < 2; inner++) {
                product[row][col] += aMatrix[row][inner] * bMatrix[inner][col];
            }
            std::cout << product[row][col] << "  ";
        }
        std::cout << "\n";
    }
}

int main() {
    MultiplyWithOutAMP();
    getchar();
}
