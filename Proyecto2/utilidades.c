#include <stdio.h>
#include <math.h>
#include "utilidades.h"

/**
 * @brief Imprime el menu de funciones del programa.
 * 
 */
void ver_comandos(){
    printf("----------------------------------CALCULADORA DE MEDIDAS DE TENDENCIA CENTRAL Y DE DISPERSION-------------------------\n");
    printf("INSTRUCCIONES: Cuando aparezca '>', puedes teclear cualquiera de los siguientes comandos que se muestran en la siguiente tabla\n");
    printf("| COMANDO | FUNCION                                                          |\n");
    printf("|----------------------------------------------------------------------------|\n");
    printf("|  ayuda  | Imprime nuevamente la tabla de ayuda.                            |\n");
    printf("|  salir  | Termina el programa.                                             |\n");
    printf("|    n    | Cambiar la cantidad de datos (por defecto, n=100).               |\n");
    printf("|  datos  | Cambiar todos los datos con los que usted desea trabajar.        |\n");
    printf("| cambiar | Cambiar un dato en la posicion especifica.                       |\n");
    printf("| imprimir| Imprimir los datos ordenados con los que se trabaja actualmente. |\n");
    printf("|  media  | Calcular la media aritmetica del conjunto de datos.              |\n");
    printf("| mediana | Calcular la mediana del conjunto de datos.                       |\n");
    printf("|  moda   | Calcular la moda del conjunto de datos.                          |\n");
    printf("| varianza| Calcular la varianza del conjunto de datos.                      |\n");
    printf("| desvest | Calcular la desviacion estandar del conjunto de datos.           |\n");
    printf("|cuartil_1| Calcular el primer cuartil del conjunto de datos.                |\n");
    printf("|cuartil_3| Calcular el tercer cuartil del conjunto de datos.                |\n");
    printf("|   ric   | Calcular el rango intercuartilico del conjunto de datos.         |\n");
    printf("|  rango  | Calcular el rango del conjunto de datos.                         |\n");
    printf("|  todos  | Calcular todas las medidas del conjunto de datos.                |\n");
}


void cambiar_n(int *i, int n){
    *i = n;
}

/**
 * @brief Llena el arreglo del programa con los datos deseados.
 * 
 * @param datos Arreglo de datos del programa
 * @param n Tamaño del arreglo o cantidad de datos del programa
 */
void llenar(float datos[], int n){
    for (int i = 0; i < n; i++){
        printf("Ingrese el numero[%d]:", i+1);
        scanf("%f", &datos[i]);
    }
    
}

/**
 * @brief Imprime los datos almacenados en el arreglo del programa.
 * 
 * @param datos Arreglo de datos del programa. El arreglo debe estar ordenado
 * @param n Tamaño del arreglo o cantidad de datos del programa
 */
void imprimir(float datos[], int n){
    for (int i = 0; i < n; i++){
        printf("Dato [%d]: %.4f\n", i+1, datos[i]);
    }
    
}

/**
 * @brief Calcula la media aritmetica del conjunto de datos almacenados en el arreglo dado
 * 
 * @param datos Arreglo de datos del programa
 * @param n Tamaño del arreglo o cantidad de datos del programa
 * @return float Media aritmetica
 */
float media(float datos[], int n){
    float acum=0;
    for (int i = 0; i < n; i++)
        acum+=datos[i];
    return acum/n;
}

/**
 * @brief Calcula la mediana del conjunto de datos almacenados en el arreglo dado.
 * 
 * @param datos Arreglo de datos del programa. El arreglo debe estar ordenado.
 * @param n Tamaño del arreglo o cantidad de datos del programa
 * @return float Mediana
 */
float mediana(float datos[], int n){
    if (n%2 == 0){
        return (datos[(n/2)-1] + datos[(n/2)])/2;
    } else {
        return datos[((n+1)/2)-1];
    }
    
}

