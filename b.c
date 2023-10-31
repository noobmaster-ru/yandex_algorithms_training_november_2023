#include <stdio.h>
#include <math.h>

int main(){
    int a,b,c,d, up , down,i ;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    up = a*d + b*c;
    down = b*d; 
    for (i =2 ; i <= ((down/2)+1); i++ ){
        if ((up % i == 0) && (down % i ==0)){
            while ((up % i == 0) && (down % i ==0)){
                up = up / i;
                down = down / i;
            }
        }

    }
    printf("%d %d",up,down);
    return 0;
}