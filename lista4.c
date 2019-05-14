#include <stdio.h>
#include <math.h>

//Item 1
int MDC(int x, int y){
    int MOD = x % y;
    if (MOD == 0){
        return y;
    } else {
        return MDC(y, MOD);
    }
}


// Item 2
double pot(double x, int k){
    if (k == 0){
        return 1;
    }

    double pow = pot(x, k / 2);

    if ((k % 2) > 0){
        // x é ímpar
        return x * pow * pow;
    }
    // x é par
    return pow * pow;
}


// Item 3
int fibonacci(int n){
    if (n <= 2){
        return 1;
    } else {
        return (fibonacci(n-2) + fibonacci(n-1));
    }
}


// Item 4
int coeficiente(int n, int k){
    if((n >= 0) && (k == 0 || k == n)){
        return 1;
    } else if (k > 0 && n > k){
        return (coeficiente(n - 1, k) + coeficiente(n - 1, k - 1));
    }
}



int main(void){
    char selection;

    printf("\t\tComputadores Digitais 2\n\t\t\tLista 3\n\n");
    printf("\t1 - MDC de três números inteiros;\n");
    printf("\t2 - Potência;\n");
    printf("\t3 - 13 primeiros termos da série de Fibonacci;\n");
    printf("\t4 - Coeficiente binomial;\n\n");

    printf("Escolha um ítem da lista para ser executado: ");
    scanf("%s", &selection);

    switch(selection){
        case '1':
            int x, y, z, mdc;

            printf("Maior divisor comum entre três inteiros.");
            printf("Entre com três números inteiros separados por espaço: ");
            scanf("%d %d %d", &x, &y, &z);

            mdc = MDC(MDC(x, y), z);
            printf("O MDC entre %d, %d e %d é %d\n", x, y, z, mdc);
            break;

        case '2':
            double number, libPow, recursivePow;
            int power;

            printf("Entre com úm operando e uma potência inteira: ");
            scanf("%lf %d", &number, &power);
            libPow = pow(number, power);
            recursivePow = pot(number, power);

            printf("math.h power = %lf\nrecursive power = %lf\n", libPow, recursivePow);
            break;

        case '3':
            int f;
            printf("Os 13 primeiros termos da série de fibonacci são:\n");
            for (int i = 1; i <= 13; i++){
                f = fibonacci(i);
                printf(" %d", f);
            }
            printf(";\n");
            break;

        case '4':
            int n, k, coef;
            printf("Entre com dois números inteiros positivos separados por espaço.\n");
            scanf("%d %d", &n, &k);
            if (n >= k){
                coef = coeficiente(n , k);
                printf("O coeficiente binomial de (%d, %d) é: ", n, k);
            } else {
                coef = coeficiente(k, n);
                printf("O coeficiente binomial de (%d, %d) é: ", k, n);
            }
            printf("%d;\n", coef);
            break;

        default :
            printf("Item não encontrado na lista!");
            break;
    }

}
