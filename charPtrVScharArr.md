The issue arises because `size()` in C++ is not directly applicable to a `const char*`. Here's a breakdown of what's happening:

---

### **Why `size()` Doesn't Work with `const char*`**

1. **`std::size()` Function**:
   - The `std::size()` function, introduced in C++17, works with containers (like `std::vector`, `std::array`, and `std::string`) and fixed-size arrays (`char msg[]`), which have a defined size at compile time.
   - `const char*` is a pointer, and pointers do not inherently store size information. Instead, they point to a memory location where the string ends with a null terminator (`\0`).

   When you try to call `size(msg1)`, where `msg1` is `const char*`, the compiler doesn't find a valid `size()` function for this type and throws an error.

2. **Why It Works with `char msg[]`**:
   - `char msg[]` is a fixed-size array, and the compiler knows its size at compile time. Therefore, `std::size(msg)` can compute the size of the array correctly.

---

### **How to Get the Size of a C-Style String (`const char*`)**
You can use `strlen()` from `<cstring>` for C-style strings (`const char*`) because it calculates the length by traversing the string until it encounters the null terminator (`\0`).

Here's how you can fix your code:

---

### **Fixed Code**
```cpp
#include "./header_b.h"
#include <unistd.h>
#include <cstring> // For strlen

using namespace printlib;

int main(void)
{
    char msg0[] = "Set A New Password";
    const char *msg1 = "Set A New Password";

    // Use std::size for the array
    write(1, msg0, std::size(msg0));

    // Use strlen for the pointer
    write(1, msg1, strlen(msg1));

    return 0;
}
```

---

### **Explanation of the Fix**
1. **`std::size(msg0)`**:
   - Works for fixed-size arrays like `char msg0[]`.

2. **`strlen(msg1)`**:
   - Computes the length of the null-terminated C-style string that `msg1` points to.

---

### **Additional Notes**
- **Avoid Mixing `std::string` and `const char*`**:
  If possible, use `std::string` instead of `const char*`. `std::string` provides the `size()` method directly.

- If you convert your `const char*` to `std::string`:
  ```cpp
  std::string msg2 = "Set A New Password";
  write(1, msg2.c_str(), msg2.size());
  ```

---

This approach will resolve the issue and make your code cleaner. Let me know if you need further clarification!

You're absolutely correct that the string value for `char* msg = "message";` is known at compile time. However, there's an important distinction between the behavior of **array declarations** (`char msg[] = "message";`) and **pointer declarations** (`char* msg = "message";`) in C++.

---

### Key Difference: Arrays vs. Pointers
#### 1. **`char msg[] = "message";`**
- When you declare a string this way, you're creating a **fixed-size array**.
- The compiler allocates memory for the array and its null terminator (`\0`), so the size is determined at compile time.
- You can use `std::size()` because it works on fixed-size arrays, as their size is embedded in the type.

  Example:
  ```cpp
  char msg[] = "message";
  std::cout << std::size(msg); // Output: 8 (7 characters + null terminator)
  ```

#### 2. **`char* msg = "message";`**
- When you declare a string this way, you're creating a **pointer** to a string literal stored in a read-only section of memory.
- The compiler knows where the string starts, but it doesn't embed the size information in the pointer type.
- As a result, `std::size()` cannot determine the size because it's just a pointer to a memory location — the size isn't inherently part of the type.

  Example:
  ```cpp
  char* msg = "message";
  std::cout << std::size(msg); // Compile-time error
  ```

---

### Why Doesn't the Compiler Infer the Size for `char*`?
The primary reason is **flexibility**:
1. **Pointer Semantics**:
   - A `char*` could point to a string literal, dynamically allocated memory, or even just part of another array. The compiler cannot guarantee that the pointer always points to a null-terminated string or even a valid memory block.

2. **Separation of Data and Metadata**:
   - C++ pointers (`char*`) only store the address of the first character. They don't carry metadata like size or bounds.

3. **String Literals and Undefined Behavior**:
   - String literals are stored in a read-only section of memory. If you were to modify `*msg`, it would lead to undefined behavior. Because `char* msg` is more abstract than `char msg[]`, the compiler doesn't attach size information to it.

---

### Conclusion: Why the Behavior Is Different
The behavior isn't because the compiler doesn't *know* the size of `"message"` when using `char*`. It's because the pointer type (`char*`) is intentionally designed to represent an address without embedding size or bounds information.

If you need size information for a `char*`, use `strlen()` from `<cstring>`. If you want size embedded, prefer fixed-size arrays (`char msg[]`) or `std::string` for safer and more modern string handling.

Let me know if you'd like more clarity or further discussion on this! 😊