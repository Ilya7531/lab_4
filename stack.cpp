#include "stack.h"
#include <cstdlib> //NULL

struct Node
{
    Data datum;
    Node *next;
    Node(Data datum): datum(datum), next(0) {}
    ~Node()
    {
        datum = 0;
        next = 0;
    }
};

class Stack::StackImplementation
{
public:
    StackImplementation();
    ~StackImplementation();

    void push(Data datum);
    Data pop();
    bool isEmpty();
    Data getNum();
    bool nextDatum(bool firstTime, Data &datum) const ;
    void clear();
private:
    int n;
    Node *top;
};

////////////  Stack //////////////

Stack::Stack():
    pimpl(0)
{
    pimpl = new StackImplementation;
}

Stack::~Stack()
{
    delete pimpl;
    pimpl = 0;
}

void Stack::push(Data datum)
{
    pimpl->push(datum);
}
bool Stack::nextDatum(bool firstTime, Data &datum) const
{
    return pimpl->nextDatum(firstTime, datum);
}

Data Stack::pop()
{
    return pimpl->pop();
}

bool Stack::isEmpty()
{
    return pimpl->isEmpty();
}

Data Stack::getNum()
{
    return pimpl->getNum();
}


///// StackImplementation ////////

Stack::StackImplementation::StackImplementation():
    top(0), n(0)
{}

Stack::StackImplementation::~StackImplementation()
{
    clear();
}

void Stack::StackImplementation::push(Data datum)
{
    Node *p = new Node(datum);
    p->next = top;
    top = p;
    p = NULL;
    ++n;
}

Data Stack::StackImplementation::pop()
{
    Node *p;
    p = top;
    top = top->next;
    p->next = NULL;
    Data datum = p->datum;
    delete p;
    p = NULL;
    --n;
    return datum;
}

bool Stack::StackImplementation::isEmpty()
{
    return !n;
}

Data Stack::StackImplementation::getNum()
{
    return n;
}

void Stack::StackImplementation::clear()
{
    while (top) pop();
    n = 0;
    /*void Stack::StackImplementation::clear()
{
    while(top)
    {
        Node *p = top;
        top = top->next;
        delete p;
        p = 0;
    }*/
}

bool Stack::StackImplementation::nextDatum(bool firstTime, Data &datum) const
{
    static Node *cur;

    if(firstTime)
        cur = top;

    bool result = cur != 0;

    if(result)
    {
        datum = cur->datum;
        cur = cur->next;
    }

    return result;
}
