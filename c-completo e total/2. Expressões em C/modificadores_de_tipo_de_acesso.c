/* O C introduziu novos modificadores (também chamados _quantificadores_) que
controlam a maneira como as variáveis podem ser acessadas ou modificadas.
Esses modificadores são *const* e *volatile*. Devem preceder os modificadores de 
tipo e os nomes que eles modificam.*/

// const
/* Variáveis do tipo *const* não podem ser modificadas por seu programa. (Uma
variável *const* pode, entretanto, receber um valor inicial.) O compilador pode
colocar variáveis  desse tipo em memóriade apenas leitura (ROM). Por exemplo:*/
const int a=10;
/* cria uma variável inteira chamada *a*, com um valor inicial 10 que seu pro-
grama não pode modificar. Você pode, porém, usar a variável *a* em outros tipos
de expressões. Uma variável *const* recebe seu valor de uma inicialização explí-
cita ou por algum recurso dependente do hardware.*/
/* O qhalificador *const* pode ser usado para proteger os objects apontados
pelos argumentos de uma função de serem modificados por esta função. Isto é,
quando um ponteiro é passado para uma função, esta função pode modificar a 
variável real apontada pelo ponteiro. Entretanto, se o ponteiro é especificado
como *const* na declaração dos parâmetros, o código da função não será capaz
de modificar o que ele aponta. Por exemplo, a função *sp_to_dash()*, no programa
seguinte, imprime um traço para cada espaço do seu argumento string. Ou melhor,
a string "isso é um teste" será impressa "isso-é-um-teste". O uso de *const*
na declaração do parâmetro assegura que o código dentro da função não possa
modificar o objeto apontado pelo parâmetro.*/

#include <stdio.h>

void sp_to_dash(const char *str);

void main(void) {
    sp_to_dash("isso é um teste");
}

void sp_to_dash(const char *str) {
    while(*str) {
        if(*str == ' ') printf("%c", '-');
        else printf("%c", *str);
        str++;
    }
}
/* Se você escrevesse *sp_to_dash()* de forma que a string fosse modificada, ela
não seria compilada. Por exemplo, se você tivesse codificado *sp_to_dash* como 
segue, obteria um erro:*/

// isso está errado
void sp_to_dash(const char *str) {
    while(*str) {
        if(*str == ' ') //*str = '-'; /*não faça isto*/
        printf("%c", *str);
        str++;
    }
}

/* Muitas funções da biblioteca C padrão usam *const* em suas declarações de 
parâmetros. Por exemplo, a função *strlen()* tem este protótipo:*/
size_t strlen(const char *str);
/* Especificar _str_ como *const* assegura que *strlen()* não modificará a 
string apontada por str. Em geral, quando uma função da biblioteca padrão não 
tem necessidade de modificar um objeto apontado por um argumento, ele é decla-
rado como *const*
   Você também pode usar *const* para verificar se seu programa não modifica 
uma variável. Lembre-se de que uma variável do tipo *const* pode ser modifica-
da por algo externo ao seu programa. Por exemplo, um dispositivo de hardware 
pode ajustar seu valor. Porém, declarando uma variável como *const*, você po-
de provar que qualquer alteração nesta variável ocorre devido a eventos exter-
nos.*/

// volatile
/* O modificador *volatile* é usado para informar ao compilador que o valor de 
uma variável pode ser alterado de maneira não explicitamente especificada pelo 
programa. Por exemplo, um endereço de uma variável global pode ser passado para
a rotina de relógio do sistema operacional e usado para guardar o tempo real 
do sistema. Nessa situação, o conteúdo da variável é alterado sem nenhum coman-
do de atribuição explícito no programa. Isso é importante porque muitos compila-
dores C automaticamente otimizam certas expressões, assumindo que o conteúdo de
uma variável é imutável, se sua referência não aparecer no lado esquerdo da ex-
pressão; logo, ela pode não ser reexaminada toda vez que for referenciada. Além
disso, alguns compiladores mudam a ordem de avaliação de uma expressão durante 
o processo de compilação. O modificador *volatile* previne a ocorrência dessas 
mudanças.
   É possível usar *const* e *volatile* juntos. Por exemplo, se 0x30 é assumido
como sendo o valor de uma porta que é mudado apenas por condições externas, a 
declaração seguinte é precisamente o que você quer para previnir qualquer pos-
sibilidadede efeitos colaterais acidentais.*/

const volatile unsigned char *port = 0x30;