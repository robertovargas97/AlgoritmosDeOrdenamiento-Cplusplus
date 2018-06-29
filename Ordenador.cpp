/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ordenador.cpp
 * Author: Roberto Vargas <robertovargasrojas97@gmail.com>
 * 
 * Created on 26 de marzo de 2018, 04:14 PM
 */

#include "Ordenador.h"
#include <algorithm>
#include <math.h> 
#define length(x) (sizeof(x)/sizeof(x[0]))

Ordenador::Ordenador() {
}

Ordenador::~Ordenador() {
}

void Ordenador::seleccion(int *arreglo, int tamano) {
    int menor = 0;
    int tmp = 0;

    for (int i = 0; i < tamano; i++) { //Recorrido para ordenar
        menor = i;
        for (int j = i + 1; j < tamano; j++) { //Recorrido para encontrar el menor
            if (arreglo[j] < arreglo[menor]) { //Si encuentra un numero menor
                menor = j;
            }
        }
        tmp = arreglo[menor];
        arreglo[menor] = arreglo[i];
        arreglo[i] = tmp;
    }
}

void Ordenador::insercion(int * arreglo, int tamano) {
    int temp = 0; //Para los cambios
    int pos = 0; //Para controlar los cambios

    for (int i = 0; i < tamano; i++) {
        pos = i; //Se guarda la posicion del menor
        temp = arreglo[i]; //Guarda el valor del numero donde está

        while ((pos > 0) && (arreglo[pos - 1] > temp)) {//Si el numero de la izquierda es mayor a donde estoy y mi arreglo no se acaba
            arreglo[pos] = arreglo[pos - 1]; //Guarda la posicion del numero izquierdo en la posicion actual simulando que se corre
            pos--; //Refresca la posicion del numero actual
        }
        arreglo[pos] = temp; //Guarda el numero actual en la posicion correspondiente simulando la insercion
    }
}

//Mezcla es un metodo privado que se utiliza para implementar el mergesort

void Ordenador::mezcla(int inicio, int final, int *vector) {
    if (((final - inicio) == 0) || ((final - inicio) == 1)) {
        return; //Salga del metodo
    }

    int tmp = (inicio + final) / 2;
    mezcla(inicio, tmp, vector);
    mezcla(tmp, final, vector);

    //Punteros para moverse sobre los arreglos
    int puntero1 = inicio;
    int puntero2 = tmp;
    int puntero3 = 0;
    //------------------------------------------//

    int vectorTemp[final - inicio];

    while ((puntero1 < tmp) || (puntero2 < final)) {
        if ((puntero1 < tmp) && (puntero2 < final)) {
            if (vector[puntero1] < vector[puntero2]) {
                vectorTemp[puntero3++] = vector[puntero1++];
            } else {
                vectorTemp[puntero3++] = vector[puntero2++];
            }
        } else if (puntero1 < tmp) {
            vectorTemp[puntero3++] = vector[puntero1++];
        } else {
            vectorTemp[puntero3++] = vector[puntero2++];
        }
    }
    for (int i = 0; i < final - inicio; i++) {
        vector[inicio + i] = vectorTemp[i];
    }
}

void Ordenador::mergesort(int * arreglo, int tamano) {
    mezcla(tamano - tamano, tamano, arreglo); //tamano-tamano se coloca en la posicion 0 es decir el inicio del arreglo
}


//------------------Metodos  para implementar heapsort-------------//

void Ordenador::corregirCima(int * arreglo, int k, int tam) {
    int temporal = 0; //Se utiliza para el intercambio en caso de ser necesario

    int j = arreglo[k]; //Guardara el mayor de el padre y los hijos, en caso de que el mayor sea el padre conserva el valor asignado inicialmente
    int pos = 0;

    if (((2 * k + 1) < tam) && (j < arreglo[2 * k + 1])) { //Si su hijo izquierdo existe y es mas grande 
        j = arreglo[2 * k + 1]; //Asigna el valor del hijo ya que es mayor
        pos = 2 * k + 1; //Guarda la posicion del hijo para luego hacer el cambio
    }
    if (((2 * k + 2) < tam) && (j < arreglo[2 * k + 2])) { //Si su hijo derecho existe y es mas grande
        j = arreglo[2 * k + 2]; //Asigna el valor del hijo ya que es mayor
        pos = 2 * k + 2; //Guarda la posicion del hijo para luego hacer el cambio
    }

    if (arreglo[k] != j) { //Si el papa es mas pequeño que el hijo
        //Se cambia el papa por el hijo 
        temporal = arreglo [k];
        arreglo[k] = j;
        arreglo[pos] = temporal;
        //Se entra a corregir cima para asegurar que quede en la posicion adecuada
        corregirCima(arreglo, pos, tam);
    }

}

