/*
    Exercicio da video-aula

    by Brenno Cavalcanti 2021
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    double *p, *q, *r, a[5];                                    //variáveis ponteiros e vetor
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 6;
    p = a;
    q = p + 1;                                                  //q recebe p (endereço de "a") + 8 bytes
    r = q + 2;                                                  //r recebe q + 16 bytes

    printf("&a[0] = %lu; *r = %lf;\n", &a[0], *r);
    printf("p = %lu; *(a + 1) = %lf;\n", p, *(a + 1));

    r = p + 4;                                                  //r recebe p + 32 bytes
    p = q;

    printf ("p + 1 = %lu; *(r - 2) = %lf;\n", q, *(r - 2));
    printf ("&a[4] = %lu; *r = %lf;\n", &a[4], *r);

    return 0;
}
