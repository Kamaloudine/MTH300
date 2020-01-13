#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "methode.h"
#include "traitement.h"


int choixMethode2()
{

    int choix;
    /// choix de la methode

    printf("\n\n\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    printf("\n\n\t+++++++++++++++++++++ SOUS MENU 2 : CHOIX DE METHODE ++++++++++++++\n");

    printf("\n\n\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    printf("\n\t\t1- Méthode de Gauss sans pivot.\n");
    printf("\n\t\t2- Méthode de Gauss avec pivot partiel.\n");
    printf("\n\t\t3- Méthode de Gauss-jordan.\n");
    printf("\n\t\t4- Méthode de Doolittle.\n");
    printf("\n\t\t5- Méthode de Crout.\n");
    printf("\n\t\t6- Méthode de Cholesky.\n");

    printf("\n\tVeuillez choisir la methode resolution : ");
    scanf("%d",&choix);

    return choix;
}

int choixTypematrice()
{

    int choix;

    printf("\n\n\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    printf("\n\n\t+++++++++++++++++++++ SOUS MENU 2 : CHOIX TYPE DE MATRICE++++++++++\n");

    printf("\n\n\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    printf("\n\t\t1- Matrice Diagonale \n");
    printf("\n\t\t2- Matrice Triangle Superieur \n");
    printf("\n\t\t3- Matrice Triangle Inferieur \n");
    printf("\n\t\t4- Matrice Symetrique \n");
    printf("\n\t\t5- Matrice Quelconque \n");

    printf("\n\tVeuillez choisir le type de matrice : ");
    scanf("%d",&choix);

    return choix;
}


void Traitement2()
{

    int reponse;
    reponse = choixTypematrice();

    switch(reponse)
    {
    case 1 :
        traitementmatricediagonale();
        break;
    case 2 :
        traitementmatricetrianglesup();
        break;
    case 3 :
        traitementmatricetriangleinf();
        break;
    case 4 :
        traitementmatricesymetrique();
        break;
    case 5 :
        traitementmatricequelconque();
        break;
    default :
        printf("");

    }

}

void traitementmatricediagonale()
{
    float a[100][100], b[100], x[100];
    int i, ligne;

    ligne = saisirLigne();

    saisirmatricediagonale(a,b,ligne);

    for(i = 0; i < ligne; i++)
    {
        if(a[i][i] != 0)
        {
            x[i] = b[i]/a[i][i];
        }
        else
        {
            printf("\nErreur de diviser car le pivot est null a la position <%d,%d>",i,i);
            exit(0);
        }
    }

    afficheSolution(x,ligne);

}

void traitementmatricetrianglesup()
{
    float a[100][100], b[100], x[100];
    int compteur, ligne;

    ligne = saisirLigne();

    saisirmatricetrianglesup(a,b,ligne);
}

void traitementmatricetriangleinf()
{
    float a[100][100], b[100], x[100];
    int compteur, ligne;

    ligne = saisirLigne();

    saisirmatricetriangleinf(a,b,ligne);

}

void traitementmatricesymetrique()
{
    float a[100][100], b[100], x[100];
    int compteur, ligne;

    ligne = saisirLigne();

    saisirmatricesymetrique(a,b,ligne);

}

void traitementmatricequelconque()
{
    float a[100][100], b[100], x[100];
    int compteur, ligne;
    int reponse;

    ligne = saisirLigne();

    saisirmatricequelconque(a,b,ligne);

    //reponse = choixMethode2();

    switch(reponse)
    {
    case 1 :
        printf("");
        break;
    case 2 :
        printf("");
        break;
    case 3 :
        printf("");
        break;
    case 4 :
        printf("");
        break;
    case 5 :
        printf("");
        break;
    default :
        printf("");
    }

}

void saisirmatricediagonale(float a[100][100], float b[100], int n)
{

    int i,j;

    printf("\n\n\tVeuillez saisir le s elements de la diagonale : \n");
    for(i = 0; i < n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i == j)
            {
                printf("A<%d,%d> : ",i+1,j+1);
                scanf("%f",&a[i][j]);
            }
            else
            {
                a[i][j] = 0;
            }
        }
    }

    saisirmatriceSecond(b,n);
    affichematrice(a,n);

}

void saisirmatricetriangleinf(float a[100][100], float b[100], int n)
{

    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i<j)
            {
                printf("A<%d,%d> : ",i+1,j+1);
                a[i][j] = 0;
            }
            else
            {
                scanf("%f",&a[i][j]);
            }
        }
    }
    saisirmatriceSecond(b,n);
    affichematrice(a,n);
}

void saisirmatricetrianglesup(float a[100][100], float b[100], int n)
{

    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i>j)
            {
                printf("A<%d,%d> : ",i=1,j+1);
                a[i][j] = 0;
            }
            else
            {
                scanf("%f",&a[i][j]);
            }
        }
    }
    saisirmatriceSecond(b,n);
    affichematrice(a,n);
}

void saisirmatricesymetrique(float a[100][100], float b[100], int n)
{

    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i>j)
            {
                printf("A<%d,%d> : ",i+1,j+1);
                a[i][j] = 0;
            }
            else
            {
                scanf("%f",&a[i][j]);
            }
        }
    }
    saisirmatriceSecond(b,n);
    affichematrice(a,n);
}

void saisirmatricequelconque(float a[100][100], float b[100], int n)
{

    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("A<%d,%d> : ",i+1,j+1);
            scanf("%f",&a[i][j]);
        }
    }
    saisirmatriceSecond(b,n);
    affichematrice(a,n);

    fusionmatrice(a,b,n);
    affichematricefusion(a,n);

}

int saisirLigne()
{

    int nbre;

    printf("\n\n\tVeuillez saisir la dimension de la matirce : ");
    scanf("%d",&nbre);
    return nbre;
}

void saisirmatriceSecond(float b[100], int n)
{

    int i;

    printf("\n\n\tVeuillez saisir les elements de la matrice : \n");
    for(i = 0; i < n; i++)
    {
        printf("B<%d> : ",i+1);
        scanf("%f",&b[i]);
    }


}


void afficheSolution(float x[100], int n)
{
    int i;

    printf("\n\n\tVoici la solution de votre systeme\n");
    for(i = 0; i < n; i++)
    {
        printf("\nx%d : %.2f",i,x[i]);
        printf("\n");
    }

}

void affichematrice(float a[100][100], int n)
{

    int i,j;
    printf("\n\nVoici la matrice saisi : \n");
    for(i=0; i<n; i++)
    {
        printf("\n");
        for(j=0; j<n; j++)
        {
            printf("\t");
            printf("%.2f",a[i][j]);
        }
    }
}



void fusionmatrice(float a[100][100], float b[100], int n)
{

    int i,j;

    for(i = 0; i<n; i++)
    {
        for(j = n; j<n+1; j++)
        {
            a[i][j] = b[i];
        }
    }

}


void affichematricefusion(float a[100][100], int n)
{

    int i,j;
    printf("\n\nVoici la matrice fusionner : \n");
    for(i=0; i<n; i++)
    {
        printf("\n");
        for(j=0; j<n+1; j++)
        {
            printf("\t");
            printf("%.2f",a[i][j]);
        }
    }

}
