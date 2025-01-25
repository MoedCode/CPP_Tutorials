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
#include <iostream>
#include <cstring>
#include <cstdlib>

/**
 * tableFormat - Formats a matrix into a table string
 * @matrix: A 3D array where the first row defines dimensions (columns, rows)
 *          and subsequent rows contain the table content.
 * @fillChar: The character used to fill empty spaces in cells (default: space).
 *
 * Return: A pointer to a static buffer containing the formatted table string,
 *         or NULL if the input matrix is invalid.
 *
 * The function expects the input matrix to have dimensions defined in the first row:
 * - matrix[0][0]: Number of columns (as string)
 * - matrix[0][1]: Number of rows (as string)
 * The table is formatted with centered text in each cell and separators using '+', '-' and '|'.
 */
char *tableFormat(char ***matrix, char fillChar = ' ')
{
    int i, j, k, len, padding, columns, rows, bufferIndex;
    int *colWidths;
    static char buffer[5000];

    /* Initialize variables */
    i = j = k = len = padding = bufferIndex = 0;
    colWidths = NULL;

    /* Validate input matrix */
    if (!matrix || !matrix[0] || !matrix[0][0] || !matrix[0][1])
        return (nullptr);

    /* Extract rows and columns from the matrix */
    columns = atoi(matrix[0][0]);
    rows = atoi(matrix[0][1]);
    if (columns <= 0 || rows <= 0)
        return (nullptr);

    /* Allocate memory for column widths */
    colWidths = new int[columns];
    if (!colWidths)
        return (nullptr);

    /* Calculate the maximum width for each column */
    for (j = 0; j < columns; ++j)
    {
        colWidths[j] = 0;
        for (i = 1; i <= rows; ++i)
        {
            if (matrix[i][j])
            {
                len = strlen(matrix[i][j]);
                if (len > colWidths[j])
                    colWidths[j] = len;
            }
        }
    }

    /* Helper function to add a separator line to the buffer */
    auto addSeparator = [&]() {
        buffer[bufferIndex++] = '+';
        for (j = 0; j < columns; ++j)
        {
            for (k = 0; k < colWidths[j] + 2; ++k)
                buffer[bufferIndex++] = '-';
            buffer[bufferIndex++] = '+';
        }
        buffer[bufferIndex++] = '\n';
    };

    /* Add the top separator */
    addSeparator();

    /* Format the table content row by row */
    for (i = 1; i <= rows; ++i)
    {
        buffer[bufferIndex++] = '|';
        for (j = 0; j < columns; ++j)
        {
            buffer[bufferIndex++] = ' ';

            /* Center the text in the cell */
            if (matrix[i][j])
            {
                len = strlen(matrix[i][j]);
                padding = (colWidths[j] - len) / 2;
                for (k = 0; k < padding; ++k)
                    buffer[bufferIndex++] = fillChar;
                strcpy(&buffer[bufferIndex], matrix[i][j]);
                bufferIndex += len;
                for (k = 0; k < colWidths[j] - len - padding; ++k)
                    buffer[bufferIndex++] = fillChar;
            }
            else
            {
                /* Fill empty cell with the fillChar */
                for (k = 0; k < colWidths[j]; ++k)
                    buffer[bufferIndex++] = fillChar;
            }

            buffer[bufferIndex++] = ' ';
            buffer[bufferIndex++] = '|';
        }
        buffer[bufferIndex++] = '\n';

        /* Add a separator after each row */
        addSeparator();
    }

    /* Null-terminate the buffer */
    buffer[bufferIndex] = '\0';

    /* Free dynamically allocated memory */
    delete[] colWidths;

    return (buffer);
}

