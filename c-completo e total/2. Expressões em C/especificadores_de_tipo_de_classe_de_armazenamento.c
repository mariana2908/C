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
/* Quando o modificador *static* é aplicado a uma variável local, o compilador
cria armazenamento permanente para ela quase da mesma forma como cria armaze-
namento para uma variável global. A diferença fundamental entre uma variável 
local *static* e uma variável global é que a variável local *static* é reco-
nhecida apenas no block em que está declarada. Em termos simples, uma variá-
vel local *static* é uma variável local que retém seu valor entre chamadas 
de função.
   Variáveis locais *static* são muito importantes na criação de funções iso-
ladas, porque diversos tipos de rotinas devem preservar um valor entre as 
chamadas. Se variáveis *static* não fossem permitidas, variáveis globais ter-
riam de ser usadas, abrindo brechas para possíveis efeitos colaterais. Um 
exemplo de função que requer uma variável local *static* é um gerador de sé-
rie de números que produz um novo número baseado no anterior. Seria possível
declarar uma variável global para reter esse valor. Porém, cada vez que a 
função é usada, você deve lembrar-se de declarar essa variável global já de-
clarada. Além disso, usar uma variável global tornaria essa função difícil 
de ser colocada em uma biblioteca de funções. A melhor solução é declarar 
a variável retém o número gerado como *static*, como neste fragmento de 
programa.*/

series(void) {
    static int series_num;

    series_num = series_num+23;
    return (series_num);
}

/* Nesse exemplo, a variável *series_num* pesmanece existindo entre as chama-
das da função em vez da criação e exclusaõ que aqs variáveis locais normais 
fariam. Isso significa que cada chamada a series() pode produzir um novo 
membroda série, baseado no número precedente, sem declarar essa variável 
globalmente.
   Você pode dar à variável local *static* um valor de inicialização. Esse 
valor é atribuído apenas uma vez - e não toda vez que o bloco de código é 
inserido, de forma análoga às variáveis locais normais. Por exemplo, essa 
versão de series() inicializa series_num() com 100:*/

series (void) {
    static int series_num = 100;
    series_num = series_num+23;
    return series_num;
}

/*Da forma como a função se acha agora, a série sempre começa com o valor 123.
Enquanto isso é aceitável para algumas aplicações, a maioria dos geradores de
séries permite ao usuário especificar o ponto inicial. Uma maneira de dar a 
*series_num* um valor especificado pelo usuário é tornar *series_num* uma va-
riável global e, em seguida, ajustar seu valor de acordo com o especificado.
Porém, *series_num* foi feita *static* justamente para não ser definida como 
global. Isso leva ao segundo uso de *static*.*/

// Variáveis Globais static (pag. 46)
/* Alicar o especificador *static* a uma variável global informa ao compila-
dor para criar uma variável global que é reconhecida apenas no arquivo no 
qual a mesma foi declarada. Isso significa que, muito embora a variável seja 
global, rotinas em outros arquivos não podem reconhecê-la ou alterar seu con-
teúdo diretamente; assim, não está sujeita a efeitos colaterais. Entretanto, 
para as poucas situações onde uma variável local *static* não possa fazer o 
trabalho, você criar um pequeno arquivo que contenha apenas as funções que 
precisam da variável global *static* e compilaar separadamente esse arquivo 
sem medo de efeitos colaterais.
   Para ilustrar uma variável global *static*, o exemplo de gerador de série
da seçaõ anterior foi recodificado de forma que um valor somente inicialize 
a série por meio de uma chamada a uma segunda função denominada *series_-
-start()*. O arquivo inteiro, que contém *series()*, *series_start()* e 
*series_num* é mostrado aqui:*/
// Isso deve estar em um único arquivo - preferencialmente isolado.
static int series_num;
void series_start(int seed);
int series(void);
series (void) {
    series_num = series_num+23;
    return series_num;
}

// Inicializa series_num
void series_start(int seed) {
    series_num = seed;
}

