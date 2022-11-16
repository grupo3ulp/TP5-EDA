/*    1. En el menú principal, se cuenta con las siguientes variables: pilaA, pilaB, pilaC, aux1 
    todos los datos son enteros, y los procedimientos o funciones son los que siguen: 
    a. Implemente la estructura Pila de Enteros que permita trabajar con variables de tipo Pila.
    b. cargaPila, que permita introducir datos en la PilaA 
    c. pasaPila, pasa todos los elementos de pilaA a PilaB 
    d. contieneE, que recibe un entero “X” y determina si está en la pilaA, todos los elementos deben quedar nuevamente en A  
    e. SeparaPI, que dada la pilaA con números enteros, coloca en pilaB los pares y en PilaC los impares  
    f. Invierte1, Dada una Pila A con números, una Pila B y una Pila C vacías, pasar los elementos de A a B de manera que queden en el mismo orden que estaban en A. (Se permite utilizar la pila C como auxiliar)
    g. Invierte2, que dada una Pila A, una variable X y una Pila Vacía B. Pasar los elementos de pilaA a pilaB de manera tal que en pilaB queden en el mismo orden que estaban en pilaA   
    h. Dada una pila A con números, buscar si existe en A un entero “X”, y reemplazarlo por un número “Y”*/

    #include <iostream>
    #include <stdlib.h>
    using namespace std;

    struct Pila{
        private: int dato[10];
        private: int tope = -1;

        public: 
        void cargaPila(){
            int m;
            int aux = tope + 1;

            cout << "aux: " << aux << "tope: " << tope << endl;
            cout << "¿Cuántos datos quiere ingresar? (El tope es 10)" << endl;
            cin >> m;
            if (m > 10 - aux){
               cout << "El número excede el tope de la pila" << endl;
            } else if( aux == 10){
                cout << "Llegaste al límite de la pila!" << endl;
            } else {
                
                for (int i = 0; i < m; i++) {
                    cout << "Ingrese un número" << endl;
                    cin >> dato[aux];
                    tope ++;
                }
                
            }       
        }

        void pasaPila(){

        }

    void contieneE(){

    }

    void separaPI(){

    }

    void invierte1(){

    }

    void invierte2(){

    }
    };

    int main(){
        Pila pilaA, pilaB, pilaC, aux1;
        int n,m;

        pilaA.cargaPila();
        pilaA.cargaPila();
        pilaA.cargaPila();
                
        return 0;
    }