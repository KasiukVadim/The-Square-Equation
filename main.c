#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double isZero(double x){
    if(abs(x) < 1e-7) return 0.0;
    return x;
}

int SolveEqu(double a, double b, double c, double *x1, double *x2){
    a = isZero(a);
    b = isZero(b);
    c = isZero(c);
    if(a*a + b*b + c*c){
        if(a != 0){
            double D = b*b - 4*a*c;
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
            if(b != 0){
                *x1 = -c/b;
                return 1;
            }
            else{
                if(c == 0){
                    return -1;
                }
                else{
                    return 0;
                }
            }
        }
    }
    else{
        return -1;
    }
}

void unit_test(int n, double a, double b, double c, int tnum, double tx1, double tx2){
    int x1, x2;
    int num = SolveEqu(a, b, c, &x1, &x2);
    if(num == tnum){
        switch (num){
            case -1: printf("Test %d is okay\n", n); break;
            case 0: printf("Test %d is okay\n", n); break;
            case 1: if(x1 == tx1) printf("Test %d is okay\n", n);
                    else {printf("Test %d is wrong\nInput data: %lg %lg %lg %d %lg\n", n, a, b, c, tnum, tx1);
                          printf("Output data: number of roots = %d, x1 = %lg\n", tnum, x1);}
                    break;
            case 2: if(x1 == tx1 && x2 == tx2){printf("Test %d is okay\n");}
                    else{printf("Test %d is wrong\nInput data: %lg %lg %lg %d %lg %lg\n", n, a, b, c, tnum, tx1, tx2);
                         printf("Output data: number of roots = %d, x1 = %lg, x2 = %lg\n", tnum, x1, x2);}
                    break;
        }
    }
    else{
        printf("Test %d is wrong\nInput data: %lg %lg %lg %d %lg\n", n, a, b, c, tnum);
        printf("Output data: number of roots = %d\n", num);
    }
}


int main(){
    double a, b, c;
    int correct = (scanf("%lg %lg %lg", &a, &b, &c) == 3) && (getchar () == '\n');
    while(!correct){
        printf("Incorrect input data, please try again\n");
        while (getchar() != '\n'){;}
        correct = (scanf("%lg %lg %lg", &a, &b, &c) == 3) && (getchar () == '\n');
    }
    double x1, x2;
    switch(SolveEqu(a, b, c, &x1, &x2)){
        case 0: printf("The equation has no roots\n");
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
