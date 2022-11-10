#include<stdio.h>
#include<math.h> 

int main(){
    int a;
    double b=0;
    printf("Enter number: ");
    scanf("%d",&a);
    
    for (int i=1;i<=a;++i){
     b=sqrt(i+b);
    }
    printf("Answer: %.3lf",b);
    return 0;
}