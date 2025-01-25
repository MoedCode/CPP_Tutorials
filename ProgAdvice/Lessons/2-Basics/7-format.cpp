#include  "header_b.h"
#include <cstdlib>
#include <cstring>
#include <iomanip>

void intformat()
{
    int i = 0, Page = 1, TotalPages = 10 , Number1 = 20, Number2 = 30;
    // print string and int variable
       printf(" num %0*i \n", 5, 9);
    printf("%i-The page number = %d \n",__LINE__, Page);
    printf("%i-You are in Page %d of %d \n",__LINE__, Page, TotalPages);
    //Width specification
    printf("%i-The page number = %0*d \n",__LINE__, 2, Page);
    printf("%i-The page number = %0*d \n",__LINE__, 3, Page);
    printf("%i-The page number = %0*d \n",__LINE__, 4 , Page);
    printf("%i-The page number = %0*d \n",__LINE__, 500, Page);

    printf("The Result of %d + %d = %d \n", Number1, Number2,
    Number1+ Number2);

}

void FDformat()
{
    printf("  AN-94 %.*f  mm\n", 5, 5.45);
    printf("  M4 %.*f mm\n", 5, 5.6);
    printf(" M7  %.5f mm\n",  7.62);
    /* to print zeros before float or double number
    te number after %0 is number of entire float or double digits
    including zeros after and before   */
    printf(" AWM %08.2f mm\n",  12.7);
}
void charsFormat()
{
    /*number of the spaces and the characters
    so in the case that number after %5c is 5 .will leave 4
    spaces cause the fifth is the character ..

    */
    printf("%*c \n", 5, 'A');
    printf("%5c \n",  'B');
    printf("%5s \n",  "HI!");

}
/*
char  *tableFormat( char ***matrix)
{

    int i = 0, j = 0, len = 0, width = 0, rows = 0, columns = 0;
    static char buffer[5000];
    if(!matrix || !matrix[0] || matrix[1] )
        return 0;
    columns = atoi(matrix[0][0]);
    rows = atoi(matrix[0][1]);
    if (!columns || !rows)
        return 0;
     width = (atoi(matrix[0][2])) ? atoi(matrix[0][2]) :0;
    if(!width)
        {
            for (int i = 1; matrix[1][i]; i++)
            {
                int len = strlen(matrix[1][j]);
                if (len > width)
                    width = len;

            }
        }
    return buffer;
}
*/
char *tableFormat(char*** matrix, char fillChar = ' ') {
    // Check if the matrix or its first row is NULL
    if (!matrix || !matrix[0] || !matrix[0][0]) {
        return nullptr;
    }
    int i = 0, j = 0, k = 0,len = 0, columns = 0, rows = 0, bufferIndex = 0;
    static char buffer[5000];
    // Extract rows and columns from the matrix
    columns = atoi(matrix[0][0]);
    rows = atoi(matrix[0][1]);

    // Calculate the maximum width for each column
    int* colWidths = new int[columns];
    for (j = 0; j < columns; j++) {
        colWidths[j] = 0;
        for (i = 1; matrix[i]; i++) {
            if (matrix[i][j]) {
                len = strlen(matrix[i][j]);
                if (len > colWidths[j]) {
                    colWidths[j] = len;
                }
            }
        }
    }

    // Static buffer to store the formatted table



    // Function to add a line separator to the buffer
    auto addSeparator = [&]() {
        buffer[bufferIndex++] = '+';
        for (j = 0; j < columns; j++) {
            for (k = 0; k < colWidths[j] + 2; k++) {
                buffer[bufferIndex++] = '-';
            }
            buffer[bufferIndex++] = '+';
        }
        buffer[bufferIndex++] = '\n';
    };

    // Add the top separator
    addSeparator();

    // Iterate over rows and columns
    for (i = 1; matrix[i]; i++) {
        buffer[bufferIndex++] = '|';
        for (j = 0; j < columns; j++) {
            buffer[bufferIndex++] = ' ';

            // Center the text in the cell
            if (matrix[i][j]) {
                int len = strlen(matrix[i][j]);
                int padding = (colWidths[j] - len) / 2;
                for (int k = 0; k < padding; k++) {
                    buffer[bufferIndex++] = fillChar;
                }
                strcpy(&buffer[bufferIndex], matrix[i][j]);
                bufferIndex += len;
                for (int k = 0; k < colWidths[j] - len - padding; k++) {
                    buffer[bufferIndex++] = fillChar;
                }
            } else {
                for (int k = 0; k < colWidths[j]; k++) {
                    buffer[bufferIndex++] = fillChar;
                }
            }

            buffer[bufferIndex++] = ' ';
            buffer[bufferIndex++] = '|';
        }
        buffer[bufferIndex++] = '\n';

        // Add a separator after each row
        addSeparator();
    }

    // Null-terminate the buffer
    buffer[bufferIndex] = '\0';

    // Clean up
    delete[] colWidths;

    return buffer;
}
