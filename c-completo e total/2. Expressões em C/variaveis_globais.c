/* Ao contrário das variáveis locais, as [variáveis globais] são reconhecidas pelo
programa inteiro podem ser usadas por qualquer pedaço de código. Além disso, elas
guardam seus valores durante toda execução do programa. Você cria variáveis globais
declarando-as fora de qualquer função. Elas podem ser acessadas por qualquer expres-
são independentemente de qual bloco de código contém a expressão.
   No programa seguinte, a variável *count* foi declarada fora de todas as funções.
Embora sua declaração ocorra antes da função *main()*, ela poderia ter sido colocada
em qualquer lugar anterior ao seu primeiro uso, desde que não estivesse em uma fun-
ção. No entanto, é melhor declarar variáveis globais no início do programa.*/

#include <stdio.h>
int count; // count é global

void func1(void);
void func2(void);

void main(void) {
   count = 100;
   func1();
}

void func1(void) {
   int temp;
   temp = count;
   func2();
   printf("count é %d", count); // imprimirá 100
}

void func2(void) {
   int count;
   for (count=1; count<10; count++)
      putchar('.');
}

/* Olhe atentamente para esse programa. Observe que, apesar de nem *main()* nem 
*func()* terem declarado a variável *count*, ambas podem usá-la. A função *func2()*,
porém, declarou uma variável local chamada *count*. Quando *func2()* referencia
*count*, ela referencia apenas sua variável local, não a variável global. Se uma 
variável global e uma variável local possuem o mesmo nome, todas as referências 
ao nome da variável dentro do bloco onde a variável local foi declarada dizem 
respeito à variável local e não têm efeito algum sobre a variável global. Pode ser 
conveniente, mas esquecer-se disso poderá fazer com que seu programa seja exe-
cutado estranhamente, embora pareça correto.
   O armazenamento de variáveis globais encontra-se em uma região fixa da memória,
separada para esse propósito pelo comppilador C. Variáveis globais são úteis quan-
do o mesmo dado é usado em muitas funções em seu programa. No entanto, você deve
evitar usar variáveis globais desneccessárias. Elas ocupam memória durante todo o
tempo em que seu programa está executando, naõ apenas quando são necessárias. Além
disso, usar uma variável global onde uma variável local poderia ser usada torna uma 
função menos geral, porque ela conta com alguma coisa que deve ser definida fora de-
la. Finalmente, usar um grande números de variáveis globais pode levar a erros no 
programa por causa de desconhecidos - e indesejáveis - efeitos colaterais. Isso 
pode ser evidenciado no BASIC padrão, em que todas as variáveis dão globais. Um 
problema maior no desenvolvimento de grandes projetos é a mudança acidental do 
valor de uma variável porque ela é usada em algum outro lugar do programa. Isso 
pode acontecer em C se você usar variáveis globais demais em seus programas.
   Uma das principais razões para uma linguagem estruturada é a compartimentaliza-
ção ou separação de código e dados. Em C, esse isolamento é conseguido pelo uso 
de variáveis locais e funç~eos. Por exemplo, a Figura 2.1 mostra duas maneiras de 
escrever *mul()* - uma função simples que calcula o produto de dois inteiros.
   Ambas as funções retorna, o produto das variáveis *x* e *y*. Contudo, a versão
generalizada, ou parametrizada, pode usada para retorna o produto de quaisquer 
dois inteiros, enquanto a versão específica só pode ser usada para encontrar o 
produto das variáveis globais *x* e *y*.*/

// Geral
mul(int x, int y) {
   return (x*y);
}

// Específica
int x, y;
mul(void) {
   return (x*y);
}