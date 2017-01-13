#include <stdio.h>
#include <stdlib.h>
#define TAILLE 5

//Structure pour les coordonées x et y.
typedef struct Pos
{
    int x;
    int y;
}Pos;

//Déclaration des prototypes.
void Debut(Pos *ptPosition,int tabCarre[][TAILLE]);
void Forward(Pos *ptPosition,int tabCarre[][TAILLE],int nCase);
int Increase(int value);
int Decrease(int value);

//But: Créez un tableau a 2 dimensions don toute les ligne et collone on la meme somme.
//Entre: L'utilisateur lance le programme.
//Sotie: Le programme affiche le tableau.

int main()
{
    int tabCarre[TAILLE][TAILLE]; //Déclaration du tableau a 2 dimensions.
    int nEmplacement = TAILLE * TAILLE; //Initialisation d'un entier indiquant le nombre de case dans le tableau.
    int nCase; //Déclaration d'un entier qui servira a ecrire les bon chiffre dans le tabeau.
    Pos Position; //Déclaration d'une structure contenant les position x et y.

    Pos *ptPosition = &Position; //Déclaration d'un pointeur vers la position de x et y.

    Debut(ptPosition,tabCarre); //Procedure d'initialisation du tableau.

    for(nCase=2;nCase<=nEmplacement;nCase++) //Boucle permetant de remplir le tableau.
    {
        Forward(ptPosition,tabCarre,nCase); //Procedure remplissant le tableau.
    }

    for(Position.y=TAILLE-1;Position.y>=0;Position.y--) //Boucle permetant d'affiche les lignes du tableau.
    {
        for(Position.x=0;Position.x<=TAILLE-1;Position.x++) //Boucle permetant d'affiche les collones du tableau.
        {
            printf("%d \t",tabCarre[Position.x][Position.y]); //Affiche la case en fonction des position.
        }

        printf("\n"); //Remise a la ligne.
    }

    return 0;
}

//But: Initialise toute les cases du tableau a 0 et donne la position du 1 dans le tableau.
//Entre: La procédure a besoin du pointeur de position de x et y ainsi que du tableau.
//Sortie: Le tableau a toute ses cases intialiser a 0.
void Debut(Pos *ptPosition,int tabCarre[][TAILLE])
{

    for(ptPosition->x=0;ptPosition->x<=TAILLE-1;ptPosition->x++) //Boucle permetant d'initialiser toute les valeurs de x a 0.
    {
        for(ptPosition->y=0;ptPosition->y<=TAILLE-1;ptPosition->y++) //Boucle permettant d'initialiser toute les valeurs de y a 0.
        {
            tabCarre[ptPosition->x][ptPosition->y]=0; //Initialise a 0 la case.
        }
    }

    ptPosition->x = TAILLE / 2; //Initialise x a la collone du centre.
    ptPosition->y = TAILLE / 2 + 1; //Initialise y a la ligne au dessus du centre.
    tabCarre[ptPosition->x][ptPosition->y]=1; //Initialise a 1 la case au dessus du centre du tableau.
}

//But: Initialise la prochaine case du tableau selon la logique du carre magique.
//Entre: La procédure a besoin du pointeur de la position x et y, du tableau et du nombre qu'il devras mettre dans la case.
//Sortie: La case est initialiser a la bonne valeur et au bonne endroit.
void Forward(Pos *ptPosition,int tabCarre[][TAILLE],int nCase)
{
    int check=1; //Initialisation d'un entier de verification.
    ptPosition->x = Increase(ptPosition->x); //Utilise la fonction pour changer la position de la collone.
    ptPosition->y = Increase(ptPosition->y); //Utilise la fonction pour changer la position de la ligne.

    while(check) //Tant que aucunne case est initialise.
    {
        if(tabCarre[ptPosition->x][ptPosition->y] == 0) //Verification que la case sélectionner est égale a 0.
        {
            tabCarre[ptPosition->x][ptPosition->y] = nCase; //Initialise la case sélectionner au nombre passer.
            check=0; //Indique que une case a été remplis.
        }

        else //Sinon
        {
            ptPosition->x = Decrease(ptPosition->x); //Utilise la fonction pour changer la position de la collone.
            ptPosition->y = Increase(ptPosition->y); //Utilise la fonction pour changer la position de la ligne.
        }
    }
}

//But: Déplace de une case vers le haut ou vers la droite l'axe passer en argument et si le deplacement n'est pas possible le deplace a l'opposer de l'axe.
//Entre: Axe a déplacer.
//Sortie: Axe a une nouvelle position.
int Increase(int value)
{
    if(value == TAILLE-1) //Si la position de l'axe est égale a la taille max des collones ou des lignes.
        return 0; //L'initialise a 0.
    else
        return ++value; //Sinon augmente l'axe de 1.
}

//But: Déplace de une case vers la gauche et si le déplacement n'est pas possible le deplace a l'opposer de l'axe.
//Entre: Axe a déplacer.
//Sortie: Axe a une nouvelle position.
int Decrease(int value)
{
    if(value == 0) //Si la position de l'axe est égale a 0.
        return TAILLE-1; //L'initialise a la taille max du tableau.
    else
        return --value; //Sinon reduit l'axe de 1.
}
