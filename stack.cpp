#include <iostream>
#include "stack.h"

Stack::Stack(){
   mElementStack.number = 0;
   mElementStack.link = NULL;
}

Stack::Stack(float x){
    mElementStack.number = x;
    mElementStack.link = NULL;
}

ElementStack* Stack::getLinkTop(){
    return mLinkTop;
}

ElementStack Stack::getElementStack(int n){

    int i=1;


    while(mLinkTop){
        i++;
        if (i == n)
            return mElementStack;
        mLinkTop++;
    }

    ElementStack nullElementStack;
    nullElementStack.number = 0;
    nullElementStack.link = NULL;
    return nullElementStack;

}

void Stack::addElementTop(float){
    //---
}
