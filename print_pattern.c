// 123456789
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define LENGTH 2*n - 1

int main() 
{

    int n;
    scanf("%d", &n);
    if (n > 100 || n < 1) return 0;
  
    for(int i=0; i< LENGTH; i++) {
        for(int j=0; j< LENGTH; j++)  {
            if (j<i)  {
                printf("%d", n-j);
            }
            else if(j>=i && j<LENGTH-i) {
                printf ("%d", n-i);
            }
            else {
                printf ("%d", n+j-LENGTH+1);
            }
        }
        printf("\n");
    }
    return 0;
}

