#include <iostream>
#include <iomanip>
#include <cstring>

char* tableFormat(char*** matrix, char fillChar = ' ') {
    // Check if the matrix or its first row is NULL
    if (!matrix || !matrix[0] || !matrix[0][0]) {
        return nullptr;
    }

    // Extract rows and columns from the matrix
    int columns = atoi(matrix[0][0]);
    int rows = atoi(matrix[0][1]);

    // Calculate the maximum width for each column
    int* colWidths = new int[columns];
    for (int j = 0; j < columns; j++) {
        colWidths[j] = 0;
        for (int i = 1; matrix[i]; i++) {
            if (matrix[i][j]) {
                int len = strlen(matrix[i][j]);
                if (len > colWidths[j]) {
                    colWidths[j] = len;
                }
            }
        }
    }

    // Static buffer to store the formatted table
    static char buffer[5000];
    int bufferIndex = 0;

    // Function to add a line separator to the buffer
    auto addSeparator = [&]() {
        buffer[bufferIndex++] = '+';
        for (int j = 0; j < columns; j++) {
            for (int k = 0; k < colWidths[j] + 2; k++) {
                buffer[bufferIndex++] = '-';
            }
            buffer[bufferIndex++] = '+';
        }
        buffer[bufferIndex++] = '\n';
    };

    // Add the top separator
    addSeparator();

    // Iterate over rows and columns
    for (int i = 1; matrix[i]; i++) {
        buffer[bufferIndex++] = '|';
        for (int j = 0; j < columns; j++) {
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

int main() {
    // Example matrix
    char *header[] = {"3", "3", nullptr}; // Columns, Rows, Width (optional)
    char *row1[] = {"Code", "Name", "Mark", nullptr};
    char *row2[] = {"C101", "Introduction to Programming 1", "95", nullptr};
    char *row3[] = {"C102", "Computer Hardware", "88", nullptr};
    char *row4[] = {"C1035243", "Network", "75", nullptr};
    char **matrix[] = {header, row1, row2, row3, row4, nullptr};

    // Generate the table with a custom fill character
    char* table = tableFormat(matrix, ' ');
    if (table) {
        std::cout << table;
    } else {
        std::cerr << "Error: Invalid matrix input." << std::endl;
    }

    return 0;
}