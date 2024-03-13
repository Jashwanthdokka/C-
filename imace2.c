#include<stdlib.h>

#define n 5

float im[n + 2][n + 2];
float te[n + 2][n + 2];
int i, j, k;
int m,l;

main()
{
    cout << "Original image:" << endl;
    for (k = 0; k < n; k++)
    {
        for (m = 0; m < n; m++)
        {
            cin >> im[k][m];
        }
    }

    /* Copy im to te*/
    for (i = 0; i < n + 2; i++)
    {
        for (j = 0; j < n + 2; j++)
        {
            te[i][j] = im[i][j];
        }
    }

    for (i = 1; i <= n - 2; i++)
    {
        for (j = 1; j <= n - 2; j++)
        {
            te[i][j] = (im[i][j] + im[i][j - 1] + im[i][j + 1] + im[i - 1][j - 1] + im[i - 1][j] + im[i + 1][j] + im[i + 1][j + 1] + im[i + 1][j - 1] + im[i - 1][j + 1]) / 9;
        }
    }

    cout << "Smoothing image" << endl;
    for (k = 0; k < n; k++)
    {
        for (l = 0; l < n; l++)
        {
            cout.precision(4);
            cout << te[k][l] << " ";
        }
        cout << endl;
    }

    return 0;
}
