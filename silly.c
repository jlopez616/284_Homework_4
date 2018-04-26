#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* silly(char* a, char* b) {
  int returnSize = 0;
  int firstSubStringSize = 0;
  int secondSubStringSize = 0;

  for (int k = strlen(a); k > 0; k--) {
    returnSize += k;
    firstSubStringSize += k;
  }
  for (int k = strlen(b); k > 0; k--) {
    returnSize += k;
    secondSubStringSize += k;
  }

  char* toReturn = malloc(sizeof(char) * returnSize);
  toReturn[returnSize] = '\0';

  int stringCounter = 0;

  for (int k = 1; k <= strlen(a); k++) {
    for (int l = 0; l < k; l++) {
          toReturn[stringCounter] = a[l];
          stringCounter++;
    }
  }

  for (int k = strlen(b); k > 0; k--) {
    for (int l = 0; l < k; l++) {
          toReturn[stringCounter] = b[l];
          stringCounter++;
    }
  }


  return toReturn;
}

int main() {
  printf("%s \n", silly("phone", "booth"));
  printf("%s \n", silly("", ""));
  printf("%s \n", silly("abc", ""));
  printf("%s \n", silly("", "abc"));
  printf("%s \n", silly("too", "real"));
}
