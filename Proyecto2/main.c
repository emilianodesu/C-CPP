#include <stdio.h>
#include <string.h>
#include "utilidades.h"
#define TAM 10

int main(int argc, char const *argv[]) {
    char opcion[20];
    int n = TAM, temp;
    float datos[TAM];

    // Inicializa el arreglo con ceros
    for (int i = 0; i < n; i++){
        datos[i] = 0; 
    }

    ver_comandos();
    while(1) {
        printf(">");
        setbuf(stdin,NULL);
        scanf("%s", opcion);
        if(strcmp(opcion, "ayuda") == 0){
            ver_comandos();
        } else if(strcmp(opcion, "salir") == 0){
            break;
        } else if(strcmp(opcion, "n") == 0){
            printf("Tu numero de elementos para el arreglo es n = %d\n", n);
            printf("Teclear por cual 'n' vas a cambiar, n = ");
            scanf("%d", &temp);
            cambiar_n(&n, temp);
            printf("Tu numero de elementos para el arreglo ha cambiado a n = %d\n", n);
        } else if(strcmp(opcion, "datos") == 0) {
            llenar(datos, n);
        } else if (strcmp(opcion, "cambiar") == 0){
            printf("Escribe la posicion del arreglo que deseas modificar, i = ");
            scanf("%d", &temp);
            printf("Escribe el nuevo valor para el dato, Dato[%d] = ", temp);
            scanf("%f", &datos[temp-1]);
            printf("Se ha actualizado el valor de Dato[%d] = %f\n", temp, datos[temp-1]);
        } else if (strcmp(opcion, "imprimir") == 0){
            ordenamiento(datos, n);
            imprimir(datos, n);            
        } else if(strcmp(opcion, "media") == 0){
            printf("La media del arreglo es: %.4f\n", media(datos, n));
        } else if (strcmp(opcion, "mediana") == 0){
            ordenamiento(datos, n);
            printf("La mediana del arreglo es: %.4f\n", mediana(datos, n));
        } else if (strcmp(opcion, "moda") == 0){
            ordenamiento(datos, n);
            printf("La moda del arreglo es: %.4f\n", moda(datos, n));
        } else if (strcmp(opcion, "varianza") == 0){
            printf("La varianza del arreglo es: %.4f\n", varianza(datos, n));
        } else if(strcmp(opcion, "desvest") == 0){
            printf("La desviacion estandar del arreglo es: %.4f\n", desvest(datos, n));
        } else if(strcmp(opcion, "cuartil_1") == 0){
            ordenamiento(datos, n);
            printf("El primer cuartil del arreglo es: %.4f\n", cuartil_1(datos, n));
        } else if(strcmp(opcion, "cuartil_3") == 0){
            ordenamiento(datos, n);
            printf("El tercer cuartil del arreglo es: %.4f\n", cuartil_3(datos, n));
        } else if(strcmp(opcion, "ric") == 0){
            ordenamiento(datos, n);
            printf("El rango intercuartilico del arreglo es: %.4f\n", ric(datos, n));
        } else if(strcmp(opcion, "rango") == 0){
            ordenamiento(datos, n);
            printf("El rango del arreglo es: %.4f\n", rango(datos, n));
        } else if(strcmp(opcion, "todos") == 0){
            todo(datos, n);
        } else {
            printf("Opcion invalida\n");
        }
    }
    return 0;
}