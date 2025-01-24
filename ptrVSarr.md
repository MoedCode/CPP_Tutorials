```cpp
int main(void)
{
    char msg0[] = "Set A  New Password";
    const char *msg1 = "Set A  New Password";
    int numbers[]{1, 2, 3};
    int *numptr = &numbers[0];

    cout << "chars array size: "<<sizeof(msg0) << endl;
    cout << "chars pointer size: "<<sizeof(msg1) << endl;
    cout << "numbers array size: " << sizeof(numbers) << endl;
    cout << "numbers pointers size: " << sizeof(numptr) << endl;
    // string PWD = validate_PWD();
   return 0;

}
```
The warnings arise because of how C++ treats string literals and the type of pointers or arrays you're trying to use. Let's break this down case by case:

---

### 1. **`char *p = "some string";` (Warning)**

- A **string literal** like `"some string"` in C++ is of type `const char[]`. It represents an array of `const char`, and it is stored in a read-only section of memory.
- Assigning it to a `char*` (a non-const pointer) is problematic because it allows modifications to the string, but attempting to modify a string literal results in **undefined behavior**.
- C++ compilers issue a warning to indicate that you're implicitly discarding the `const` qualifier.

**Why the warning?**
Because you're assigning a `const char[]` to a `char*`, which violates type safety.

---

### 2. **`const char *p = "some string";` (No Warning)**

- Here, you're correctly declaring the pointer as `const char*`, which reflects the fact that the string literal is read-only.
- The compiler sees this as safe because you're promising not to modify the string.

**Why no warning?**
Because the `const` qualifier matches the read-only nature of string literals.

---

### 3. **`char p[] = "some string";` (No Warning)**

- Here, you're creating an array `p` on the stack, initialized with a **copy** of the string literal.
- The array `p` is writable, so there are no issues or warnings. You can modify the contents of `p` without affecting the original string literal.

**Why no warning?**
Because this creates a separate, writable copy of the string literal in memory, and modifying it is safe.

---

### Key Points:

- String literals are **read-only** in C++.
- Assigning them to `char*` is discouraged because it suggests you can modify the string, but doing so is undefined behavior.
- Using `const char*` respects the immutability of string literals.
- Using `char[]` creates a writable copy, which avoids the issue entirely.

---

### Practical Advice:
- Always use `const char*` when working with string literals if you don't intend to modify them.
- If you need to modify the string, create a writable copy using `char[]` or `std::string`.

Let me know if you'd like further clarification! 😊
