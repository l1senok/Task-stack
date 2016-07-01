#ifndef STACK_H
#define STACK_H

struct ElementStack
{
    float number;
    ElementStack* link;
};


class Stack {
private:
  ElementStack mElementStack;
  ElementStack* mLinkTop;
public:
    Stack();
    Stack(float);

    ElementStack* getLinkTop();
    ElementStack getElementStack(int);

    void addElementTop(float);

};

#endif // STACK_H
