#include <stdlib.h>

#define n 5

/* Function to apply Gaussian blur to a pixel*/
float applyGaussianBlur(int x, int y, float im[][n + 2]) {
    float kernel[3][3] = {
        {1.0 / 16, 2.0 / 16, 1.0 / 16},
        {2.0 / 16, 4.0 / 16, 2.0 / 16},
        {1.0 / 16, 2.0 / 16, 1.0 / 16}
    };

    float sum = 0.0;
    for (int ky = -1; ky <= 1; ky++) {
        for (int kx = -1; kx <= 1; kx++) {
            sum += im[y + ky][x + kx] * kernel[ky + 1][kx + 1];
        }
    }
    return sum;
}

int main() {
    float im[n + 2][n + 2];
    float te[n + 2][n + 2];

    /* Prompt the user for input and output file paths*/
    string inputFileName, outputFileName;
    cout << "Enter the input PGM file name: ";
    cin >> inputFileName;
    cout << "Enter the output PGM file name: ";
    cin >> outputFileName;

    /* Open the input PGM file*/
    ifstream inputFile(inputFileName.c_str());
    if (!inputFile) {
        cerr << "Error opening input file" << endl;
        return 1;
    }

    /* Read the PGM header*/
    string magic;
    int width, height, maxVal;
    inputFile >> magic >> width >> height >> maxVal;

    if (magic != "P2" || width != n || height != n || maxVal != 255) {
        cerr << "Invalid PGM format or dimensions" << endl;
        return 1;
    }

    /* Read pixel values into the im array*/
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            inputFile >> im[i][j];
        }
    }
    inputFile.close();

    /* Apply Gaussian blur and store the result in te array*/
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            te[i][j] = applyGaussianBlur(j, i, im);
        }
    }

    /* Open the output PGM file*/
    ofstream outputFile(outputFileName.c_str());
    if (!outputFile) {
        cerr << "Error opening output file" << endl;
        return 1;
    }

    /* Write the PGM header to the output file*/
    outputFile << "P2" << endl;
    outputFile << n << " " << n << endl;
    outputFile << maxVal << endl;

    /* Write the smoothed image pixel values to the output file*/
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            outputFile << te[i][j] << " ";
        }
        outputFile << endl;
    }

    outputFile.close();

    cout << "Image smoothing completed. Smoothed image saved as " << outputFileName << endl;

    return 0;
}