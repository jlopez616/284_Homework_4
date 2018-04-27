#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int returnCode = 0;

static bool legal(uint32_t codepoint) {
    return codepoint <= 0x0010FFFF
        && (codepoint < 0x0000FDD0 || codepoint > 0x0000FDEF)
        && (codepoint & 0x0000FFFE) != 0x0000FFFE;
      }

void convert(int block) {
  if (!legal(block)) {
    returnCode = 1;
    putchar(0xEF);
    putchar(0xBF);
    putchar(0xBB);
  } else if (block <= 0x7F) {
       putchar(block);
   } else if (block <= 0x7FF) {
       putchar(0xC0 | block>>6);
       putchar(0x80 | block & 0x3F);
   } else if (block <= 0xFFFF) {
       putchar(0xE0 | block>>12);
       putchar(0x80 | block>>6 & 0x3F);
       putchar(0x80 | block & 0x3F);
   } else {
       putchar(0xF0 | block>>18);
       putchar(0x80 | block>>12 & 0x3F);
       putchar(0x80 | block>>6 & 0x3F);
       putchar(0x80 | block & 0x3F);
   }

}


int main() {

  const int blockSize = 1024;
  uint32_t buffer[blockSize];

  while (true) {
    int bytes_read = fread(buffer, sizeof(uint32_t), blockSize, stdin); //everything read will go into here
    if (bytes_read == 0) {
      break;
    }

    for (int k = 0; k < blockSize; k++) {
      convert(buffer[k]);
    }
  }

  return returnCode;
}
