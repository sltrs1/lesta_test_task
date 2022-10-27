#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

#include <stddef.h>
#pragma once

/*
 * Задание:
 * На языке С++, написать минимум по 2 класса реализовывающих циклический буфер.
 * Объяснить плюсы и минусы каждой реализации.
*/

/*
 * Реализация 1.
 * Для хранения данных используется статический массив фиксированного размера.
 * В этой реализации на размер наложено ограничение: он должен быть степенью двойки.
 * Это позволяет некоторые операции с индексами заменить битовыми операциями.
 * Также с это позволяет с помощью битовой маски легко обрабатывать
 * ситуацию перехода через ноль.
 * Такая реализация проста и наглядна и позволяет, например, реализовать оператор
 * произвольного доступа [] к элементам буфера.
 * Недостатком такой реализации является ограниченный размер буфера.
*/


template<int SIZE, class DATA>
class CircularBuffer {
static_assert((SIZE&(SIZE-1))==0, "SIZE must be power of 2");
private:
    DATA data[SIZE];
    volatile size_t readCount = 0;
    volatile size_t writeCount = 0;
    static constexpr size_t mask = SIZE - 1;
public:

    bool isEmpty() const {
        return readCount == writeCount;
    }

    bool isFull() const {
        return ((size_t)(writeCount - readCount) & (size_t)~(mask)) != 0;
    }

    size_t count() const {
        return (writeCount - readCount) & mask;
    }

    void clear() {
        readCount=0;
        writeCount=0;
    }

    size_t size() const {
        return SIZE;
    }

    // В случае попытки прочитать из пустого места,
    // будет возвращено значение по умолчаниб
    const DATA operator[](size_t i) const {
        if (isEmpty() || i > count()) {
            return DATA();
        }
        return data[(readCount + i) & mask];
    }

    DATA first() const {
        return operator[](0);
    }

    DATA last() const {
        return operator[](count());
    }

    bool write(DATA val) {
        if (isFull()) {
            return false;
        }
        data[writeCount++ & mask] = val;
        return true;
    }

    bool read(DATA & val) {
        if (isEmpty()) {
            return false;
        }
        val = data[readCount++ & mask];
        return true;
    }

};

#endif // CIRCULARBUFFER_H
