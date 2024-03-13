/*
Header for tinydog.pgm - the file used in this example
    P2
    # Created by GIMP version 2.10.34 PNM plug-in
    25 19
    255
*/
#include <stdlib.h>
/* Number of lines in <image>.pgm header */
#define header_lines 4;
/* "Hard coding" image header values into sizing and values to be written out.
    Change this to match the values in your image */
/* Note: Image Type P2 will be written directly in cout */
#define image_columns 25
#define image_rows 19
#define  MaxGrayComponentValue 255;
#define carriage_return '\n'

/* Here's the image array you will read into */
int image_in[image_rows+ 1][image_columns+ 1];
/* Here's the image you will write to */
int image_out[image_rows + 1][image_columns+ 1];

/*here's your iterators to scan through the image*/
int i, j;

/* End of Global variables Shared Memory*/

void read_image_header()
 {
/* this procedure reads the four header lines and throw them away*/
    char buffer[header_lines+1][80]; /* buffer for storing input line */
    char c;
    int m;
    for (m = 1; m <= header_lines; ++m)
    do
    {
      cin >> c;  /* input next character */
    } while (c != carriage_return);
 }

void read_image_values()
  {/* read image into array */
    for(i = 1; i <= image_rows; i++)
        for( j = 1; j <= image_columns; j++)
         cin >> image_in[i][j];
   }

/* Your work smoothing function */

 int smooth_pixel(int p, int q)
 {
 int sum = 0;
 int count = 0;
 int windowSize = 3;
 int centerX = windowSize / 2;
 int centerY = windowSize / 2;
 for (i = -centerY; i <= centerY; i++)
 {
        for (j = -centerX; j <= centerX; j++) 
        {
            /* Check if the neighbor pixel is within bounds*/
            if (p + i >= 1 && p + i <= image_rows && q + j >= 1 && q + j <= image_columns) 
            {
                sum += image_in[p + i][q + j];
                count++;
            }
        }
 }
     int smoothedValue = sum / count;
         return smoothedValue;
}



void write_image_to_file()
 {
    int output_row_width = 10;
    int OUTPUT_ROW_COUNTER = 1;
    cout << "P2" << ENDL;
    cout << image_columns << " " << image_rows << ENDL;
    cout << MaxGrayComponentValue << ENDL;
    /*this loop write to the file in a manner acceptable to cstar 10 values per Row */
    for(i = 1; i <= image_rows; i++)
    {
      for ( j = 1; j <= image_columns; j++)
      {
        if (OUTPUT_ROW_COUNTER == output_row_width)
        {
          cout << ENDL;
          OUTPUT_ROW_COUNTER = 1;
        }
        cout << image_out[i][j] << " ";
        OUTPUT_ROW_COUNTER = OUTPUT_ROW_COUNTER + 1;
      }
    }
  }
main()
{

read_image_header();

read_image_values();

  /*  Your work - create the logic to process the image array_in
     Outer for loop is row counter.*/

for(i = 1; i <= image_rows; i++)
     {
       forall j = 1 to image_columns do
       {
         /*Your work: Design the Inner forall loop logic:
          Examine the image_in[i][j] value .
           if (image_in[i][j] is inside the smoothing perimeter) call smooth_pixel and write retruned result to image_out[i][j],
           else
           the pixel is outside the perimeter is on the edge of the image)
           write the pixel (unchanged) to image_out array */

           /*next line is for your initial testing. It justs assigns the image_in pixel to image_out. Remove it when you add your own logic*/
           image_out[i][j] = image_in[i][j];
        }
      }
write_image_to_file();

}
