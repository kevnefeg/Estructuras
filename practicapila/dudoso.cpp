#include <iostream>
#include <string>
using namespace std;

struct Libro
{
    string titulo;
    int numPagina;
    struct Libro *siguiente; 
};
typedef struct Libro *Pila;

void inicializar(Pila *s){ //initialize

    *s = NULL;
}

bool vacia(Pila *s){ //empty

    return *s == NULL;
}

void ingresar(Pila *s, string titulos, int numPaginas){ //push

    struct Libro *libro;
    libro = (struct Libro *)malloc(sizeof(struct Libro));
    libro->titulo = titulos;
    libro->numPagina = numPaginas;
    libro->siguiente = *s;

    *s = libro;
    
}
void desapilar(Pila *s){ //pop

    if(!vacia(s)){
        struct Libro *auxiliar = *s;
        *s = (*s)->siguiente; 
        delete(auxiliar);
    }else{
        return;
    }
}

void recibirLibro(Pila *s, string titulos){
    if ((*s)->titulo == titulos)
    {
        cout<<"El libro contiene "<<(*s)->numPagina<<" paginas"<<endl;
        return;

    }else{desapilar(s);
        recibirLibro(s, titulos);
    }   
}

int main(){
    Pila stack;
    inicializar(&stack);

    ingresar(&stack, "jose", 23);
    ingresar(&stack, "juan", 23);

    delete stack;

    string titulos;
    cout<<"Ingrese el libro que busca : "<<endl;
    getline(cin, titulos);
    recibirLibro(&stack, titulos);
}


