//codigo con libreria 
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

//Definiendo estructura Libro, la cual va a componer a la pila
struct Libro {
    string titulo;
    string autor;
    int edicion;
    string categoria;
    int isbn;
};

//Definiendo estructura Libro, la cual va a componer a la pila
struct Revista {
    string titulo;
    string autor;
    int volumen;
    int issues;
    string categoria;
    int issn;
};

//Definiendo estructura Estudiante, la cual va a componer a mi lista simple
struct Estudiante {
    string nombre;
    string apellido;
    int carnet;
    Libro *libro = NULL;
    Revista *revista = NULL;
};

//Función que verifica si el estudiante ya tiene asignado un libro o revista
bool puedeAsignar(Estudiante estudiante) {
    //Tanto como el libro y revista del estudiante tiene que estar NULL, si uno no es NULL no se puede ingresar otro libro o revista
    if (estudiante.revista == NULL && estudiante.libro == NULL) {
        return true;
    }else {
        return false;
    }
}

bool asignarLibro(vector<Estudiante> *listaEstudiantes, int carnet, Libro *libro) {
    //Creación de bandera booleana que va a retornar mi función
    bool asignado = false;

    //Verificar si la lista de estudiantes está vacía o no
    if(listaEstudiantes->empty()) {
        cout << "No se puede asignar el libro, no hay estudiantes en la lista" << endl;
        return asignado;
    }else {
        //Bandera booleana que verifica si ya se encontró el estudiante con el carnet deseado
        bool encontrado = false;

        //Recorrer la lista por medio de un for
        for(int pos = 0; pos < listaEstudiantes->size(); pos++) {
            //Verficación de que el estudiante en la posición actual tiene el mismo carnet que el carnet pedido por el usuario
            if(listaEstudiantes->at(pos).carnet == carnet) {
                //Modificando mi bandera booleana encontrado
                encontrado = true;

                //Verificar si el estudiante ya tiene un libro o revista asignado
                if(puedeAsignar(listaEstudiantes->at(pos))) {
                    //Le asigno el libro al estudiante en la posición actual
                    listaEstudiantes->at(pos).libro = libro;

                    //Modificando bandera asignado a verdadero
                    asignado = true;

                    /* El siguiente cout se muestra de la siguiente manera:
                    El libro '<titulo>' de <autor>, Edición <numero_de_edición>. ISBN #<isbn>.
                    Fue asignado al estudiante <nombre> <apellido>, con carnet <carnet>
                    */
                    cout << "El libro '" << listaEstudiantes->at(pos).libro->titulo << "' de " << listaEstudiantes->at(pos).libro->autor
                         << ", Edición " << listaEstudiantes->at(pos).libro->edicion << ". ISBN #" << listaEstudiantes->at(pos).libro->isbn << "."
                         << endl;
                    cout << "Fue asignado al estudiante " << listaEstudiantes->at(pos).nombre << " " << listaEstudiantes->at(pos).apellido
                         << ", con carnet: " << listaEstudiantes->at(pos).carnet << endl;
                }else {
                    cout << "No se le pudo asignar el libro al estudiante porque ya tiene otro libro asignado" << endl;
                }

            }

        }

        //Verificando si el estudiante deseado no estaba en la lista
        if(encontrado == false) {
            cout << "El carnet ingresado no pertenece a ningún estudiante" << endl;
        }

        return asignado;
    } 
}

bool asignarRevista(vector<Estudiante> *listaEstudiantes, int carnet, Revista *revista) {
    //Creación de la bandera asignado que va a retornar la función
    bool asignado = false;

    //Verifico si hay estudiantes en la lista
    if(listaEstudiantes->empty()) {
        cout << "No se puede asignar la revista, no hay estudiantes en la lista" << endl;
        return asignado;
    }else {
        //Bandera booleana que verifica si ya se encontró el estudiante con el carnet deseado
        bool encontrado = false;

        //Verifico si el estudiante en la posición actual tiene el mismo carnet que el carnet pedido por el usuario
        for(int pos = 0; pos < listaEstudiantes->size(); pos++) {

            if(listaEstudiantes->at(pos).carnet == carnet) {
                //Modificación de la bandera found a verdadero
                encontrado = true;

                //Verificar si el estudiante ya tiene un libro o revista asignado
                if(puedeAsignar(listaEstudiantes->at(pos))) {
                    //Le asigno al estudiante el libro
                    listaEstudiantes->at(pos).revista = revista;

                    //Modificación de la bandera asignado a verdadero
                    asignado = true;

                     /* El siguiente cout se muestra de la siguiente manera:
                    La revista '<titulo>' de <autor>, (Vol. <numero_volumen>) Issue #<numero_issue>. ISSN #<issn>.
                    Fue asignado al estudiante <nombre> <apellido>, con carnet <carnet>
                    */
                    cout << "La revista '" << listaEstudiantes->at(pos).revista->titulo << "' de " << listaEstudiantes->at(pos).revista->autor
                         << ", (Vol. " << listaEstudiantes->at(pos).revista->volumen << ") Issue #" << listaEstudiantes->at(pos).revista->issues
                         << ". ISSN #" << listaEstudiantes->at(pos).revista->issn << "." << endl;
                    cout << "Fue asignado al estudiante " << listaEstudiantes->at(pos).nombre << " " << listaEstudiantes->at(pos).apellido
                         << ", con carnet: " << listaEstudiantes->at(pos).carnet << endl;
                    return asignado;
                }else {
                    cout << "No se pudo asignar la revista porque el estudiante ya tiene un libro o revista asignado" << endl;
                }
            }
        }

        //Verificando si el estudiante deseado no estaba en la lista
        if(encontrado == false) {
            cout << "El carnet no pertenece a ningún estudiante de la lista" << endl;
        }
        
        return asignado;
    }
}

