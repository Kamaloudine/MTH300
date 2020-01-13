#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "methode.h"
#include "traitement.h"



//FONCTION DE CALCUL
float CalculFonction(float x)
{

    float resultat;

    resultat = (x-1)*(x-1);

    return resultat;

}

double df(double x)
{
    double solution;

    solution = 2*(x - 1);

    return solution;
}

int ChoixTypeResolution()
{
    int choix;


    printf("\n\n\t\t\t++++++++MENU 1+++++++++++++++");
    printf("\n\n\t\t1-) Resolution des équations non linéaire");
    printf("\n\n\t\t2-) Resolution des équations non linéaire");

    printf("\n\nVeuillez choisir le type de resolution :");
    scanf("%d",&choix);

    return choix;
}

//FONCTION DU CHOIX DE METHODE
int ChoixMethode()
{

    int choix;

    printf("\n\n\t\t++++++++ SOUS MENU 1+++++++++++++++");

    printf("\n\n\t\t1-) Methode de Bissection");
    printf("\n\n\t\t2-) Methode de Lagrange");
    printf("\n\n\t\t3-) Methode de Newton");
    printf("\n\n\t\t4-) Methode de la Secante");
    printf("\n\n\t\t5-) Methode de la corde1");
    printf("\n\n\t\t6-) Methode de la corde2");
    printf("\n\n\t\t7-) Methode du point fixe");

    printf("\n\nVeuillez choisir methode de resolution :");
    scanf("%d",&choix);

    return choix;
}

//FONCTION DE CHOIX DU TYPE DE RESOLUTION
void TraitementChoixTypeResolution(float const eps,int nbre)
{
    int nbreMax;


    switch(nbre)
    {

    case 1 :
        printf("\n\nVeuillez saisir le nombre maximal d'iteration : ");
        scanf("%d",&nbreMax);
        Traitement(eps,nbreMax);
        break;
    case 2 :
        Traitement2();
        break;
    default :
        printf("Error de choix ");
    }
}


//FONCTION DE TRAITEMENT SUIVANT LE CHOIX DE METHODE
void Traitement(float eps, int nbreMax)
{
    int reponse;

    reponse = ChoixMethode();

    switch(reponse)
    {

    case 1 :
        Dichotomie(eps,nbreMax);
        break;
    case 2 :
        Lagrange(eps, nbreMax);
        break;
    case 3 :
        Newton(eps, nbreMax);
        break;
    case 4 :
        Secante(eps,nbreMax);
        break;
    case 5 :
        Corde1(eps,nbreMax);
        break;
    case 6 :
        Corde2(eps,nbreMax);
        break;
    default :
        printf("Erreur de choix ...");
    }

}



//FONCTION DE LA METHODE DE BISSECTION
void Dichotomie(float const eps, int nbreMax)
{
    float a,b;

    printf("\n\nSaisir la borne inferieur de l'intervalle : ");
    scanf("%f",&a);

    printf("\n\nSaisir la borne superieur de l'intervalle : ");
    scanf("%f",&b);

    traitementDichotomie(eps,nbreMax,a,b);
}


//FONCTION DE LA METHODE DE lAGRANGE
void Lagrange(float const eps, int nbreMax)
{
    float a,b;

    printf("\n\nSaisir la borne inferieur de l'intervalle : ");
    scanf("%f",&a);

    printf("\n\nSaisir la borne superieur de l'intervalle : ");
    scanf("%f",&b);

    traitementLagrange(eps,nbreMax,a,b);


}


//FONCTION DE LA METHODE DE NEWTON
void Newton(float const eps, int nbreMax)
{

    float x0;

    printf("\n\nSaisi la valeur initial x0 = ");
    scanf("%f",&x0);

    traitementNewton(eps,nbreMax,x0);

}


//FONCTION DE LA METHODE DE LA SECANTE
void Secante(float const eps, int nbreMax)
{
    float x0,x1;
    printf("\n\nSaisi la valeur initial x0 = ");
    scanf("%f",&x0);

    printf("\n\nSaisi la valeur initial x1 = ");
    scanf("%f",&x1);

    traitementSecante(eps,nbreMax,x0,x1);

}



//FONCTION DE LA METHODE DE LA CORDE
void Corde1(float const eps, int nbreMax)
{
    float a,b;

    printf("\n\nSaisir la borne inferieur de l'intervalle : ");
    scanf("%f",&a);

    printf("\n\nSaisir la borne superieur de l'intervalle : ");
    scanf("%f",&b);

    traitementCorde1(eps,nbreMax,a,b);

}

