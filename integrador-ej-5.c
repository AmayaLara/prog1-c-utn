#include <stdio.h>
/*
5. Se deben registrar los puntajes obtenidos (números enteros entre 0 y 100) 
por hasta 40 alumnos en un examen.
La carga finaliza si se ingresa un número fuera de rango o se completan los 40 alumnos.

Calcular:
a. El puntaje más alto
b. Cuántos estudiantes aprobaron (puntaje >= 60)
c. El promedio general
d. El porcentaje de desaprobados
    ● Usar una función para la carga y validación.
    ● Otra para los cálculos
*/

int cargarPuntajes(int puntajes[]);
int getPuntajeAlto(int puntajes[], int cantAlumnos);
void calcularPromedio(int puntajes[], int cantAlumnos);
void calcularDesaprobados(int puntajes[], int cantAlumnos);

void main() {
     int puntajes[40];

     int cantAlumnos = cargarPuntajes(puntajes);

     int mayor = getPuntajeAlto(puntajes, cantAlumnos);
     printf("El puntaje mas alto es el %d \n", mayor);

     calcularPromedio(puntajes, cantAlumnos);
     calcularDesaprobados(puntajes, cantAlumnos);

}


int cargarPuntajes(int puntajes[]) {
    int puntaje;
    int contador=0;
     do {
        printf("Ingrese el puntaje del alumno %d \n", contador+1);
        scanf("%d", &puntaje);

        if (puntaje>=0 && puntaje<=100) {
            puntajes[contador] = puntaje;
            contador++;
        }
     } while (puntaje>=0 && puntaje<=100 && contador<40);

     return contador;
}


int getPuntajeAlto(int arr[], int cantAlumnos) {
    int mayor = arr[0];

    for(int i=0; i<cantAlumnos; i++) {
        if (arr[i]>mayor) {
            mayor = arr[i];
        }
    }
    return mayor;
}

void calcularPromedio(int puntajes[], int cantAlumnos){
    int suma =0;

    for(int i=0; i<cantAlumnos; i++) {
        suma= suma+puntajes[i];
    }
    float promedio = (float)suma/cantAlumnos;
    printf("El promedio de los puntajes es %2.f\n",promedio);
}

void calcularDesaprobados(int puntajes[], int cantAlumnos) {
    int desaprobados=0;

    for(int i=0; i<cantAlumnos; i++){
        if (puntajes[i]<60) {
            desaprobados++;
        }  
    }
    printf("La cantidad de alumnos es: %d, y la cantidad de desaprobados es: %d\n", cantAlumnos, desaprobados);
}
