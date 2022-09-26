#include <iostream>
#include <hello.h>

int main(int argc, char* argv[])
{
    std::cout << hello() << "\n";

    auto hello_struct = hello_advanced();
    std::cout << "Hello from struct buffer: " << hello_struct->buffer << "\n";
    std::cout << "Is hello: " << hello_struct->is_hello << "\n";

    // We have to manually free the memory here or its a memory leak.
    free((void*)hello_struct);
    hello_struct = nullptr;
    
    return 0;
}
