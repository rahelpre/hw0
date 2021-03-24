#include <stdio.h>
#include <stdlib.h>
#define NUM_OF_DIG 10
#define DIG_ST '0'
#define DIG_END '9'

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
        if (c>= DIG_ST && c< DIG_END) {
            hist[c - DIG_ST]++;
        }
        c = getc(stdin);
    }
    for(int i=0; i<NUM_OF_DIG; i++) {
        putc(hist[i]+DIG_ST, stdout);
    }
    return 0;
}
