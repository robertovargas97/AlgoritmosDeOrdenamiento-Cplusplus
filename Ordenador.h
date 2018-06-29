/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ordenador.h
 * Author: Roberto Vargas <robertovargasrojas97@gmail.com>
 *
 * Created on 26 de marzo de 2018, 04:14 PM
 */

#ifndef _CLASE_ORDENADOR
#define _CLASE_ORDENADOR
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "time.h"
using namespace std;

class Ordenador {
private:

    //Defina aqu’ los mŽtodos auxiliares de los algoritmos de ordenamiento solamente.
    //Puede definir cuantos mŽtodos quiera.

public:

    Ordenador();

    ~Ordenador();

    //Si piensa no implementar algunos de los mŽtodos de ordenamiento, no los borre,
    //simplemente dŽjelos con el cuerpo vac’o para evitar errores de compilaci—n, ya
    //que se va a ejecutar el mismo ÔmainÕ para todas las tareas.
    void seleccion(int * arreglo, int tamano);

    void insercion(int * arreglo, int tamano);

    void mergesort(int * arreglo, int tamano);

    void heapsort(int * arreglo, int tamano);

    void quicksort(int * arreglo, int tamano);

    void radixsort(int * arreglo, int tamano);

    int mediana(int * arreglo, int tamano);

private:
    void mezcla(int inicio, int final, int *vec); //Metodo que se llamará para probar mergesort

    //-----Metodos para implementar el heapsort-------------//
    void monticularizar(int *arreglo, int t);
    void corregirCima(int * arreglo, int k,int t);
    int extraerMaximo(int * arreglo, int t);
    //-----------------------------------------------------//

    //-----Metodos para implementar Quicksort-------------//
    int partition(int *arreglo, int inicio, int fin);
    void quickS(int *arreglo, int inicio, int fin);
    //int partitionCormen(int *arreglo, int inicio, int fin); 

    //-----------------------------------------------------//

    //-----Metodos para implementar la mediana-------------//
    int randomized_Select(int *arreglo, int p, int r, int i);
    //-----------------------------------------------------//


    //------------------Metodos para implementar el Radix Sort------------//
    void Counting_Sort(int *arreglo, int *v_temporal, int tamano);
    void arregla(int *arreglo, int tamano);
    //-----------------------------------------------------//


    //DEBIDO A QUE SOLO SE PUEDEN AGREGAR METODOS PRIVADOS, LOS METODOS PARA LLENAR EL ARREGLO Y VERIFICARLO SE
    //IMPLEMENTARON EN EL MAIN
    //SE PONEN A CONTINUACION PARA QUE LOS PUEDA USAR A LA HORA DE REVISAR


    /* METODO PARA LLENAR ARREGLO 
     
     void LlenarArreglo(int *v, int t) { 

    srand(time(NULL));
    int numAleatorio;
    int esNegativo =0;
    
    for (int i = 0; i < t; i++) {
        numAleatorio = rand() % t + 1; //Crea numero aleatorio de 0 hasta t ,es decir el tamaño del arreglo
        
        esNegativo= rand() % 10 + 1; //Crea numero aleatorio para decidir si el numero que se metera en el arreglo sera positivo o negativo
        
        if (esNegativo > 10 / 2) { 
            numAleatorio = numAleatorio*-1;
        }
        v[i] = numAleatorio;
        // cout << v[i] << " ";
    }
} 
     */


    /*METODO PARA COMPROBAR SI SE ORDENO CORRECTAMENTE
     
     void EstaOrdenado(int n, int *A) {
    for (int i = 1; i < n; i++) {
        if (A[i] < A[i - 1]) {
            cout << " No esta en orden";
        }
    }
}
     
     */



};
#endif


