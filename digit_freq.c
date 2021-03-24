// 123456789
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int hist[10]={0};
    char c;
    c = getc(stdin);
    while ( c!= '?'){ \\change this later
        if (c>='0' && c<'9') {
            hist[c-'0']++;
        }
        c = getc(stdin);
    }
    for(int i=0; i<10; i++) {
        printf("%d", hist[i]); \\change this later
    }
    return 0;
}
