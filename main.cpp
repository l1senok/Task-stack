#include <iostream>


#include "stack.h"

using namespace std;

int main()
{
    cout << "Реализация стека для вещественных чисел" << endl;

    cout << "Создание стека из одного элемента (5)." << endl;
    Stack A(5);
    A.printStack();
    cout << "----------------------------------------" << endl;
    cout << "Добавление элементов(3, 5, 7, 1) на стек." << endl;
    A.pushElement(3); A.pushElement(5); A.pushElement(7); A.pushElement(1);
    A.printStack();
    cout << "----------------------------------------" << endl;
    cout << "Снятие элемента со стека: " << A.popElement() << endl;
    A.printStack();
    cout << "----------------------------------------" << endl;
    cout << "Выбор элемента со стека без снятия: " << A.peekElement() << endl;
    A.printStack();
    cout << "----------------------------------------" << endl;
    cout << "" << endl;

    return 0;
}
