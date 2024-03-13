#include<stdlib.h>
#define m 5;
#define n 5;
main()
{
    int i,j,k,l;
    float img[m][n], new_img[m][n]; /* declaring 2D-array */
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            img[i][j]=rand() % 256; /* storing float values from 0-255 into 2D-array*/
        }
    }
    cout.precision(4);
    cout<<"Pixels of Image are:\n"; 
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout<<img[i][j]<<" "; /* printing the pixel values before smoothing */
        }
        cout<<"\n";
    }
    cout<<"\n";
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == 0 || i == m-1 || j == 0 || j == n-1) 
            {
                new_img[i][j] = img[i][j]; /* assigning the outer four boundary values as it is to new 2D-array */
            }
            else 
            {
                float sum = 0;
                int count = 0;
                for( k = i-1; k <= i+1; k++)
                {
                    forall l = j-1 to j+1 do /* using forall statement to assign different processors */
                    {
                        sum = sum + img[k][l];
                        count++;
                    }
                }
                float avg = sum / count;
                new_img[i][j] = avg; /* replacing the pixel value with the avg value of all it's neighbors */
            }
        }
    }
    cout<<"Pixels of Image after smoothing are:\n";
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            cout<<new_img[i][j]<<" "; /* printing the pixel values after smoothing is applied */
        }
        cout<<"\n";
    }
    return 0;
}