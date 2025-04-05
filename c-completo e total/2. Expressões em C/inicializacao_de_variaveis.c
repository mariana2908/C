// Inicialização de Variáveis (pág. 49)
/* Você pode dar à maioria das variáveis em C um valor, no mesmo momento em que 
elas são declaradas, colocando um sinal de igual e uma constante após o nome da 
variável. A forma geral de uma inicialização é */
    // _tipo nome_da_variavel = constante;_
    // Alguns exemplos são
char ch = 'a';
int first = 0;
float balance = 123.23;
/* Variáveis globais e variáveis locais *static* são inicializadas apenas no co-
meço do programa. Variáveis locais (incluindo variáveis locais *static*) são ini-
cializadas cada vez que o bloco no qual estão declaradas for inserido. Variáveis
locais e *register* que não são inicializadas possuem valores desconhecidos antes
de ser efetuada a primeira atribuição a elas. Variáveis globais não inicializadas
e variáveis locais estáticaqs são inicializadas com zero.*/