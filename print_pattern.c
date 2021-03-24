#include <stdio.h>
#include <stdlib.h>

#define LENGTH 2*n - 1
/**
*@ Brief LinePrinter prints the value of each place 
*@ note LENGTH*LENGTH is the size of the matrix
**/

//function
void LinePrinter (int n, int i) {
    for (int j=0; j<LENGTH; j++) {
       if (j<i)  {
                printf("%d ", n-j);
            } else if(j>=i && j<LENGTH-i) {
                printf ("%d ", n-i);
            } else {
                printf ("%d", n+j-LENGTH+3);
                if (j!=LENGTH-1){
                    printf(" ");
                }
            }
        } 
}

int main() 
{

    int n;
    scanf("%d", &n);
    if (n > 100 || n < 1) return 0;
  
    for(int i=0; i<LENGTH; i++) {
        if (i<n){
            LinePrinter (n, i);
        } else {
            LinePrinter (n, LENGTH-i-1);
        }
        printf("\n");
    }
    return 0;
}
