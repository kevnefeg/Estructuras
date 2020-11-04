#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct producto
{
    string nombre;
    float precio_unitario;
};

struct pedido
{
    string apellido;
    vector<producto> lista_comida;
};

producto NuevoProducto;
pedido NuevoPedido;

queue<pedido> Donas;
queue<pedido> PlatoFuerte;

float totalGananciasDonas = 0, totalGananciasPlatos = 0;

void menuInicio();
void atenderPedido(int opcion);
void menuDonas();
void menuPlatos();
void ingresarDona(int cantidadDonas);
void ingresarPlatos(int cantidadPlatos);

int main()
{
    menuInicio();
}

void menuInicio()
{
    int opcion = 0;
    bool salir = true;
    cout << "---* Bienvenido por favor elija una opcion *---" << endl;
    cout << "1) Atender pedidos de clientes " << endl;
    cout << "2) Calcular ganancias por venta de donas" << endl;
    cout << "3) Calcular ganancias por venta de platos fuertes" << endl;
    cout << "4) Salir" << endl;
    cin >> opcion;
    do
    {
        switch (opcion)
        {
        case 1:
            atenderPedido(opcion);
            break;
        case 2:
            cout << endl << "--* LAS GANANCIAS TOTALES POR VENTAS DE DONAS ES: " << totalGananciasDonas << " --*" << endl << endl;
            menuInicio();
            break;
        case 4:
            salir = false;
        default:
            break;
        }
    } while (salir);
}

void atenderPedido(int opcion)
{
    char opcionMenu = 0;
    cout << "-- Desea comprar donas o un plato fuerte? --" << endl;
    cout << "D = Donas" << endl;
    cout << "P = Platos fuertes" << endl;
    cout << "I = Menu de inicio" << endl;
    cout << "Elija (D/P/I)" << endl;
    cin >> opcionMenu;
    switch (opcionMenu)
    {
    case 'd':
    case 'D':
        menuDonas();
        break;
    case 'p':
    case 'P':
        menuPlatos();
        break;
    case 'i':
    case 'I':
        menuInicio();
        break;
    case 'j':

        break;
    default:
        break;
    }
}

void menuDonas()
{
    cin.ignore();
    cout << "-- Ingrese el apellido --" << endl;
    getline(cin, NuevoPedido.apellido);
    cout << "-- Cuantas donas pedira? --" << endl;
    int cantidadDonas = 0;
    cin >> cantidadDonas;
    ingresarDona(cantidadDonas);
}

void menuPlatos()
{
    cin.ignore();
    cout << "-- Ingrese el apellido --" << endl;
    getline(cin, NuevoPedido.apellido);
    cout << "-- Cuantos platos pedira? --" << endl;
    int cantidadPlatos = 0;
    cin >> cantidadPlatos;
    ingresarPlatos(cantidadPlatos);
}

void ingresarPlatos(int cantidadPLatos)
{
    for (int i = 0; i < cantidadPLatos; i++)
    {
        int platoOpcion = 0;
        cout << "-- El menu de platos fuertes consta de la siguiente manera: --" << endl
             << endl;
        cout << "1) $2.50 desayunos" << endl;
        cout << "2) $5 almuerzo" << endl;
        cout << "3) $3.50 cena" << endl;
        cin >> platoOpcion;

        switch (platoOpcion)
        {
        case 1:
            NuevoProducto.nombre = "Desayuno";
            NuevoProducto.precio_unitario = 2.50;
            totalGananciasPlatos + 2.50;
            NuevoPedido.lista_comida.insert(NuevoPedido.lista_comida.begin(), NuevoProducto);
            PlatoFuerte.push(NuevoPedido);
            cout << endl
                 << "Pedido ingresado exitosamente " << i + 1 << "!\n";
            break;
        case 2:
            NuevoProducto.nombre = "Almuerzo";
            NuevoProducto.precio_unitario = 5.00;
            totalGananciasPlatos + 5.00;
            NuevoPedido.lista_comida.insert(NuevoPedido.lista_comida.begin(), NuevoProducto);
            PlatoFuerte.push(NuevoPedido);
            cout << endl
                 << "Pedido ingresado exitosamente " << i + 1 << "!\n";
            break;
        case 3:
            NuevoProducto.nombre = "Cena";
            NuevoProducto.precio_unitario = 3.50;
            totalGananciasPlatos + 3.50;
            NuevoPedido.lista_comida.insert(NuevoPedido.lista_comida.begin(), NuevoProducto);
            PlatoFuerte.push(NuevoPedido);
            cout << endl
                 << "Pedido ingresado exitosamente " << i + 1 << "!\n";
            break;
        default:
            cout << "!!! Error !!!" << endl;
            break;
        }
    }
}

void ingresarDona(int cantidadDonas)
{
    float resultado = 0;
    for (int i = 0; i < cantidadDonas; i++)
    {
        int donaOpcion = 0;
        cout << "-- El menu de donas consta de la siguiente manera: --" << endl
             << endl;
        cout << "1) $1 sencillas" << endl;
        cout << "2) $1.25 rellena de leche" << endl;
        cout << "3) $1.50 sabores especiales (moca, caramelo)" << endl;
        cin >> donaOpcion;

        switch (donaOpcion)
        {
        case 1:
            NuevoProducto.nombre = "Sencillas";
            NuevoProducto.precio_unitario = 1;
            totalGananciasDonas + 1;
            NuevoPedido.lista_comida.insert(NuevoPedido.lista_comida.begin(), NuevoProducto);
            Donas.push(NuevoPedido);
            cout << endl
                 << "Pedido ingresado exitosamente " << i + 1 << "!\n";
            break;
        case 2:
            NuevoProducto.nombre = "Rellena de leche";
            NuevoProducto.precio_unitario = 1.25;
            totalGananciasDonas + 1.25;
            NuevoPedido.lista_comida.insert(NuevoPedido.lista_comida.begin(), NuevoProducto);
            Donas.push(NuevoPedido);
            cout << endl
                 << "Pedido ingresado exitosamente " << i + 1 << "!\n";
            break;
        case 3:
            NuevoProducto.nombre = "Sabores especiales";
            NuevoProducto.precio_unitario = 1.50;
            totalGananciasDonas + 1.50;
            NuevoPedido.lista_comida.insert(NuevoPedido.lista_comida.begin(), NuevoProducto);
            Donas.push(NuevoPedido);
            cout << endl
                 << "Pedido ingresado exitosamente " << i + 1 << "!\n";
            break;
        default:
            cout << "!!! Error !!!" << endl;
            break;
        }
    }
}




