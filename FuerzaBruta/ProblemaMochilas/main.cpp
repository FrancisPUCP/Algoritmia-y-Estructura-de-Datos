#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void  carga_binaria(int numero,int n,int *cromo) {
    int residuo;
    for (int j=0;j<n;j++) {
        cromo[j]=0;
    }
    int i=0;
    while (numero>0) {
        residuo=numero%2;
        numero=numero/2;
        cromo[i]=residuo;
        i++;
    }
}
int main() {
    int paq[]={1,2,1,12,4};
    int peso = 15;
    int n = sizeof(paq)/sizeof(paq[0]); // numero de paquetes

    int cromo[n];
    int comb=(int) pow(2,n);

    for (int i=0;i<comb;i++) {
        int peso_parcial=0;
        carga_binaria(i,n,cromo);
        for (int j=0;j<n;j++) {
            peso_parcial=peso_parcial+paq[j]*cromo[j];

        }
        if (peso_parcial==peso) {
            cout<<"Encontre la solucion"<<endl;
            cout<<"Decimal:"<<i<<endl;
            for (int j=0;j<n;j++) {
                cout<<cromo[j]<<" ";
                cout<<endl;
            }
        }
    }
    return 0;
}
