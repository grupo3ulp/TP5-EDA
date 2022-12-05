#include <iostream>

using namespace std;

const int N = 10;

enum Operacion {
    D, E, O
};

struct Persona {
    string dni;
    Operacion operacion;
};

struct Fila {
private:
    int p = 0;
    int u = -1;
    int cant = 0;
    Persona personas[N];

public:
    void init() {
        int p = 0;
        int u = -1;
        int cant = 0;
    }

    bool empty() {
        return cant == 0;
    }

    bool full() {
        return cant == N;
    }

    bool push(Persona persona) {

        if (!full()) {
            if (u == N - 1) {
                u = -1;
            }
            u++;
            personas[u] = persona;
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

    Persona front() {
        return personas[p];
    }

    Persona back() {
        return personas[u];
    }

    int size() {
        return cant;
    }
};

Operacion elejirOp(int i) {
    switch (i) {
        case 1: {
            return D;
        }
        case 2: {
            return E;
        }
        case 3: {
            return O;
        }
    }
}

int main() {

    Persona p1 = {"111111111", O}, p2 = {"22222222", O}, p3 = {"33333333", O},
    p4 = {"4444444444", O}, p5 = {"55555555555", O}, p6 = {"66666666", O},
    p7 = {"77777777777", O};
    Persona p8 = {"888888888", O},p9 = {"99999999", O},p10 = {"1010101010", O};

    Fila filaD, filaE, filaO;

    filaO.push(p1);
    filaO.push(p2);
    filaO.push(p3);
    filaO.push(p4);
    filaO.push(p5);
    filaO.push(p6);
    filaO.push(p7);
    filaO.push(p8);
    filaO.push(p9);
    filaO.push(p10);

    int opc;


    do {
        cout << "--------------------------------------------" << endl;
        cout << "MENU" << endl;
        cout << "1. Sacar Turno" << endl;
        cout << "2. Atender" << endl;
        cout << "3. Ver Primero" << endl;
        cout << "4. Ver Ultimo" << endl;
        cout << "5. Ver Cantidad de Gente" << endl;
        cout << "0. EXIT" << endl;
        cin >> opc;
        switch (opc) {
            case 1: {
                Persona p;
                cout << "SELECCIONAR OPEACION" << endl;
                cout << "1.Depocitos" << endl;
                cout << "2.Extracciones" << endl;
                cout << "3.Operaciones Varias" << endl;
                cin >> opc;
                while (opc > 3 || opc < 1) {
                    cout << "Opcion incorrecta, Elija nuevamente una opcion del 1 al 3" << endl;
                    cin >> opc;
                }

                p.operacion = elejirOp(opc);

                cout << "Ingrese su numero de DNI" << endl;
                cin >> p.dni;

                switch (opc) {
                    case 1: {
                        if (filaD.push(p)) {
                            cout << "Se agrego a la persona con el DNI " << p.dni << " en la fila correctamente"
                                 << endl;
                        } else {
                            cout << "No se pudo agregar a la persona en la fila ya que se encuentra llena" << endl;
                        }
                        break;

                    }
                    case 2: {
                        if (filaE.push(p)) {
                            cout << "Se agrego a la persona con el DNI " << p.dni << " en la fila correctamente"
                                 << endl;
                        } else {
                            cout << "No se pudo agregar a la persona en la fila ya que se encuentra llena" << endl;
                        }
                        break;
                    }
                    case 3: {
                        if (filaO.push(p)) {
                            cout << "Se agrego a la persona con el DNI " << p.dni << " en la fila correctamente"
                                 << endl;
                        } else {
                            cout << "No se pudo agregar a la persona en la fila ya que se encuentra llena" << endl;
                        }
                        break;
                    }

                }
                break;
            }
            case 2: {
                cout << "ELEGIR FILA A ATENDER" << endl;
                cout << "1.Fila de Depocitos" << endl;
                cout << "2.Fila de Extracciones" << endl;
                cout << "3.Fila de Operaciones Varias" << endl;
                cin >> opc;
                while (opc > 3 || opc < 1) {
                    cout << "Opcion incorrecta, Elija nuevamente una opcion del 1 al 3" << endl;
                    cin >> opc;
                }
                switch (opc) {
                    case 1: {
                        Persona aux = filaD.front();
                        if (filaD.pop()) {
                            cout << "Se atendio corectamente a la persona con el DNI " << aux.dni << endl;
                        } else {
                            cout << "No se pudo atender a nadie por que la fila esta vacia" << endl;
                        }
                        break;
                    }
                    case 2: {
                        Persona aux = filaE.front();
                        if (filaE.pop()) {
                            cout << "Se atendio corectamente a la persona con el DNI " << aux.dni << endl;
                        } else {
                            cout << "No se pudo atender a nadie por que la fila esta vacia" << endl;
                        }
                        break;
                    }
                    case 3: {
                        Persona aux = filaO.front();
                        if (filaO.pop()) {
                            cout << "Se atendio corectamente a la persona con el DNI " << aux.dni << endl;
                        } else {
                            cout << "No se pudo atender a nadie por que la fila esta vacia" << endl;
                        }
                        break;
                    }

                }
                break;
            }
            case 3: {
                cout << "ELEGIR FILA" << endl;
                cout << "1.Fila de Depocitos" << endl;
                cout << "2.Fila de Extracciones" << endl;
                cout << "3.Fila de Operaciones Varias" << endl;
                cin >> opc;
                while (opc > 3 || opc < 1) {
                    cout << "Opcion incorrecta, Elija nuevamente una opcion del 1 al 3" << endl;
                    cin >> opc;
                }
                switch (opc) {
                    case 1: {
                        cout << "La primera persona de la Fila de Depocitos tiene el DNI " << filaD.front().dni << endl;
                        break;
                    }
                    case 2: {
                        cout << "La primera persona de la Fila de Extracciones tiene el DNI " << filaE.front().dni
                             << endl;
                        break;
                    }
                    case 3: {
                        cout << "La primera persona de la Fila de Operaciones Varias tiene el DNI " << filaO.front().dni
                             << endl;
                        break;
                    }
                }
                break;
            }
            case 4: {
                cout << "ELEGIR FILA" << endl;
                cout << "1.Fila de Depocitos" << endl;
                cout << "2.Fila de Extracciones" << endl;
                cout << "3.Fila de Operaciones Varias" << endl;
                cin >> opc;
                while (opc > 3 || opc < 1) {
                    cout << "Opcion incorrecta, Elija nuevamente una opcion del 1 al 3" << endl;
                    cin >> opc;
                }
                switch (opc) {
                    case 1: {
                        cout << "La ultima persona de la Fila de Depocitos tiene el DNI " << filaD.back().dni << endl;
                        break;
                    }
                    case 2: {
                        cout << "La ultima persona de la Fila de Extracciones tiene el DNI " << filaE.back().dni
                             << endl;
                        break;
                    }
                    case 3: {
                        cout << "La ultima persona de la Fila de Operaciones Varias tiene el DNI " << filaO.back().dni
                             << endl;
                        break;
                    }
                }
                break;
            }
            case 5: {
                cout << "ELEGIR FILA" << endl;
                cout << "1.Fila de Depocitos" << endl;
                cout << "2.Fila de Extracciones" << endl;
                cout << "3.Fila de Operaciones Varias" << endl;
                cin >> opc;
                while (opc > 3 || opc < 1) {
                    cout << "Opcion incorrecta, Elija nuevamente una opcion del 1 al 3" << endl;
                    cin >> opc;
                }
                cin;

                switch (opc) {
                    case 1: {
                        cout << "La cantidad de personas en la Fila de Depocitos es de " << filaD.size() << endl;
                        break;
                    }
                    case 2: {
                        cout << "La cantidad de personas en la Fila de Extracciones es de " << filaE.size() << endl;
                        break;
                    }
                    case 3: {
                        cout << "La cantidad de personas en la Fila de Operaciones es de " << filaO.size() << endl;
                        break;
                    }
                }
                break;
            }
            case 0: {

                break;
            }
            default: {
                cout << "Opcion incorrecta, Elija nuevamente una opcion del 1 al 5" << endl;
                break;
            }


        }

    } while (opc != 0);

    return 0;
}
