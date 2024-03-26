#include "etudiant.h"

void EnregistrerEtudiant(Etudiant etudiant)
{
    FILE *fichier;
    fichier = fopen("BD_Etudiants.txt", "a");

    fprintf(fichier, "%s;%s;%d;%c;%.2f;%.2f;%.2f\n",etudiant.numero, etudiant.nom, etudiant.age, etudiant.serie, etudiant.noteMath, etudiant.noteInfo, etudiant.noteAng);
    
    fclose(fichier);   
    printf("\n!!! Etudiant '%s' enregistre avec succes !!! \n", etudiant.numero);
    sleep(2);
}

void AfficherEtudiant()
{
    FILE *fichier;
    fichier = fopen("BD_Etudiants.txt", "r");
    Etudiant ListOfStudent[1000];
    int i = 0;


    if(fichier == NULL)
    {
        printf("Fichier inexistant\n");
        return;
    }
    printf("############ Liste des Etudiants ############\n\n");
    while(fscanf(fichier, "%[^;];%[^;];%d;%c;%f;%f;%f\n",ListOfStudent[i].numero, ListOfStudent[i].nom, &ListOfStudent[i].age, &ListOfStudent[i].serie, &ListOfStudent[i].noteMath, &ListOfStudent[i].noteInfo, &ListOfStudent[i].noteAng)==7)
    {
        printf("..................................\n");
        printf("NUMERO : %s\n", ListOfStudent[i].numero);
        printf("NOM : %s\n", ListOfStudent[i].nom);
        printf("AGE : %d\n", ListOfStudent[i].age);
        printf("SERIE : %c\n", ListOfStudent[i].serie);
        printf("NOTE DE MATHEMATIQUE : %.2f\n", ListOfStudent[i].noteMath);
        printf("NOTE DE INFORMATIQUE : %.2f\n", ListOfStudent[i].noteInfo);
        printf("NOTE DE ANGLAIS : %.2f\n", ListOfStudent[i].noteAng);

        i += 1;
    }

    fclose(fichier);
}

void AfficherNbEtudiant()
{
    FILE *fichier;
    Etudiant etudiant;
    int nombre = 0;
    fichier = fopen("BD_Etudiants.txt", "r");

    if (fichier == NULL)
    {
        printf("Fichier inexistant\n");
        return;
    }

    while(fscanf(fichier, "%[^;];%[^;];%d;%c;%f;%f;%f\n", etudiant.numero, etudiant.nom, &etudiant.age, &etudiant.serie, &etudiant.noteMath, &etudiant.noteInfo, &etudiant.noteAng) == 7)
    {
        nombre += 1;
    }

    fclose(fichier);

    printf("\nIL y'a au total %d etudiant(s) enregistre\n",nombre);

    sleep(2);

}

void RechercheEtudiant(char *numero)
{
    FILE *fichier;
    Etudiant etudiant;
    int trouve = 0;
    fichier = fopen("BD_Etudiants.txt", "r");

    if (fichier == NULL)
    {
        printf("Fichier inexistant\n");
        return;
    }

    while(fscanf(fichier, "%[^;];%[^;];%d;%c;%f;%f;%f\n", etudiant.numero, etudiant.nom, &etudiant.age, &etudiant.serie, &etudiant.noteMath, &etudiant.noteInfo, &etudiant.noteAng) == 7)
    {
        if (strcmp(etudiant.numero, numero) == 0)
        {
            trouve = 1;
            printf("..................................\n");
            printf("NUMERO : %s\n", etudiant.numero);
            printf("NOM : %s\n", etudiant.nom);
            printf("AGE : %d\n", etudiant.age);
            printf("SERIE : %c\n", etudiant.serie);
            printf("NOTE DE MATHEMATIQUE : %.2f\n", etudiant.noteMath);
            printf("NOTE DE INFORMATIQUE : %.2f\n", etudiant.noteInfo);
            printf("NOTE DE ANGLAIS : %.2f\n", etudiant.noteAng);
            printf("..................................\n");
            break;
        }
    }    

    if (trouve == 0)
        printf("\nAucun etudiant ayant le numero %s n'existe dans notre base de donnees\n",numero);

    fclose(fichier);

    sleep(2);
}

