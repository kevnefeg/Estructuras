#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title;
    int numPage;
    struct Book *next;
};
typedef struct Book *Stack;

void initiliaze(Stack *s) {
    *s = NULL;
}



void push(Stack *s, string title, int numPags) {
    struct Book *node;
    node = (struct Book *)malloc(sizeof(struct Book));
    node->title = title;
    node->numPage = numPags;
    node->next = *s;

    *s = node;
}

bool empty(Stack *s) {
    return *s == NULL;
}

void pop(Stack *s)
 {
    if (!empty(s))
     {
        struct Book *aux = *s;
        *s = (*s)->next;
        delete(aux);
    }else {
        return;
    }
}

void findBookPages(Stack *s, string title) {
    if ((*s)->title == title) {
        cout << "Tiene " << (*s)->numPage << endl;
        return;
    }else {
        pop(s);
        findBookPages(s, title);
    }
}

int main() {
    Stack bookStack;
    initiliaze(&bookStack);

    //cout << "prueba" << endl;
 
    push(&bookStack, "computacion", 175);
    push(&bookStack, "principito", 200);


  
//se puede correr con pocos datos
    string title;
    cout << "Ingrese el titulo del libro: " << endl;
    getline(cin, title);

    findBookPages(&bookStack, title);

    }