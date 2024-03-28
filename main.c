#include "etudiant.h"

int main(void)
{   
    int choix;
    int n = 0;
    char numero[10];
    Etudiant newEtudiant;

    do
    {
        printf("\nQue souhaitez vous faire \n\n");

        printf("\t0. Quitter le programme\n");
        printf("\t1. Enregistrer un etudiant\n");
        printf("\t2. Afficher les informations de tous les etudiants\n");
        printf("\t3. Afficher le nombre d'etudiant\n");
        printf("\t4. Rechercher un etudiant\n");
        printf("\t5. Modifier les informations d'un etudiant\n");
        printf("\t6. Effectuer la selection\n");
        printf("\t7. Afficher la liste des selectionnes\n");
        printf("Choix : ");
        scanf("%d",&choix); 

        switch(choix)
        {
            case 0 :
                printf("Sortie du programme... \n");
                break;
            case 1 :

                printf("Entrez le numero de l'etudiant : ");
                scanf("%s", newEtudiant.numero);
                printf("Entrez le nom de l'etudiant : ");
                scanf("%s", newEtudiant.nom);
                printf("Entrez son age : ");
                scanf("%d", &newEtudiant.age);
                printf("Quelle est sa serie ? \n");
                printf("\n\t1. Serie C \t2. Serie D\n\n");
                printf("Serie (Veuillez choisir 1 ou 2 ): ");
                scanf("%d", &choix);
                if(choix == 1)
                    newEtudiant.serie = 'C';
                else if(choix == 2)
                    newEtudiant.serie = 'D';
                else
                {
                    printf("Mausaise valeur \n");
                    break;
                }
                printf("Entrez la note de l'etudiant en Mathematique : ");
                scanf("%f", &newEtudiant.noteMath);
                printf("Entrez la note de l'etudiant en Informatique : ");
                scanf("%f", &newEtudiant.noteInfo);
                printf("Entrez la note de l'etudiant en Anglais : ");
                scanf("%f", &newEtudiant.noteAng);

                EnregistrerEtudiant(newEtudiant);
                break;

            case 2 : 
                AfficherEtudiant();
                break;

            case 3 : 
                AfficherNbEtudiant();
                break;

            case 4 : 
                printf("Entrer le numero de l'etudiant a rechercher : ");
                scanf("%s",numero);
                RechercheEtudiant(numero);
                break;

            case 5 : 
                printf("Entrer le numero de l'etudiant a modifier : ");
                scanf("%s",numero);
                ModfierEtudiant(numero);
                break;

            case 6 : 
                printf("\nCombien de personne souhaitez vous selectionner : ");
                scanf("%d", &choix);
                printf("En fonction de quel critere souhaitez vous effectuer la selection cette annee ?\n");
                printf("\n1. Les plus meritant en math \t2. Les plus meritant en Info \t3. Les plus meritant en Math et Info\n");
                printf("\t4. Les plus meritant en Math et Anglais; \t 5. Les plus meritant en math, info et anglais \n\n");
                printf("Votre choix : ");
                scanf("%d",&n);
                if((n!=1) && (n!=2) && (n!=3) && (n!=4) && (n!=5))
                {
                    printf("Mauvaise option");
                    return 0;
                }
                Selection(choix, n);
                break;
            
            case 7 : 
                AfficherSelectionne();
                break;

            default : 
                printf("Mauvaise valeur, veuillez choisir soit 1 soit 2, ou alors 0 pour sortir du programme\n");
                break;
        }
    }

    while(choix != 0);

    return 0;
}