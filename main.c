#include<stdio.h>
#include<math.h>

int SolveEqu(double a, double b, double c, double *x1, double *x2){
    double D;
    if((a*a + b*b + c*c) != 0){
        if(a != 0){
            D = b*b - 4*a*c;
            if(D < 0){
                return 0;
            }
            else if(D == 0){
                *x1 = -b/(2*a);
                return 1;
            }
            else if(D >= 0){
                *x1 = (-b + sqrt(D))/(2*a);
                *x2 = (-b - sqrt(D))/(2*a);
                return 2;
            }
        }
        else{
            *x1 = -b/c;
            return 1;
        }
    }
    else{
        return -1;
    }
}

int main(){
    double a, b, c;
    scanf("%lg %lg %lg", &a, &b, &c);
    double x1, x2;
    switch(SolveEqu(a, b, c, &x1, &x2)){
        case 0: printf("The equatin has no roots\n");
                break;
        case 1: printf("The equation has one root: %lg\n", x1);
                break;
        case 2: printf("The equation has two roots: %lg %lg\n", x1, x2);
                break;
        case -1: printf("The equation has infinitely many roots\n");
                break;
    }
    return 0;
}
