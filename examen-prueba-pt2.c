#include <stdio.h>

float getImporteHora();
void cargarNombres(char profesores[][30]);
void cargarHoras(int horas[][5]);
void importeACobrar(int horas[][5], char profesores[][30], float importeHora);
void trabajoMasViernes(int horas[][5], char profesores[][30]);
int buscarProfesor(char nombre[], char profesores[][30]);

void main() {

    int horasPorDias[4][5];
    char profesores[4][30];
    float importeHora = getImporteHora();
    cargarNombres(profesores);
    cargarHoras(horasPorDias);

    int opcion;
    printf("Ingrese una opcion a continuacion \n");
    scanf("%d", &opcion);
    
    do {    
    
        switch (opcion) {
            case 1:
                importeACobrar(horasPorDias, profesores, importeHora);
                break;
            case 2:
                trabajoMasViernes(horasPorDias, profesores);
                break;
            case 3: {
                char nombre[30];
                printf("Ingrese el nombre de un profesor: \n");
                scanf("%s", nombre);

                int indice= buscarProfesor(nombre, profesores);
                if (indice == -1) {
                    printf("Nombre inexistente\n");
                } else {
                    printf("Horas trabajadas por %s:\n", nombre);
                    char dias[5][10] = {"lunes", "martes", "miercoles", "jueves", "viernes"};
                    for (int j = 0; j < 5; j++) {
                        printf("  %s: %d horas\n", dias[j], horasPorDias[indice][j]);
                    }
                }
                break;
            }
            case 4: 
                printf("bye bye \n");
                break;
            default: 
                printf("Ingrese una opcion valida entre 1 y 4\n");
                break;
            }

    } while (opcion != 4);

}


float getImporteHora(){
    float importeHora;
    do {
        printf("Ingrese el valor que se pagara por una hora de clase\n");
        scanf("%f", &importeHora);
        
        if(importeHora<=0) {
            printf("Debe ingresar un importe mayor a 0\n");
        }
    } while (importeHora<=0);

    return importeHora;
}

void cargarNombres(char nombres[][30]) {
    for(int i=0; i<4; i++){
        printf("Ingrese el nombre del profesor %d\n", i+1);
        scanf("%s", nombres[i]);
    }
    printf("Listado de profesores a continuacion: \n");
    for(int i=0; i<4; i++){
        printf("%s\n", nombres[i]);
    }
}

void cargarHoras(int horas[][5]) {
    char dias[5][10] = {"lunes", "martes", "miercoles", "jueves", "viernes"};

    for(int i=0; i<4; i++) { //profesores
        for(int j=0; j<5; j++) { //dias
            printf("Ingrese las horas que trabajo el profesor %d el dia %s \n", i+1, dias[j]);
            scanf("%d", &horas[i][j]);
        }

    }
}


void importeACobrar(int horas[][5], char profesores[][30], float importeHora) {
    int horasTrabajadas =0;
    for(int i=0; i<4; i++) {
        horasTrabajadas =0;
        for(int j=0; j<5; j++) {
            horasTrabajadas= horasTrabajadas+horas[i][j];
        }
        printf("El total de horas trabajadas por el profesor %s es de: %d\n", profesores[i], horasTrabajadas);
        printf("Y el importe total a cobrar es de: %.2f\n", horasTrabajadas*importeHora);
    }
}

void trabajoMasViernes(int horas[][5], char profesores[][30]) {
    int mayorCantidadHoras =0;
    int profesorLaburante=0;
    for (int i = 0; i < 4; i++) {
        if(horas[i][4]>mayorCantidadHoras) {
            mayorCantidadHoras=horas[i][4];
            profesorLaburante=i;
        }
    }
    printf("El profesor que trabajo mas horas el viernes fue %s, con un total de %d horas \n", profesores[profesorLaburante], mayorCantidadHoras);
}

int buscarProfesor(char nombre[], char profesores[][30]) {
    for (int i = 0; i < 4; i++) {
        if (strcmp(nombre, profesores[i]) == 0) {
            return i;  // índice del profesor
        }
    }
    return -1;  // no encontrado
}