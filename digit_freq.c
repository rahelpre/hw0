#include <stdio.h>
#include <stdlib.h>


int main() {
    int hist[10]={0};
    char c;
    c = getc(stdin);
    while ( c!= EOF){
        if (c>='0' && c<'9') {
            hist[c-'0']++;
        }
        c = getc(stdin);
    }
    for(int i=0; i<10; i++) {
        putc(hist[i]+'0', stdout);
    }
    return 0;
}
