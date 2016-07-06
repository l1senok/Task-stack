#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <iomanip>
#include "stack.h"

using namespace std;
using std::ostream;


template <typename T>
struct ElementStack
{
    T number;
    ElementStack* link;
};

/**
Реализация стека для вещественных чисел, основан на вышеуказанной структуре
*/
template <typename T>
class Stack
{

private:
  ElementStack<T> *mLinkTop;
public:
    Stack();
    Stack(const T);
   // Stack(const Stack &);//конструктор копировани
    ~Stack();

    void pushElement(const T);     //добавить элемент на стек
    T popElement();          //снять элемент со стека
    T peekElement();         //получение врехнего числа без снятия со стека
    void invertStack();

    void printStack();           //распечатать весь стек
    void deleteStack();          //удалить весь стек
    int sizeStack();             //размер(количество элементов на стеке)

    template <typename U>
    friend ostream& operator<<(ostream&, Stack<U> &);

    template <typename K>
    friend istream& operator>>(ostream&, Stack<K> &);

    Stack<T>& operator=(Stack<T>);
    Stack<T>& operator+=(Stack<T>& right);

    template <typename L>
    friend Stack<L> operator+(Stack<L>& left,Stack<L>& right);

    bool operator==(Stack<T> &);

    void reduceElementN(const T);       //уменьшить все числа в стеке на n
};

//Функция вне класса
template <typename T>
void deleteNElements(Stack<T>* , int);      //удалить n элементов с верхушки стека


//---------------------------РЕАЛИЗАЦИЯ-------------------------------


//------------------------Конструторы, деструктор---------------------

//пустой конструктор
template <typename T>
Stack<T>::Stack(){
    mLinkTop = NULL;
    }

//коснструктор с заданным начальным значением
template <typename T>
Stack<T>::Stack(const T x){
    ElementStack<T> *temp = (ElementStack<T> *)malloc(sizeof(ElementStack<T>));
    temp->number = x;
    temp->link = NULL;
    mLinkTop = temp;
}

/*
template <typename T>
Stack<T>::Stack(const Stack<T> &){

}*/


template <typename T>
Stack<T>::~Stack()
{   ElementStack<T> *temp;

    while(mLinkTop != NULL){
        temp = mLinkTop;
        mLinkTop = temp->link;
        free(temp);
    }
}

//------------------Основные функции для работы со стеком-------------
//delete push pop peek print invert


//удаление всего стека
template <typename T>
void Stack<T>::deleteStack()
{   ElementStack<T> *temp;

    while(mLinkTop != NULL){
        temp = mLinkTop;
        mLinkTop = temp->link;
        free(temp);
    }
}


//добавление элемент на стек
template <typename T>
void Stack<T>::pushElement(T x){
    ElementStack<T> *temp = (ElementStack<T> *)malloc(sizeof(ElementStack<T>));
    temp->number = x;
    temp->link = mLinkTop;
    mLinkTop = temp;

}

//снять элемент со стека
template <typename T>
T Stack<T>::popElement(){
    ElementStack<T> *temp = mLinkTop;
    mLinkTop = temp->link;
    T x = temp->number;
    free(temp);
    return x;
}

//получение верхнего числа без снятия со стека
template <typename T>
T Stack<T>::peekElement(){
    return mLinkTop->number;
    }

//распечатать весь стек
template <typename T>
void Stack<T>::printStack(){
    ElementStack<T> *temp = mLinkTop;

    if (temp == NULL )
        cout << "Стек пуст";
    else while(temp != NULL){
        cout << " -> " << temp->number  ;
        temp = temp->link;
    }
    cout << "."<< endl;
}

template <typename T>
ElementStack<T> *helpInvert(T x, ElementStack<T>* link){
        ElementStack<T> *temp2 = (ElementStack<T> *)malloc(sizeof(ElementStack<T>));
        temp2->number = x;
        temp2->link = link;
        return temp2;
    }

template <typename T>
void Stack<T>::invertStack(){
    ElementStack<T> *temp1;//двигаюсь
    ElementStack<T> *tempTop;//ссылка

    temp1 = mLinkTop;
    tempTop = NULL;
    while(temp1 != NULL){
        tempTop = helpInvert(temp1->number, tempTop);
        temp1 = temp1->link;
    }
    mLinkTop = tempTop;
}

//------------Перегрузка операторов(=,<<,>>,+,-,==,+=, -=  )----------------------

template <typename T>
ostream& operator<<(ostream& os, Stack<T> & st)
{
    ElementStack<T> *temp = st.mLinkTop;

    if (temp == NULL )
        os << "Стек пуст";
    else
        {st.mLinkTop = temp->link;
        os << " снят: " << temp->number <<endl;}

    return os;
}
//перегрузка ">>" (добавляет элемент на стек)
template <typename T>
istream& operator>>(istream& is, Stack<T> & st)
{
    T value;

    is >> value;
    st.pushElement(value);

    return is;
}


//перегрузка оператора "="
template <typename T>
Stack<T> & Stack<T>::operator=(Stack<T> st){
    this->deleteStack();
    ElementStack<T> *temp = st.mLinkTop;

    while (temp != NULL){
        this->pushElement(temp->number);
        temp = temp->link;

        }
    temp = NULL;

    this->invertStack();
    return *this;
    }


template <typename T>
Stack<T>& Stack<T>::operator+=(Stack<T>& right){
    ElementStack<T> * x = mLinkTop;
    ElementStack<T> * y = right.mLinkTop;

    if (sizeStack() == right.sizeStack())
        while (x){
            x->number+=y->number;
            x = x->link;
            y = y->link;
        }
    return *this;
    }

template <typename T>
Stack<T> operator+(Stack<T>& left, Stack<T>& right){

    Stack<T> Sum;
    for(int i = 0; i< left.sizeStack(); i++)
        Sum.pushElement(0);

    Sum += right;
    Sum += left;
    return Sum;
}

template <typename T>
bool Stack<T>::operator==(Stack<T> & other){

        if (this->sizeStack() != other.sizeStack())
        return false;

        ElementStack<T> *temp1;    ElementStack<T> *temp2;
        temp1 = this->mLinkTop; temp2 = other.mLinkTop;

        bool buf = true;


        if ((temp1 == NULL ) && (temp2 == NULL))
            return true;

        while(temp1 != NULL ){
            if (temp1->number != temp2->number)
                return false;
            temp1 = temp1->link;
            temp2 = temp2->link;
        }
        return buf;
    }




//------------------------Доп. функции--------------------------------

//размер(количество элементов на стеке)
template <typename T>
int Stack<T>::sizeStack(){
    ElementStack<T> *temp = mLinkTop;
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


//уменьшить все числа в стеке на n(определенно для int, float, double)
template <typename T>
void Stack<T>::reduceElementN(T n){
    ElementStack<T> *temp;
    temp = mLinkTop;

    if ((typeid(T) == typeid(int))||((typeid(T) == typeid(double)))||(typeid(T) == typeid(float)))
        while(temp != NULL){
            temp->number = temp->number-n;
            temp = temp->link;
        }

}



//удалить n элементов с верхушки стека
template <typename T>
void deleteNElements(Stack<T> * A, int n){
    for(int i=0; i<n ; i++, A->popElement());
}

#endif // STACK_H
