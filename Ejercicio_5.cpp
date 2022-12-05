#include <iostream>
#include <queue>

#include  <cstdio>

using namespace std;
const int MAX = 10;

struct Pila {
private:
    int tope = -1;
    int enteros[MAX];
public:
    bool empty() {
        return tope < 0;
    }

    int front() {
        return enteros[tope];
    }

    bool pop() {
        if (empty()) {
            return false;
        } else {
            tope--;
            return true;
        }
    }

    bool push(int n) {
        if (tope < MAX) {
            tope++;
            enteros[tope] = n;
            return true;
        } else {
            return false;
        }
    }

    void pasaPila(Pila &pila) {
        while (tope >= 0) {
            pila.push(enteros[tope]);
            pop();
        }
    }

    void mostrarPila() {
        if (!empty()) {
            for (int i = 0; i <= tope; ++i) {
                cout << enteros[i] << " - ";
            }
        } else {
            cout << "la Pila se encuentra vacia";
        }
        cout << endl;
    }

    bool contieneE(int n) {
        Pila aux;
        bool flag = false;
        for (int i = tope; i >= 0; --i) {
            if (front() == n) {
                flag = true;
                break;
            } else {
                aux.push(front());
                pop();
            }
        }
        aux.pasaPila(*this);
        if (flag) {
            return true;
        } else {
            return false;
        }

    }

    void separaPila(Pila &pilaB, Pila &pilaC) {
        for (int i = tope; i >= 0; --i) {
            if (front() % 2 == 0) {
                pilaB.push(front());
                pop();
            } else {
                pilaC.push(front());
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

    bool remplazaXporY(int x, int y) {
        Pila aux;
        bool flag = false;
        for (int i = tope; i >= 0; --i) {
            if (front() == x) {
                enteros[tope] = y;
                flag = true;
            } else {
                aux.push(front());
                pop();
            }
        }
        aux.pasaPila(*this);
        if (!flag) {
            cout << "El elemento x no se encuentra en la pila" << endl;
        }
    }

    void resetPila() {
        for (size_t i = tope; i < -1; i--) {
            pop();
        }

    }


};

struct Fila {

private:
    int p = 0;
    int u = -1;
    int cant = 0;
    int elementos[MAX];

public:
    void init() {
         p = 0;
        u = -1;
        cant = 0;
    }

    bool empty() {
        return cant == 0;
    }

    bool full() {
        return cant == MAX;
    }

    bool push(int elemento) {
        /* if (!full()) {
        u=(1+U)%MAX;
        elementos[u] = elemento;
        cant++;
        return true;
    } else {
        return false;
    }*/

        if (!full()) {
            if (u < MAX - 1) {
                u++;
            } else {
                u = 0;
            }
            elementos[u] = elemento;
            cant++;
            return true;
        } else {
            return false;
        }
    }

    bool pop() {
        if (!empty()) {
            cant--;
            p++;
            return true;
        } else {
            return false;
        }
    }

    int front() {
        return elementos[p];
    }

    int back() {
        return elementos[u];
    }

    int size() {
        return cant;
    }

    void mostrarFila() {
        int c = 0, auxP = p;
        if (!empty()) {
            while (c < cant) {
                if (auxP > MAX - 1) {
                    auxP = 0;
                }
                cout << elementos[auxP] << " - ";
                auxP++;
                c++;

            }
            cout << endl;
        } else {
            cout << "Fila Vacia" << endl;
        }
    }

    bool contieneX(int x) {
        Fila filaAux;
        bool flag = false;

        while (!empty()) {
            if (front() == x) {
                flag = true;
            }
            filaAux.push(front());
            pop();
        }


        while (!filaAux.empty()) {
            push(filaAux.front());
            filaAux.pop();
        }
        return flag;
    }


};

//a)
void invertirCola(Fila &adelante, Fila &atras) {

    if (adelante.size() >= 1) {
        int x = adelante.front();
        adelante.pop();
        invertirCola(adelante, atras);
        atras.push(x);
    }
}

//b)
void copiarPilaEnFila(Fila &fila, Pila &pila) {
    Pila pilaAux;
    pila.pasaPila(pilaAux);
    while (!pilaAux.empty()) {
        fila.push(pilaAux.front());
        pila.push(pilaAux.front());
        pilaAux.pop();
    }
}


int main() {
    //a)Dada una fila A, Invertirla. Mostrar ambas filas. (usar fila auxiliar si lo necesita)
    cout << "EJERCICIO 5a" << endl;
    Pila pilaA;
    Fila filaA, filaB, filaC;
    int x;
    for (int i = 1; i <= MAX; ++i) {
        filaA.push(i);
    }
    for (int i = 1; i <= MAX; ++i) {
        pilaA.push(i);
    }
    cout << "FILA A" << endl;
    filaA.mostrarFila();
    cout << "FILA B" << endl;
    filaB.mostrarFila();
    cout << "----------------" << endl;
    invertirCola(filaA, filaB);
    cout << "FILA A" << endl;
    filaA.mostrarFila();
    cout << "FILA B" << endl;
    filaB.mostrarFila();

    cout << "======================================" << endl;
    cout << "======================================" << endl;
    cout << "EJERCICIO 5b" << endl;
    //b)Utilizando las operaciones de pila y de Fila, COPIE el contenido de una pila P, a una Fila C, de tal manera que
    // el primer elemento de la Fila será el elemento “F” que se encuentra en el fondo de la pila, el segundo de la Fila
    // el que está apilado sobre “F”, y así siguiendo. De esta forma el elemento del tope de la pila quedará en el último
    // lugar de la Fila. (Para resolver este ejercicio, use pila auxiliar)
    cout << "FILA C" << endl;
    filaA.mostrarFila();
    cout << "PILA A" << endl;
    pilaA.mostrarPila();
    cout << "----------------" << endl;
    copiarPilaEnFila(filaA, pilaA);
    cout << "FILA C" << endl;
    filaA.mostrarFila();
    cout << "PILA A" << endl;
    pilaA.mostrarPila();

    cout << "======================================" << endl;
    cout << "======================================" << endl;
    cout << "EJERCICIO 5c" << endl;
    //Ahora queremos buscar si el número entero X determinar está en la Fila A. La Fila A deberá quedar en su
    // estado original al finalizar el algoritmo.
    cout << "FILA A AL INICIO" << endl;
    filaA.mostrarFila();
    filaA.init();
    for (int i = 1; i <= MAX; ++i) {
        filaA.push(i);
    }
    cout << "Ingrese un valor a entero natural a buscar en la fila" << endl;
    cin >>x;
    if(filaA.contieneX(x)){
        cout << "El valor a entero " << x << " está en la fila"<< endl;
    }else{
        cout << "El valor a entero " << x << " no está en la fila"<<endl;
    }
    cout << "FILA A AL FINAL" << endl;
    filaA.mostrarFila();

    cout << "======================================" << endl;
    cout << "======================================" << endl;
    cout << "EJERCICIO 5d" << endl;
    //Además de la Fila A cree la fila B, vacíe la fila A y cargue A y B con elementos ordenados,
    // realice un algoritmo que inserte los elementos de la fila A y B en otra fila C de manera tal que queden ordenados.

    return 0;
}