void Ordenador::monticularizar(int *arreglo, int t) {
    int k = floor(t / 2); //Se posiciona en el ultimo papa
    k = k - 1; //-1 por ser manejo de arreglos
    for (k; k >= 0; k--) { //Inspecciona los padres
        corregirCima(arreglo, k, t);
    }
}

int Ordenador::extraerMaximo(int * arreglo, int t) {
    int tam = t - 1; //Por ser arreglo la ultima posicion es n-1
    int maximo = arreglo[0]; //Guarda la posicion del maximo
    arreglo[0] = arreglo[tam]; //Pone el ultimo en la primea posicion
    corregirCima(arreglo, 0, tam); //Se acomodan para que el elemento quede en la posicion correcta
    return maximo;
}

void Ordenador::heapsort(int * arreglo, int tamano) {
    monticularizar(arreglo, tamano);
    int posicion = tamano - 1; //Por ser arreglo la ultima posicion es n-1
    while (posicion >= 0) { //Mientras el arreglo no se acabe
        arreglo[posicion--] = extraerMaximo(arreglo, tamano--);
    }
}

//------------------Metodos para implementar el Quicksort-------------//

void Ordenador::quicksort(int * arreglo, int tamano) {
    quickS(arreglo, tamano - tamano, tamano);
}

int Ordenador::partition(int *arreglo, int inicio, int fin) {
    int pivote = arreglo[fin - 1]; //Toma como pivote el ultimo elemento del arreglo
    int i = inicio; //Indice que se pondra al inicio del arreglo
    int j = fin - 1; //Indice que posiciona en el ultimo elemento del arreglo en caso de que todos los elementos sean iguales
    int tmp = 0; //Variable de paso para hacer cambios

    while (i < j) { //Mientras no se encuetren los indices
        if (arreglo[i] <= pivote) { //El elemento del lado izquierdo es menor o igual al pivote
            ++i; //Muevase a la derecha 
        } else { // El elemento es mayor ,entonces se procede a mover j para el intercambio
            while ((arreglo[j] >= pivote) && (i <= j)) { //Mueva a j mientras sea mayor o igual al pivote y no se encuentre con i
                j--; //Se mueve j
            }
            //Se realiza el cambio de arreglo[j] con arreglo[i] para ponerlos en la posicion correcta
            if (i <= j) {
                tmp = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = tmp;
                i++; //Se mueve i para seguir con las comparaciones
            }
        }
    }

    //Se intercambia la posicion del arreglo[i] con el pivote
    tmp = arreglo[i];
    arreglo[i] = pivote;
    arreglo[fin - 1] = tmp;
    return i;
}

void Ordenador::quickS(int *arreglo, int inicio, int fin) {
    srand(time(NULL));
    if (fin > inicio) {
        int pivote = partition(arreglo, inicio, fin);
        quickS(arreglo, inicio, pivote); //Busca a la izquierda
        quickS(arreglo, pivote + 1, fin); //Busca a la derecha
    }
}

/*int Ordenador::partitionCormen(int *arreglo, int inicio, int fin) {
    int pivote = arreglo[fin - 1];
    int temp = 0;
    int i = inicio - 1;
    for (int j = inicio; j < fin - 1; ++j) {
        if (arreglo[j] <= pivote) {
            i = i + 1;
            temp = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = temp;
        }
    }
    temp = arreglo[i + 1];
    arreglo[i + 1] = arreglo[fin - 1];
    arreglo[fin - 1] = temp;
    return i + 1;
}
 */

//------------------Metodos para implementar el Radix Sort------------//

