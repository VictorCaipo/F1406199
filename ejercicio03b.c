#include <stdint.h>
//Definicion de direcciones
#define GPIO_P0 0x50000000 
#define OUT     (GPIO_P0 + 0x504)
#define OUTSET  (GPIO_P0 + 0x508)
#define OUTCLR  (GPIO_P0 + 0x50C)
#define IN      (GPIO_P0 + 0x510)
#define DIR     (GPIO_P0 + 0x514)
#define DIRSET  (GPIO_P0 + 0x518)
#define DIRCLR  (GPIO_P0 + 0x51C)
//Declaracion de punteros de manera global
volatile uint32_t *out;
volatile uint32_t *outset;
volatile uint32_t *outclr;
volatile uint32_t *in;
volatile uint32_t *dir;
volatile uint32_t *dirset;
volatile uint32_t *dirclr;

void setup() {
    //Asignacion de punteros
    out =     (volatile uint32_t *)OUT;
    outset =  (volatile uint32_t *)OUTSET;
    outclr =  (volatile uint32_t *)OUTCLR;
    in =      (volatile uint32_t *)IN;
    dir =     (volatile uint32_t *)DIR;
    dirset =  (volatile uint32_t *)DIRSET;
    dirclr =  (volatile uint32_t *)DIRCLR;
}
void loop(){
    //:c
}

