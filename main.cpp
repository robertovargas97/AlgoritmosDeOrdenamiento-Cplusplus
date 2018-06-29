/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Roberto Vargas <robertovargasrojas97@gmail.com>
 *
 * Created on 26 de marzo de 2018, 04:12 PM
 */

#include <cstdlib>

using namespace std;
#include "Ordenador.h"

/*
 * 
 */
void LlenarArreglo(int *v, int t) {

    srand(time(NULL));
    int numAleatorio;

    int esNegativo = 0;

    for (int i = 0; i < t; i++) {
        numAleatorio = rand() % t + 1; //Crea numero aleatorio de 0 hasta t ,es decir el tamaño del arreglo

        esNegativo = rand() % 10 + 1; //Crea numero aleatorio para decidir si el numero que se metera en el arreglo sera positivo o negativo

        if (esNegativo > 10 / 2) {
            numAleatorio = numAleatorio*-1;
        }
        v[i] = numAleatorio;
        // cout << v[i] << " ";
    }
}

void LlenarArreglo1(int *v, int t) {
    for (int i = 0; i < t; i++) {
        cin >> v[i];
    }
}

void EstaOrdenado(int n, int *A) {
    for (int i = 1; i < n; i++) {
        if (A[i] < A[i - 1]) {
            cout << " No esta en orden con " << i - 1 << " y " << i;
        }
    }
}

void imprimirArreglo(int *v, int t) {
    for (int i = 0; i < t; i++) {
        cout << v[i] << " ";
    }
}