/* Para inicializar o gerador de série, deve-se chamar *series_start()* 
com algum valor inteiro conhecido. Depois disso, chamadas a *series()* 
geram os pr´´oximos elementos da série.
   _Revisando_: Os nomes das variáveis locais *static* são reconhecidos apenas
na função ou bloco de código em que elas são declaradas. Os nomes das variá-
veisglobais *static* são reconhecidos apenas no arquivo em que elas residem. 
Isso significa que, se vocêcolocar as funções *series()* e *series_start()* em
uma biblioteca, poderá usar as funções, mas não poderá referenciar a variável
*series_num*, que está escodida do resto do código de seu programa. De fato, 
você pode, inclusive, declarar e usar outra variável chamada *series_num* em 
seuprograma (em outro arquivo, é claro). Em essência, o modificador *static*
permite variáveis que são reconhecidaas pelas funções que precisam delas, sem 
confundir outras funções.
   As variáveis *static* admitem que você, o programador, esconda porções de 
seu programa das outras partes. Isso pode ser uma vantagem imensa quando se 
tenta gerenciar um programa muito grande e complexo. O especificador de clas-
se de armazenamento *static* deixa você criar funções gerais que podem ir pa-
ra bibliotecas que serão utilizadas posteriormente.*/

// Variáveis register (pág. 47)
/* O especificador de armazenamento *register* tradicionalmente era aplicado 
apenas a variáveis dod tipos *int* e *char*. Contudo, o padrão C ANSI ampliou
sua definição de forma que ele possa ser aplicado a qualquer variável.
   Originalmente, o especificador *register* solicitava ao compilador C que 
armazenasse o valor das variáveis declaradas com esse especificador num regis-
trador da CPU em vez da memória, onde as variáveis normais são armazenadas. Is-
so significa que operações com variáveis *register* poderiam ocorrer muito mais 
rapidamente que nas variáveis armazenadas na memória, pois o valor dessas va-
riáveis era realmente conservado na CPU e não era necessário acesso à memória 
para determinar ou modificar seus valores.
   Hoje, uma vez que agora o padrão C ANSI permite que você modifique qualquer 
tipo de variável com *register*, ele alterou a definição do que *register* faz.
O padrão C ANSI simplismente determina que "o acesso ao objeto é o mais rápido
possível". Na prática, caracteres e inteiros são colocados nos registradores
da CPU. Objetos maiores, como matrizes, obviamente não podem ser armazenados 
em um registrador, mas eles ainda podem receber um tratamento diferenciado.
Dependendo da implementação do compilador C e de seu ambiente operacional, va-
riáveis *register* podem ser manipuladas de quaisquer formas consideradas cabí-
veis pelo implementador do compilador. O padrão C ANSI também permite que o 
compilador ignore o especificador *register* e trate as variáveis modificadas 
por ele como se não fossem, mas isso raramente ocorre na prática.
   Você só pode aplicar o especificador *register* a variáveis locais e a parâ-
metros formais em uma função. Assim, variáveis globais *register* naõ são permi-
mitidas. Aqui está um exemplo de como declarar uma variável *register* do tipo
*int* e usá-la para controlar um laço. Essa função calcula o resultado de M^e 
para inteiros:*/

int_pwr(register int m, register int e) {
    register int temp;
    
    temp = 1;

    for(; e; e--) temp = temp * m;
    return temp;
}

/* Nesse exemplo, tanto *e* quanto *m* e *temp* são declaradas como variáveis
*register* porque são usadas dentro do laço. O fato de variáveis *register* se-
rem otimizadas para velocidade torna-as ideais ao controle de laço. Geralmente, 
variáveis *register* são usadas quando mais apropriadas, isto é, em lugares on-
de são feitas muitas referências a uma variável. Isso é importante porque você 
pode declarar qualquer número de variáveis como sendo do tipo *register*, mas 
nem todas recebem a mesma otimização de velocidade.
*/ 
