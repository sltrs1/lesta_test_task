#ifndef ISEVEN_H
#define ISEVEN_H

#pragma once

/*
 * Задание:
 * На языке С/С++, написать алгоритм (функцию) определения четности целого числа,
 * который будет аналогичен нижеприведенному по функциональности, но отличен по своей сути.
 * Объяснить плюсы и минусы обеих реализаций.
 * C/C++ example:
 * bool isEven(int value){return value%2==0;}
*/

// Комментарии к решению находятся в файле с реализацией iseven.cpp

/**
 * @brief isEvenRem функция проверки четности методом деления с остатком
 * @param value проверяемое значение
 * @return true если число четное, false - если нечетное
 */
bool isEven(int value);

/**
 * @brief isEvenBit функция проверки четности c использованием битовых операций
 * @param value проверяемое значение
 * @return true если число четное, false - если нечетное
 */
bool isEvenBit(int value);

/**
 * @brief isEvenInt функция проверки четности c использованием особенностей типа int
 * @param value проверяемое значение
 * @return true если число четное, false - если нечетное
 */
bool isEvenInt(int value);

#endif // ISEVEN_H
