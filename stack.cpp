#include <iostream>
#include <cstdlib>
#include <cstring>

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
//перегрузка вывода стека
ostream& operator<<(ostream& os, Stack const& st)
{
    ElementStack *temp = (ElementStack* )malloc(sizeof(ElementStack));
    temp = st.mLinkTop;

    if (temp == NULL )
        os << "Стек пуст";
    else while(temp != NULL){
        os << " -> " << temp->number  ;
        temp = temp->link;
    }
    os << "."<< endl;
    free(temp);
    return os;
}
//Доработать перегрузку присваивания
Stack& Stack::operator=(Stack& st){
    ElementStack *temp1 = (ElementStack* )calloc(st.sizeStack(), sizeof(ElementStack));
    temp1 = st.mLinkTop;
    memcpy(&mLinkTop, &temp1,st.sizeStack()*sizeof(ElementStack));
    return *this;
    }

//уменьшить все числа в стеке на n
void Stack::reduceElementN(float n){
    ElementStack *temp;
    temp = mLinkTop;

    while(temp != NULL){
        temp->number = temp->number-n;
        temp = temp->link;
    }

}



//удалить n элементов с верхушки стека
void deleteNElements(Stack * A, int n){
    for(int i=0; i<n ; i++, A->popElement());
}
