#include "draw.h"		/* for font */
#include "stdio.h"		/* for putchar */

<<<<<<< HEAD
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
=======
>>>>>>> 240304530ab95a5b51c42c5e0b3818b6d42a6994
void print_char_11x16(char c)
{
  c -= 0x20;
  for (char row = 0; row < 11; row++) {
    unsigned short rowBits = font_11x16[c][row];
    for (char col = 0; col < 16; col++) {
<<<<<<< HEAD
      unsigned short colMask = 1 << (15-col); //Mask to select bit associated with bit
=======
      unsigned short colMask = 1 << (15-col); /* mask to select bit associated with bit */
>>>>>>> 240304530ab95a5b51c42c5e0b3818b6d42a6994
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
}
<<<<<<< HEAD
*/

=======
>>>>>>> 240304530ab95a5b51c42c5e0b3818b6d42a6994