/**
 * @brief Calcula la moda del conjunto de datos almacenados en el arreglo dado.
 * 
 * @param datos Arreglo de datos del programa. El arreglo debe estar ordenado
 * @param n Tamaño del arreglo o cantidad de datos del programa
 * @return float Moda
 */
float moda(float datos[], int n){
    float actual = datos[0];
    float moda = actual;
    int cont = 1;
    int max = 1;

    for (int i = 1; i < n; i++) {
        if (datos[i] == actual){
            cont++;
        } else if(cont > max){
            max = cont;
            moda = actual;
        }
        actual = datos[i];
        cont=1;
    }
    if (cont > max){
        moda = actual;
    }
    return moda;
}

/**
 * @brief Calcula el rango del conjunto de datos almacenados en el arreglo dado.
 * 
 * @param datos Arreglo de datos del programa. El arreglo debe estar ordenado.
 * @param n Tamaño del arreglo o cantidad de datos del programa
 * @return float Rango
 */
float rango(float datos[], int n){
    return datos[n-1] - datos[0];
}

/**
 * @brief Calcula la varianza del conjunto de datos almacenados en el arreglo dado.
 * 
 * @param datos Arreglo de datos del programa
 * @param n Tamaño del arreglo o cantidad de datos del programa
 * @return float Varianza
 */
float varianza(float datos[], int n){
    float acum=0;
    float prom = media(datos, n);
    for (int i = 0; i < n; i++)
        acum+=(float)pow(datos[i]-prom,2);
    return acum/(n-1);
}

/**
 * @brief Calcula la desviacion estandar del conjunto de datos almacenados en el arreglo dado.
 * 
 * @param datos Arreglo de datos del programa
 * @param n Tamaño del arreglo o cantidad de datos del programa
 * @return float Desviacion estandar
 */
float des_estandar(float datos[], int n){
    return (float)sqrt(varianza(datos, n));
}

/**
 * @brief Calcula Q1 del conjunto de datos almacenados en el arreglo dado.
 * 
 * @param datos Arreglo de datos del programa. El arreglo debe estar ordenado.
 * @param n Tamaño del arreglo o cantidad de datos del programa
 * @return float Q1
 */
float cuartil_1(float datos[], int n){
    float pos = (n+1)*0.25;
    int parte_entera = (int)pos;
    float porcentaje = pos - parte_entera;
    return datos[parte_entera-1] + porcentaje*(datos[parte_entera]-datos[parte_entera-1]);
}

/**
 * @brief Calcula Q3 del conjunto de datos almacenados en el arreglo dado.
 * 
 * @param datos Arreglo de datos del programa. El arreglo debe estar ordenado.
 * @param n Tamaño del arreglo o cantidad de datos del programa
 * @return float Q3
 */
float cuartil_3(float datos[], int n){
    float pos = (n+1)*0.75;
    int parte_entera = (int)pos;
    float porcentaje = pos - parte_entera;
    return datos[parte_entera-1] + porcentaje*(datos[parte_entera]-datos[parte_entera-1]);
}

/**
 * @brief Calcula el rango intercuartil del conjunto de datos almacenados en el arreglo dado.
 * 
 * @param datos Arreglo de datos del programa. El arreglo debe estar ordenado.
 * @param n Tamaño del arreglo o cantidad de datos del programa
 * @return float Rango intercuartil
 */
float rango_intercuartil(float datos[], int n){
    return cuartil_3(datos, n) - cuartil_1(datos, n);
}

/**
 * @brief Realiza todas las operaciones con el conjunto de datos almacenados en el arreglo dado.
 * 
 * @param datos Arreglo de datos del programa
 * @param n Tamaño del arreglo o cantidad de datos del programa
 */
void todo(float datos[], int n){

}

void ordenamiento(float datos[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (datos[i] > datos[j]) {
                float temp = datos[i];
                datos[i] = datos[j];
                datos[j] = temp;
            }
        }
    }
}