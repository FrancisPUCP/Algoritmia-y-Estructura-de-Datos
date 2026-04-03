#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void carga_base(int numero,int n,int base ,int *cromosomas) {
    for(int i=0;i<n;i++) {
        cromosomas[i]=0;
    }

    int i=0;
    while (numero>0) {
        cromosomas[i]=numero%base;
        numero=numero/base;
        i++;
    }
}

int main() {

    int numero_tablas,numero_discos;

    cout<<"Ingrese numero de tablas:";
    cin>>numero_tablas;

    int tablas[numero_tablas];
    for(int i=0;i<numero_tablas;i++) {
        cout<<"Ingrese velocidad de la tabla "<<i+1<<": ";
        cin>>tablas[i];
    }

    cout<<"Ingrese numero de discos:";
    cin>>numero_discos;

    int discos[numero_discos];
    for(int i=0;i<numero_discos;i++) {
        cout<<"Ingrese velocidad del disco "<<i+1<<": ";
        cin>>discos[i];
    }

    // base = discos + 1 (porque 0 = no asignado)
    int base = numero_discos + 1;

    int combinaciones = (int)pow(base, numero_tablas);

    int cromosomas[numero_tablas];
    int mejor = -1;
    int mejor_cromo[numero_tablas];

    for(int i=0;i<combinaciones;i++) {

        carga_base(i,numero_tablas,base,cromosomas);

        int restante[numero_discos];

        // copiar discos
        for(int d=0; d<numero_discos; d++) {
            restante[d] = discos[d];
        }

        // asignar tablas
        for(int j=0;j<numero_tablas;j++) {
            int valor = cromosomas[j];

            if(valor != 0) {
                int disco = valor - 1; // ajuste de índice
                restante[disco] -= tablas[j];
            }
        }

        // validar capacidades
        bool valido = true;
        for(int d=0;d<numero_discos;d++) {
            if (restante[d] < 0) {
                valido = false;
                break;
            }
        }

        // 🔥 evitar solución trivial (todo 0)
        bool uso_algo = false;
        for(int j=0;j<numero_tablas;j++) {
            if(cromosomas[j] != 0) {
                uso_algo = true;
                break;
            }
        }

        if(!uso_algo) valido = false;

        // evaluar
        if (valido) {

            int minimo = restante[0];
            for(int d=1;d<numero_discos;d++) {
                if (restante[d] < minimo) {
                    minimo = restante[d];
                }
            }

            if (minimo > mejor) {
                mejor = minimo;

                for(int j=0;j<numero_tablas;j++) {
                    mejor_cromo[j] = cromosomas[j];
                }
            }
        }
    }

    // resultado final
    if(mejor == -1) {
        cout<<"\nNo se encontro solucion valida"<<endl;
        return 0;
    }

    cout<<"\nMEJOR SOLUCION FINAL"<<endl;
    cout<<"Minimo restante: "<<mejor<<endl;

    cout<<"\nAsignacion:\n";
    for(int j=0;j<numero_tablas;j++) {
        if(mejor_cromo[j]==0)
            cout<<"Tabla "<<j+1<<" -> No usada"<<endl;
        else
            cout<<"Tabla "<<j+1<<" -> Disco "<<mejor_cromo[j]<<endl;
    }

    return 0;
}
