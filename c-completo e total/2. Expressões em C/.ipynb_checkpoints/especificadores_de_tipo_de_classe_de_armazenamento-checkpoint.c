/* Há quatro especificadores de classe de armazenamento suportados por C.
    extern
    static
    register
    auto
Esses especificadores são usados para informar ao compilador como a 
variável deve ser armazenada. O especificador de armazenamento procede o res-
to da declaração da variável. Sua forma geral é: */
// especificador_de_armazenamento tipo nome_da_variavel;

// extern
/* Uma vez que C permite que módulos de um programa grande sejam compilados 
separadamente para então seremlinkeditados juntos, uma forma de aumentar a 
velocidade de compilação e ajudar no gerenciamento de grandes projetos, deve 
haver alguma maneira de dizer a todos os arquivos sobre as variáveis globais
solicitadas pelo programa. Lembre-se de que você pode declarar uma variável 
global apenas uma vez. Se você tentar declarar duas variáveis com o mesmo 
nome dentro do mesmo arquivo, seu compilador C poderá imprimir uma mensa-
gem de erro como "nome de variável duplicado" ou poderá simplismente es-
colher uma variável. O mesmo problema ocorre se você simplismente declara 
todas as variáveis globais necessárias ao seu programa em cada arquivo. Embo-
ra o compilador não emita nenhuma mensagem de erro em tempo de compilação,
você estaria realmente tentando criar duas (ou mais) cópias de cada variável.
O transtorno começaria quando você tentasse linkeditar seus módulos. O linke-
ditor mostraria a mensagem de erro como "rótulo duplicado" porque ele não 
saberia que variável usar. A solução seria declarar todas as suas variáveis 
globais em um arquivo e usar declarações *extern* nos outros, como na Figura
 2.2.
   No arquivo 2, a lista de variáveis globais foi copiada do arquivo 1 e o 
especificador *extern* foi adicionado às declarações. O especificador 
*extern* diz ao compilador que os tipos e nomes de variável que o seguem fo-
ram declarados em outro lugar. Em outras palavras, *extern* deixa o compila-
dor saber o que os tipos e nomes são para essas variáveis globais sem real-
mente criar armazenamento para elas novamente. Quando o linkeditor unir os 
dois módulos, todas as referências externas sarão resolvidas.
   Quando utiliza uma variável global dentro de uma função que está no mesmo
arquivo que a declaração da variável global, você pode usar *extern*, como 
mostrado aqui:*/

//Arquivo 1
int x, y;
char ch;
main(void) {
    //...
}

func1() {
    x = 123;
}

//Arquivo 2
extern int x, y;
extern char ch;
func22(void) {
    x = y/10;
}

func23() {
    y = 10;
}

//*Figura 2.2* Uso de variáveis globais em módulos compilados separadamente.
int first, last; /* declaração global de first e last*/
void main(void) {
    extern int first; /*uso opcional da declaração extern*/
    // ...
}

/* Embora as declarações de variáveis *extern* possam ocorrer dentro do mesmo
arquivo da declaração global, elas não são necessárias. Se o compilador C en-
contra uma variável que não fopi declarada, ele verificase ela tem o mesmo 
nome de alguma variável global. Se tiver, o compilador assumirá que a variá-
vel global está sendo referenciada.*/

//Variáveis static
/* Dentro de sua própria função ou arquivo, variáveis *static* são variáveis
permanentes. Ao contrário das variáveis globais, elas não são reconhecidas 
fora de sua função ou arquivo, mas mantêm seus valores entre chamadas. Essa
característica torna-as uteís quando você escreve funções generalizadas e 
funções de bilbioteca que podem ser usadas por outros programadores. O espe-
cificador *static* tem efeitos diferewntes em variáveis locais e em variá-
veis globais.*/

// Variáveis locais static (pag. 45)