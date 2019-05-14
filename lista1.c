#include <stdio.h>
#include <math.h>


// Item 1
void sphereVol(void){
    float radius, volume;

    printf("Digite o raio da esfera: ");
    scanf("%f", &radius);

    volume = (4.0/3.0) * M_PI * pow(radius, 3);
    printf("O volume de uma esfera de raio %f cm é %f cm cúbicos.\n", radius, volume);

}


// Item 2
void gasPrice(void){
    float gallonPrice, litrePrice, conversionTax;
    float litresPerGallon = 3.7854;

    printf("Digite o preço do galão de gasolina nos EUA: ");
    scanf("%f", &gallonPrice);
    printf("Digite taxa de conversão de Dólar para Real: ");
    scanf("%f", &conversionTax);

    litrePrice = (gallonPrice / litresPerGallon) * conversionTax;
    printf("O preço do litro da gasolina em reais é de R$%.3f.\n", litrePrice);
}


// Item 3
void eventDuration(void){
    unsigned long elapsedSeconds;
    int hours, minutes, seconds;

    printf("Entre com um tempo em segundos: .\n");
    scanf("%d", &elapsedSeconds);

    seconds = elapsedSeconds % 60;
    hours = elapsedSeconds / 3600;
    minutes = (elapsedSeconds % 3600) / 60;

    printf("O evento durou %02d:%02d:%05.2f\n", hours, minutes, seconds);

}


// Item 4
void rad2dms(void){

    float rad, deg, min, sec;

    printf("Digite um ângulo em radianos: ");
    scanf("%f", &rad);

    deg = rad * (180 / M_PI);
    min = (deg - (int)deg) * 60;
    sec = (min - (int)min) * 60;

    printf("%.4f radianos equivale a %d°%d\'%d\"\n", rad, (int)deg, (int)min, (int)sec);

}


// Item 5
void posNvel(void){
    float s, s0, v, v0, t, a;

    printf("Para um corpo em movimente, determine:\n Sua aceleração:  a = ");
    scanf("%f", &a);
    printf(" sua posição inicial:  S0 = ");
    scanf("%f", &s0);
    printf(" sua velocidade inicial:  V0 = ");
    scanf("%f", &v0);
    printf(" o tempo de duração do movimento:  t = ");
    scanf("%f", &t);

    s = s0 + (v0 * t) + (a * pow(t, 2)) / 2.0;
    v = v0 + (a * t);

    printf(" V = %.2f;\n S = %.2f\n", v, s);

}


// Item 6
void contaNotas(void){

    int cedulas[7] = {100, 50, 20, 10, 5, 2, 1};
    int valor, resultado;

    printf("Entre com um valor inteiro de Reais: ");
    scanf("%d", &valor);

    printf("Este montante pode ser divido nas seguintes cédulas:\n");

    for (int i = 0; i < 7; i++){
        if (valor >= cedulas[i]){
            resultado = valor / cedulas[i];
            valor = valor % cedulas[i];
            printf(" %d de R$%d;\n", resultado, cedulas[i]);
        }
    }
}


int main(void) {
    char selection;

    printf("\t\tComputadores Digitais 2\n\t\t\tLista 1\n\n");
    printf("\t1 - Volume da esfera;\n");
    printf("\t2 - Galão em Dólares para Litro em Reias;\n");
    printf("\t3 - Tempo em segundos para formato hh:mm:ss.00;\n");
    printf("\t4 - Radianos para Graus, minutos e segundos;\n");
    printf("\t5 - Só vovó tem aquilo tudo quadrado e rachado no meio, vovô e vovó ainda tentam;\n");
    printf("\t6 - Montante em Reais para cédulas;\n\n");

    printf("Escolha um ítem da lista para ser executado: ");
    scanf("%s", &selection);

    switch(selection){
        case '1':
            sphereVol();
            break;
        case '2':
            gasPrice();
            break;
        case '3':
            eventDuration();
            break;
        case '4':
            rad2dms();
            break;
        case '5':
            posNvel();
            break;
        case '6':
            contaNotas();
            break;
        default :
            printf("Item não encontrado na lista!\n");
            break;
    }
}