int main(int argc, char** argv) {



    //Inicia Prueba de Seleccion// 

    Ordenador a;
    double t0 = 0, t1 = 0, time = 0;
    int tam = 0;
    int e = 0;
    cin>>tam;
    int *vec = new int [tam];

    for (int i = 0; i < tam; i++) {
        cin>>e;
        vec[i] = e;
    }
    // imprimirArreglo(vec, tam);
    cout << endl;
    t0 = clock(); //Marca tiempo de inicio
    a.seleccion(vec, tam); //Ejecuta algoritmo a probar
    t1 = clock(); //Marca tiempo final
    time = (double(t1 - t0) / CLOCKS_PER_SEC); //Guarda el tiempo en segundos
    EstaOrdenado(tam, vec); //Avisa si el arreglo no esta ordenado
    cout << endl;
    imprimirArreglo(vec, tam);
    cout << "Seleccion duro en ordenar : " << time << " segs " << endl;
    delete[]vec;

    /*

        //Inicia Prueba de Insercion//
        Ordenador a1;
        double t00 = 0, t01 = 0, time1 = 0;
        int tam1 = 0;
        cin>>tam1;
        int *vec1 = new int [tam1];
        LlenarArreglo(vec1, tam1);


        t00 = clock(); //Marca tiempo de inicio
        a1.insercion(vec1, tam1); //Ejecuta algoritmo a probar
        t01 = clock(); //Marca tiempo final
        time1 = (double(t01 - t00) / CLOCKS_PER_SEC); //Guarda el tiempo en segundos
        EstaOrdenado(tam1, vec1);
        // imprimirArreglo(vec1, tam1);
        cout << "Insercion duro en ordenar : " << time1 << " segs " << endl;
        delete[]vec1;




        //Inicia Prueba de Merge//

        Ordenador merge;
        double tm = 0, tm1 = 0, timem = 0;
        int tamm = 0;
        cin>>tamm;
        int *vecm = new int [tamm];
        LlenarArreglo(vecm, tamm);


        tm = clock(); //Marca tiempo de inicio
        merge.mergesort(vecm, tamm); //Ejecuta algoritmo a probar
        tm1 = clock(); //Marca tiempo final
        timem = (double(tm1 - tm) / CLOCKS_PER_SEC); //Guarda el tiempo en segundos
        // imprimirArreglo(vecm, tamm);
        cout << "Merge duro en ordenar : " << timem << " segs " << endl;
        EstaOrdenado(tamm, vecm);

        delete[]vecm;





        //Inicia Prueba de HeapSort//
        Ordenador heap;
        double th = 0, th1 = 0, timeh = 0;
        int tamh = 0;
        cin>>tamh;
        int *vech = new int [tamh];

        LlenarArreglo(vech, tamh);
        // imprimirArreglo(vech, tamh);
        // LlenarArreglo1(vech, tamh);

        th = clock(); //Marca tiempo de inicio
        heap.heapsort(vech, tamh); //Ejecuta algoritmo a probar
        cout << endl;
        // imprimirArreglo(vech, tamh);
        cout << endl;
        th1 = clock(); //Marca tiempo final
        timeh = (double(th1 - th) / CLOCKS_PER_SEC); //Guarda el tiempo en segundos
        cout << "HeapSort duro en ordenar : " << timeh << " segs " << endl;
        EstaOrdenado(tamh, vech);
        delete[]vech;


        //Inicia Prueba de QuickSort//
        Ordenador quick;
        double tq = 0, tq1 = 0, timeq = 0;
        int tamq = 0;
        cin>>tamq;
        int *vecq = new int [tamq];

        LlenarArreglo(vecq, tamq);
        //LlenarArreglo1(vecq, tamq);
        // imprimirArreglo(vecq, tamq);
        cout << endl;
        tq = clock(); //Marca tiempo de inicio
        quick.quicksort(vecq, tamq); //Ejecuta algoritmo a probar
        // imprimirArreglo(vecq, tamq);

        tq1 = clock(); //Marca tiempo final
        timeq = (double(tq1 - tq) / CLOCKS_PER_SEC); //Guarda el tiempo en segundos

        cout << "QuickSort  duro en ordenar : " << timeq << " segs " << endl;
        EstaOrdenado(tamq, vecq);
        delete [] vecq;



        //Inicia Prueba de RadixSort//
        Ordenador radix;
        double tr = 0, tr1 = 0, timer = 0;
        int tamr = 0;
        cin>>tamr;
        int *vecr = new int [tamr];

        LlenarArreglo(vecr, tamr);
        //LlenarArreglo1(vecq, tamq);
        // imprimirArreglo(vecr, tamr);
        tr = clock(); //Marca tiempo de inicio
        radix.radixsort(vecr, tamr); //Ejecuta algoritmo a probar
        tr1 = clock(); //Marca tiempo final
        timer = (double(tr1 - tr) / CLOCKS_PER_SEC); //Guarda el tiempo en segundos
        cout << "RadixSort  duro en ordenar : " << timer << " segs " << endl;
        // imprimirArreglo(vecr, tamr);
        EstaOrdenado(tamr, vecr);
        delete [] vecr;


     */

/*

    for (int i = 0; i < 30; i++) {
        //Inicia Prueba de Mediana//
        Ordenador med;
        int tamed = 0;
        cin>>tamed;

        double tmed = 0, tmed1 = 0, timed = 0;
        float to = tamed;
        int medi = ceil(to / 2); //Para saber la posicion del elemento de la mediana

        int *vecmed = new int [tamed];
        LlenarArreglo(vecmed, tamed);
        cout << "Arreglo que uso para la mediana" << endl;
        imprimirArreglo(vecmed, tamed);
        cout << endl;

        tmed = clock(); //Marca tiempo de inicio
        int elemento = med.mediana(vecmed, tamed); //Ejecuta algoritmo a probar
        tmed1 = clock(); //Marca tiempo final
        timed = (double(tmed1 - tmed) / CLOCKS_PER_SEC); //Guarda el tiempo en segundos

        cout << "El " << medi << "-esimo elemento del arreglo es: " << elemento << endl;
        cout << "Busqueda de la mediana duro " << timed << " segs" << endl;

        med.heapsort(vecmed, tamed);
        imprimirArreglo(vecmed, tamed);

        delete[] vecmed;
        cout << endl;
        cout << endl;
    }
*/
    return 0;
}

