#include <iostream>
#include "stack.h"
using namespace std;

void createStack_103012330225(stack &S){
    Top(S) = 0;
}

bool isEmpty_103012330225(stack S){
    if(Top(S) == 0){
        return true;
    }else{
        return false;
    }
}

bool isFull_103012330225(stack S){
    if(Top(S) == 15){
        return true;
    }else{
        return false;
    }
}

void push_103012330225(stack &S, infotype X){
    if(isFull_103012330225(S) == false){
        Top(S) = Top(S) + 1;
        info(S)[Top(S)] = X;
    }
}

string pop_103012330225(stack &S){
    string X;

    X = info(S)[Top(S)];
    Top(S) = Top(S) - 1;
    return X;
}

void printInfo_103012330225(stack S){
    for(int i = Top(S); i >= 1; i--){
        cout << info(S)[i] << " ";
    }
    cout << endl;
}
