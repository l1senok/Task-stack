#include <iostream>


#include "stack.h"

using namespace std;

int main()
{
    cout << "Реализация стека для вещественных чисел" << endl;

    cout << "Создание стека из одного элемента (5)." << endl;
    Stack<int> A(5);
    A.printStack();
    cout << "----------------------------------------" << endl;

    cout << "Добавление элементов(3, 9, 7, 1) на стек." << endl;
    A.pushElement(3); A.pushElement(9); A.pushElement(7); A.pushElement(1);
    cout << "----------------------------------------" << endl;

    cout << "Снятие элемента со стека: " << A.popElement() << endl;
    A.printStack();
    cout << "----------------------------------------" << endl;

    cout << "Попытка снять элемент с помощью перегрузки: " << A;
    A.printStack();
    cout << "----------------------------------------" << endl;

    cout << "Попытка добавить элемент с помощью перегрузки(введите): ";
    cin >> A;
    A.printStack();
    cout << "----------------------------------------" << endl;

    cout << "Инвертированние стека. " << endl;
    A.invertStack();
    A.printStack();
    cout << "----------------------------------------" << endl;

    cout << "Выбор элемента со стека без снятия: " << A.peekElement() << endl;
    A.printStack();
    cout << "----------------------------------------" << endl;

    cout << "Уменьшение всех элементов на стеке на n(2). "<< endl;
    A.reduceElementN(2);
    A.printStack();
    cout << "----------------------------------------" << endl;

    cout << "Вывод количества элементов в стеке: " << A.sizeStack() << endl;
    A.printStack();
    cout << "----------------------------------------" << endl;

    cout << "Удаление n(2) элементов в стеке." << endl;
    deleteNElements(&A, 2);
    A.printStack();
    cout << "----------------------------------------" << endl;

    cout << "Удаление всего стека." << endl;
    A.deleteStack();
    A.printStack();
    cout << "----------------------------------------" << endl;

    cout << "Перегрузки " << endl ;
    Stack<int> X; X.pushElement(7); X.pushElement(3); X.pushElement(6); X.pushElement(1); X.pushElement(4);
    Stack<int> Y; Y.pushElement(7); Y.pushElement(3); Y.pushElement(6); Y.pushElement(1); Y.pushElement(4); Y.pushElement(2);
    Stack<int> X1; X1.pushElement(7); X1.pushElement(3); X1.pushElement(6); X1.pushElement(9); X1.pushElement(10);
    Stack<int> X2 = X;
    Stack<int> Z;
    cout << "---------------Печать стека X-------------------------" << endl;
    X.printStack();
    cout << "---------------Печать стека X1------------------------" << endl;
    X1.printStack();
    cout << "---------------Печать стека X2------------------------" << endl;
    X2.printStack();
    cout << "---------------Печать стека Y-------------------------" << endl;
    Y.printStack();
    cout << "---------------Печать стека Z-------------------------" << endl;
    Z.printStack();
    cout << "---------------Проверка X==X1 : " << (X == X1) << endl;
    cout << "---------------Проверка X==X2 : " << (X == X2) << endl;
    cout << "---------------Проверка Z = Y-------------------------" << endl;
    Z = Y; Z.printStack();
    cout << "---------------Проверка X+=X1 -------------------------" << endl;
    X+=X1; X.printStack();
    cout << "---------------Проверка Z = X + X1-------------------------" << endl;
    X.printStack(); X1.printStack();
    Z = (X + X1); Z.printStack();
    Z = X;Z.printStack();


    return 0;
}
