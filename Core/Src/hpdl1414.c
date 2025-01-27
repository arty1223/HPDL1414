#include <hpdl1414.h>
#include <stdlib.h>
#include <string.h>

void hpdl1414_init(){
  hpdl1414_update(3,' ');
  hpdl1414_update(2,' ');
  hpdl1414_update(1,' ');
  hpdl1414_update(0,' ');
}

void hpdl1414_update(unsigned int digit, unsigned int sprite){
  // GPIOB->ODR = 0b1010000000;  9 бит - WR, 8,7 бит - выбор сегмента, 6,5,4,3,2,1,0 биты - выбор символа
  __GPIO_PORT->ODR &= 1 << 9; // очищаем регистр кроме 9 бита (WR)
  __GPIO_PORT->ODR |= digit << 7; // выставляем знакоместо
  __GPIO_PORT->ODR ^= 1 << 9; // выставляем 0 на 9 бите (WR)
  __GPIO_PORT->ODR |= sprite; // выставляем символ
  __GPIO_PORT->ODR |= 1 << 9; // возварт 9 бита на 1 (WR)
}

void hpdl1414_string(char str[]){ 
  hpdl1414_update(3,str[0]);
  hpdl1414_update(2,str[1]);
  hpdl1414_update(1,str[2]);
  hpdl1414_update(0,str[3]);  
}

void hpdl1414_num(int numb){
  if (numb < 0){
    numb = abs(numb);
    hpdl1414_update(3U, '-');
    hpdl1414_update(2U, (unsigned) numb % 1000 / 100 + 48);
    hpdl1414_update(1U, (unsigned) numb % 1000 % 100 / 10 + 48);  
    hpdl1414_update(0U, (unsigned) numb % 1000 % 100 % 10 + 48);
    return;
  }
  hpdl1414_update(3U, (unsigned) numb / 1000 + 48);
  hpdl1414_update(2U, (unsigned) numb % 1000 / 100 + 48);
  hpdl1414_update(1U, (unsigned) numb % 1000 % 100 / 10 + 48);  
  hpdl1414_update(0U, (unsigned) numb % 1000 % 100 % 10 + 48);
}

void hpdl1414_mix(char ltr, int numb){
  hpdl1414_update(3, ltr);
  hpdl1414_update(2, numb % 1000 / 100 + 48);
  hpdl1414_update(1, numb % 1000 % 100 / 10 + 48);  
  hpdl1414_update(0, numb % 1000 % 100 % 10 + 48);
}