void Corde2(float const eps, int nbreMax)
{
    float x0;

    printf("\n\nSaisi la valeur initial x0 = ");
    scanf("%f",&x0);

    traitementCorde2(eps,nbreMax,x0);

}


void VerifieBorne(float a, float b)
{



    if(CalculFonction(b) == 0 && CalculFonction(a) == 0)
    {
        printf("\n\nOn a plusieurs  solutions sur l'intervalle ");
    }
    else
    {
        if(CalculFonction(a) == 0)
        {
            printf("la solution de l'equation est : %f",a);
            exit(0);

        }
        else if(CalculFonction(b) == 0)
        {
            printf("la solution de l'equation est : %f",b);
            exit(0);
        }
    }



}


void traitementDichotomie(float const eps, int nbreMax, float a, float b)
{


    float tampon;
    int compteur = 0;

    VerifieBorne(a,b);


    if( CalculFonction(a) != 0 && CalculFonction(b) != 0)
    {
        if(CalculFonction(a)*CalculFonction(b) < 0)
        {

            do
            {

                tampon = (a+b)/2;
                if(CalculFonction(a)*CalculFonction(tampon) < 0)
                {
                    b = tampon;
                }
                else if(CalculFonction(tampon)*CalculFonction(b) < 0)
                {
                    a = tampon;
                }
                else
                {
                    VerifieBorne(a,tampon);
                    VerifieBorne(tampon,b);
                }
                if( compteur > nbreMax)
                {
                    printf("la convergence n'est pas atteinte en %d  iterations \n\n",nbreMax);
                    exit(0);
                }
                else
                {
                    compteur++;
                }

            }
            while (fabs(b-a) < eps || compteur < nbreMax);
            printf("\n\nLa solution de l'equation est : %f",tampon);
        }
        else if(CalculFonction(a)*CalculFonction(b) > 0)
        {

            printf("\n\nPeut etre il y a une solution double");
            printf("\n\nCherchons une des solution \n\n");
            tampon = (a+b)/2;
            VerifieBorne(a,tampon);

        }

    }
    else
    {
        printf("\n\nNous avons une fonction position sur l'intervalle\n\n");
        exit(0);
    }





}


void traitementLagrange(float const eps, int nbreMax, int a, int b)
{

    float tampon;
    int compteur = 0;
    int i;

    VerifieBorne(a,b);

    if( CalculFonction(a) != 0 && CalculFonction(b) != 0)
    {
        if(CalculFonction(a)*CalculFonction(b) < 0)
        {

            do
            {

                tampon = a - (b-a)*CalculFonction(a)/(CalculFonction(b) - CalculFonction(a));
                if(CalculFonction(a)*CalculFonction(tampon) < 0)
                {
                    b = tampon;
                }
                else if(CalculFonction(tampon)*CalculFonction(b) < 0)
                {
                    a = tampon;
                }
                else
                {
                    VerifieBorne(a,tampon);
                    VerifieBorne(tampon,b);
                }
                if( compteur > nbreMax)
                {
                    printf("la convergence n'est pas atteinte en %d  iterations \n\n",nbreMax);
                    exit(0);
                }
                else
                {
                    compteur++;
                }

            }
            while (fabs(b-a) < eps || compteur < nbreMax);
            printf("\n\nLa solution de l'equation est : %f",tampon);
        }
        else if(CalculFonction(a)*CalculFonction(b) > 0)
        {
            i=0;
            while(i<10)
            {
                i++;
                printf("\n\nPeut etre il y a une solution double");
                printf("\n\nCherchons une des solution \n\n");
                if(i>10)
                {

                }
                tampon = (a+b)/2;
                VerifieBorne(a,tampon);
                traitementLagrange(eps,nbreMax,a,tampon);
            }

        }
        else
        {

        }

    }


}


void traitementNewton(float const eps, int nbreMax, int x0)
{

    float x[100];
    int i;

    x[0] = x0;

    for(i= 0; i< nbreMax; i++)
    {

        if(df(x[i]) == 0)
        {
            printf("\n\n+++Erreur : impossible de diviser par zero car df(x[i]) == 0");
            exit(0);
        }
        else
        {

            x[i+1] = x[i] - (CalculFonction(x[i])/df(x[i]));

            if(x[i+1]  == 0)
            {
                printf("\n\n+++Erreur : impossible de diviser par zero car x[i+1] vaut zero");
                exit(0);
            }
            else
            {
                if((fabs(x[i+1]- x[i])/fabs(x[i+1])) < eps)
                {

                    printf("La convergence est atteinte ");
                    printf("\nL'iteration N°%d solution est = %f\n\n",i,x[i+1]);
                    exit(0);
                }
                else if(i > nbreMax)
                {

                    printf("\n\nLa convergence n'est pas atteint a la %d ieme iterations ",nbreMax);
                    exit(0);
                }
                else
                {
                    printf("\n\nL'iteration N°%d  x = %f\n\n",i,x[i+1]);
                }
            }
        }

    }

}


