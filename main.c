#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


#include "methode.h"
#include "traitement.h"

int main()
{

    setlocale(LC_CTYPE,"");
    float const epsilon = pow(10,-8);
    int result;

    printf("\n\n\t\tBienvenue dans le programme de résolution des équations\n\n");
    result = ChoixTypeResolution();

    TraitementChoixTypeResolution(epsilon,result);

    return 0;
}
