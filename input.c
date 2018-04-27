#include <stdio.h>
#include <ctype.h>


int main() {
  const int blockSize = 1024;
  char buffer[blockSize];

  while (blockSize != EOF) {
    int bytes_read = fread(buffer, blockSize, sizeof(w_char_t), stdin); //everything read will go into here
    if (bytes_read == 0) {
      break;
    }
/*

ACTUAL CONTENT WILL GO here
*/


    /*for (int i = 0; i < bytes_read; i++) {
      buffer[i]= toupper(buffer[i]);
    } */

    fwrite(buffer, sizeof(w_char_t), bytes_read, stdout);

    //for e', the codepoint is U+00E9
    //the 11 000 11 1 0001
    //to add a 10 to a codepoint, OR 1000000 with it, and the first two bits will fall off.

    //use the right shift operator (>> to move


  }
}
