#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Item 1 -------------------------------
int conta_ocorrencias(char *s, char c){
    int i, counter = 0;
    for (i = 0; s[i] != '\0'; i++){
        if (s[i] == c){
            counter ++;
        }
    }
    return counter;
}


// Item 3 -------------------------------
void minusculo(char *str){
    int i;
    for (i = 0; str[i] != '\0'; i++){
        if (str[i]>='A' && str[i]<='Z'){
            str[i] = str[i] + 32;
        }
    }
}


// Item 2 -------------------------------
int conta_vogais(char *str){
    int i, counter = 0;
    minusculo(str);
    for (i = 0; str[i] != '\0'; i++){
        if ((str[i] == 'a') || (str[i] == 'e') || (str[i] == 'i') || (str[i] == 'o') || (str[i] == 'u')){
            counter ++;
        }
    }
    return counter;
}



// Item 4 -------------------------------
void shift_string(char *str){
    int i;
    char ch;
    for (i = 0; str[i] != '\0'; i++){
        ch = str[i];
        if ((str[i] == 90) || (str[i] == 122)){
            str[i] -= 25;
        } else if (!((str[i] >= 48) && (str[i] <= 57))) {
            str[i]++;
        }
    }
}


// Item 5 -------------------------------
void string_oposta(char *str){
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] >= 'A' && str[i] <= 'M'){
            str[i] = 'Z' - (str[i] - 'A');
        } else if (str[i] >= 'N' && str[i] <= 'Z'){
            str[i] = 'A' + ('Z' - str[i]);
        } else if (str[i] >= 'a' && str[i] <= 'm'){
            str[i] = 'z' - (str[i] - 'a');
        } else if (str[i] >= 'n' && str[i] <= 'z'){
            str[i] = 'a' + ('z' - str[i]);
        }
    }
}


// Item 6 -------------------------------
void roda_string(char *str){
    int i, sz = strlen(str);
    char ch = str[sz-1];
    for (i = sz - 1; i >= 0; i--){
        if (i == 0){
            str[i] = ch;
        } else {
            str[i] = str[i-1];
        }
    }
}


// Item 7 -------------------------------
char* retira_sufixo(char *s, int n){
    int i, sz = strlen(s);
    char *str;

    if(n>sz){
        n = sz;
    }

    str = (char*)malloc((sz+1)*sizeof(char));
    strcpy(str,s);

    for (i = 0; i < sz; i++){
        if (i >= (sz-n)){
            str[i] = '\0';
        }
    }
    return str;
}


// Item 8 -------------------------------
char* converte(char *s){
    char *str;
    int sz = strlen(s);
    int i, j = 0;

    str = (char*)malloc((sz+1)*sizeof(char));

    for (i = 0; s[i] != '\0'; i++){
        if ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')){
            str[j] = s[i];
            j++;
        }
    }
    str[j] = '\0';
    return str;
}


// Item 9 -------------------------------
char* concatena(char *s1, char *s2, char sep){
    int sz = (strlen(s1) + strlen(s2) + 1);
    int i = 0;
    int j = 0;
    char *str;

    str = (char*)malloc((sz+1)*sizeof(char));

    while (s1[i] != '\0'){
        str[i] = s1[i];
        i++;
    }
    str[i] = sep;
    i++;
    while (s2[j] != '\0'){
        str[i] = s2[j];
        i++;
        j++;
    }
    str[i] = '\0';
    return str;
}


void inputStr(char *buffer){
    printf("Entre com uma string de caracteres:\n");
    scanf(" %80[^\n]", buffer);
}


int main(void){
    char selection, buffer[81], buffer2[81], *outBuffer, ch;
    int counter;

    printf("\t\tComputadores Digitais 2\n\t\t\tLista 7\n\n");
    printf("\t1 - Conta ocorrências de um char numa string;\n");
    printf("\t2 - Conta quantidade de vogais numa string;\n");
    printf("\t3 - Converte letras maiúsculas em minúsculas;\n");
    printf("\t4 - Shift string;\n");
    printf("\t5 - String oposta;\n");
    printf("\t6 - Roda string;\n");
    printf("\t7 - Remove sufixo;\n");
    printf("\t8 - Só letras;\n");
    printf("\t9 - concatena separador;\n\n");

    printf("Escolha um ítem da lista para ser executado: \n");
    scanf("%s", &selection);

    switch(selection){
        case '1':
            printf("Entre com o caracter cuja ocorrência deseja-se detectar na string: ");
            scanf(" %c", &ch);
            inputStr(buffer);
            counter = conta_ocorrencias(buffer, ch);
            printf("O caracter %c, aparece %d vezes na string.\n", ch, counter);
        break;

        case '2':
            inputStr(buffer);
            counter = conta_vogais(buffer);
            printf("A string tem %d vogais.\n", counter);
        break;

        case '3':
            inputStr(buffer);
            minusculo(buffer);
            printf("%s\n", buffer);
        break;

        case '4':
            inputStr(buffer);
            shift_string(buffer);
            printf("%s\n", buffer);
        break;

        case '5':
            inputStr(buffer);
            string_oposta(buffer);
            printf("%s\n", buffer);
        break;

        case '6':
            inputStr(buffer);
            roda_string(buffer);
            printf("%s\n", buffer);
        break;

        case '7':
            inputStr(buffer);
            printf("Quantos caracteres devem ser removidos do fim: ");
            scanf(" %d", &counter);
            outBuffer = retira_sufixo(buffer, counter);
            printf("String resultante: %s\n", outBuffer);
        break;

        case '8':
            inputStr(buffer);
            outBuffer = converte(buffer);
            printf("String resultante: %s\n", outBuffer);
        break;

        case '9':
            inputStr(buffer);
            printf("Entre com UM caracter separador: ");
            scanf(" %c", &ch);
            inputStr(buffer2);
            outBuffer = concatena(buffer, buffer2, ch);
            printf("String resultante: %s\n", outBuffer);
        break;

        default :
            printf("Item não encontrado na lista!\n");
        break;
    }
}
