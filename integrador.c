#include <stdio.h>
#include <string.h>

#define MAX_PASAJEROS 60

void cargarPasajeros(int dnis[], char nombres[][30], char apellidos[][30], 
                     int edades[], char codigosDestinos[][3], int cantPasajeros);
int validarDni(int dni); //boolean

void main() {
    int cantPasajeros;
    printf("Ingrese la cantidad de pasajeros que contrataron viajes. \n");
    scanf("%d", &cantPasajeros);

    int dnis[MAX_PASAJEROS];
    char nombres[MAX_PASAJEROS][30];
    char apellidos[MAX_PASAJEROS][30];
    char codigosDestinos[MAX_PASAJEROS][3];
    char destinos[MAX_PASAJEROS][30];
    int edades[MAX_PASAJEROS];

    cargarPasajeros(dnis, nombres, apellidos, edades, codigosDestinos, destinos, cantPasajeros);



}

int validarDni(int dni) {

    if (dni<1000000 || dni>99999999) {
        return 0; //invalido
    }

    int primerosDigitos;
    if (dni < 10000000) {  // 7 dígitos
        primerosDigitos = dni / 100000;  
    } else {  // 8 dígitos
        primerosDigitos = dni / 1000000;
    }

    int primerDigito = primerosDigitos /10;

    if (primerDigito == 5 || primerDigito == 6 || (primerosDigitos >= 10 && primerosDigitos <= 60)) {
        return 1; //valido
    } else {
        return 0;
    }


}



void cargarPasajeros(int dnis[], char nombres[][30], char apellidos[][30], 
                    int edades[], char codigosDestinos[][3], int cantPasajeros) {

    int dniScanned; 
    int dniIsValid;                       

    //por cada pasajero guardo su info 
    for (int i = 0; i < cantPasajeros; i++)
    {
        printf("============= Pasajero %d =============\n", i+1);

        // _______________________ dni
        do {
            printf("Ingrese el DNI:\n");
            scanf("%d", &dniScanned);

            dniIsValid= validarDni(dniScanned);

            if (dniIsValid==0) { 
                printf("DNI invalido. Ingreselo nuevamente.\n");
            }

        } while(dniIsValid==0);

        dnis[i]= dniScanned;

        printf("Ingrese apellido: \n");
        scanf("%s", apellidos[i]);

        printf("Ingrese nombre: \n");
        scanf("%s", nombres[i]);

        printf("Ingrese edad: \n");
        scanf("%d", &edades[i]);

        printf("Ingrese codigo de destino (BRA, MDQ, MZA, BRC): \n");
        //todo pasar a to upper case
        scanf("%s", destinos[i]);

        
    }
    

}