#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define N 4


// Item 1  -----------------------------------
int triangular_inferior(double A[][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if ((j > i) && (A[i][j] != 0)){
                return 0;
            }
        }
    }
    return 1;
}


// Item 2  -----------------------------------
int identidade(double A[][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (((i == j) && (A[i][j] != 1)) || ((i != j) && (A[i][j] != 0))){
                return 0;
            }
        }
    }
    return 1;
}


// Item 3  -----------------------------------
int inversa(double A[][N], double B[][N]){
    int i, j, k, soma = 0;
    double mult[N][N];
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            mult[i][j] = 0;
            for (k = 0; k < N; k++){
                mult[i][j] += A[i][k] * B[k][j];
            }
            mult[i][j] = roundf(mult[i][j]);
        }
    }
    return identidade(mult);
}


// Item 4  ----------------------------------
// a
float** converte_a(int m, int n, float *mat){
    int i, j, k;
    float **resp;

    resp = (float**)malloc(m*sizeof(float*));
    for (i = 0; i < m; i++){
        resp[i] = (float*)malloc(n*sizeof(float));
    }

    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            k = (i * n) + j;
            resp[i][j] = mat[k];
        }
    }
    return resp;
}


// b
float* converte_b(int m, int n, float **mat){
    int i, j, k;
    float *resp;
    resp = (float*)malloc(m*n*sizeof(float));

    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            k = (i * n) + j;
            resp[k] = mat[i][j];
        }
    }
    return resp;
}


// AUX METHODS  ------------------------------
void printMatrix(int row, int col, double mat[][N]){
    for (int i=0; i < row; i++){
        printf("\t");
        for(int j=0; j<col; j++){
            if(mat[i][j] < 0){
                printf("%.2lf  ", mat[i][j]);
            } else {
                printf("%.3lf  ", mat[i][j]);
            }
        }
        printf("\n");
     }
}


void printTestMatrix(double A[][N], double B[][N], double ID[][N], double INVA[][N]){
    printf("\nMatriz 1:\n    A =\n");
    printMatrix(N,N,A);
    printf("\nMatriz 2:\n    B =\n");
    printMatrix(N,N,B);
    printf("\nMatriz 3:\n   ID =\n");
    printMatrix(N,N,ID);
    printf("\nMatriz 4:\n INVA =\n");
    printMatrix(N,N,INVA);
    printf("\n");
}


float* createVectorMatrix(int row, int col){
    int i, j, k = 0;
    float *resp;
    resp = (float*)malloc(row*col*sizeof(float));

    printf("entre com os valores da matriz:\n");
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            k = i * col + j;
            printf("V[%d] = ", k);
            scanf("%f", &resp[k]);
        }
    }
    printf("\n");
    return resp;
}


float** createVectorOfPointersMatrix(int row, int col){
    int i, j;
    float **resp;

    resp = (float**)malloc(row*sizeof(float*));
    for (i = 0; i < row; i++){
        resp[i] = (float*)malloc(col*sizeof(float));
    }

    printf("entre com os valores da matriz:\n");
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            printf("M[%d][%d] = ", i, j);
            scanf("%f", &resp[i][j]);
        }
    }
    printf("\n");
    return resp;
}


int main(void){
    char selection, charVar;
    int i, j, k, intVar, intVar2, result, lin, col;
    float floatVal, *floatArr, **floatPArr;
    double A[N][N]={{1, 0, 0, 0},
                    {1, 2, 0, 0},
                    {1, 2, 3, 0},
                    {1, 2, 3, 4}};

    double B[N][N]={{1, 0, 0, 1},
                    {1, 2, 0, 0},
                    {1, 2, 3, 0},
                    {1, 2, 3, 4}};

    double ID[N][N]={{1, 0, 0, 0},
                    {0, 1, 0, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 1}};

    double INVA[N][N]={{1, 0, 0, 0},
                       {-0.5, 0.5, 0, 0},
                       {0, -0.333, 0.333, 0},
                       {0, 0, -0.25, 0.25}};

    printf("\t\tComputadores Digitais 2\n\t\t\tLista 6\n\n");
    printf("\t1 - Matriz Triangular inferior;\n");
    printf("\t2 - Matriz Identidade;\n");
    printf("\t3 - Se as Matrizes A e B são inversas;\n");
    printf("\t4 - Converte formato de Matriz;\n\n");

    printf("Escolha um ítem da lista para ser executado: ");
    scanf("%s", &selection);

    switch(selection){
        case '1':
            printTestMatrix(A, B, ID, INVA);
            printf("Escolha uma matriz: ");
            scanf("%d", &intVar);
            if (intVar == 1){
                result = triangular_inferior(A);
            } else if(intVar == 2){
                result = triangular_inferior(B);
            } else if(intVar == 3){
                result = triangular_inferior(ID);
            } else if(intVar == 4){
                result = triangular_inferior(INVA);
            } else{
                printf("The cake is a lie!");
                break;
            }

            if(result == 1){
                printf("A matriz escolhida É triangular inferior!\n");
            } else{
                printf("A matriz escolhida NÃO é triangular inferior!\n");
            }

        break;

        case '2':
            printTestMatrix(A, B, ID, INVA);
            printf("Escolha uma matriz: ");
            scanf("%d", &intVar);
            if (intVar == 1){
                result = identidade(A);
            } else if(intVar == 2){
                result = identidade(B);
            } else if(intVar == 3){
                result = identidade(ID);
            } else if(intVar == 4){
                result = identidade(INVA);
            } else{
                printf("Matriz não encontrada!");
                break;
            }

            if(result == 1){
                printf("A matriz escolhida É identidade!\n");
            } else{
                printf("A matriz escolhida NÃO é identidade!\n");
            }
            // printf("%d\n", var);
        break;

        case '3':
            result = inversa(A, INVA);
            if(result == 1){
                printf("As matrizes escolhidas SÃO inversas!\n");
            } else{
                printf("As matrizes escolhidas NÃO são inversas!\n");
            }

        break;

        case '4':
            printf("\ta - Matriz como vetor para vetor de ponteiros;\n");
            printf("\tb - Matriz vetor de ponteiros para vetor;\n");
            printf("Selecione uma letra: ");
            scanf("%s", &charVar);

            if(charVar == 'a'){
                printf("Entre como número de linhas da matriz: ");
                scanf("%d", &lin);
                printf("Entre como número de colunas da matriz: ");
                scanf("%d", &col);
                floatArr = createVectorMatrix(lin, col);
                floatPArr = converte_a(lin, col, floatArr);

                for (i = 0; i < lin; i++){
                    for(j = 0; j < col; j++){
                        printf("M[%d][%d] = %f\n", i, j, floatPArr[i][j]);
                    }
                }
            } else if (charVar == 'b'){
                printf("Entre como número de linhas da matriz: ");
                scanf("%d", &lin);
                printf("Entre como número de colunas da matriz: ");
                scanf("%d", &col);
                floatPArr = createVectorOfPointersMatrix(lin, col);
                floatArr = converte_b(lin, col, floatPArr);

                for (i = 0; i < lin; i++){
                    for(j = 0; j < col; j++){
                        k = i * col + j;
                        printf("V[%d] = %f\n", k, floatArr[k]);
                    }
                }
            } else {
                printf("Item não encontrado!\n");
            }
        break;

        default :
            printf("Item não encontrado na lista!\n");
        break;
    }

}
