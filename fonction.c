//
// Created on 20/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"


extern liste_emp LE;
extern TPEmploye employe;
extern int num,nombre_emp,mat_,telephone_,dat1,dat2;
extern char service;
extern int pos,jour;
extern char Nom[20];
/**************************************************************************************/
struct date{//structure date
    int j;
    int m;
    int a;
};

struct employe{//structure employe
    int mat;
    char nom[20];
    char prenom[20] ;
    char adresse[50];
    struct date DE; //date d'embauche
    int telephone ;
    char service;
    float salairebrut;
    struct employe *suiv;
};
typedef struct employe * liste_emp;

typedef struct TPEmploye{
    float salaire;
    float revenu_annuel;
    float deductions;
    float salaire_brut;
    float montantCNSS;
} TPEmploye;

/**************************************************************************************/

//Fonction creation permettant de remplir la liste par des employes 
liste_emp  CREATION(liste_emp LE){
        liste_emp nouveau_emp = (liste_emp)malloc(sizeof(liste_emp));
        printf("Donnez le matricule de l employe: ");
        scanf("%d", &nouveau_emp->mat);
        printf("Donnez le nom de l employe: ");
        scanf("%s", nouveau_emp->nom);
        printf("Donnez le prenom de l employe: ");
        scanf("%s", nouveau_emp->prenom);
        printf("Donnez l adresse: ");
        scanf("%s", nouveau_emp->adresse);
        printf("Donnez la date d embauche de l employe (jj/mm/aaaa):\n ");
        scanf("%d  %d  %d", &nouveau_emp->DE.j, &nouveau_emp->DE.m, &nouveau_emp->DE.a);
        printf("Donnez le numero de telephone de l employe: ");
        scanf("%d", &nouveau_emp->telephone);
        printf("Donnez le service de l employe: ");
        scanf(" %c", &nouveau_emp->service);
        printf("Donnez le salaire brut de l employe: ");
        scanf("%f",&nouveau_emp->salairebrut);
        nouveau_emp->suiv = LE;
        LE = nouveau_emp;
        nouveau_emp = nouveau_emp->suiv;
        
       return nouveau_emp;
      
}


/**************************************************************************************/

//Fonction taille_liste_emp permettant de connaître la longueur de la liste
int taille_liste_emp (liste_emp LE) {
    int taille = 0;
    liste_emp liste_courante = LE;
    while (liste_courante != NULL) {
        liste_courante = liste_courante->suiv;
        taille+=1;
    }
  return taille;
}


/**************************************************************************************/

//Fonction permettant de rechercher un employe sur la liste
liste_emp recherche_emp(liste_emp LE, int num) {
    liste_emp liste_courante = LE;
    while (liste_courante != NULL) {
        if (liste_courante->mat == num) return liste_courante;
        liste_courante = liste_courante->suiv;
    }
    return NULL;
}


/**************************************************************************************/

//Fonction permettant d 'ajouter un employe en tête de liste
void insere_tete_emp(liste_emp LE) {
    liste_emp nouveau_emp = (liste_emp)malloc(sizeof(struct employe));
    printf("Entrez le matricule de l employe: ");
    scanf("%d", &nouveau_emp->mat);
    printf("Entrez le nom de l employe: ");
    scanf("%s", nouveau_emp->nom);
    printf("Entrez le prenom de l employe: ");
    scanf("%s", nouveau_emp->prenom);
    printf("Entrez l adresse de l employe: ");
    scanf("%s", nouveau_emp->adresse);
    printf("Entrez la date d embauche de l employe (jj/mm/aaaa): ");
    scanf("%d %d %d", &nouveau_emp->DE.j, &nouveau_emp->DE.m, &nouveau_emp->DE.a);
    printf("Entrez le numero de telephone de l employe: ");
    scanf("%d", &nouveau_emp->telephone);
    printf("Entrez le service de l employe: ");
    scanf(" %c", &nouveau_emp->service);
    printf("Entrez le salaire brut de l employe: ");
    scanf("%f", &nouveau_emp->salairebrut);

    nouveau_emp->suiv = LE;
    LE = nouveau_emp;
    
}


