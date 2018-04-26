#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
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

    const int STEPS = sizeof(KEY_NAMES)/ sizeof(KEY_NAMES[0]);
    const int NUMBER_OF_KEYS = 88;
    const float INITIAL_FREQUENCY = 27.5;

    float frequency;
    for (float k = 0; k < NUMBER_OF_KEYS; k++) {
        frequency = (float) INITIAL_FREQUENCY * powf(2, (k / STEPS));
        printf("%s \t %.4f \n", KEY_NAMES[(int)k % STEPS], frequency);
    }
    return 0;
}
