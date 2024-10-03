#include <stdio.h>
#include <thread>
#include <iostream>

void print_function(int a) {
    printf("This function is working with thread %d..\n", a);
}

void func_point_one(){
    std::cout << "Function 1 is called" << std::endl;
}

void func_point_two(){
    std::cout << "Function 2 is called" << std::endl;
}


int main() { 
    // Checking if threading is installed
    std::cout << "C++ thread library is available!" << std::endl;

    // Initialize pointers
    void (*func_ptr)();

    // Try function pointer
    int choice; 
    std::cout << "Enter 1 or 2 for function pointer call ";
    std::cin >> choice; 

    if (choice == 1){
        func_ptr = func_point_one;
    } else if(choice == 2){
        func_ptr = func_point_two;
    } else { 
        std::cout << "This is not 1 or 2" << std::endl;
    }

    // Call function via pointer
    func_ptr();

    // Thread One
    std::thread t1(print_function, 1);

    // Thread Two
    std::thread t2(print_function, 2);

    // Function call 
    print_function(3);

    // Wait for threads to finish
    t2.join();
    t1.join();
    

    return 0;
}