/**************************************************************************************/

//Fonction permettant d 'ajouter un employe en fin de liste
void insere_queue_emp(liste_emp LE) {
    liste_emp nouveau_emp = (liste_emp) malloc(sizeof(struct employe));
    printf("Entrez le matricule de l employe: ");
    scanf("%d", &nouveau_emp->mat);
    printf("Entrez le nom de l employe: ");
    scanf("%s", nouveau_emp->nom);
    printf("Entrez le prenom de l'employe: ");
    scanf("%s", nouveau_emp->prenom);
    printf("Entrez l adresse de l employe: ");
    scanf("%s", nouveau_emp->adresse);
    printf("Entrez la date d embauche de l employe (jj/mm/aaaa): ");
    scanf("%d %d %d", &nouveau_emp->DE.j, &nouveau_emp->DE.m, &nouveau_emp->DE.a);
    printf("Entrez le numero de telephone de l employe: ");
    scanf("%d", &nouveau_emp->telephone);
    printf("Entrez le service de l employe: ");
    scanf(" %c", &nouveau_emp->service);
    printf("Entrez le salaire brut de l employe: ");
    scanf("%f", &nouveau_emp->salairebrut);


    nouveau_emp->suiv = NULL;
    liste_emp liste_courante = LE;
    if (LE == NULL) {
        LE = nouveau_emp;
    } else {
        while (liste_courante->suiv != NULL) {
            liste_courante = liste_courante->suiv;
        }
        liste_courante->suiv = nouveau_emp;
    }
}


/**************************************************************************************/

//Fonction permettant d 'ajouter un employe dans une position donnée de la liste
void insere_pos_emp(liste_emp LE) {
    liste_emp nouveau_emp = (liste_emp) malloc(sizeof(struct employe));
    printf("Entrez le matricule de l employe: ");
    scanf("%d", &nouveau_emp->mat);
    printf("Entrez le nom de l employe: ");
    scanf("%s", nouveau_emp->nom);
    printf("Entrez le prenom de l employe: ");
    scanf("%s", nouveau_emp->prenom);
    printf("Entrez l adresse de l employe: ");
    scanf("%s", nouveau_emp->adresse);
    printf("Entrez la date d embauche de l employe (jj/mm/aaaa): ");
    scanf("%d %d %d", &nouveau_emp->DE.j, &nouveau_emp->DE.m, &nouveau_emp->DE.a);
    printf("Entrez le numero de telephone de l employe: ");
    scanf("%d", &nouveau_emp->telephone);
    printf("Entrez le service de l employe: ");
    scanf(" %c", &nouveau_emp->service);
    printf("Entrez le salaire brut de l'employe: ");
    scanf("%f", &nouveau_emp->salairebrut);

    int position;
    printf("Entrez la position à inserer: ");
    scanf("%d", &position);

    liste_emp liste_courante = LE;
    liste_emp liste_precedente = NULL;
    int i = 1;
    if (position < 1) {
        printf("Position invalide.\n");
        free(nouveau_emp);
    }
    else {
        while (liste_courante != NULL && i < position) {
            liste_precedente = liste_courante;
            liste_courante = liste_courante->suiv;
            i++;
        }
        if (i == position) {
            printf("Employe insere a la position %d\n", position);
            if (liste_precedente == NULL) {
                nouveau_emp->suiv = LE;
                LE = nouveau_emp;
            }
            else {
                nouveau_emp->suiv = liste_courante;
                liste_precedente->suiv = nouveau_emp;
            }
        }
        else {
            printf("Position introuvable.\n");
            free(nouveau_emp);
        }
    }
}


/**************************************************************************************/

//Fonction permettant de supprimer un employe en tête de liste
void supprimer_tete_emp(liste_emp LE) {
    if (LE == NULL) {
        printf("La liste est vide.");
    }
    else {
        liste_emp temp = LE;
        LE = LE->suiv;
        free(temp);
    }
}


/**************************************************************************************/

