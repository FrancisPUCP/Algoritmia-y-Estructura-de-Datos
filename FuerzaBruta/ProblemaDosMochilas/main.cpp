#include <iostream>
#include <iomanip>
using namespace std;
#include <cmath>
void  carga_binaria(int numero,int n,int *cromosomas) {
    int residuo;
    for (int j=0;j<n;j++) {
        cromosomas[j]=0;
    }
    int i=0;
    while (numero > 0) {
        residuo = numero % 3;
        numero = numero / 3;
        cromosomas[i] = residuo;
        i++;
    }
}
int main() {
    int paquetes[]={3,5,4,7,6};
    int peso1=10;
    int peso2=12;
    int n= sizeof(paquetes)/sizeof(paquetes[0]); // obtenemos la cantidad de paquetes
    int combinaciones = (int) pow(3,n);
    int cromosomas[n];
    int mejor=0;
    for (int i=0;i<combinaciones;i++) {
        int peso_parcial1=0, peso_parcial2=0;
        carga_binaria   (i,n,cromosomas);
        for (int j=0;j<n;j++) {
            if (cromosomas[j] ==1) {
                peso_parcial1 += paquetes[j];
            }else if (cromosomas[j] ==2) {
                peso_parcial2 += paquetes[j];
            }
        }
        if (peso_parcial1 <=peso1 && peso_parcial2<=peso2) {
            int total = peso_parcial1 + peso_parcial2;
            if (total>mejor) {
                mejor = total;
                cout<<"Se encontro la mejor solución:"<<endl;
                cout<<"Decimal:"<<i<<endl;
                for (int j=0;j<n;j++) {
                    cout<<cromosomas[j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
