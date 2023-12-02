//
// Created on 21/11/23.
//


//
//    FONCTIONS GENERALES
//
typedef struct employe * liste_emp;
typedef struct TPEmploye TPEmploye;
liste_emp CREATION(liste_emp LE);
int taille_liste_emp (liste_emp LE);
liste_emp recherche_emp(liste_emp LE, int num);
void insere_tete_emp(liste_emp LE);
void insere_queue_emp(liste_emp LE);
void insere_pos_emp(liste_emp LE);
void supprimer_tete_emp(liste_emp LE);
void supprimer_queue_emp(liste_emp LE);
void suppression_pos_emp(liste_emp LE, int pos);
void suppression_employe_donne(liste_emp LE, int num);
void suppression_employes_service(liste_emp LE, char service);
void afficher_employe_donne(liste_emp LE, int num);
void afficher_liste_emp(liste_emp LE);

//
//      MENU
//
void menu_general();
void menu_maj();
void menu_ajouter();
void menu_suppression();
void menu_modification();
void menu_ra();
void menu_ca();

//
//    CALCULS
//
float CNSS(TPEmploye employe);
float impots(TPEmploye employe);
float Salaire_Net(TPEmploye employe);
float somme_salaires_bruts(TPEmploye *employe, int nombre_emp);
float sommeCNSS(TPEmploye *employe, int nombre_emp);

//
//   RECHERCHE
//
void afficher_employe_donne(liste_emp LE, int num);
void rechercheParMatricule(liste_emp LE, int mat_);
void rechercheParNom(liste_emp LE,char Nom);
void rechercheParTelephone(iste_emp LE, int telephone_);
void rechercheAnneeBissextile(liste_emp liste_employes, int matricule);
//int comparerDates( int date1, int date2);
void rechercheRetraite(liste_emp LE, int jour);
//void rechercheIndicatif(liste_emp liste_employes, const char* indicatif);
//void tri1(liste_emp LE);
//void tri2(liste_emp LE);

