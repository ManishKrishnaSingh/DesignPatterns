#include <bits/stdc++.h>

using namespace std;

class Iterator;

class Stack {
    int items[10];
    int stackpointer;
  public:
    Stack() {
        stackpointer = -1;
    }

    void push(int num) {
        items[++stackpointer] = num;
    }

    int pop() {
        return items[stackpointer--];
    }

    bool isEmpty() {
        return (stackpointer == -1);
    }

    friend class Iterator;
    Iterator *createIterator() const;
};

class Iterator {
    int index;
    const Stack *stack;
  public:
    Iterator(const Stack* iStack) {
        stack = iStack;
    }

    void first() {
        index = 0;
    }

    void next() {
        index++;
    }

    bool isLast() {
        return index == stack->stackpointer + 1;
    }

    int currentItem() {
        return stack->items[index];
    }
};

Iterator *Stack::createIterator() const {
    return new Iterator(this);
}

int main() {
    Stack stk;

    // insert into stack
    for(int i=1; i<=5; i++){
        stk.push(i);
    }

    // iterate through the stack
    Iterator* iter = stk.createIterator();
    for(iter->first(); !iter->isLast(); iter->next()){
        cout<<"[Item] => "<<iter->currentItem()<<endl;
    }

    return 0;
}

