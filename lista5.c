#include <stdio.h>
#include <math.h>
#include<stdlib.h>

// Item 1  ----------------------------------------------
int negativos(int n, float *v){
    int negativeCounter = 0;
    for (int i = 0; i < n; i ++){
        if (v[i] < 0){
            negativeCounter ++;
        }
    }
    return negativeCounter;
}


// Item 2  ----------------------------------------------
int pares(int n, int *v){
    int contador = 0;
    for (int i = 0; i < n; i++){
        if ((v[i] % 2) == 0){
            contador ++;
        }
    }
    return contador;
}


// Item 3  ----------------------------------------------
void inverte(int n, int *v){
    int temp;
    for (int i = 0; i < n/2; i++){
        temp = v[i];
        v[i] = v[n-1-i];
        v[n-1-i] = temp;
    }
}


// Item 4  ----------------------------------------------
float minimo(int n, float *v){
    float min = INFINITY;
    for (int i = 0; i < n; i++){
        if (v[i] < min){
            min = v[i];
        }
    }
    return min;
}


// Item 5  ----------------------------------------------
int negativosRec(int n, float *v, int counter){
    n--;
    if (n < 0){
        return counter;
    }
    if (v[n] < 0){
        counter ++;
    }
    negativosRec(n,v,counter);

}


int paresRec(int n, int *v, int counter){
    n--;
    if (n < 0){
        return counter;
    }
    if (v[n] % 2 == 0){
        counter ++;
    }
    paresRec(n, v, counter);
}


void inverteRec(int n, int *v, int index){
    int temp;
    if (index < n/2){
        temp = v[index];
        v[index] = v[n-1-index];
        v[n-1-index] = temp;
        index++;
        inverteRec(n, v, index);
    }
}


float minimoRec(int n, float *v, float min){
    n--;
    if (n < 0){
        return min;
    }
    if (v[n] < min){
        min = v[n];
    }
    minimoRec(n, v, min);
}


// Item 6  ----------------------------------------------
float harmonica (int n, float *v){
    float media = 0;
    for (int i = 0; i < n; i++){
        media += (1 / v[i]);
    }
}


// Item 7  ----------------------------------------------
float geometrica(int n, float *v){
    float media = 1;
    for (int i = 0; i < n; i++){
        media *= v[i];
    }
    media = pow(media, 1.0/n);
    return media;
}


// Item 8  ----------------------------------------------
float ponderada(int n, float *v, float *w){
    float num = 0;
    float den = 0;
    float media;
    for (int i = 0; i < n; i++){
        num += (v[i] * w[i]);
        den += w[i];
    }
    media = num / den;
    return media;
}


// Item 9  ----------------------------------------------
double avalia(double *poli, int grau, double x){
    double root = 0;
    for (int i = 0; i <= grau; i++){
        root += (poli[i] * pow(x,(grau - i)));
    }
    return root;
}


// Item 10  ----------------------------------------------
void deriva(double *poli, int grau, double *out){
    for (int i = 1; i <= grau; i++){
        out[i-1] = poli[i] * i;
    }
}


// Item 11  ----------------------------------------------
int testPA(int n, int *v){
    int k = v[1] - v[0];
    for(int i = 0; i < n; i++){
        if (v[i] != (v[0] + i*k)){
            return 0;
        }
    }
    return k;
}


// Item 12  ----------------------------------------------
void histograma(int n, float *v, int *h){
    int index;
    for (int i = 0; i < n; i++){
        index = v[i] / 0.1;
        h[index]++;
    }
}


// AUX FUNCTIONS --------------------------------------------
int* intArray(int n){
    int i;
    int *array;

    array = (int*)malloc(n*sizeof(int));
    printf("Entre com %d números inteiros:\n", n);
    for (i = 0; i < n; i++){
        scanf(" %d", &array[i]);
    }
    return array;

}


float* floatArray(int n){
    int i;
    float *array;

    array = (float*)malloc(n*sizeof(float));
    printf("Entre com %d números reais:\n", n);
    for (i = 0; i < n; i++){
        scanf(" %f", &array[i]);
    }
    return array;

}


double* doubleArray(int n){
    int i;
    double *array;

    array = (double*)malloc(n*sizeof(double));
    printf("Entre com %d números reais:\n", n);
    for (i = 0; i < n; i++){
        scanf(" %lf", &array[i]);
    }
    return array;

}


int tamanhoArray(void){
    int n;
    printf("Entre com o tamanho do vetor: ");
    scanf(" %d", &n);
    return n;
}


void printIntArray(int n, int *arr){
    int i;
    for (i = 0; i < n; i++){
        printf(" %d", arr[i]);
    }
    printf(";\n");
}


void printFloatArray(int n, float *arr){
    int i;
    for (i = 0; i < n; i++){
        printf(" %f", arr[i]);
    }
    printf(";\n");
}

void printDoubleArray(int n, double *arr){
    int i;
    for (i = 0; i < n; i++){
        printf(" %lf", arr[i]);
    }
    printf(";\n");
}

