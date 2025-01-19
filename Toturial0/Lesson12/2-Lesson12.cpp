#include <iostream>
#include <string>
#include <vector>

void drawH(int height, int width, const std::string& symbol) {
    if (height < 3 || width < (int)symbol.size()) {
        std::cerr << "Invalid dimensions." << std::endl;
        return;
    }

    std::string space(width - symbol.size(), ' ');
    std::string middleRow(width, symbol[0]); // Adjust for multi-character strings

    for (int i = 0; i < height; ++i) {
        if (i == height / 2) {
            // Print the middle row
            for (int j = 0; j < width / (int)symbol.size(); ++j)
                std::cout << symbol;
        } else {
            // Print the side rows
            std::cout << symbol << space << symbol;
        }
        std::cout << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <height> <width> <symbol>" << std::endl;
        return 1;
    }

    int height = std::stoi(argv[1]);
    int width = std::stoi(argv[2]);
    std::string symbol = argv[3];

    drawH(height, width, symbol);

    return 0;
}
