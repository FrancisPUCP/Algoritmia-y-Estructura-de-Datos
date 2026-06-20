#include <iostream>
#include <iomanip>
using namespace std;
#define N 10
int obtener_maxima_1(int arreglo[],int inicio,int fin) {
    if (inicio == fin) return fin;
    int medio=(inicio+fin)/2;
    if (arreglo[medio]>arreglo[medio+1] and arreglo[medio]>arreglo[medio-1]) {
        return medio;
    }
    if (arreglo[inicio]==0 and arreglo[medio]==0) {
        // vamos a la derecha
        return obtener_maxima_1(arreglo,medio+1,fin);
    } else {
        if (arreglo[medio]<arreglo[medio+1]) {
            // vamos a la derecha
            return obtener_maxima_1(arreglo,medio+1,fin);
        }else {
            if (arreglo[medio]==arreglo[medio+1]) {
                if (arreglo[medio-1]<arreglo[medio]) {
                    // vamos a la derecha
                    return obtener_maxima_1(arreglo,medio+1,fin);
                }else {
                    // vamo a la izquierda
                    return obtener_maxima_1(arreglo,inicio,medio);
                }
            }else {
                // vamo a la izquierda
                return obtener_maxima_1(arreglo,inicio,medio);
            }
        }
    }

}

void obtener_maxima_pureza(int matriz[N][N]) {
    int maxima=-9999;
    int muestra=-1;
    int estrato=-1;
    for (int i = 0; i < N; i++) {
        int max=obtener_maxima_1(matriz[i],0,N-1);

        if (maxima<matriz[i][max]) {
            muestra=i;
            estrato=max;
            maxima=matriz[i][max];
        }
    }
    cout << "La maxima pureza es: " << maxima << endl;
}
int contar_minerales1(int arreglo[],int inicio,int fin) {
    if (inicio >= fin) {
        if (arreglo[fin]==0) {
            return 0;
        }else {
            return 1;
        }
    }
    int medio=(inicio+fin)/2;

    if (arreglo[medio]!=0) {
        // vamos a la izquierda
        return fin-medio+1+contar_minerales1(arreglo, inicio, medio-1);
    }else {

            // para la derecha
            return contar_minerales1(arreglo, medio+1, fin);

    }
}
int contar_minerales2(int arreglo[],int inicio,int fin) {
    if (inicio == fin) {
        if (arreglo[inicio]==0 ) {
            return 0;
        }else {
            return 1;
        }
    }else if (fin<inicio) {
        return 0;
    }
    int medio=(inicio+fin)/2;
    if (arreglo[medio]!=0) {
        // vamos a la derecha
        return medio-inicio+1+contar_minerales2(arreglo, medio+1, fin);
    }else {

        // para la izquierda
        return contar_minerales2(arreglo, inicio, medio-1);

    }
}
void mayor_cantidad(int matriz[N][N]) {
    int mayor_cantidad=INT_MIN;
    int arreglo[N];
    for (int i = 0; i < N; i++) {
        int cantidad=0;
        if (matriz[i][0]==0) {
            cantidad=contar_minerales1(matriz[i],0,N-1);
        }else{
            cantidad=contar_minerales2(matriz[i],0,N-1);
        }
        if (mayor_cantidad<cantidad) {
            mayor_cantidad=cantidad;
        }
        arreglo[i]=cantidad;
    }

    cout << "Las muestras con mayor cantida de niveles con minerales son: ";
    for (int i = 0; i < N; i++) {
        if (mayor_cantidad==arreglo[i]) {
            cout<<i+1<<" ";
        }
    }
    cout<<endl;
    cout<<"ambos con "<<mayor_cantidad<<" estratos de minerales"<<endl;

}
int main() {
    int matriz[N][N] = {
        {0, 0,  0, 3, 3, 7, 5, 5, 1, 1},
        {8, 8, 10, 9, 9, 5, 4, 4, 2, 0},
        {3, 5,  8, 9, 7, 6, 4, 2, 0, 0},
        {4, 4,  4, 6, 9, 4, 2, 0, 0, 0},
        {0, 2,  2, 3, 3, 4, 4, 5, 3, 3},
        {0, 0,  0, 0, 0, 0, 2, 3, 4, 5},
        {1, 2,  2, 3, 3, 4, 3, 2, 0, 0},
        {0, 0,  0, 0, 0, 0, 3, 5, 5, 7},
        {6, 5,  5, 2, 2, 1, 0, 0, 0, 0},
        {3, 2,  2, 0, 0, 0, 0, 0, 0, 0}
    };
    obtener_maxima_pureza(matriz);
    mayor_cantidad(matriz);
    // cout<<contar_minerales2(matriz[2],0,N-1);
    return 0;
}
