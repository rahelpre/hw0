// 123456789
#include <stdio.h>
#include <stdlib.h>

#define LENGTH 2*n - 1

int pro (int n, int i) {
    for (int j=0; j<LENGTH; j++) {
       if (j<i)  {
                printf("%d", n-j);
            }
        else if(j>=i && j<LENGTH-i) {
                printf ("%d", n-i);
            }
        else {
                printf ("%d", n+j-LENGTH+3);
            }
        } 
    return 0;
}

int main() 
{

    int n;
    scanf("%d", &n);
    if (n > 100 || n < 1) return 0;
  
    for(int i=0; i<LENGTH; i++) {
        if (i<n){
            pro (n, i);
        }
        else {
            pro (n, LENGTH-i-1);
        }
        printf("\n");
    }
    return 0;
}