void Ordenador::arregla(int *arreglo, int tamano) {
    int positivos = 0; //Acumula cantidad de positivos de arreglo
    int negativos = 0; //Acumula negativos 
    int ind = 0; //Indice para moverse sobre el arreglo original

    for (int i = 0; i < tamano; i++) { //Recorre el arreglo para saber cuantos negativos y positivos tiene el arreglo

        if (arreglo[i] >= 0) { //Si el numero es positivo
            positivos++; //Aumenta la cantidad de positivos
        } else { //Sino
            negativos++; //Aumenta la cantidad de negativos
        }
    }

    //Se crean arreglos que juntos suman n para intercabiar elementos
    int *neg = new int [negativos]; //Crea arreglo para los negativos
    int *pos = new int [positivos]; //Crea arreglo para los positivos

    for (int i = 0, j = positivos; ((i < positivos) || (j < tamano)); i++, j++, ind++) { //Llena el arreglo de los positivos y negativos simultaneamente
        if ((i < positivos) && (j < tamano)) { //Mientras hayan numeros
            pos[i] = arreglo[i]; //Coloca los positivos en el arreglo
            neg[ind] = arreglo[j]; //Coloca los negativos en el arreglo
        } else if ((i >= positivos) && (j < tamano)) { //Si ya no hay positivos,pero quedan negativos
            neg[ind] = arreglo[j]; //Coloca el negativo en la posicion correcta del arreglo
        } else if ((i < positivos) && (j >= tamano)) { //Si quedan positivos, pero no negativos
            pos[i] = arreglo[i]; //Coloca el positivo en la posicion correcta del arreglo
        }
    }

    ind = 0;
    for (int indice = 0; indice < tamano; indice++) { //Coloca los elementos en la posicion correcta
        if (indice < negativos) { //Si hay negativos que poner
            arreglo[indice] = neg[indice]; //Coloca los negativos en el arreglo original
        } else {
            arreglo[indice] = pos[ind]; //Coloca los positivos en el arreglo original
            ind++;
        }

    }
    delete [] neg; //Libera memoria
    delete[] pos; //Libera memoria
}

void Ordenador::Counting_Sort(int *arreglo, int *v_temporal, int tam) {
    int r = floor(log2(tam)); //r optimo
    int bits = sizeof (arreglo[0]); //cantidad de bits del entero
    int n_grupos = ceil(bits / 2 * r); //Numero de grupos que deben hacerse
    int mascara = (1 << r) - 1;
    int contadores [1 << r];
    int histograma_acumulativo[1 << r];

    for (int pasadas = 0, corrimientos = 0; pasadas < n_grupos; pasadas++) {

        for (int j = 0; j < length(contadores); j++) {//Inicializa el arreglo de contadores
            contadores[ j ] = 0;
        }
        for (int i = 0; i < tam; i++) { //Llena el arrego de contadores
            contadores [(arreglo [ i ] >> corrimientos) & mascara ]++;
        }
        histograma_acumulativo [ 0 ] = 0;
        for (int i = 1; i < length(contadores); i++) { //Llena el histograma acumulativo
            histograma_acumulativo [ i ] = histograma_acumulativo [ i - 1 ] + contadores[ i - 1 ];
        }
        for (int i = 0; i < tam; i++) { //Llena el vector temporal 
            v_temporal [ histograma_acumulativo [(arreglo [ i ] >> corrimientos) & mascara]++] = arreglo [ i ];
        }

        for (int i = tam - 1; i >= 0; i--) { //Coloca los elementos en el vector en el orden correspondiente
            arreglo[i] = v_temporal[i];
        }
        corrimientos += r;
    }
    arregla(arreglo,tam); //Termina de ordenar el arreglo
}

void Ordenador::radixsort(int * arreglo, int tamano) {
    int *v_temporal = new int [tamano]; //Arreglo temporal extra que usa el Radix
    Counting_Sort(arreglo, v_temporal, tamano); //Ordena
    delete[]v_temporal; //Libera memoria
}

//-----Metodos para implementar la mediana-------------//

int Ordenador::mediana(int * arreglo, int tamano) {
    float t = tamano;
    int med = ceil(t / 2); // Dice cual deberia ser la posicion del elemento de la mediana
    int m = 0;
    m = randomized_Select(arreglo, tamano - tamano, tamano, med);
    return m;
}

int Ordenador::randomized_Select(int *arreglo, int inicio, int fin, int k) {
    int piv = partition(arreglo, inicio, fin); //Guarda el pivote que devuelve patition

    if (k == piv) { //Si el pivote es igual a lo que busco
        return arreglo[piv]; //Devuelva el elemento del arreglo en esa posicion
    } else if (k > piv) {//Si el pivote es mas pequeño
        
        randomized_Select(arreglo, piv + 1, fin, k); //Busque a la derecha
    } 
    else {//Si el pivote es mas grande
        randomized_Select(arreglo, inicio, piv, k); //Busque a la izquierda
    }

}