#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Calculo de la suma de divisores
int calculo_divisores(int numero){
    int suma_divisores = 0;
        for(int j = 1; j < numero; j++){       
            if (numero%j==0){
                suma_divisores+=j;
            }
        }
    return suma_divisores;
}
//Clasificacion si el numero es deficiente, perfecto o abundante
const char* clasificacion(int numero, int suma){
    if(suma<numero){
        return "Deficiente";
    }
    if(suma==numero){
        return "Perfecto";
    }
    if(suma>numero){
        return "Abundante";
    }
}
int main(void){
    //Generando numeros aleratorios
    int datos[15];
    srand(time(0));
    for(int i = 0; i < 15; i++){
        datos[i] = rand() % 99;
        int suma_divisores = calculo_divisores(datos[i]);
        const char* estado = clasificacion(datos[i],suma_divisores); 
        printf("El numero aleratorio es: %i la suma de sus divsores es: %i su estado es: %s\n",datos[i],suma_divisores,estado);
    }
    return 0;
}