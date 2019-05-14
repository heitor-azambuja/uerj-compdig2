#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Item 1
void maior(void){
    int a, b, c;

    printf("Entre com três números inteiros separados por espaço.\n");
    scanf("%d %d %d", &a, &b, &c);

    printf("O maior número é ");
    if (a >= b && a >= c){
        printf("%d\n", a);
    } else if(b >= a && b >= c){
        printf("%d\n", b);
    } else {
        printf("%d\n", c);
    }
}


// Item 2
void ordemCrescente(void){
    int val[3], temp, swap = 1;

    printf("Entre com três números inteiros separados por espaço.\n");
    scanf("%d %d %d", &val[0], &val[1], &val[2]);

    // Bubble sort
    while (swap != 0){
        swap = 0;
        for (int i = 1; i < 3; i++){
            if (val[i-1] > val[i]){
                temp = val[i-1];
                val[i-1] = val[i];
                val[i] = temp;
                swap++;
            }
        }
    }

    printf("Números em ordem crescente: %d %d %d\n", val[0], val[1], val[2]);
}


// Item 3
void eqQuadratica(void){
    float a, b, c, delta, x1, x2;

    printf("Entre com os índices a, b e c de uma equação do segundo grau separados por espaço.\n");
    scanf("%f %f %f", &a, &b, &c);

    delta = pow(b, 2) - (4 * a * c);

    if (delta > 0){
        x1 = (-b + sqrt(delta)) / (2*a);
        x2 = (-b - sqrt(delta)) / (2*a);

        printf("A equação tem duas raízes reais e distintas:\n");
        printf("x1 = %.2f\n", x1);
        printf("x2 = %.2f\n", x2);
    } else if(delta == 0){
        x1 = (-b) / (2*a);

        printf("A equação tem duas raízes reais e iguais:\n");
        printf("x1 = x2 = %.2f\n", x1);
    } else {
        printf("A equação não tem raízes reais.\n");
    }
}


// Item 4
void mediaFinal(void){
    float p1, p2, media;

    printf("Entre com as notas da P1 e P2 separadas por espaço.\n");
    scanf("%f %f", &p1, &p2);

    media = (p1 + p2) / 2;
    if (media >= 5.0 && p1 >= 3.0 && p2 >= 3){
        printf("Média final = %.1f; Aluno Aprovado Direto.\n", media);
    } else {
        float p3;
        printf("Entre com a nota da p3.\n");
        scanf("%f", &p3);

        if (p1 >= p2){
            media = (p1 + p3) / 2;
        } else {
            media = (p2 + p3) / 2;
        }

        if (media >= 5.0){
            printf("Média final = %.1f; Aluno Aprovado.\n", media);
        } else {
            printf("Média final = %.1f; Aluno Reprovado.\n", media);
        }
    }
}


// Item 5
void pol2cart(void){
    float r, a, x, y;
    int flag = 0;

    while(flag == 0){
        printf("Entre com um valor para o raio: ");
        scanf("%f", &r);

        if (r < 0){
            printf("O raio deve ser maior ou igual a zero\n");
        } else {
            flag = 1;
        }
    }

    printf("Entre com um valor para o ângulo em graus: ");
    scanf("%f", &a);

    x = r * cos(a);
    y = r * sin(a);

    printf("x = %f\ny = %f\n", x, y);

}


// Item 6
void converter(void){
    float val, resp;
    char selection2, *selection1;
    selection1 = (char*)malloc(2);

    printf("\tSelecione uma grandeza física.\n\n");
    printf("\t1 - Peso;\n");
    printf("\t2 - Volume;\n");
    printf("\t3 - Comprimento;\n");
    scanf("%s", selection1);

    printf("\tSelecione uma conversão.\n\n");
    switch(*selection1){
        case '1':
            printf("\t\t1 - Libra -> Quilograma\n");
            printf("\t\t2 - Quilo -> Libra\n");
            printf("\t\t3 - Onça  -> Grama\n");
            printf("\t\t4 - Grama -> Onça\n");
            break;
        case '2':
            printf("\t\t1 - Galão     -> Litro\n");
            printf("\t\t2 - Litro     -> Galão\n");
            printf("\t\t3 - Onça      -> Mililitro\n");
            printf("\t\t4 - Mililitro -> Onça\n");
            break;
        case '3':
            printf("\t\t1 - Milha      -> Quilômetro\n");
            printf("\t\t2 - Quilômetro -> Milha\n");
            printf("\t\t3 - Jarda      -> Metro\n");
            printf("\t\t4 - Metro      -> Jarda\n");
            break;
        default :
            printf("Item não encontrado na lista!\n");
            return;
            break;
    }

    scanf("%s", &selection2);
    printf("Entre com o valor a ser convertido: ");
    scanf("%f", &val);

    switch(selection2){
        case '1':
            printf("selection1 = %c\n",selection1);
            if (*selection1 == '1'){
                resp = val * 0.4536;
                printf("%f libra(s) vale %f quilograma(s)\n", val, resp);
            } else if(*selection1 == '2') {
                resp = val * 3.76541;
                printf("%f galão(ões) vale %f litro(s)\n", val, resp);
            } else {
                resp = val * 1.6093;
                printf("%f milha(s) vale %f quilômetro(s)\n", val, resp);
            }
            break;
        case '2':
            if (*selection1 == '1'){
                resp = val / 0.4536;
                printf("%f quilo(s) vale %f libra(s)\n", val, resp);
            } else if(*selection1 == '2') {
                resp = val / 3.76541;
                printf("%f litro(s) vale %f galão(ões)\n", val, resp);
            } else {
                resp = val / 1.6093;
                printf("%f quilômetro(s) vale %f milha(s)\n", val, resp);
            }
            break;
        case '3':
            if (*selection1 == '1'){
                resp = val * 28.3498;
                printf("%f onça(s) vale %f grama(s)\n", val, resp);
            } else if(*selection1 == '2') {
                resp = val * 29.5735;
                printf("%f onça(s) vale %f mililitro(s)\n", val, resp);
            } else {
                resp = val * 0.9144;
                printf("%f jarda(s) vale %f metro(s)\n", val, resp);
            }
            break;
        case '4':
            if (*selection1 == '1'){
                resp = val / 28.3498;
                printf("%f grama(s) vale %f onça(s)\n", val, resp);
            } else if(*selection1 == '2') {
                resp = val / 29.5735;
                printf("%f mililitro(s) vale %f onça(s)\n", val, resp);
            } else {
                resp = val / 0.9144;
                printf("%f metro(s) vale %f jarda(s)\n", val, resp);
            }
            break;
        default :
            printf("Item não encontrado na lista!\n");
    }
    free(selection1);
}


int main(void) {
    char selection;

    printf("\t\tComputadores Digitais 2\n\t\t\tLista 2\n\n");
    printf("\t1 - Maior de 3 inteiros;\n");
    printf("\t2 - 3 inteiros em ordem crescente;\n");
    printf("\t3 - Resolver Equação quadrática;\n");
    printf("\t4 - Média final;\n");
    printf("\t5 - Polar para cartesiano;\n");
    printf("\t6 - Converter unidades;\n\n");

    printf("Escolha um ítem da lista para ser executado: ");
    scanf("%s", &selection);

    switch(selection){
        case '1':
            maior();
            break;
        case '2':
            ordemCrescente();
            break;
        case '3':
            eqQuadratica();
            break;
        case '4':
            mediaFinal();
            break;
        case '5':
            pol2cart();
            break;
        case '6':
            converter();
            break;
        default :
            printf("Item não encontrado na lista!\n");
            break;
    }
}
