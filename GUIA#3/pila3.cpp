#include <iostream>
using namespace std;

struct Node {
    int element;
    struct Node *next;
};
typedef struct Node *Stack;

void initiliaze(Stack *s) {
    *s = NULL;
}

bool empty(Stack *s) {
    return *s == NULL;
}

void push(Stack *s, int e) {
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->element = e;
    node->next = *s;

    *s = node;
}

void pop(Stack *s) {
    if (!empty(s)) {
        struct Node *aux = *s;
        *s = (*s)->next;
        delete(aux);
    }else {
        return;
    }
}

bool isPair(int num) {
    if (num % 2 == 0) {
        return true;
    }else {
        return false;
    }
}

void sum(Stack *s, int sumP, int sumI) {
    if (empty(s)) {
        cout << "Mostrando suma de los pares: " << sumP << endl;
        cout << "Mostrando suma de los impares: " << sumI << endl;
        return;
    }else {
        if (isPair((*s)->element))
        {
            sumP += (*s)->element;
        }else{
            sumI += (*s)->element;
        }
        pop(s);
        sum(s, sumP, sumI);
    }
    
}

int main() {
    Stack stack;
    initiliaze(&stack);
    
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

    int sumP = 0, sumI = 0;

    sum(&stack, sumP, sumI);
}
