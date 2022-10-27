#ifndef CIRCULARBUFFER2_H
#define CIRCULARBUFFER2_H

#include <iostream>
#include <stddef.h>
#pragma once

/*
 * Задание:
 * На языке С++, написать минимум по 2 класса реализовывающих циклический буфер.
 * Объяснить плюсы и минусы каждой реализации.
*/

/*
 * Реализация 2.
 * Для хранения данных используется односвязный список,
 * который динамически расширяется при добавлении новых элементов.
 * Такая реализация исключает ситуацию переполнения буфера,
 * но может неограниченно расходовать память.
 * Также за счет того, что используются операторы с указателями, а не индексами,
 * затруднена реализация некоторых методов. Например, оператор произвольного
 * доступа [] теряет свой смысл, поскольку при таком подходе он вместо O(1) работает за O(N)
 * и для перебора значений в буфере лучше воспользоваться другими методами.
*/

template<class DATA>
class Node {
public:
    DATA value;
    Node *next;
    Node(DATA& a) {
        value = a;
        next == NULL;
    }
};

template<class DATA>
class CircularBuffer2 {

private:
    Node<DATA> * front;
    Node<DATA> * back;
    int size;

public:
    CircularBuffer2() {
        front = nullptr;
        back = nullptr;
        size = 0;
    }

    void push(DATA val) {
        size++;
        Node<DATA> * tmp = new Node(val);
        if (front == nullptr) {
            front = tmp;
        }
        else {
            back->next = tmp;
        }
        back = tmp;
        back->next = front;
    }

    DATA pop() {
        if (front == nullptr) {
            return DATA();
        }

        size--;
        DATA tmp_val;

        if (front == back) {
            tmp_val = front->value;
            delete front;
            front = nullptr;
            back = nullptr;
            return tmp_val;
        }

        Node<DATA> * tmp_node = front;
        tmp_val = tmp_node->value;
        front = front->next;
        back->next = front;
        delete tmp_node;
        return tmp_val;
    }

    void show() const {
        Node<DATA> * tmp = front;
        while(tmp->next != front) {
            std::cout << tmp->value << std::endl;
            tmp = tmp->next;
        }
        std::cout << tmp->value << std::endl;
        std::cout << std::endl;
    }

    const DATA operator[](size_t i) const {
        if (front == back || i > size) {
            return DATA();
        }

        Node<DATA> * tmp = front;

        for (int j = 0; j < i; j++) {
            tmp = tmp->next;
        }

        return tmp->value;
    }

    int getSize() const {
        return size;
    }

};



#endif // CIRCULARBUFFER2_H
