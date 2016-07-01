#include <iostream>
#include <cstdlib>

#include "stack.h"
using namespace std;

Stack::Stack(){
    mLinkTop = NULL;
    }

Stack::Stack(float x){
    ElementStack* temp = (ElementStack*)malloc(sizeof(ElementStack));
    temp->number = x;
    temp->link = NULL;
    mLinkTop = temp;
}
//?получение сылки на первый элемент стека
ElementStack* Stack::getLinkTop(){
     return mLinkTop;
}

//добавить элемент на стек
void Stack::pushElement(float x){
    ElementStack *temp = (ElementStack* )malloc(sizeof(ElementStack));
    temp->number = x;
    temp->link = mLinkTop;
    mLinkTop = temp;

}

//снять элемент со стека
float Stack::popElement(){
    float x;
    x = mLinkTop->number;
    mLinkTop = mLinkTop->link;
    return x;

}

//получение врехнего числа без снятия со стека
float Stack::peekElement(){
    return mLinkTop->number;
    }

//распечатать весь стек
void Stack::printStack(){
    ElementStack *temp = (ElementStack* )malloc(sizeof(ElementStack));
    temp = mLinkTop;

    while(temp != NULL){
        cout << " -> " << temp->number  ;
        temp = temp->link;
    }
    cout << "."<< endl;
    free(temp);
}
/*
//удалить весь стек
void Stack::deleteStack(){
    }

//размер(количество элементов на стеке)
int Stack::sizeStack(){
    ElementStack *temp = (ElementStack* )malloc(sizeof(ElementStack));
    int countElements = 0;
    temp = mLinkTop;

    if (temp){    free(temp);
        return 0;}
    else
        while(temp){
            countElements++;
            temp++;
            }
    free(temp);
    return countElements;
    }
*/
