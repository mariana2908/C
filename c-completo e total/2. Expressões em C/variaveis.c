#include <stdio.h>
#include <string.h>

// A forma geral de uma declaração é
// tipo lista_de_variaveis;

// Algumas declarações:
int i,j,l;
short int si;
unsigned int ui;
double balance, profit, loss;

// Variáveis locais
void func1(void){
    int x;
    x = 10;
}

void func2(void){
    int x;
    x = -199;
}

// ...
int main(void){
    int t;

    scanf("%d", &t);

    if(t == 1) {
        char s[80]; /* isto é criado apenas na entrada deste bloco*/
        getchar(); // Consumir o caractere de nova linha deixado por scanf
        fgets(s, sizeof(s), stdin);
        /* Remove o caractere de nova linha, se presente */
        s[strcspn(s, "\n")] = '\0';

        /* faz alguma coisa ... */
        printf("Você digitou: %s\n", s);
    }

    return 0;
}

// Todas as variáveis locais devem ser declaradas no início do bloco em que elas são definidas
/* Esta função está errada */
void f(void){
    int i;

    i = 10;

    int j;  /* esta linha irá provocar um erro */

    j = 20;
}
// Correção:
/* Define j dentro de seu próprio block de código. */
void f(void){
    int i; 
    i = 10;
    {   /* Define j em seu próprio bloco de código */
        int j;
        j = 20;
    }
}

/* Define j no início do bloco da função. */
void f(void){
    int i; 
    int j;

    i = 10;
    j = 20;
}

// Você pode inicializar uma variável local com algum valor conhecido. Esse valor será atribuído à variável cada vez que o bloco de código em que ela é declarada for executado. Por exemplo, o programa seguinte imprime o número 10 dez vezes:
#include <stdio.h>

void f(void);

void main(void) {
    int i;
    for (i=0; i<10; i++) f();
}

void f(void) {
    int j = 10;
    printf("%d", j);
    j++; /* esta linha não tem nenhum efeito */
}