//Fonction permettant d 'ajouter un employe en fin de liste
void supprimer_queue_emp(liste_emp LE) {
    if (LE == NULL) {
        printf("La liste est vide.");
    }
    else if (LE->suiv == NULL) {
        free(LE);
        LE = NULL;
    }
    else {
        liste_emp temp = LE;
        while (temp->suiv->suiv != NULL) {
            temp = temp->suiv;
        }
        free(temp->suiv);
        temp->suiv = NULL;
    }
}


/**************************************************************************************/

//Fonction permettant de supprimer un employe dans une position donnée de la liste
void suppression_pos_emp(liste_emp LE, int position) {
    if (LE == NULL) {
        printf("La liste est vide.");
    }
    else if (position == 1) {
        supprimer_tete_emp(LE);
    }
    else {
        liste_emp temp = LE;
        liste_emp prev = NULL;
        int i = 1;
        while (temp != NULL && i < position) {
            prev = temp;
            temp = temp->suiv;
            i++;
        }
        if (temp == NULL) {
            printf("La liste est terminee et nous n avons pas pu trouve l employe.");
        }
        else {
            prev->suiv = temp->suiv;
            free(temp);
        }
    }
}


/**************************************************************************************/

//Fonction permettant de supprimer un employe donnée sur la liste
void suppression_employe_donne(liste_emp LE, int num) {
    if (LE == NULL) {
        printf("La liste est vide.");
    }
    else if (LE->mat == num) {
        supprimer_tete_emp(LE);
    }
    else {
        liste_emp temp = LE;
        liste_emp prev = NULL;
        while (temp != NULL && temp->mat != num) {
            prev = temp;
            temp = temp->suiv;
        }
        if (temp == NULL) {
            printf("La liste est terminee et nous n avons pas pu trouve l employe.");
        }
        else {
            prev->suiv = temp->suiv;
            free(temp);
        }
    }
}


/**************************************************************************************/

//Fonction permettant d'afficher un employé donné
void afficher_employe_donne(liste_emp LE, int num) {
    if (LE == NULL) {
        printf("La liste est vide.\n");
    }
    else {
        liste_emp temp = LE;
        while (temp != NULL && temp->mat != num) {
            temp = temp->suiv;
        }
        if (temp == NULL) {
            printf("L employe avec la matricule %d n existe pas.\n", num);
        }
        else {
            printf("Les informations de l employe avec la matricule %d sont:\n", num);
            printf("Nom: %s\n", temp->nom);
            printf("Prenom: %s\n", temp->prenom);
            printf("Adresse: %s\n", temp->adresse);
            printf("Date d embauche: %d %d %d\n", temp->DE.j, temp->DE.m, temp->DE.a);
            printf("Telephone: %d\n", temp->telephone);
            printf("Service: %c\n", temp->service);
            printf("Salaire brut: %f\n", temp->salairebrut);
        }
    }
}


/**************************************************************************************/

//Fonction permettant d'afficher la liste
void afficher_liste_emp(liste_emp LE) {
    if (LE == NULL) {
        printf("La liste est vide.\n");
    }
    else {
        liste_emp temp = LE;
        while (temp != NULL) {
            printf("Les informations de l employe avec la matricule %d sont:\n", temp->mat);
            printf("Nom: %s\n", temp->nom);
            printf("Prénom: %s\n", temp->prenom);
            printf("Adresse: %s\n", temp->adresse);
            printf("Date d'embauche: %d/%d/%d\n", temp->DE.j, temp->DE.m, temp->DE.a);
            printf("Téléphone: %d\n", temp->telephone);
            printf("Service: %c\n", temp->service);
            printf("Salaire brut: %f\n", temp->salairebrut);
            printf("\n");
            temp = temp->suiv;
        }
    }
}


/**************************************************************************************/

