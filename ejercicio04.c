#include <stdint.h>
#include <stdio.h>
#include <Arduino.h>

#define SENS_SAR_START_FORCE_REG   0x3FF4882C
#define SENS_SAR_READ_CTRL_REG     0x3FF48800
#define SENS_SAR_MEAS_START1_REG   0x3FF48854
#define SENS_SAR_ATTEN1_REG        0x3FF48834
#define IO_MUX_GPIO4_REG           0x3FF49048
#define IO_MUX_GPIO5_REG           0x3FF4906C
#define GPIO_IN_REG                0x3FF4403C

volatile uint32_t *sens_sar_start_force_reg;
volatile uint32_t *sens_sar_read_ctrl_reg;
volatile uint32_t *sens_sar_meas_start1_reg;
volatile uint32_t *sens_sar_atten1_reg;
volatile uint32_t *io_mux_gpio4_reg;
volatile uint32_t *io_mux_gpio5_reg;
volatile uint32_t *gpio_in_reg;
volatile uint32_t tempo = 0;

void adc1_configuracion(void){
  sens_sar_start_force_reg = (volatile uint32_t*)SENS_SAR_START_FORCE_REG;
  sens_sar_read_ctrl_reg   = (volatile uint32_t*)SENS_SAR_READ_CTRL_REG;
  sens_sar_meas_start1_reg = (volatile uint32_t*)SENS_SAR_MEAS_START1_REG;
  sens_sar_atten1_reg      = (volatile uint32_t*)SENS_SAR_ATTEN1_REG;
  io_mux_gpio4_reg         = (volatile uint32_t*)IO_MUX_GPIO4_REG;
  io_mux_gpio5_reg         = (volatile uint32_t*)IO_MUX_GPIO5_REG;
  gpio_in_reg              = (volatile uint32_t*)GPIO_IN_REG;

  *sens_sar_atten1_reg &= ~(0x3 << 8);// Atenuación solo del canal 4 (bits 8 y 9)
  *sens_sar_read_ctrl_reg |= (1 << 27);  // Habilita modo force para canales ADC1
  *sens_sar_read_ctrl_reg |= (0x3 << 16);  // Resolucion interna 12 bits global
  *sens_sar_start_force_reg |= (0x3 << 0);// Habilita la capacidad de iniciar conversiones manuales (no a una canal especifico)
  *io_mux_gpio4_reg &= ~(1 << 7);
  *io_mux_gpio4_reg |= (1 << 8);
  *io_mux_gpio5_reg &= ~(1 << 7);
  *io_mux_gpio5_reg |= (1 << 8);
}

int incremento_tiempo(int var){
  if (var == 0){
    tempo += 2;
  }
  return tempo;
}
int decremento_tiempo(int var){
  if (var == 0){
    tempo -= 2;
  }
}

void setup() {
  adc1_configuracion();
}
void loop() {
  int sw1 = (*gpio_in_reg & (1 << 4));
  int sw2 = (*gpio_in_reg & (1 << 5));
  if (tempo < 20){
    incremento_tiempo(sw1);
  } else{
    tempo = tempo;
  }
  if (tempo > 2){
    decremento_tiempo(sw2);
  } else{
    tempo = tempo;
  }
  
}
