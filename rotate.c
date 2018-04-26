#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* rotate(char* s, int k) {

  if (k < 0 || k > strlen(s)) {
    return "Please input a k-value >= 0 that is shorter than the length of the string.";
  }

  char* toReturn = malloc(sizeof(char) * strlen(s));
  char* toAppend = malloc(sizeof(char) * k);

  for (int i = 0; i < k; i++) {
    toAppend[i] = s[i];
  }
  toAppend[k] = '\0';

  for(int i = 0; i < strlen(s) - k; i++) {
    toReturn[i] = s[k + i];
  }
  toReturn[strlen(s) - k] = '\0';

  strncat(toReturn, toAppend, k);
  return toReturn;
}

int main() {
  printf("%s\n", rotate("doghouse", -1));
  printf("%s\n", rotate("doghouse", 1));
  printf("%s\n", rotate("doghouse", 2));
  printf("%s\n", rotate("doghouse", 3));
  printf("%s\n", rotate("doghouse", 4));
  printf("%s\n", rotate("doghouse", 5));
  printf("%s\n", rotate("doghouse", 6));
  printf("%s\n", rotate("doghouse", 9));
}
