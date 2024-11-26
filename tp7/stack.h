#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
#define Top(S) S.Top
#define info(S) S.info
using namespace std;
typedef string infotype;

struct stack {
    infotype info[15];
    int Top;
};

void createStack_103012330225(stack &S);
bool isEmpty_103012330225(stack S);
bool isFull_103012330225(stack S);
void push_103012330225(stack &S, infotype x);
string pop_103012330225(stack &S);
void printInfo_103012330225(stack S);

#endif // STACK_H_INCLUDED
