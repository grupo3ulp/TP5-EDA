#include <iostream>

using namespace std;
const int N = 10;

/*  1. En el menú principal, se cuenta con las siguientes variables: pilaA, pilaB, pilaC, aux1 todos los datos son enteros, y los procedimientos o }
    funciones son los que siguen:
    a. Implemente la estructura Pila de Enteros que permita trabajar con variables de tipo Pila.
    b. cargaPila, que permita introducir datos en la PilaA
    c. pasaPila, pasa todos los elementos de pilaA a PilaB
    d. contieneE, que recibe un entero “X” y determina si está en la pilaA, todos los elementos deben quedar nuevamente en A
    e. SeparaPI, que dada la pilaA con números enteros, coloca en pilaB los pares y en PilaC los impares
    f. Invierte1, Dada una Pila A con números, una Pila B y una Pila C vacías, pasar los elementos de A a B de manera que queden en el mismo orden que estaban en A.
    (Se permite utilizar la pila C como auxiliar)
    g. Invierte2, que dada una Pila A, una variable X y una Pila Vacía B. Pasar los elementos de pilaA a pilaB de manera tal que en pilaB queden en el mismo orden
    que estaban en pilaA
    h. Dada una pila A con números, buscar si existe en A un entero “X”, y reemplazarlo por un número “Y”*/


struct Pila {
private:
    int tope = -1;
    int enteros[N];
public:
    bool pilaVacia() {
        return tope < 0;
    }

    int getElementoTope() {
        return enteros[tope];
    }

    void mostrarTope() {
        cout << tope;
    }

    void pop() {
        if (pilaVacia()) {
            cout << "No se pueden eliminar items de una pila vacia" << endl;
        } else {
            tope--;
        }
    }

    void cargarPila(int n) {
        if (tope < N) {
            tope++;
            enteros[tope] = n;
        } else {
            cout << "La pila esta llena" << endl;
        }
    }

    void pasaPila(Pila &pila) {
        while (tope >= 0) {
            pila.cargarPila(enteros[tope]);
            pop();
        }
    }

    void mostrarValores() {
        if(!pilaVacia()){
            for (int i = 0; i <= tope; ++i) {
                cout << enteros[i] << " - ";
            }
        }else{
            cout<<"la Pila se encuentra vacia";
        }
        cout << endl;
    }

    bool contieneE(int n) {
        Pila aux;
        bool flag=false;
        for (int i = tope; i >=0; --i) {
            if (getElementoTope() == n) {
                flag=true;
                break;
            } else {
                aux.cargarPila(getElementoTope());
                pop();
            }
        }
        aux.pasaPila(*this);
        if(flag){
            return true;
        }else{
            return false;
        }

    }

    void separaPila(Pila &pilaB, Pila &pilaC) {
        for (int i = tope; i >= 0; --i) {
            if (getElementoTope() % 2 == 0) {
                pilaB.cargarPila(getElementoTope());
                pop();
            } else {
                pilaC.cargarPila(getElementoTope());
                pop();
            }
        }
    }

    void Invierte1(Pila &pilaB, Pila &pilaC) {
       pasaPila(pilaC);
       pilaC.pasaPila(pilaB);
    }

    void Invierte2(Pila &pilaB) {
        Pila x;
        pasaPila(x);
        x.pasaPila(pilaB);
    }

    bool remplazaXporY(int x,int y) {
        Pila aux;
        bool flag=false;
        for (int i = tope; i >=0; --i) {
            if (getElementoTope() == x) {
                enteros[tope]=y;
                flag=true;
            } else {
                aux.cargarPila(getElementoTope());
                pop();
            }
        }
        aux.pasaPila(*this);
        if(!flag){
            cout <<"El elemento x no se encuentra en la pila"<< endl;
        }
    }


};

int main() {
    Pila pilaA;
    Pila pilaB;
    Pila pilaC;

    int op;

   do   {
        cout << "---------------------------------------------------------------------------------------" <<endl;
        cout << "Menú principal" << endl;
        cout << "1. Cargar la pila A." << endl;
        cout << "2. Pasar todos los elementos de pilaA a PilaB." << endl;
        cout << "3. Buscar un número en la pila A." << endl;
        cout << "4. Coloca en pilaB los números pares y en PilaC los impares." << endl;
        cout << "5. (Dada una Pila A con números, una Pila B y una Pila C vacías) Pasar los elementos de A a B de manera que queden en el mismo orden que estaban en A." << endl;
        cout << "6. (Dada una Pila A, una variable X y una Pila Vacía B) Pasar los elementos de A a B de manera que queden en el mismo orden que estaban en A." << endl;
        cout << "7. Dada una pila A con números, buscar si existe en A un entero “X”, y reemplazarlo por un número “Y”" << endl;
        cout << "8. Salir" << endl;
        cout << "---------------------------------------------------------------------------------------" <<endl;
        cin >> op;

        switch (op)    {
        case 1:
            for (int i = 1; i <= 10; ++i) {
                pilaA.cargarPila(i);
            }
            cout << "La pila fue cargada exitosamente" << endl;
            break;
        case 2:
            cout << "Pila A" << endl;
            pilaA.mostrarValores();
            pilaA.pasaPila(pilaB);
            cout << "Pila B" << endl;
            pilaB.mostrarValores();
            cout << "Pila A" << endl;
            pilaA.mostrarValores();
            break;
        case 3:
            cout << "Pila A" << endl;
            pilaA.mostrarValores();
            cout << "ingrese un valor a buscar" << endl;
            int n;
            cin >> n;

            if (pilaA.contieneE(n)) {
                cout << "El elemento " << n << " se encuentra en la pila" << endl;

            }else{
                cout << "El elemento " << n << " No se encuentra en la pila" << endl;
            }
        pilaA.mostrarValores();

            break;
        case 4:
            cout << "Pila A" << endl;
            pilaA.mostrarValores();
            pilaA.separaPila(pilaB,pilaC);
            cout << "Pila A" << endl;
            pilaA.mostrarValores();
            cout << "Pila B" << endl;
            pilaB.mostrarValores();
            cout << "Pila C" << endl;
            pilaC.mostrarValores();

            break;
        case 5:
            cout << "Pila A" << endl;
            pilaA.mostrarValores();
            pilaA.Invierte1(pilaB,pilaC);
            cout << "Pila A" << endl;
            pilaA.mostrarValores();
            cout << "Pila B" << endl;
            pilaB.mostrarValores();
            cout << "Pila C" << endl;
            pilaC.mostrarValores();

            break;
        case 6:
            cout << "Pila A" << endl;
            pilaA.mostrarValores();
            pilaA.Invierte2(pilaB);
            cout << "Pila A" << endl;
            pilaA.mostrarValores();
            cout << "Pila B" << endl;
            pilaB.mostrarValores();

            break;
        case 7:
            cout << "Pila A" << endl;
            pilaA.mostrarValores();
            cout << "Ingrese el elemento a remplazar de la pila A"<<endl;
            int x;
            cin>>x;
            cout << "Ingrese el elemento por el cual lo quiere remplzar"<<endl;
            int y;
            cin>>y;
            pilaA.remplazaXporY(x,y);
            cout << "Pila A" << endl;
            pilaA.mostrarValores();
            break;
        case 8:
            cout << "Cerrando programa" << endl;
            break;
        
        default:
            break;
        }

    } while (op !=8);


    return 0;
}
