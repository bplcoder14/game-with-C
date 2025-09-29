#include "inputState.h"

uint8_t controls = 0x00;


uint16_t get_mouse_x();
uint16_t get_mouse_y();


struct mouse {
  uint8_t buttonState = 0x00;
  uint32_t pos = 0x00000000;
};
