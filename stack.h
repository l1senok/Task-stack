#ifndef STACK_H
#define STACK_H

struct ElementStack
{
    float number;
    ElementStack* link;
};

/**
Реализация стека для вещественных чисел, основан на вышеуказанной структуре
*/
class Stack {

private:
  //ElementStack mElementStack;
  ElementStack* mLinkTop;
public:
    Stack();
    Stack(float);//??

    ElementStack* getLinkTop();  //получение сылки на первый элемент стека

    void pushElement(float);     //добавить элемент на стек
    float popElement();          //снять элемент со стека
    float peekElement();         //получение врехнего числа без снятия со стека

    void printStack();           //распечатать весь стек
    void deleteStack();          //удалить весь стек
    int sizeStack();             //размер(количество элементов на стеке)

//    float findMaxElement();      //найти максимальный элемент на стеке
//    float findMinElement();      //найти минамальный элемент на стеке
//    void reduceElementN();       //уменьшить все числа в стеке на n
};

void deleteNElements(Stack* , int);      //удалить n элементов с верхушки стека

#endif // STACK_H
