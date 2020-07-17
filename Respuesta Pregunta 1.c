#include<stdio.h>
#include <omp.h>
#include <string.h>
int main()
{
    char mensaje[1000], letra;
    int i, llave;

    printf("Mensaje a encriptar: ");
    gets(mensaje);
    printf("Ingrese llave: ");
    scanf("%d", &llave);
    size_t len = strlen(mensaje);
    len = len-1;
    #pragma omp parallel
    {
        #pragma omp for private (i)
        for(i = 0; i<=len; ++i){
        letra = mensaje[i];

        if(letra >= 'a' && letra <= 'z'){
            letra = letra + llave;

            if(letra > 'z'){
                letra = letra - 'z' + 'a' - 1;
            }

            mensaje[i] = letra;
        }
        else if(letra >= 'A' && letra <= 'Z'){
            letra = letra + llave;

            if(letra > 'Z'){
                letra = letra - 'Z' + 'A' - 1;
            }

            mensaje[i] = letra;
        }
        else if(letra >= '0' && letra <= '9'){
            letra = letra + llave;

            if(letra > '9'){
                letra = letra - '9' + '1' - 1;
            }

            mensaje[i] = letra;
        }
    }
    }

    printf("El mensaje encriptado es: %s", mensaje);

    return 0;
}