void ModfierEtudiant(char *numero)
{
    FILE *fichier;
    Etudiant ListOfStudent[1000] = {0};
    int i = 0, trouve = 0, choix;
    fichier = fopen("BD_Etudiants.txt", "r");

    if(fichier == NULL)
    {
        printf("Fichier inexistant\n");
        return;
    }

    while(fscanf(fichier, "%[^;];%[^;];%d;%c;%f;%f;%f\n",ListOfStudent[i].numero, ListOfStudent[i].nom, &ListOfStudent[i].age, &ListOfStudent[i].serie, &ListOfStudent[i].noteMath, &ListOfStudent[i].noteInfo, &ListOfStudent[i].noteAng)==7)
    {
        if(strcmp(ListOfStudent[i].numero, numero) == 0)
        {
            trouve = 1;
            printf("..................................\n");
            printf("NUMERO : %s\n", ListOfStudent[i].numero);
            printf("NOM : %s\n", ListOfStudent[i].nom);
            printf("AGE : %d\n", ListOfStudent[i].age);
            printf("SERIE : %c\n", ListOfStudent[i].serie);
            printf("NOTE DE MATHEMATIQUE : %.2f\n", ListOfStudent[i].noteMath);
            printf("NOTE DE INFORMATIQUE : %.2f\n", ListOfStudent[i].noteInfo);
            printf("NOTE DE ANGLAIS : %.2f\n", ListOfStudent[i].noteAng);
            printf("..................................\n");

            printf("\n\tQuelle information souhaitez vous modifier ? \n");
            printf("\t1. Numero \t2. Nom \t3. Age \t4. Serie \t5. Note de math \t6. Note d'info \t7. Note d'anglais\n");
            printf("Choix de modification : ");
            scanf("%d",&choix);

            switch(choix)
            {
                case 1 :
                    printf("Entrez le nouveau numero : ");
                    scanf("%s", ListOfStudent[i].numero);
                    break;

                case 2 :
                    printf("Entrez le nouveau nom : ");
                    scanf("%s", ListOfStudent[i].nom);
                    break;

                case 3 :
                    printf("Entrez le nouvel age : ");
                    scanf("%d",& ListOfStudent[i].age);
                    break;

                case 4 : 
                    printf("Entrez la nouvelle serie (1 pour la C et 2 pour la D) : ");
                    scanf("%d",&choix);
                    if(choix == 1)
                        ListOfStudent[i].serie = 'C';
                    else if(choix == 2)
                        ListOfStudent[i].serie = 'D';
                    else
                    {
                        printf("Mauvaise valeur\n");
                        return;
                    }

                    break;

                case 5 :
                    printf("Entrez la nouvelle note de Math : ");
                    scanf("%f", &ListOfStudent[i].noteMath);
                    break;

                case 6 : 
                    printf("Entrez la nouvelle note d'Info : ");
                    scanf("%f", &ListOfStudent[i].noteInfo);
                    break;

                case 7 :
                    printf("Entrez la nouvelle note d'Anglais : ");
                    scanf("%f", &ListOfStudent[i].noteAng);
                    break;

                default : 
                    printf("Mauvaise valeur\n");
                    break;
            }

        }


        i += 1;
    }

    fclose(fichier);

    if (trouve == 0)
    {
        printf("Aucun etudiant ayant le numero %s n'a ete trouve\n",numero);
    }
    else
    {
        fichier = fopen("BD_Etudiants.txt", "w");

        if(fichier == NULL)
        {
            printf("Fichier inexistant\n");
            return;
        }

        for(i=0; i<1000; i++)
        {
            if(ListOfStudent[i].age != 0)
            {     
                fprintf(fichier, "%s;%s;%d;%c;%.2f;%.2f;%.2f\n", ListOfStudent[i].numero, ListOfStudent[i].nom, ListOfStudent[i].age, ListOfStudent[i].serie, ListOfStudent[i].noteMath, ListOfStudent[i].noteInfo, ListOfStudent[i].noteAng);
            }
            else
                break;
        }

        fclose(fichier);
    }

    printf("\nModification effectue avec success ! \n");
    sleep(2);
}

void TriMath(Etudiant *listOfStudent)
{
    Etudiant tmp;

    for(int i = 0; i < 1000; i++)
    {
        if(strlen(listOfStudent[i].numero) == 0)
        {
            break;
        }

        if(listOfStudent[i].noteMath < listOfStudent[i+1].noteMath)
        {
            tmp = listOfStudent[i];
            listOfStudent[i] = listOfStudent[i+1];
            listOfStudent[i+1] = tmp;
        }
    }
}

void TriInfo(Etudiant *listOfStudent)
{
    Etudiant tmp;

    for(int i = 0; i < 1000; i++)
    {
        if(strlen(listOfStudent[i].numero) == 0)
        {
            break;
        }

        if(listOfStudent[i].noteInfo < listOfStudent[i+1].noteInfo)
        {
            tmp = listOfStudent[i];
            listOfStudent[i] = listOfStudent[i+1];
            listOfStudent[i+1] = tmp;
        }
    }
}