//Fonction permettant de supprimer un employé par le biais de son service
void suppression_employes_service(liste_emp LE, char service) {
    char s;
    printf("Veuillez donner le service:");scanf("%s",service);
    liste_emp liste_courante = LE;
    liste_emp liste_precedente = NULL;

    while (liste_courante != NULL) {
        if (liste_courante->service == service) {
            if (liste_precedente == NULL) {
                LE = liste_courante->suiv;
            } else {
                liste_precedente->suiv = liste_courante->suiv;
            }
            free(liste_courante);
            liste_courante = liste_precedente == NULL ? LE : liste_precedente->suiv;
        } else {
            liste_precedente = liste_courante;
            liste_courante = liste_courante->suiv;
        }
    }
}


/**************************************************************************************/

// Fonction pour calculer le montant CNSS
float CNSS(TPEmploye employe) {
    float tauxCotisation = 0.05;
    float montantCNSS = employe.salaire * tauxCotisation;
    return montantCNSS;
}


/**************************************************************************************/

// Fonction pour calculer les impôts
float impots(TPEmploye employe) {
     float taux_imposition = 0.2;
    float impots = employe.revenu_annuel * taux_imposition;
    
    return impots;
}


/**************************************************************************************/

// Fonction pour calculer le salaire net
float Salaire_Net(TPEmploye employe) {
    float salaireNet = employe.salaire_brut - employe.deductions;
    return salaireNet;
}


/**************************************************************************************/

float somme_salaires_bruts(TPEmploye *employe, int nombre_emp) {
    float somme = 0.0;
    for (int i = 0; i < nombre_emp; i++) {
        somme += employe->salaire_brut;
    }
     return somme;
  }
  

/**************************************************************************************/

// Fonction pour calculer la somme des montants CNSS
float sommeCNSS(TPEmploye *employe, int nombre_emp) {
    float somme = 0.0;
    for (int i = 0; i < nombre_emp; ++i) {
        somme += employe->montantCNSS;
    }
    return somme;
}


/**************************************************************************************/

