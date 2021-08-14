#include<stdio.h>
#include<stdlib.h>
#include <math.h>
int reverse(int x){
    long num = 0;
    while(x!=0){
        num= (num*10)+(x%10);
        x=x/10;
    }
    if(num >= pow(-2, 31) && num<= pow(2, 31))
    return num;
    return 0;
}