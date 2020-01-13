#ifndef TRAITEMENT_H_INCLUDED
#define TRAITEMENT_H_INCLUDED

int ChoixTypeResolution();


int ChoixMethode();


void TraitementChoixTypeResolution(float const eps,int nbre);


//TRAITEMENT DES METHODES DE RESOLUTION DES EQUATIONS NON LINEAIRES


void Traitement(float const eps, int nbreMax);


void traitementDichotomie(float const eps, int nbreMax, float a, float b);


void traitementLagrange(float const eps, int nbreMax, int a, int b);


void traitementNewton(float const eps, int nbreMax, int x0);


void traitementSecante(float const eps, int nbreMax, int x0, int x1);


void traitementCorde1(float const eps, int nbreMax, int a, int b);


void traitementCorde2(float const eps, int nbreMax, int x0);


void VerifieBorne(float a, float b);


//TRAITEMENT DES METHODES DE RESOLUTION DES SYSTEMES D'EQUATIONS LINEAIRES

int choixMethode2();

int choixTypematrice();

void Traitement2();

void traitementmatricediagonale();

void saisirmatricediagonale(float a[100][100], float b[100], int);

void traitementmatricetrianglesup();

void saisirmatricetrianglesup(float a[100][100], float b[100], int);

void traitementmatricetriangleinf();

void saisirmatricetriangleinf(float a[100][100], float b[100], int);

void traitementmatricesymetrique();

void saisirmatricesymetrique(float a[100][100], float b[100], int);

void traitementmatricequelconque();

void saisirmatricequelconque(float a[100][100], float b[100], int);

int saisirLigne();

void saisirmatriceSecond(float b[100], int n);

void afficheSolution(float x[100], int n);

void affichematrice(float a[100][100],int n);

void fusionmatrice(float a[100][100], float b[100], int n);

void affichematricefusion(float a[100][100], int n);

#endif // TRAITEMENT_H_INCLUDED
