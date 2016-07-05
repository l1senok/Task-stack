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
  //ElementStack mElementStack;
  ElementStack<T> *mLinkTop;
public:
    Stack();
    Stack(const T);//??
    ~Stack();

    void pushElement(const T);     //добавить элемент на стек
    T popElement();          //снять элемент со стека
    T peekElement();         //получение врехнего числа без снятия со стека

    void printStack();           //распечатать весь стек
    void deleteStack();          //удалить весь стек
    int sizeStack();             //размер(количество элементов на стеке)

    friend ostream& operator<<(ostream&, Stack<T> const&);
    friend istream& operator>>(ostream&, Stack<T> const&);
    //Stack<T> operator+(Stack<T> const &);
    bool operator==(Stack<T> const &);

    //Stack& operator=(Stack<T>& const );


    //???оператор приведения


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
//delete push pop peek print


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
    float x = temp->number;
    free(temp);
    return x;
}

//получение врехнего числа без снятия со стека
template <typename T>
T Stack<T>::peekElement(){
    return mLinkTop->number;
    }

//распечатать весь стек
template <typename T>
void Stack<T>::printStack(){
    ElementStack<T> *temp = (ElementStack<T> *)malloc(sizeof(ElementStack<T>));
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

//------------Перегрузка операторов(=,<<,>>,+,-,==,+=, -=  )----------------------

template <typename T>
ostream& operator<<(ostream& os, Stack<T> const& st)
{
    ElementStack<T> *temp = (ElementStack<T> *)malloc(sizeof(ElementStack<T>));
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
/*
template <typename T>
istream& operator<<(istream& is, Stack<T> const& st)
{
    ElementStack<T> *temp = (ElementStack<T> *)malloc(sizeof(ElementStack<T>));
    temp = st.mLinkTop;
    is >>
    free(temp);
    return is;
}
*/

/*
//Доработать перегрузку присваивания
template <typename T>
Stack<T> & Stack<T>::operator=(Stack& const st){
    ElementStack<T> *temp1 = (ElementStack<T> *)calloc(st.sizeStack(), sizeof(ElementStack<T>));
    temp1 = st.mLinkTop;
    memcpy(&mLinkTop, &temp1,st.sizeStack()*sizeof(ElementStack<T>));
    return *this;
    }
*/


//Stack<T> operator+(Stack<T> const &);

template <typename T>
bool Stack<T>::operator==(Stack<T> const& other)
    {
        if (!((this.sizeStack()== other.sizeStack)&&(typeid(this) == typeid(other))))
        return false;

        ElementStack<T> *temp1 = (ElementStack<T> *)malloc(sizeof(ElementStack<T>));
        ElementStack<T> *temp2 = (ElementStack<T> *)malloc(sizeof(ElementStack<T>));
        temp1 = this.mLinkTop;temp2 = other.mLinkTop;
        bool buf = true;

        if ((temp1 == NULL)&&(temp2 == NULL))
            return true;

        else while(temp1 != NULL){
            if (temp1->number != temp2->number){
                return false;
                break;}
        }
        free(temp1);free(temp2);
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
