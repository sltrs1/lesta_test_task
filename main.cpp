#include <iostream>

#include "circularbuffer.h"
#include "iseven.h"

int main()
{
    std::cout << "Hello World!" << std::endl;


    std::cout << isEven(4) << std::endl;
    std::cout << isEven(5) << std::endl;
    std::cout << "==========" << std::endl;
    std::cout << isEvenBit(4) << std::endl;
    std::cout << isEvenBit(5) << std::endl;
    std::cout << "==========" << std::endl;
    std::cout << isEvenInt(4) << std::endl;
    std::cout << isEvenInt(5) << std::endl;
    std::cout << "==========" << std::endl;

    CircularBuffer<16, size_t> cb;

    size_t v;

    cb.write(123);
    cb.write(456);
    cb.write(789);
    cb.read(v);
    cb.write(1010);

    for (size_t i = 0; i < cb.count(); i++) {
        std::cout << cb[i] << std::endl;
    }



    return 0;
}
