#include<stdio.h>
#include<math.h>
#include<locale.h>

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
    char *locale = setlocale(LC_ALL, "");
    double a, b, c;
    scanf("%lg %lg %lg", &a, &b, &c);
    double x1, x2;
    switch(SolveEqu(a, b, c, &x1, &x2)){
        case 0: printf(" вадратное уравнение не имеет корней\n");
                break;
        case 1: printf(" вадратное уравнение имеет 1 корень: %lg\n", x1);
                break;
        case 2: printf(" вадратное уравнение имеет 2 корн€: %lg %lg\n", x1, x2);
                break;
        case -1: printf("”равнение имеет бесконечно много корней\n");
                break;
    }
    return 0;
}
