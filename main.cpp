#include <iostream>
#include <string>
#include <random>
#include "circularbuffer.h"
#include "circularbuffer2.h"
#include "iseven.h"
#include "sort.h"


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


    std::cout << "+++++++++++" << std::endl;
    CircularBuffer2<size_t> cb2;

    cb2.push(123);
    cb2.push(456);
    cb2.push(789);
    cb2.pop();
    cb2.push(5445);
    cb2.push(546854);

    cb2.show();

    std::cout << "+++++++++++" << std::endl;

    for (size_t i = 0; i < cb2.getSize(); i++) {
        std::cout << cb2[i] << std::endl;
    }

    std::cout << "+++++++++++" << std::endl;

    constexpr int num = 1000;
    int arr1[num];
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, num*10);

    for (int i = 0; i < num; i++) {
        arr1[i] = dist(rng);
    }

    std::cout << "Arr1 unsort (every 100th element)" << std::endl;
    for (int i = 0; i < num; i+=100) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Quicksort" << std::endl;

    quickSort(arr1, 0, num-1);

    std::cout << "Arr1 sort (every 100th element)" << std::endl;
    for (int i = 0; i < num; i+=100) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    //--------------------------------

    int arr2[num];
    for (int i = 0; i < num; i++) {
        arr2[i] = dist(rng);
    }

    std::cout << "Arr2 unsort (every 100th element)" << std::endl;
    for (int i = 0; i < num; i+=100) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Merge Sort" << std::endl;

    mergeSort(arr2, 0, num-1);

    std::cout << "Arr2 sort (every 100th element)" << std::endl;
    for (int i = 0; i < num; i+=100) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    std::getchar();

    return 0;
}
