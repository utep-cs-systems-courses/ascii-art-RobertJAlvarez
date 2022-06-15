#include "draw.h"		/* for font */
#include "stdio.h"		/* for putchar */

void print_char(char c, int nRows, int nCols)
{
  c -= 0x20;  //Rescale input because we ignore the first 20 ASCII characters
  for (char row = 0; row < nRows; row++) {
    unsigned short rowBits;
    if (nRows == 5) {
      rowBits = font_5x7[c][row];
    } else if (nRows == 12) {
      rowBits = font_12x8[c][row];
    } else if (nRows == 11) {
      rowBits = font_11x16[c][row];
    }
    for (char col = 0; col < nCols; col++) {
      unsigned short colMask = 1 << (nCols-1-col); //Mask to select bit associated with bit
      putchar ( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
}

/*
void print_char_11x16(char c)
{
  c -= 0x20;
  for (char row = 0; row < 11; row++) {
    unsigned short rowBits = font_11x16[c][row];
    for (char col = 0; col < 16; col++) {
      unsigned short colMask = 1 << (15-col); //Mask to select bit associated with bit
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
}
*/