void traitementSecante(float const eps, int nbreMax, int x0, int x1)
{

    float x[100];
    int i;

    x[0] = x0;
    x[1] = x1;

    for(i= 1; i< nbreMax; i++)
    {

        if((CalculFonction(x[i]) - CalculFonction(x[i-1])) == 0)
        {
            printf("\n\n+++Erreur : impossible de diviser par zero car (f(x[i] - f(x[i-1])) vaut zero\n");
            exit(0);
        }
        else
        {

            x[i+1] = x[i] - (CalculFonction(x[i])*(x[i] - x[i-1]))/(CalculFonction(x[i]) - CalculFonction(x[i-1]));
            if(x[i+1]  == 0)
            {
                printf("\n\n+++Erreur : impossible de diviser par zero x[i+1]  == 0\n");
            }
            else
            {
                if((fabs(x[i+1]- x[i])/fabs(x[i+1])) < eps)
                {

                    printf("La convergence est atteinte ");
                    printf("\nL'iteration N°%d solution est = %f\n\n",i,x[i+1]);
                    exit(0);
                }
                else if(i > nbreMax)
                {

                    printf("\n\nLa convergence n'est pas atteint a la %d ieme iterations ",nbreMax);
                    exit(0);
                }
                else
                {
                    printf("\n\nL'iteration N°%d  x = %f\n\n",i,x[i+1]);
                }
            }
        }

    }

}


void traitementCorde1(float const eps, int nbreMax, int a, int b)
{
    float tampon;
    int compteur = 0;


    float x = a;

    VerifieBorne(a,b);

    if( CalculFonction(a) != 0 && CalculFonction(b) != 0)
    {
        if(CalculFonction(a)*CalculFonction(b) < 0)
        {

            do
            {

                tampon = x - (b-a)*CalculFonction(x)/(CalculFonction(b) - CalculFonction(a));
                if(CalculFonction(a)*CalculFonction(tampon) < 0)
                {
                    b = tampon;
                }
                else if(CalculFonction(tampon)*CalculFonction(b) < 0)
                {
                    a = tampon;
                }
                else
                {
                    VerifieBorne(a,tampon);
                    VerifieBorne(tampon,b);
                }
                if( compteur > nbreMax)
                {
                    printf("la convergence n'est pas atteinte en %d  iterations \n\n",nbreMax);
                    exit(0);
                }
                else
                {
                    compteur++;
                }

            }
            while (fabs(b-a) < eps || compteur < nbreMax);
            printf("\n\nLa solution de l'equation est : %f",tampon);
        }
        else if(CalculFonction(a)*CalculFonction(b) > 0)
        {

            printf("\n\nPeut etre il y a une solution double");
            printf("\n\nCherchons une des solution \n\n");
            tampon = (a+b)/2;
            VerifieBorne(a,tampon);
            //traitementLagrange(eps,nbreMax,a,tampon);


        }
        else
        {

        }

    }



}



void traitementCorde2(float const eps, int nbreMax, int x0)
{

    float x[100];
    int i;

    x[0] = x0;

    for(i= 0; i< nbreMax; i++)
    {

        if(df(x0) == 0)
        {
            printf("\n\n+++Erreur : impossible de diviser par zero car df(x0) == 0");
            exit(0);
        }
        else
        {

            x[i+1] = x[i] - (CalculFonction(x[i])/df(x0));

            if(x[i+1]  == 0)
            {
                printf("\n\n+++Erreur : impossible de diviser par zero car x[i+1] vaut zero");
                exit(0);
            }
            else
            {
                if((fabs(x[i+1]- x[i])/fabs(x[i+1])) < eps)
                {

                    printf("La convergence est atteinte ");
                    printf("\nL'iteration N°%d solution est = %f\n\n",i,x[i+1]);
                    exit(0);
                }
                else if(i > nbreMax)
                {

                    printf("\n\nLa convergence n'est pas atteint a la %d ieme iterations ",nbreMax);
                    exit(0);
                }
                else
                {
                    printf("\n\nL'iteration N°%d  x = %f\n\n",i,x[i+1]);
                }
            }
        }

    }

}
