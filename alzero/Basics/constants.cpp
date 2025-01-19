#include <stdio.h>

struct KeyValuePair {
    const char *key;
    const char *value;
};

int main() {
    // Define a constant KeyValuePair
    struct KeyValuePair pair = {"name", "mohamed"};
    // Print the key-value pair
    printf("%s: %s\n", pair.key, pair.value);
    pair.value = "mizo";

    printf("%s: %s\n", pair.key, pair.value);

    // Attempting to modify the pair will result in a compiler error
    // pair.key = "age";  // Uncommenting this will cause an error
    // pair.value = "33"; // Uncommenting this will cause an error

    return 0;
}
