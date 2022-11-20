#include <iostream>

using namespace std;

const int n = 10;

struct hora{
    int h;
    int m;
};

struct coche{
    string propietario;
    string placa;
    hora hora;
};

struct pila{
private:
    coche cochera[n];
    int tope = -1;


public:
    void push(coche coche){
        if (tope == 9){
            cout<<"Cochera llena"<<endl;
            return;
        }else{
            tope++;
            cochera[tope] = coche;
        }
    }

    void mostrarCochera(){
        for (int i = tope; i >= 0; --i) {
            cout<<"Propietario: "<<cochera[i].propietario<<endl;
            cout<<"Placa: "<<cochera[i].placa<<endl;
            cout<<"Horario de entrada: "<<cochera[i].hora.h<<":"<<cochera[i].hora.m<<endl;
            cout<<"----------------------------"<<endl;
        }
    }
};


int main() {
    pila cochera1, cochera2;
    coche c;
    hora hr;
    int op;
    do {


    cout<<"Ingrese una opcion"<<endl;
    cout<<"1: Estacionar un coche en la cochera 1"<<endl;
    cout<<"2: Estacionar un coche en la cochera 2"<<endl;
    cout<<"3: Mostrar la cochera 1"<<endl;
    cout<<"4: Mostrar la cochera 2"<<endl;
    cout<<"5: Salir"<<endl;
    cin>>op;
    cin.ignore();

        switch (op) {
            case 1:
                cout<<"Ingrese su nombre"<<endl;
                getline(cin, c.propietario);
                cout<<"Ingrese la placa del coche"<<endl;
                getline(cin, c.placa);
                cout<<"Ingrese la hora y minutos de entrada"<<endl;
                cin>>hr.h;
                cin>>hr.m;
                c.hora = hr;
                cochera1.push(c);
                break;
            case 2:
                cout<<"Ingrese su nombre"<<endl;
                getline(cin, c.propietario);
                cout<<"Ingrese la placa del coche"<<endl;
                getline(cin, c.placa);
                cout<<"Ingrese la hora y minutos de entrada"<<endl;
                cin>>hr.h;
                cin>>hr.m;
                c.hora = hr;
                cochera2.push(c);
                break;
            case 3:
                cochera1.mostrarCochera();
                break;
            case 4:
                cochera2.mostrarCochera();
                break;
        }
    } while (op !=5);

    return 0;
}
