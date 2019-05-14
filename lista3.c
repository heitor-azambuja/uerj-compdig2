#include <stdio.h>
#include <math.h>


// Item 1
float volCalotaEsferica(float h, float r){
    return ((1 / 3) * M_PI * pow(h, 2) * (3 * r - h));
}


float volEsfera(float r){
    return ((4 / 3) * M_PI * pow(r, 3));
}


float volCilindro(float h, float r){
    return (M_PI * h * pow(r, 2));
}


float volMicanga(float raioEsfera, float raioFuro){
    float hCil, volCil, volEsf, volCalota, flechaDoArco;

    flechaDoArco = raioEsfera - sqrt(pow(raioEsfera, 2) - pow(raioFuro, 2));
    hCil = 2 * (raioEsfera - flechaDoArco);

    volEsf = volEsfera(raioEsfera);
    volCil = volCilindro(hCil, raioFuro);
    volCalota = volCalotaEsferica(flechaDoArco, raioEsfera);

    return (volEsf - (volCil + 2 * volCalota));
}


// Item 2
double aproxPI(int n){
    double pi = 0;
    for (int i = 0; i <= n; i++){
        pi += (pow(-1, i) / ((2 * i) + 1));
    }
    return (4 * pi);
}


// Item 3
int raizes(double a, double b, double c, double* x1, double* x2){
    double delta = pow(b, 2) - (4 * a * c);

    if (delta > 0){
        *x1 = (-b + sqrt(delta)) / (2 * a);
        *x2 = (-b - sqrt(delta)) / (2 * a);

        return 2;
    } else if(delta == 0){
        *x1 = (-b) / (2*a);
        *x2 = *x1;

        return 1;
    } else {
        *x1 = 0;
        *x2 = 0;

        return 0;
    }
}


// Item 4
int MDC(int x, int y){
    int temp;
    while (y != 0){
        temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}


// Item 5
int isPrime(int n){
    int rest;
    if (n <= 1){
        return 0;
    } else if (n == 2){
        return 1;
    }

    for (int i = 2; i < n; i++){
        rest = n % i;
        if (rest == 0){
            return 0;
        }
    }
    return 1;
}

// 5.a
int printPrimes(int x){
    int primeFlag;
    printf("Primos menores que %d:", x);
    for (int i = 0; i < x; i++){
        primeFlag = isPrime(i);
        if (primeFlag == 1){
            printf(" %d", i);
        }
    }
    printf(";\n");
}

// 5.b
int printNFirstPrimes(int n){
    int primeFlag;
    int i = 1;

    printf("primeiros %d números primos: \n", n);

    while (n > 0){
        primeFlag = isPrime(i);
        if (primeFlag == 1){
            printf(" %d", i);
            n--;
        }
        i++;
    }
    printf(";\n");
}


// Item 6
int nthFibonacci(int n){
    int F[n];
    F[0] = 1;
    F[1] = 1;
    for (int i = 2; i < n; i++){
        F[i] = F[i-2] + F[i-1];
    }
    return F[n-1];
}

// 6.a
void firstNFibonacci(void){
    int n, f;
    printf("Entre com o número de termos da série de fibonnaci: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        f = nthFibonacci(i);
        printf(" %d", f);
    }
    printf(";\n");
}

// 6.b
int isFibonacci(int n){
    int stopFlag, nthFib;
    int i = 1;
    while (stopFlag != 1){
        nthFib = nthFibonacci(i);
        if (nthFib == n){
            printf("O número %d é o termo número %d na série de fibonacci.\n", n, i);
            stopFlag = 1;
        } else if(nthFib > n){
            printf("O número %d não pertence a série de fibonacci.\n", n);
            stopFlag = 1;
        }
        i++;
    }
}


// Item 7
double aproxSqrt(double n){
    double xi, xii;
    double tol = 0.001;
    xi = 1;
    do {
        xii = 0.5 * (xi + (n / xi));
        xi = xii;
    } while (abs(pow(xi,2) - n) > tol);
    return xi;
}



int main(void) {
    char selection;

    printf("\t\tComputadores Digitais 2\n\t\t\tLista 3\n\n");
    printf("\t1 - Volume da miçanga;\n");
    printf("\t2 - Aproximação de pi pela fórmula de Leibniz;\n");
    printf("\t3 - Raízes de equação quadrática;\n");
    printf("\t4 - Maior Divisor Comum entre dois inteiros positivos;\n");
    printf("\t5 - Primos;\n");
    printf("\t6 - Fibonacci;\n");
    printf("\t7 - Aproximação de raiz quadrada;\n\n");

    printf("Escolha um ítem da lista para ser executado: ");
    scanf("%s", &selection);

    switch(selection){
        case '1':
            float rE, rF, vol;

            printf("Entre com o raio da esfera e do furo separados por espaço.\n");
            scanf("%f %f", &rE, &rF);
            if(rE <= rF){
                printf("O raio da esfera deve ser maior que o raio do furo!\n");
                break;
            }

            vol = volMicanga(rE, rF);
            printf("O volume da miçanga vale %f unidades cúbicas\n", vol);
            break;

        case '2':
            int n;
            float pi;

            printf("Entre com o número de iterações desejadas.\n");
            scanf("%d", &n);

            pi = aproxPI(n);
            printf("pi = %f\n", pi);
            break;

        case '3':
            float a, b, c;
            double x1, x2;
            int numRaizes;

            printf("Entre com os termos a, b e c separados por espaço.\n");
            scanf("%f %f %f", &a, &b, &c);

            numRaizes = raizes(a, b, c, &x1, &x2);
            printf("Raízes reais = %d\nx1 = %f\nx2 = %f\n", numRaizes, x1, x2);
            break;

        case '4':
            int A, B, mdc;

            printf("Entre com dois números inteiros positivos separados por espaço\n");
            scanf("%d %d", &A, &B);

            mdc = MDC(A, B);
            printf("MDC = %d\n", mdc);
            break;

        case '5':
            char sel;
            int num;

            printf("\ta - Primos menores que n;\n");
            printf("\tb - Primeiros n primos;\n");
            printf("Selecione uma letra: ");
            scanf("%s", &sel);
            if(sel == 'a'){
                printf("Entre com um número inteiro: ");
                scanf("%d", &num);
                printPrimes(num);
            } else if (sel == 'b'){
                printf("Entre com um número inteiro: ");
                scanf("%d", &num);
                printNFirstPrimes(num);
            } else {
                printf("Item não encontrado!\n");
            }
            break;

        case '6':
            printf("\ta - Primeiros n números da série de Fibonacci;\n");
            printf("\tb - Verifica se o termo pertence a série de Fibonacci;\n");
            printf("Selecione uma letra: ");
            scanf("%s", &sel);
            if(sel == 'a'){
                firstNFibonacci();
            } else if (sel == 'b'){
                printf("Entre com um número inteiro: ");
                scanf("%d", &num);
                isFibonacci(num);
            } else {
                printf("Item não encontrado!\n");
            }
            break;

        case '7':
            double in, out;
            printf("Entre com um número real: ");
            scanf("%lf", &in);
            out = aproxSqrt(in);
            printf("A raiz quadrada aproximada de %lf é %lf.\n", in, out);
            break;

        default :
            printf("Item não encontrado na lista!\n");
    }
}