int main() {
    //Creando e inicializando la pila de libros y la pila de revistas
    stack<Libro> pilaLibros;
    stack<Revista> pilaRevistas;

    //Creando e inicializar la lista simple de los estudiantes
    vector<Estudiante> listaEstudiantes;

    //Creando bandera booleana para iterar el while
    bool status = true;

    //Menu por medio de while, verificando variable status por cada iteración
    while(status) {
        //Imprimiendo en consola las opciones del menú
        cout << "********** MENU **********" << endl;
        cout << "1. Ingresar libro a la pila" << endl;
        cout << "2. Ingresar revista a la pila" << endl;
        cout << "3. Ingresar estudiante a la lista" << endl;
        cout << "4. Asignar libro a un estudiante de la lista" << endl;
        cout << "5. Asignar revista a un estudiante de la lista" << endl;
        cout << "6. Salir del programa" << endl;

        //Creación de variable entera que servirá para ejecutar una opción del menú
        int option;

        //Pidiéndole al usuario que ingrese la opción por medio de consola
        cout << "\n" << "Ingrese la opción del menú que desea ejecutar: ";
        cin >> option;
        cin.ignore();

        //Creación de variable de tipo Estudiante
        Estudiante estudiante;

        //Creación de variable de tipo Libro
        Libro libro;

        //Creación de variable de tipo Revista
        Revista revista;

        //Case para verificar la opción ingresada
        switch (option){
            case 1:
                //Caso en el que se añade un libro a la pila previamente creada

                //Pidiéndole al usuario los datos del libro
                cout << "Ingrese el titulo del libro" << endl;
                getline(cin, libro.titulo);

                cout << "Ingrese el autor del libro" << endl;
                getline(cin, libro.autor);

                cout << "Ingrese el número de edición del libro" << endl;
                cin >> libro.edicion;
                cin.ignore();

                cout << "Ingrese la categoria del libro" << endl;
                getline(cin, libro.categoria);

                cout << "Ingrese el ISBN del libro" << endl;
                cin >> libro.isbn;

                //Agregando el libro, ya con los datos, a la pila
                pilaLibros.push(libro);
                break;
            case 2:
                //Caso en el que se añade una revista a la pila previamente creada

                //Pidiéndole al usuario los datos de la revista
                cout << "Ingrese el titulo de la revista" << endl;
                getline(cin, revista.titulo);

                cout << "Ingrese el autor de la revista" << endl;
                getline(cin, revista.autor);

                cout << "Ingrese el volumen de la revista" << endl;
                cin >> revista.volumen;
                
                cout << "Ingrese el issue de la revista" << endl;
                cin >> revista.issues;
                cin.ignore();

                cout << "Ingrese la categoria de la revista" << endl;
                getline(cin, revista.categoria);

                cout << "Ingrese el ISSN de la revista" << endl;
                cin >> revista.issn;

                pilaRevistas.push(revista);
                break;
            case 3:
                //Caso en el que se añade un estudiante a la lista simple

                //Pidiéndole al usuario los datos del estudiante
                cout << "Ingrese el nombre del estudiante" << endl;
                getline(cin, estudiante.nombre);

                cout << "Ingrese los apellidos del estudiante" << endl;
                getline(cin, estudiante.apellido);

                cout << "Ingrese el carnet del estudiante" << endl;
                cin >> estudiante.carnet;

                //El puntero libro y revista quedan en null porque el estudiante no ha recogido ninguno

                //Agregando el estudiante, ya con los datos, a la lista
                listaEstudiantes.push_back(estudiante);
                break;
            case 4:
                //Caso en el que se le asigna un libro a un estudiante
                
                //Verificando que hayan libros en la pila
                if(pilaLibros.empty()) {
                    cout << "No se puede asignar libros, porque la pila está vacía" << endl;
                }else {
                    //Asigno a una variable libro el libro que se encuentra hasta arriba de la pila
                    Libro libro = pilaLibros.top();

                    //Creando variable entera donde se va a almacenar el carnet del estudiante al que se le desea asignar el libro
                    int carnet;

                    //Pidiéndole al usuario el carnet que desea buscar
                    cout << "Ingrese el carnet del estudiante que desea buscar" << endl;
                    cin >> carnet;

                    //Mandar a llamar la función para asignar, con la lista completa de estudiantes, el carnet deseado y el libro
                    if(asignarLibro(&listaEstudiantes, carnet, &libro)) {
                        pilaLibros.pop();
                    }
                }
                break;
            case 5:
                //Caso en el que se le asigna una revista a un estudiante

                //Verificando que hayan revistas en la pila
                if(pilaRevistas.empty()) {
                    cout << "No se puede asignar revistas, porque la pila está vacía" << endl;
                }else {
                    //Asigno una variable revista la revista que se encuentra arriba de la pila
                    Revista revista = pilaRevistas.top();

                    //Creando variable entera donde se va a almacenar el carnet del estudiante
                    int carnet;

                    cout << "Ingrese el carnet del estudiante" << endl;
                    cin >> carnet;

                    if(asignarRevista(&listaEstudiantes, carnet, &revista)) {
                        pilaRevistas.pop();
                    }
                }
                break;
            case 6:
                status = false;
                cout << "Fin del programa." << endl;
                break;
            default:
                cout << "Opción no válida" << endl;
                break;
        }
    }
    return 0;
}
