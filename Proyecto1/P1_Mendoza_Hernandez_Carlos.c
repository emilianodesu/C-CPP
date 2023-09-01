#include <stdio.h>

int main() {

    float num1, num2;

    printf("Ingrese el primer numero: ");
    scanf("%f", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%f", &num2);
    printf("Sus numeros ingresados fueron: %.4f %.4f. \n", num1, num2 );
    printf("   |    OPERACION    |    RESULTADO    |\n");
    printf("   |-----------------|-----------------|\n");
    printf("   |SUMA             |%17.4f|\n", num1+num2);
    printf("   |RESTA            |%17.4f|\n", num1-num2);
    printf("   |MULTIPLICACION   |%17.4f|\n", num1*num2);
    printf("   |DIVISION         |%17.4f|\n\n\n", num1/num2); 
    // Se asume que no habrán divisiones entre 0

    return 0;
}