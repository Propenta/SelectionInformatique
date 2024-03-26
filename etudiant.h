#ifndef __ETUDIANT_H__
#define __ETUDIANT_H__

    /*  Appel de bibliotheques  */
    #include <stdio.h>
    #include <string.h>
    #include <unistd.h>

    /*  Definition de la structure d'un Etudiant    */
    typedef struct{
        char numero[10];
        char nom[50];
        int age;
        char serie;
        float noteMath;
        float noteInfo;
        float noteAng;

    }Etudiant;

    /*  Definition des prototypes */

    void EnregistrerEtudiant(Etudiant etudiant); // Fonction pour enregistrer un etudiant
    void AfficherEtudiant(); // Fonction pour afficher la liste des etudiants
    void AfficherNbEtudiant(); // Fonction permettant d'afficher le nombre d'étudiant
    void RechercheEtudiant(char *numero); // Fonction permettant de rechercher un etudiant
    void ModfierEtudiant(char *numero); // Fonction permettant de modifier les informations d'un etudiant
    void TriMath(Etudiant *listOfStudents); // Fonction permettant de Trier les etudiants par ordre decroissant de note de math
    void TriInfo(Etudiant *listOfStudents); // Fonction permettant de Trier les etudiants par ordre decroissant de note d'info
    void TriMathAnglais(Etudiant *listOfStudents); // Fonction permettant de Trier les etudiants par ordre decroissant de note d'anglais et de math
    void TriMathInfo(Etudiant *listOfStudents); // Fonction permettant de Trier les etudiants par ordre decroissant de note d'info et de math
    void TriMax(Etudiant *listOfStudents); // Fonction permettant de Trier les etudiants par ordre decroissant de note totale
    void Selection(int nombre, int critere); // Fonction permettant d'effectuer la selection
    void AfficherSelectionne(); // Fonction pour afficher la liste des etudiants ayant ete selectionne

    

#endif