int main (void){
    int selection;
    int i, n, counter, *intArr;
    float floatVal, *floatArr, *floatArr2;
    float v[] = {0.11, 0.2, 0.03, 0.56, 0.323, 0.345, 0.234, 0.56,0.6546, 0.123, 0.123, 0.999};
    int h[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int vn = 12;
    double doubleVal, doubleVal2, *doubleArr, *doubleArr2;

    printf("\t\tComputadores Digitais 2\n\t\t\tLista 5\n\n");
    printf("\t 1 - Conta números negativos em um vetor;\n");
    printf("\t 2 - Conta números pares em um vetor;\n");
    printf("\t 3 - Inverte ordem dos elementos;\n");
    printf("\t 4 - Menor valor no vetor;\n");
    printf("\t 5 - Todos os anteriores recursivamente;\n");
    printf("\t 6 - Cálculo de média harmônica;\n");
    printf("\t 7 - Cálculo da média geométria;\n");
    printf("\t 8 - cálculo da média ponderada;\n");
    printf("\t 9 - Avalia polinômio;\n");
    printf("\t10 - Derivada simbólica de um polinômio;\n");
    printf("\t11 - Testa se vetor é PA;\n");
    printf("\t12 - Histograma;\n\n");

    printf("Escolha um ítem da lista para ser executado: ");
    scanf("%d", &selection);

    switch(selection){
        case 1:
            n = tamanhoArray();
            floatArr = floatArray(n);
            counter = negativos(n, floatArr);
            printf("O vetor tem %d números negativos.\n", counter);
        break;

        case 2:
            n = tamanhoArray();
            intArr = intArray(n);
            counter = pares(n, intArr);
            printf("O vetor tem %d números pares.\n", counter);
        break;

        case 3:
            n = tamanhoArray();
            intArr = intArray(n);
            inverte(n, intArr);
            printIntArray(n, intArr);
        break;

        case 4:
            n = tamanhoArray();
            floatArr = floatArray(n);
            floatVal = minimo(n, floatArr);
            printf("%f é o menor elemento do vetor.\n", floatVal);
        break;

        case 5:
            n = tamanhoArray();
            intArr = intArray(n);
            floatArr = floatArray(n);

            counter = negativosRec(n, floatArr, 0);
            printf("O vetor de reais tem %d números negativos.\n", counter);

            counter = paresRec(n, intArr, 0);
            printf("O vetor de inteiros tem %d números pares.\n", counter);

            inverteRec(n, intArr, 0);
            printf("O array de inteiros invertido: ");
            printIntArray(n, intArr);

            floatVal = minimoRec(n, floatArr, INFINITY);
            printf("O menor elemento do vetor de reais é %.4f.\n", floatVal);
        break;

        case 6:
            n = tamanhoArray();
            floatArr = floatArray(n);
            floatVal = harmonica(n, floatArr);
            printf("A média harmónica dos elementos do vetor vale %f;\n", floatVal);
        break;

        case 7:
            n = tamanhoArray();
            floatArr = floatArray(n);
            floatVal = geometrica(n, floatArr);
            printf("A média geimétrica dos elementos do vetor vale %f;\n", floatVal);
        break;

        case 8:
            n = tamanhoArray();
            printf("Vetor de valores:\n");
            floatArr = floatArray(n);
            printf("Vetor de pesos:\n");
            floatArr2 = floatArray(n);
            floatVal = ponderada(n, floatArr, floatArr2);
            printf("A média ponderada dos elementos dos vetores vale %f;\n", floatVal);
        break;

        case 9:
            printf("Estrutura:\n");
            printf("função = ax² + bx + c\nvetor = [c b a]\n\n");
            printf("Entre com o Grau do polinômio:\n");
            scanf(" %d", &n);
            printf("Vetor de coeficientes:\n");
            doubleArr = doubleArray(n+1);
            printf("Entre com um valor para X: ");
            scanf("%lf", &doubleVal);
            doubleVal2 = avalia(doubleArr, n, doubleVal);
            printf("Para o valor dado, o polinômio avalia para: %lf;\n", doubleVal2);
        break;

        case 10:
            printf("Estrutura:\n");
            printf("função = ax² + bx + c\nvetor = [c b a]\n\n");
            printf("Entre com o Grau do polinômio:\n");
            scanf(" %d", &n);
            printf("Vetor de coeficientes:\n");
            doubleArr = doubleArray(n+1);
            doubleArr2 = (double*)malloc((n)*sizeof(double));
            deriva(doubleArr, n, doubleArr2);
            printf("Os coeficientes da derivada simbólica são:\n");
            printDoubleArray(n, doubleArr2);
        break;

        case 11:
            n = tamanhoArray();
            intArr = intArray(n);
            counter = testPA(n, intArr);
            if(counter == 0){
                printf("O vetor não é uma PA!\n");
            } else {
                printf("O vetor é uma PA de constante k=%d;\n", counter);
            }
        break;

        case 12:
            printf("Médias Consideradas:\n");
            printFloatArray(vn, v);
            histograma(vn, v, h);
            printf("Histograma resultante:\n");
            printIntArray(10, h);
        break;

        default :
            printf("Item não encontrado na lista!\n");
        break;
    }
}
