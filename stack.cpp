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
    ElementStack *temp = mLinkTop;
    mLinkTop = temp->link;
    float x = temp->number;
    free(temp);
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

    if (temp == NULL )
        cout << "Стек пуст";
    else while(temp != NULL){
        cout << " -> " << temp->number  ;
        temp = temp->link;
    }
    cout << "."<< endl;
    free(temp);
}

//удалить весь стек
void Stack::deleteStack(){
    ElementStack *temp;

    while(mLinkTop != NULL){
        temp = mLinkTop;
        mLinkTop = temp->link;
        free(temp);
    }
}

//размер(количество элементов на стеке)
int Stack::sizeStack(){
    ElementStack *temp = mLinkTop;
    int countElements = 0;

    if (temp == NULL)
        return 0;
    else
        while(temp != NULL){
            countElements++;
            temp = temp->link;
            }

    return countElements;
    }

//удалить n элементов с верхушки стека
void deleteNElements(Stack * A, int n){
    for(int i=0; i<n ; i++, A->popElement());
}
