#ifndef STACK_H
#define STACK_H

typedef int Data;

class Stack
{


public:
    Stack();
    ~Stack();

    void push(Data datum);
    int pop();
    bool isEmpty();
    int getNum();
protected:
        bool nextDatum(bool firstTime, Data &datum) const;
private:
     class StackImplementation;
    StackImplementation *pimpl;


};

#endif // STACK_H
