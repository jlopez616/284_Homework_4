#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>



int main(int argc, char ** argv) {

   if (argc != 2) {
     printf("%s \n", "Please add one argument from A-F#");
     return 1;
   }
    char *KEY_NAMES[12];
    KEY_NAMES[0] = "A";
    KEY_NAMES[1] = "A#";
    KEY_NAMES[2] = "B";
    KEY_NAMES[3] = "C";
    KEY_NAMES[4] = "C#";
    KEY_NAMES[5] = "D";
    KEY_NAMES[6] = "D#";
    KEY_NAMES[7] = "E";
    KEY_NAMES[8] = "F";
    KEY_NAMES[9] = "F#";
    KEY_NAMES[10] = "G";
    KEY_NAMES[11] = "G#";

    int NUMBER_OF_NOTES = sizeof(KEY_NAMES)/ sizeof(KEY_NAMES[0]);

    int MAJOR_STEPS[6] = {2,2,1,2,2,2};
    int MINOR_STEPS[6] = {2,1,2,2,1,2};
    int NUMBER_OF_STEPS =  sizeof(MAJOR_STEPS)/ sizeof(MAJOR_STEPS[0]);


    void printScale(int note_index, char type[], int steps[]) {
        printf("%s %s: %s ", KEY_NAMES[note_index], type, KEY_NAMES[note_index]);
        int offset = 0;
        for (int step = 0; step < NUMBER_OF_STEPS; step++) {
            offset += steps[step];
            printf("%s ", (KEY_NAMES[(note_index + offset) % NUMBER_OF_NOTES]));
        }
        printf("\n");
    }

    int key_index;
    int key_exists = 0;

    char *toMakeUpper = argv[1];
    for(int k = 0; k < strlen(toMakeUpper); k++) {
      toMakeUpper[k] = toupper(toMakeUpper[k]);
    }

    for (int k = 0; k < NUMBER_OF_NOTES; k++) {
        if (strcmp( KEY_NAMES[k], toMakeUpper) == 0) {
            key_index = k;
            key_exists = 1;
        }

    }

    if (key_exists != 1) {
       printf("%s \n", "Please add one argument from A-F#");
       return 1;
    }

    printScale(key_index, "major", MAJOR_STEPS);
    printScale(key_index, "minor", MINOR_STEPS);

    return 0;
}
