#ifndef JEU_H
#define JEU_H

#define TAILLE 5
#define TAILLE_DECK 9

typedef struct carte_jeu {
  
	char type[10]; //attaque / action / terrain
  char nom[30]; //pike, infantry...
  int n_carte; // par rapport à la bibliotheque au début de la fonction main
  //char *affichage[9]; //visuel de la carte
  
  //FN_ATTAQUE attaque;  // suggestion affecter le ptr de fonction qui correspond à la carte

  //attaque/action
  int mouvement; //points de mouvement
  int flank; // points de flank
  int attaque; // point d'attaque
  int commandement; //point de commandement
  int victory_points;

  //terrain
  int joueur_controle;
	struct carte_jeu *suivant; //carte suivante
} CARTE_JEU, *PTR_CARTE_JEU;



//typedef void (*AFFICHAGE)(CARTE_JEU);

typedef struct joueur {
  char nom[40];
  int shuffle;
  int nbre_terrain_occupe;
  PTR_CARTE_JEU paquet[48];
  PTR_CARTE_JEU paquet_tirage;
  PTR_CARTE_JEU bonus_card;
  //struct carte_jeu *paquet_tirage;
  PTR_CARTE_JEU deck[TAILLE_DECK];
  int nb_carte_deck;
  //CARTE_ATTAQUE *deck; // suggest : tableau statique[taille]
  PTR_CARTE_JEU paquet_mort_adverse;
  PTR_CARTE_JEU paquet_defausse;
} JOUEUR, *PTR_JOUEUR;

typedef PTR_CARTE_JEU PLATEAU[TAILLE][TAILLE];

typedef int (*PTR_FN_TERRAIN)(PTR_CARTE_JEU, PTR_CARTE_JEU, PTR_CARTE_JEU); // suggestion

typedef int (*PTR_FN_ATTAQUE)(PTR_CARTE_JEU, PTR_CARTE_JEU, PTR_CARTE_JEU); // suggestion

typedef struct elements_du_jeu {
	PTR_JOUEUR joueurs[2];
  PLATEAU plateau;
  PTR_FN_ATTAQUE fonction_attaque[12];
  PTR_FN_TERRAIN fonction_terrain[4];
} JEU, *PTR_JEU;


PTR_CARTE_JEU append(PTR_CARTE_JEU p_tirage, PTR_CARTE_JEU carte);
PTR_CARTE_JEU supprimer_carte_tirage(PTR_CARTE_JEU p_tirage);
void afficher_carte(PTR_CARTE_JEU ligne_carte[], int debut, int taille);
void afficher_carte_terrain(PTR_CARTE_JEU ligne_carte[], int taille);
int calcul_point_attaque(PTR_JEU jeu, int tour, int vrai_tour, int carte_ami, int carte_enn);
int check_name(PTR_JEU);
void creation_affichage(char *aff[9]);
/*
void aff_action(PTR_CARTE_JEU carte);
void aff_attaque(PTR_CARTE_JEU carte);
void aff_terrain(PTR_CARTE_JEU carte);
*/
void initialisation_cartes(PTR_CARTE_JEU *paquet);
PTR_CARTE_JEU creation_carte(char *type, char *nom, int n_carte, int mouv, int flank, int attck, int comm, int vic_pts);
void initialisation_paquet_cartes_terrains(PTR_CARTE_JEU *paquet);
PTR_CARTE_JEU creation_carte_terrain(char *type, char *nom, int n_carte);
void melanger_carte(PTR_CARTE_JEU *paquet, int taille);
void melanger_carte_terrain(PTR_CARTE_JEU paquet, int taille);
void creation_main_tirage(PTR_JOUEUR joueurs);
void choix_paquet_tirage();
void detect_attaque_flank(PTR_JEU jeu, int tour);
void flank_attaque(PTR_JEU jeu, int tour);
void complete_deck(PTR_JOUEUR joueur);
void nb_carte_deck(PTR_JOUEUR joueur);
int somme_mort(PTR_JEU jeu, int tour);
void debut_partie(PTR_JEU jeu);
void tuer_carte(PTR_JEU jeu, int tour, int carte_attaquante);
//{elephant, spear, archers, light_cavalry, light_infantry, medium_infantry, cavalry, heavy_infantry, pike, commander, overlap, reserves}

