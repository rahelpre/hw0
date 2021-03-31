#include <stdio.h>
#include <stdlib.h>
#define NUM_OF_DIG 10

/**
 * @brief function outpus frequency of each digit in all chars in input.
 * @variable c holds current char from input.
 */

int main() {
    int hist[NUM_OF_DIG]={0};
    char c;
    c = getc(stdin);
    while ( c!= EOF){
        if (c>= '0' && c< '9') {
            hist[c - '0']++;
        }
        c = getc(stdin);
    }
    for(int i=0; i<NUM_OF_DIG-1; i++) {
        printf("%d ", hist[i]);
    }
    printf("%d", hist[NUM_OF_DIG-1]);
    return 0;
}
