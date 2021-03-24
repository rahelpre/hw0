#include <stdio.h>
#include <stdlib.h>
#define NUM_OF_DIG 10

/**
 * @brief function outpus frequency of each digit in all chars in input.
 * @param c holds current char from input.
 * @note getc gets a new char till EOF 
 */

int main() {
    int hist[NUM_OF_DIG]={0};
    char c;
    c = getc(stdin);
    while ( c!= EOF){
        if (c>='0' && c<'9') {
            hist[c-'0']++;
        }
        c = getc(stdin);
    }
    for(int i=0; i<NUM_OF_DIG; i++) {
        putc(hist[i]+'0', stdout);
    }
    return 0;
}
