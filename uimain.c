#include <stdio.h>
#include "draw.h"

static void options(int *c);
static int char_options(int *nRows, int *nCols);

static void options(int *c)
{
  fputs("Select which shape you want to print (Arrow = a, Triangle = t, Square = s, Chars = c) or 'q' to quit\n> ", stdout);
  fflush(stdout);		// stdout only flushes automatically on \n
  while ((*c = getchar()) == '\n'); // ignore newlines
  if (*c == EOF)		     // terminate on end-of-file
    *c = 'q';
}

static int char_options(int *nRows, int *nCols)
{
  int opt;
  fputs("Select which font you want to use (1. 5x7, 2. 12x8, 3. 11x16)", stdout);
  fflush(stdout);
  while ((opt = getchar()) == '\n');
    if (opt == EOF)
      opt = 'z'; //'z' is not a menu options so we would just print the main menu again
  switch (opt) {
  case '1':
    *nRows = 5;
    *nCols = 7;
    break;
  case '2':
    *nRows = 12;
    *nCols = 8;
    break;
  case '3':
    *nRows = 11;
    *nCols = 16;
    break;
  case '\n':
    break;
  default:
    printf("Unrecognized option  '%c', please try again!\n", opt);
    return 0;
  }
  return 1;
}

int main() 
{
  int c;
  puts("Welcome!");
  options(&c);
  
  while (c != 'q') {
    // Given the user answer, select which method to call
    switch (c) {
    case 'a':
      puts("You selected arrow:");
      print_arrow();
      break;
    case 't':
      puts("You selected triangle:");
      print_triangle(5, 7);
      break;
    case 's':
      puts("You selected square:");
      print_square(5, 5);
      break;
    case 'c':
      puts("You selected chars:");
      int nRows, nCols;
      if (char_options(&nRows, &nCols)) {
        puts("Enter and ASCII number to print the character.\n");
        puts("Valid numbers are 32 <= input <= 126.\n");
        puts("Any other number would stop printing characters\n");
        scanf(" %d",&c);
        while (c > 32 && c < 127) {
          printf("Printing: '%c'\n", c);
          print_char(c,nRows,nCols);
          puts("Enter another ASCII number:");
          scanf(" %d",&c);
        }
      }
      break;
    case '\n':
      break;
    default:
      printf("Unrecognized option '%c', please try again!\n", c);
    }
    options(&c);
  }

  return 0;
}