//Fonction permettant de rechercher un employe par matricule
void rechercheParMatricule(liste_emp LE, int mat_) {
    liste_emp employe_actuel = LE;

    while (employe_actuel != NULL) {
        if (employe_actuel->mat == mat_) {
            printf("Matricule: %d\n",employe_actuel->mat;
	    printf(" Nom: %s\n",employe_actuel->nom); 
	    printf("Prenom: %s\n", employe_actuel->prenom);
	    printf("Telephone: %s\n",employe_actuel->telephone);
	    printf("Salaire: %f\n", employe_actuel->salairebrut);
	    printf("Date d'embauche: %d/%d/%d\n",employe_actuel->DE.j,employe_actuel->DE.m,employe_actuel->DE.a);
            return;// rupture du programme
        }
        employe_actuel = employe_actuel->suivant;
    }

    printf("Aucun employe avec la matricule %d n a ete trouve.\n", mat_);
}


/**************************************************************************************/

//Fonction permettant de rechercher un employe par nom
void rechercheParNom(liste_emp LE,char Nom) {
    liste_emp employe_actuel = LE;

    while (employe_actuel != NULL) {
        if (strcmp(employe_actuel->nom, Nom) == 0) {
            printf("Matricule: %d\n",employe_actuel->mat);
	    printf("Nom: %s\n",employe_actuel->nom); 
	    printf("Prenom: %s\n", employe_actuel->prenom);
	    printf("Telephone: %s\n", employe_actuel->telephone);
	    printf("Salaire: %f\n",employe_actuel->salaire);
	    printf("Date d'embauche: %d/%d/%d\n",employe_actuel->DE.j,employe_actuel->DE.m,employe_actuel->DE.a);
            return;
        }
        employe_actuel = employe_actuel->suivant;
    }

    printf("Aucun employe avec le nom %s n a ete trouve.\n", Nom);
}


/**************************************************************************************/

////Fonction permettant de rechercher un employe par telephone
void rechercheParTelephone(liste_emp LE, int telephone_) {
    liste_emp employe_actuel = LE;

    while (employe_actuel != NULL) {
        if (employe_actuel->telephone == telephone_) {
            printf("Matricule: %d\n", employe_actuel->matricule); 
	    printf("Nom: %s\n",employe_actuel->nom);
	    printf("Prenom: %s\n", employe_actuel->prenom);
	    printf("Telephone: %s\n",employe_actuel->telephone);
	    printf("Salaire: %f\n",employe_actuel->salaire);
	    printf("Date d'embauche: %d/%d/%d\n",employe_actuel->DE.j,employe_actuel->DE.m,employe_actuel->DE.a);
        }
        employe_actuel = employe_actuel->suivant;
    }

    printf("Aucun employe avec le numero de telephone %s n a ete trouve.\n", telephone_);
}


/**************************************************************************************/

//Fonction pour rechercher et afficher si un employé donné est embauché dans une année bissextile ou non
void rechercheAnneeBissextile( liste_emp LE, int mat_) {
    liste_emp employe_actuel = LE;

    while (employe_actuel != NULL) {
        if (employe_actuel->mat == mat_) {
            if ((employe_actuel->date_embauche % 4 == 0 && employe_actuel->date_embauche % 100 != 0) ||
                employe_actuel->date_embauche % 400 == 0) {
                printf("L employe avec le matricule %d a ete embauche dans une annee bissextile.\n", mat_);
            } else {
                printf("L employe avec le matricule %d n a pas ete embauche dans une annee bissextile.\n", mat_);
            }
            return;
        }
        employe_actuel = employe_actuel->suivant;
    }

    printf("Aucun employe avec le matricule %d n a ete trouve.\n", mat_);
    
}


/**************************************************************************************/

// Fonction pour comparer les dates
int comparerDates( int date1, int date2) {
      
}
    
/**************************************************************************************/ 
    	
//Fonction pour rechercher et afficher les employés 
void rechercheRetraite(liste_emp LE, int jour) {

}

/**************************************************************************************/ 

// Fonction pour rechercher et afficher les employés dont les numéros commencent par un indicatif
void rechercheIndicatif( liste_emp LE, int indicatif) {

}

/**************************************************************************************/ 

// Fonction pour trier la liste des employés par ordre décroissant 
void tri1(struct Employe* liste_employes) {
    struct Employe* i;
    struct Employe* j;

    for (i = liste_employes; i != NULL; i = i->suivant) {
        for (j = i->suivant; j != NULL; j = j->suivant) {
            if (i->salaire < j->salaire) {
                // Échanger les valeurs des cellules
                struct Employe temp = *i;
                *i = *j;
                *j = temp;
            }
        }
           
           
                        /*********************MENU*********************/

int val;
void menu_general() {
     int choix = 1;
    printf("    _____________________________________________________\n");
    printf("   |                     Menu General                    |\n");
    printf("   |                                                     |\n");
    printf("   |[1]-Creation des employes                            |\n");
    printf("   |                                                     |\n");
    printf("   |[2]-Mise a jour de la liste des employes             |\n");
    printf("   |                                                     |\n");
    printf("   |[3]-Calcul et affichage des salaires des employes    |\n");
    printf("   |                                                     |\n");
    printf("   |[4]-Recherche,affichage et Tri                       |\n");
    printf("   |                                                     |\n");
    printf("   |[5]-Quitter                                          |\n");
    printf("   |                                                     |\n");
    printf("   |_____________________________________________________|\n");
    printf("\n");
    printf("                Donner votre choix SVP:");
    scanf("%d",&val);
    switch(val){
        case 1: system("clear");//system("clear") permet de nettoyer la console sous linux --stdlib.h--
             while(choix == 1){ LE=CREATION(LE);printf("Voulez vouz ajouter un autre employe O/N ");
            scanf("%d",&choix);
             } system("clear");menu_general();
            break;
        case 2:
            system("clear"); menu_maj();
            break;
        case 3:
            system("clear");menu_ca();
            break;
        case 4:
            system("clear"); menu_ra();
            break;
        case 5: system("clear");exit(0);//return; --rupture du programme mais après nettoyage --stdlib.h--
            break;
        default:printf("Choix invalide.");menu_general();
    }


}


void menu_maj(){
    printf("    _____________________________________________________\n");
    printf("   |                     Menu Maj                        |\n");
    printf("   |                                                     |\n");
    printf("   |[1]-Ajoute un nouvel employe                         |\n");
    printf("   |                                                     |\n");
    printf("   |[2]-Supprimer un employe                             |\n");
    printf("   |                                                     |\n");
    printf("   |[3]-Modifier les donnees d un employe                |\n");
    printf("   |                                                     |\n");
    printf("   |[4]-Retour menu general                              |\n");
    printf("   |                                                     |\n");
    printf("   |_____________________________________________________|\n");
    printf("\n");
    printf("                 Donner votre choix SVP:");
    scanf("%d",&val);
    switch(val){
        case 1: system("clear"); menu_ajouter();
            break;
        case 2: system("clear"); menu_suppression();
            break;
        case 3: system("clear"); menu_modification();
            break;
        case 4: system("clear");menu_general();
            break;
        default:printf("Choix invalide."); system("clear");menu_general();

    }

}


void menu_ajouter(){
    printf("    _____________________________________________________\n");
    printf("   |                     Menu Ajouter                    |\n");
    printf("   |                                                     |\n");
    printf("   |[1]-Ajoute en tete                                   |\n");
    printf("   |                                                     |\n");
    printf("   |[2]-Ajout en queue                                   |\n");
    printf("   |                                                     |\n");
    printf("   |[3]-Ajout dans une position                          |\n");
    printf("   |                                                     |\n");
    printf("   |[4]-Retour au menu MAJ                               |\n");
    printf("   |                                                     |\n");
    printf("   |_____________________________________________________|\n");
    printf("\n");
    printf("                 Donner votre choix SVP:");
    scanf("%d",&val);
    switch(val){
        case 1: system("clear"); insere_tete_emp(LE);system("clear");menu_ajouter();
            break;
        case 2: system("clear"); insere_queue_emp(LE);system("clear");menu_ajouter();
            break;
        case 3: system("clear"); insere_pos_emp(LE);system("clear");menu_ajouter();
            break;
        case 4: system("clear");menu_maj();
            break;
        default:printf("Choix invalide.");system("clear");menu_maj();

    }

}


void menu_suppression(){
    printf("    _____________________________________________________\n");
    printf("   |                   Menu Suppression                  |\n");
    printf("   |                                                     |\n");
    printf("   |[1]-Suppression en tete                              |\n");
    printf("   |                                                     |\n");
    printf("   |[2]-Suppression  en queue                            |\n");
    printf("   |                                                     |\n");
    printf("   |[3]-Suppression a partir d une position              |\n");
    printf("   |                                                     |\n");
    printf("   |[4]-Suppression d un employe donnee                  |\n");
    printf("   |                                                     |\n");
    printf("   |[5]-Suppression des employes d un service            |\n");
    printf("   |                                                     |\n");
    printf("   |[6]-Retour au menu MAJ                               |\n");
    printf("   |_____________________________________________________|\n");
    printf("\n");
    printf("                 Donner votre choix SVP:");
    scanf("%d",&val);
    switch(val){
        case 1: system("clear"); supprimer_tete_emp(LE);system("clear");menu_suppression();
            break;

        case 2: system("clear"); supprimer_queue_emp(LE);system("clear");menu_suppression();

            break;
        case 3: system("clear"); suppression_pos_emp(LE,pos);system("clear");menu_suppression();
            break;

        case 4: system("clear"); suppression_employe_donne(LE,num);system("clear");menu_suppression();

            break;
        case 5: system("clear"); suppression_employes_service(LE,service);system("clear");menu_suppression();
            break;

        case 6: system("clear");menu_maj();
            break;
        default:printf("Choix invalide.");system("clear");menu_modification();

    }


}


void menu_modification() {

    printf("    _____________________________________________________\n");
    printf("   |                  Menu Modification                  |\n");
    printf("   |                                                     |\n");
    printf("   |[1]-Adresse                                          |\n");
    printf("   |                                                     |\n");
    printf("   |[2]-Telephone                                        |\n");
    printf("   |                                                     |\n");
    printf("   |[3]-Retour au menu MAJ                               |\n");
    printf("   |_____________________________________________________|\n");
    printf("\n");
    printf("                 Donner votre choix SVP:");
    scanf("%d",&val);
    switch(val){

        case 1: system("clear");//modif_add(LE,add);
        system("clear");menu_modification();
            break;
        case 2: system("clear");//modif_tel(LE,tel);
        system("clear");menu_modification();
            break;
        case 3: system("clear");menu_maj();
        system("clear");menu_modification();
            break;
        default:printf("Choix invalide.");
        system("clear");menu_modification();
    }
}



void menu_ra(){

    printf("    _____________________________________________________\n");
    printf("   |            Menu Recherche et Affichage              |\n");
    printf("   |                                                     |\n");
    printf("   |[1]-Contenu de la liste des employes                 |\n");
    printf("   |                                                     |\n");
    printf("   |[2]-Recherche par matricule                          |\n");
    printf("   |                                                     |\n");
    printf("   |[3]-Recherche par nom                                |\n");
    printf("   |                                                     |\n");
    printf("   |[4]-Recherche par Telephone                          |\n");
    printf("   |                                                     |\n");
    printf("   |[5]-Recherche par annee bixetile                     |\n");
    printf("   |                                                     |\n");
    printf("   |[6]-Recherche date ancienne                          |\n");
    printf("   |                                                     |\n");
    printf("   |[7]-Recherche retraite                               |\n");
    printf("   |                                                     |\n");
    printf("   |[8]-Recherche par indicatif Telephone                |\n");
    printf("   |                                                     |\n");
    printf("   |[9]-Tri 1                                            |\n");
    printf("   |                                                     |\n");
    printf("   |[10]-Tri 2                                           |\n");
    printf("   |                                                     |\n");
    printf("   |[11]-Retour au menu general                          |\n");
    printf("   |_____________________________________________________|\n");
    printf("\n");
    printf("                 Donner votre choix SVP:");
    scanf("%d",&val);
    switch(val){
        case 1: system("clear");//afficher_liste_emp(LE);
        system("clear");menu_ra();
            break;
        case 2: system("clear");//rechercheParMatricule(LE,num);
        system("clear");menu_ra();
            break;
        case 3: system("clear");//rechercheParNom(LE,nom);
        system("clear");menu_ra();
            break;
        case 4: system("clear");//rechercheParTelephone(LE,telephone);
        system("clear");menu_ra();
            break;
        case 5: system("clear");//rechercheAnneeBissextile(liste_employes,num);
        system("clear");menu_ra();
            break;
        case 6: system("clear");//comparerDates(date1,date2);
            break;
        case 7: system("clear");//rechercheRetraite(LE,jour); 
            break;
        case 8: system("clear");//rechercheIndicatif(LE,indicatif);
            break;
        case 9: system("clear");//tri1(LE);
            break;
        case 10: system("clear");//tri2(LE);
            break;
        case 11: system("clear");menu_general();
            break;
    }

}


void menu_ca(){
    printf("    _____________________________________________________\n");
    printf("   |                   Menu Calcul                       |\n");
    printf("   |                                                     |\n");
    printf("   |[1]-Calcul du CNSS                                   |\n");
    printf("   |                                                     |\n");
    printf("   |[2]-Calcul des Impots                                |\n");
    printf("   |                                                     |\n");
    printf("   |[3]-Calcul du Salaire Net                            |\n"); 
    printf("                                                         |\n");
    printf("   |[4]-Calcul du Salaire Brut                           |\n");     
    printf("   |                                                     |\n");
    printf("   |[5]-Retour au menu general                           |\n");
    printf("   |_____________________________________________________|\n");
    printf("\n");
    printf("                 Donner votre choix SVP:");
    scanf("%d",&val);
    switch(val){
        case 1: system("clear");CNSS(employe);
            break;
        case 2: system("clear");impots(employe);
            break;
        case 3: system("clear");Salaire_Net(employe);
            break;
        case 4: system("clear");//Salaire_Brut(employe);
            break;
        case 5: system("clear");menu_general();
            break;
       }

}
