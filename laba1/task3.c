#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    float ux;
    float uy;
    printf("insert coords x y: ");
    scanf("%f %f", &ux, &uy);
    if (uy<=2 && uy>=0 && uy>=(-2*ux-2) && uy>=(2*ux-2)){
        printf("its inside the trapecii\n");
    }else{  
        printf("it got out\n");
    }



}
