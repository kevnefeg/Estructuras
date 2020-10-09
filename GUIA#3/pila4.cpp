#include <iostream>
using namespace std;

struct Node {
    int element;
    struct Node *next;
};
typedef struct Node *Stack;

void initialize(Stack *s) {
    *s = nullptr;
}

bool empty(Stack *s) {
    return *s == nullptr;
}

void push(Stack *s, int e) {
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->element = e;
    node->next = *s;

    *s = node;
}

int pop(Stack *s) {
    if (!empty(s)) {
        struct Node *node = *s;
        int e = (*s)->element;
        *s = (*s)->next;
        delete(node);
        return e;
    }else {
        return -1;
    }
}

void showStack(Stack *s) {
    struct Node *node = *s;
    bool isEmpty = false;
    while (!isEmpty)
    {
        if (!empty(&node))
        {
            cout << node->element << " ";
            node = node->next;
        }else {
            isEmpty = true;
        }
    }
}

void invert(Stack *s, Stack *i) {
    if (empty(s)) {
       return;
    }else {
        int aux = (*s)->element;
        pop(s);
        push(i, aux);

        invert(s, i);
    }
    
}

int main() {
    Stack stack, invStack;
    initialize(&stack);
    initialize(&invStack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    push(&stack, 6);
    push(&stack, 7);
    push(&stack, 8);
    push(&stack, 9);
    push(&stack, 10);

   
    cout << "Mostrando pila original" << endl;
    showStack(&stack);
    cout << endl;

    invert(&stack, &invStack);

    cout << "Mostrando pila invertida" << endl;
    showStack(&invStack);
    cout << endl;

    
}