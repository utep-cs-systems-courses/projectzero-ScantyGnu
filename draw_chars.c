#include "draw.h"		/* for font */
#include "stdio.h"		/* for putchar */
#include "string.h"

void print_char_11x16(char c)
{
  c -= 0x20;
  for (char row = 0; row < 11; row++) {
    unsigned short rowBits = font_11x16[c][row];
    for (char col = 0; col < 16; col++) {
      unsigned short colMask = 1 << (15-col); /* mask to select bit associated with bit */
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
}

void print_char_myfont(char c)
{
  c -= 0x20;
  for (char row = 6; row >= 0; row--) {
    unsigned short colMask = 1 << (6 - row);
    for (char col = 0; col < 5; col++) {
      unsigned short colBits = myfont_5x7[c][col];
      putchar( (colBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
}

void print_char_row_myfont(char c, unsigned short colMask)
{
  c -= 0x20;
  for (char col = 0; col < 5; col++) {
    unsigned short colBits = myfont_5x7[c][col];
    putchar( (colBits & colMask) ? '*' : ' ');
  }
}

void print_word_myfont(char word[])
{
  char letterChar;
  for (char row = 6; row >= 0; row--) {
    unsigned short colMask = 1 << (6 - row);
    for (char letter = 0; letter < strlen(word); letter++) {
      letterChar = word[letter];
      print_char_row_myfont(letterChar, colMask);
      putchar(' ');
    }
    putchar('\n');
  }
}
