/* 3. Implemente la estructura necesaria que permita trabajar con variables de tipo Queue.    
4. Se desea modelar las filas de un banco, de cada persona se sabe el DNI y la operación que desea realizar, 
las operaciones son depósitos(D), extracciones(E), varios (O). Declare tres Queues de cada tipo de operación correspondiente.
Inicialmente la gente forma 1 fila, cuando comienza la atención las personas se distribuyen según la operación, 
sacando un turno (botón “Sacar turno”). Modele estructura persona. Debe introducir por una pantalla un DNI, 
y elegir el tipo de operación, según sea, se encola la persona para ser atendida en la fila correspondiente.
Otra función, elimina gente de la fila elegida. Se deben refrescar las filas con cada nuevo turno que se saque y agregue.*/

#include <iostream>
using namespace std;

const int MAX = 1000;

enum operaciones {
    D,E,O
};

string enum_to_string(operaciones op) {
    switch (op) {
        case 0:
            return "Depósitos";
        case 1:
            return "Extracciones";
        case 2:
            return "Varios";
    }
}

struct Persona{
    int DNI;
    operaciones op;
};

struct Cola{
    private:
        Persona p[MAX];
        int cantidad = 0;
        int P = 0; //primero
        int U = -1; // último
    public:
            void encolar(int dni, operaciones o){
                if (cantidad!=MAX){
                    if (U<MAX){
                        U++;
                    } else{
                        U = 0;
                    }
                    p[U].DNI = dni;
                    p[U].op = o;
                    cantidad++;
                }
                
            }
            void mostrarFila(){
                for (int i = 0; i < cantidad; i++) {
                    cout << "------------------" << endl;
                    cout << "Persona #" << i << endl;
                    cout << "DNI: "<< p[i].DNI << endl;
                    cout << "Operación: "<< enum_to_string(p[i].op) << endl;
                    cout << "------------------" << endl;
                }
                
            }

}fila1, filaD, filaE, filaO;

void separarFilas(Persona p){
    if (p.op == O){
        filaO.encolar(p.DNI, p.op);
        cout << "La persona fue añadida a la fila de operaciones Varios(O)" << endl;
    }
    if (p.op == D){
        filaD.encolar(p.DNI, p.op);
        cout << "La persona fue añadida a la fila de operaciones Depósitos(D)" << endl;
    }
    if (p.op == E){
        filaE.encolar(p.DNI, p.op);
        cout << "La persona fue añadida a la fila de operaciones Extracciones(E)" << endl;
    }

}


int main(){

    //Creamos 3 personas que corresponden a los 3 tipos de operaciones
    Persona p1, p2, p3;
    p1 = {39332491, D};
    p2 = {32642491, E};
    p3 = {32684411, O};

    //Al comienzo van a estar todas en la misma fila
    fila1.encolar(p1.DNI, p1.op);
    fila1.encolar(p2.DNI, p2.op);
    fila1.encolar(p3.DNI, p3.op);

    //Luego se las separa según la operación
    separarFilas(p1);
    separarFilas(p2);
    separarFilas(p3);

    //Mostrando las filas
    cout << "Fila D: " << endl;
    filaD.mostrarFila();
    cout << "Fila E: " << endl;
    filaE.mostrarFila();
    cout << "Fila O: " << endl;
    filaO.mostrarFila();

    return 0;
}