void TriMathAnglais(Etudiant *listOfStudent)
{
    Etudiant tmp;

    for(int i = 0; i < 1000; i++)
    {
        if(strlen(listOfStudent[i].numero) == 0)
        {
            break;
        }

        if((listOfStudent[i].noteAng + listOfStudent[i].noteMath) < (listOfStudent[i+1].noteAng + listOfStudent[i+1].noteMath))
        {
            tmp = listOfStudent[i];
            listOfStudent[i] = listOfStudent[i+1];
            listOfStudent[i+1] = tmp;
        }
    }
}

void TriMathInfo(Etudiant *listOfStudent)
{
    Etudiant tmp;

    for(int i = 0; i < 1000; i++)
    {
        if(strlen(listOfStudent[i].numero) == 0)
        {
            break;
        }

        if((listOfStudent[i].noteInfo + listOfStudent[i].noteMath) < (listOfStudent[i+1].noteInfo + listOfStudent[i+1].noteMath))
        {
            tmp = listOfStudent[i];
            listOfStudent[i] = listOfStudent[i+1];
            listOfStudent[i+1] = tmp;
        }
    }
}

void TriMax(Etudiant *listOfStudent)
{
    Etudiant tmp;

    for(int i = 0; i < 1000; i++)
    {
        if(strlen(listOfStudent[i].numero) == 0)
        {
            break;
        }

        if((listOfStudent[i].noteAng + listOfStudent[i].noteMath + listOfStudent[i].noteInfo) < (listOfStudent[i+1].noteAng + listOfStudent[i+1].noteMath + listOfStudent[i+1].noteInfo))
        {
            tmp = listOfStudent[i];
            listOfStudent[i] = listOfStudent[i+1];
            listOfStudent[i+1] = tmp;
        }
    }
}

void Selection(int nombre, int critere)
{
    FILE *fichier, *fichierSelectionnes;
    
    fichier = fopen("BD_Etudiants.txt", "r");
    fichierSelectionnes = fopen("BD_Etudiants_Selectionnes.txt", "w");

    Etudiant listOfStudent[1000];
    int i = 0;

    while(fscanf(fichier, "%[^;];%[^;];%d;%c;%f;%f;%f\n", listOfStudent[i].numero, listOfStudent[i].nom, &listOfStudent[i].age, &listOfStudent[i].serie, &listOfStudent[i].noteMath, &listOfStudent[i].noteInfo, &listOfStudent[i].noteAng) == 7)
    {
        i += 1;
    }

    switch(critere)
    {
        case 1 : TriMath(listOfStudent);break;
        case 2 : TriInfo(listOfStudent);break;
        case 3 : TriMathInfo(listOfStudent);break;
        case 4 : TriMathAnglais(listOfStudent);break;
        case 5 : TriMax(listOfStudent);break;
        default:
            break;
    }

    for( i = 0; i < nombre; i++)
    {
        fprintf(fichierSelectionnes, "%s;%s;%d;%c;%.2f;%.2f;%.2f\n",listOfStudent[i].numero, listOfStudent[i].nom, listOfStudent[i].age, listOfStudent[i].serie, listOfStudent[i].noteMath, listOfStudent[i].noteInfo, listOfStudent[i].noteAng);
    }

    
    fclose(fichier);
    fclose(fichierSelectionnes);
}

void AfficherSelectionne()
{
    FILE *fichier;
    fichier = fopen("BD_Etudiants_Selectionnes.txt", "r");
    Etudiant ListOfStudent[1000];
    int i = 0;


    if(fichier == NULL)
    {
        printf("Fichier inexistant\n");
        return;
    }
    printf("############ Liste Des Etudiants Selectionnes ############\n\n");
    while(fscanf(fichier, "%[^;];%[^;];%d;%c;%f;%f;%f\n",ListOfStudent[i].numero, ListOfStudent[i].nom, &ListOfStudent[i].age, &ListOfStudent[i].serie, &ListOfStudent[i].noteMath, &ListOfStudent[i].noteInfo, &ListOfStudent[i].noteAng)==7)
    {
        printf("..................................\n");
        printf("NUMERO : %s\n", ListOfStudent[i].numero);
        printf("NOM : %s\n", ListOfStudent[i].nom);
        printf("AGE : %d\n", ListOfStudent[i].age);
        printf("SERIE : %c\n", ListOfStudent[i].serie);
        printf("NOTE DE MATHEMATIQUE : %.2f\n", ListOfStudent[i].noteMath);
        printf("NOTE DE INFORMATIQUE : %.2f\n", ListOfStudent[i].noteInfo);
        printf("NOTE DE ANGLAIS : %.2f\n", ListOfStudent[i].noteAng);

        i += 1;
    }

    fclose(fichier);
}