#include <iostream>
#include <vector>

void luDecomposition(std::vector<std::vector<double>>& mat, int n) {
    std::vector<std::vector<double>> lower(n, std::vector<double>(n, 0.0));
    std::vector<std::vector<double>> upper(n, std::vector<double>(n, 0.0));

    for (int i = 0; i < n; i++) {
        for (int k = i; k < n; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++)
                sum += (lower[i][j] * upper[j][k]);

            upper[i][k] = mat[i][k] - sum;
        }

        for (int k = i; k < n; k++) {
            if (i == k)
                lower[i][i] = 1;
            else {
                double sum = 0;
                for (int j = 0; j < i; j++)
                    sum += (lower[k][j] * upper[j][i]);

                lower[k][i] = (mat[k][i] - sum) / upper[i][i];
            }
        }
    }

    std::cout << "Lower Triangular Matrix" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            std::cout << lower[i][j] << " ";
        std::cout << std::endl;
    }

    std::cout << "Upper Triangular Matrix" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            std::cout << upper[i][j] << " ";
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<double>> mat = { {2, -1, -2}, {-4, 6, 3}, {-4, -2, 8} };
    luDecomposition(mat, 3);
    return 0;
}
