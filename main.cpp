#include <iostream>

typedef void (*FuncPtr)();

asm("base:");
class Base {
public:
    virtual void foo() { std::cout << "Base::foo()\n"; }
    virtual void bar() { std::cout << "Base::bar()\n"; }
            void zoo() { std::cout << "Base::zoo()\n";}
};
asm("baseEnd:");
asm("derived:");
class Derived : public Base {
public:
    void foo () override { std::cout << "Derived::func1\n"; }
    void bar2() { std::cout << "Derived::func2\n"; }

};
asm("derivedEnd:");
int main()
{
    Base baseObj;
    Derived derivedObj;

    std::cout << "Base Object VTable:" << std::endl;
    FuncPtr* vtable = *(FuncPtr**)&baseObj;

    std::cout << "VTable Address    : " << (void*)vtable << std::endl;
    char* start_address = reinterpret_cast<char*>(&baseObj);
    char* end_address = start_address + sizeof(Base) - 1;

    std::cout << "Start address of obj: " << static_cast<void*>(start_address) << std::endl;
    std::cout << "End address of obj: " << static_cast<void*>(end_address) << std::endl;

    // Print the function pointers in the vtable
    for (int i = 0; vtable[i] != nullptr; ++i) {
        std::cout << "Function " << i << " Address: " << (void*)vtable[i]  << " -> \n";
  vtable[i](); // Call the function in the vtable
    }
printf("\n");
    std::cout << "\nDerived Object VTable:" << std::endl;
    //printVTable(&derivedObj);
    // Convert function pointers to uintptr_t for arithmetic



//uintptr_t address1 = reinterpret_cast<uintptr_t>(ptr1);
    //uintptr_t address2 = reinterpret_cast<uintptr_t>(ptr2);

    // Calculate difference and cast to int for signed comparison
    //int difference = static_cast<int>(address1 - address2);
    return 0;
}
