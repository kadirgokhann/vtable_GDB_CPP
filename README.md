# C++ Code: Virtual Table (VTable) Inspection and Function Pointer Invocation

This C++ code demonstrates how to inspect and interact with the virtual table (VTable) of objects that utilize virtual functions. The code creates two classes, `Base` and `Derived`, where `Derived` inherits from `Base`. The purpose of the code is to:
1. Access and print the VTable of both a `Base` and a `Derived` object.
2. Call functions directly from the VTable using function pointers.

## Key Concepts:
### 1. **Virtual Functions**:
   - The `Base` class contains two virtual functions (`foo` and `bar`) and a non-virtual function (`zoo`).
   - The `Derived` class overrides the `foo` function and adds a new function `bar2`.

### 2. **VTable**:
   - When a class has virtual functions, the compiler creates a VTable, which is a table of pointers to the virtual functions for the class. Each object of such a class has a pointer to the VTable.
   - The code accesses the VTable of both `Base` and `Derived` objects and prints the addresses of the functions stored in the VTable.

### 3. **Key Steps**:
   1. **Object Creation**:
      - Two objects are created: one from the `Base` class and another from the `Derived` class.

   2. **Accessing the VTable**:
      - The VTable for the `Base` object is accessed by casting the object to a pointer to a function pointer (`FuncPtr*`).
      - The start and end addresses of the `Base` object in memory are printed.

   3. **Printing and Invoking Functions from VTable**:
      - The addresses of the virtual functions in the VTable are printed, and the functions are invoked by dereferencing the function pointers.

### 4. **Future Work**:
   - Incomplete handling of the `Derived` object's VTable is present. Additional functionality (such as printing and comparing addresses) may be intended for future implementation.

### 5. **Inline Assembly**:
   - Inline assembly (`asm`) is used to mark the locations of the `Base` and `Derived` class definitions for potential low-level inspection or debugging purposes.

## Expected Output:
- The program prints the addresses of the functions in the VTable for the `Base` object.
- It invokes the virtual functions stored in the VTable and prints their output (`Base::foo()`, `Base::bar()`).
- Output for the `Derived` object's VTable is commented out but could be similarly implemented.

### Example Output:
Base Object VTable: VTable Address: 0x... Function 0 Address: 0x... -> Base::foo() Function 1 Address: 0x... -> Base::bar()

### Summary:
This code provides a way to inspect the VTable of C++ objects with virtual functions, print function addresses, 
and invoke these functions through function pointers. It showcases how virtual function dispatch works behind 
the scenes by manually interacting with the VTable.