int victory_check(PTR_JOUEUR joueurs[], PLATEAU plateau, int tour);
void compte_joueur_terrain(PLATEAU plateau, PTR_JOUEUR joueurs[]);
void advance(PTR_JEU jeu, int tour);

int elephant(PTR_CARTE_JEU carte_ami, PTR_CARTE_JEU carte_ami2, PTR_CARTE_JEU carte_enn);
int spear(PTR_CARTE_JEU carte_ami, PTR_CARTE_JEU carte_ami2, PTR_CARTE_JEU carte_enn);
int archers(PTR_CARTE_JEU carte_ami, PTR_CARTE_JEU carte_ami2, PTR_CARTE_JEU carte_enn);
int light_cavalry(PTR_CARTE_JEU carte_ami, PTR_CARTE_JEU carte_ami2, PTR_CARTE_JEU carte_enn);
int light_infantry(PTR_CARTE_JEU carte_ami, PTR_CARTE_JEU carte_ami2, PTR_CARTE_JEU carte_enn);
int medium_infantry(PTR_CARTE_JEU carte_ami, PTR_CARTE_JEU carte_ami2, PTR_CARTE_JEU carte_enn);
int cavalry(PTR_CARTE_JEU carte_ami, PTR_CARTE_JEU carte_ami2, PTR_CARTE_JEU carte_enn);
int heavy_infantry(PTR_CARTE_JEU carte_ami, PTR_CARTE_JEU carte_ami2, PTR_CARTE_JEU carte_enn);
int pike(PTR_CARTE_JEU carte_ami, PTR_CARTE_JEU carte_ami2, PTR_CARTE_JEU carte_enn);
int commander(PTR_CARTE_JEU carte_ami, PTR_CARTE_JEU carte_ami2, PTR_CARTE_JEU carte_enn);
int overlap(PTR_CARTE_JEU carte_ami, PTR_CARTE_JEU carte_ami2, PTR_CARTE_JEU carte_enn);
int reserves(PTR_CARTE_JEU carte_ami, PTR_CARTE_JEU carte_ami2, PTR_CARTE_JEU carte_enn);

void creation_flank_test(PTR_JEU jeu);
void afficher_plateau(PTR_JEU jeu, int tour, int etat);
void players_actions(PTR_JEU jeu, int tour);

int plain(PTR_CARTE_JEU carte_ami, PTR_CARTE_JEU carte_ami2, PTR_CARTE_JEU carte_enn);
int rough(PTR_CARTE_JEU carte_ami, PTR_CARTE_JEU carte_ami2, PTR_CARTE_JEU carte_enn);
int woods(PTR_CARTE_JEU carte_ami, PTR_CARTE_JEU carte_ami2, PTR_CARTE_JEU carte_enn);
int hill(PTR_CARTE_JEU carte_ami, PTR_CARTE_JEU carte_ami2, PTR_CARTE_JEU carte_enn);

int attaque(PLATEAU pleateau, int tour, CARTE_JEU *carte_att, CARTE_JEU *carte_terr);
int detection_victoire(int numero_joueur);
void tour_joueur();
void afficher_HandDeck();
void placement_carte(PTR_JEU jeu,int joueur);
void init(PLATEAU plateau);
void affiche(PLATEAU plateau);
void verif(PTR_JEU jeu,int ntr,int joueur, int carte_res, int i, int j);
void choix_plac(PTR_JEU jeu, int tour);
void enlevement(PTR_JEU jeu,int joueur,int carte_res,int DisM,int ntr);
void pioche(PTR_JEU jeu,int tour);
#endif