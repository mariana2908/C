/* Se uma função usa argumentos, ela deve declarar variáveis que receberão os
valores dos argumentos. Essas variáveis são denominadas [parâmetros formais] da 
função. Elas se comportam como qualquer outra variável local dentro da função.
Como é mnostrado no fragmento de programa seguinte, suas declarações ocorrem 
depois do nome da função e dentro dos parênteses: */
// Retorna 1 se c é parte da string s; 0 se não é o caso
is_in (char *s, char c) {
    while (*s)
        if (*s == c) return 1;
        else s++;

    return 0;
}