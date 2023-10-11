
#include <iostream>
#include <stdlib.h>

// Fonction qui affiche les règles du jeu
void afficherRegles() {

    std::cout << "Bienvenue sur Fantasy Clash !\nUn jeu realise par Maxime Corona et Marion Hance.\n";
    std::cout << "Le but du jeu est simple : Tuer son adversaire !\n";
    std::cout << "Il s'agit d'un jeu de combat au tour par tour, qui se joue a deux joueurs. \n";
    std::cout << "Au debut de la partie, chaque joueur choisit un personnage parmi les quatre disponibles, chaque personnage possède ses propres statistiques ainsi que trois competences, deux infligeant des degats et une permettant de se soigner.\n";
    std::cout << "Attention ! Chaque sort coûte des points de mana ou d'energie, il vous faudra alors bien gerer vos ressources afin de ne pas etre a court ! \n";
    std::cout << "Pas de panique ! Votre personnage regenere 10 points de mana par tour.\n";
}

// Fonction qui affiche chaque les informations de chaque personnage + leurs compétences
void afficherPersos() {

    std::cout << "\n1. Mage :\n \nPV : 80\nAttaque : 20\nMana : 150\n";
    std::cout << "\nCompetences :\n";
    std::cout << "1. Boule de feu : Lance une boule de feu qui inflige 10 points de degats (+20 ATQ). Cout 10 mana.\n";
    std::cout << "2. Missile arcanique : Lance 3 missiles d arcane qui infligent chacun 5 points de degats (+20 ATQ). Cout 15 mana.\n";
    std::cout << "3. Guerison cleste : Se soigne de 30 points de vie. Cout 15 mana.\n";
    std::cout << "\n              ----------------------             \n ";
	std::cout << "\n2. Paladin :\n \nPV : 150\nAttaque : 10\nMana : 80\n";
	std::cout << "\nCompetences :\n";
	std::cout << "1. Coup de bouclier : Projette son bouclier sur l ennemi et inflige 5 points de degats (+10 ATQ). Cout 10 mana.\n";
	std::cout << "2. Vertical slash : Donne un coup d epee qui inflige 10 points de degats (+10 ATQ). Cout 15 mana.\n";
	std::cout << "3. Purification : Se soigne de 15 PV. Cout 15 mana.\n";
    std::cout << "\n              ----------------------             \n ";
	std::cout << "\n3. Archer :\n \nPV : 100\nAttaque : 15\nMana : 100\n";
    std::cout << "\nCompetences :\n";
    std::cout << "1. Salve de fleches : Tire plusieurs fleches qui infligent 5 points de degats chacunes (+15 ATQ). Cout 15 mana.\n";
    std::cout << "2. Tir explosif : Tire une fleche explosive qui inflige 20 points de dégâts (+15 ATQ). Cout 30 mana.\n";
    std::cout << "3. Guerison spirituelle : Se soigne de 20 PV. Cout 20 mana.\n";
    std::cout << "\n              ----------------------             \n ";
	std::cout << "\n4. Assassin :\n \nPV : 100\nAttaque : 10\nMana : 100\n";
	std::cout << "\nCompetences :\n";
	std::cout << "1.Dague furtive : Lance une dague sur l ennemi qui inflige 15 pts de degats. Cout 15 mana.\n";
	std::cout << "2. Vertical slash : Donne un coup d epee qui inflige 10 points de degats (+10 ATQ). Cout 15 mana.\n";
	std::cout << "3. Purification : Se soigne de 15 PV. Cout 15 mana.\n"; 
    std::cout << "\n             ----------------------             \n ";
}


using namespace std;

struct Personnage {
    string nomPerso;
    int PV;
    int ATQ;
    int manaEnergie;
};

// fiches des personnages
Personnage mage = { "Mage", 80, 20, 150 };
Personnage paladin = { "Paladin", 150, 10, 80 };
Personnage archer = { "Archer", 100, 15, 100 };
Personnage assassin = { "Assassin", 100, 10, 100 };

struct Joueur {
    Personnage personnage;
    int PM;
    int PVJ;
};

void afficherStatistiquesJoueur(Joueur joueur) {
    std::cout << "Points de vie : " << joueur.PVJ << std::endl;
    std::cout << "Points de mana : " << joueur.PM << std::endl;
}



// Fonction principale
int main() {

    int choix;
    int choixJoueur1Perso;
    int choixJoueur2Perso;
    Personnage joueur1Perso;
    Personnage joueur2Perso;
    Joueur joueur1;
    Joueur joueur2;
    afficherRegles();

    while (true) {
        std::cout << "Etes-vous prets ? 1) Lancer le jeu 2) Quitter\n";
        std::cin >> choix;

        // Si le choix du joueur est 1, on lance la partie :
        if (choix == 1) {
            std::cout << "\nBon jeu !\n";
            std::cout << "\nVoici la liste des personnages :\n";
            afficherPersos();

            // -------------------------------- CHOIX DES PERSONNAGES --------------------------------------------------------

            // Le joueur 1 selectionne un personnage :
            while (true) {
                std::cout << "\nJoueur 1 : Selectionnez un personnage (1, 2, 3 ou 4)\n";
                std::cin >> choixJoueur1Perso;

                if (choixJoueur1Perso < 1 || choixJoueur1Perso > 4) {
                    std::cout << "\nChoix invalide. Veuillez choisir un numero de personnage valide.\n";
                }

                else {
                    break; // Sortir de la boucle de sélection du personnage
                }
            }

            if (choixJoueur1Perso == 1) {
                joueur1Perso = mage;
                joueur1.PM = mage.manaEnergie;
                joueur1.PVJ = mage.PV;
                std::cout << "\nVous avez choisi le Mage !\n";
            }
            else if (choixJoueur1Perso == 2) {
                joueur1Perso = paladin;
                joueur1.PM = paladin.manaEnergie;
                joueur1.PVJ = paladin.PV;
                std::cout << "\nVous avez choisi le Paladin !\n";
            }
            else if (choixJoueur1Perso == 3) {
                joueur1Perso = archer;
                joueur1.PM = archer.manaEnergie;
                joueur1.PVJ = archer.PV;

                std::cout << "\nVous avez choisi l'Archer !\n";
            }
            else if (choixJoueur1Perso == 4) {
                joueur1Perso = assassin;
                joueur1.PM = assassin.manaEnergie;
                joueur1.PVJ = assassin.PV;
                std::cout << "\nVous avez choisi l'Assassin !\n";
            }
            break; // Sortir de la boucle principale
        }

        else if (choix == 2) {
            std::cout << "Vous quittez le jeu";
            break;
        }

        else { // Si le joueur ne met pas un nombre entre 1 et 4
            std::cout << "Merci de selectionner une option valide (1 ou 2)\n";
        }
    }
    // Le joueur 2 selectionne un personnage : 
    while (true) {
        std::cout << "\nJoueur 2 : Selectionnez un personnage (1, 2, 3 ou 4)\n";
        std::cin >> choixJoueur2Perso;

        if (choixJoueur2Perso < 1 || choixJoueur2Perso > 4) {
            std::cout << "\nChoix invalide. Veuillez choisir un numero de personnage valide.\n";
        }
        else {
            break; // Sortir de la boucle de sélection du personnage
        }
    }

    if (choixJoueur2Perso == 1) {// Le deuxieme joueur choisit a son tours
        joueur2Perso = mage;
        joueur2.PM = mage.manaEnergie;
        joueur2.PVJ = mage.PV;
        std::cout << "\nVous avez choisi le Mage !\n";
    }
    else if (choixJoueur2Perso == 2) {
        joueur2Perso = paladin;
        joueur2.PM = paladin.manaEnergie;
        joueur2.PVJ = paladin.PV;
        std::cout << "\nVous avez choisi le Paladin !\n";
    }
    else if (choixJoueur2Perso == 3) {
        joueur2Perso = archer;
        joueur2.PM = archer.manaEnergie;
        joueur2.PVJ = archer.PV;
        std::cout << "\nVous avez choisi l'Archer !\n";
    }
    else if (choixJoueur2Perso == 4) {
        joueur2Perso = assassin;
        joueur2.PM = assassin.manaEnergie;
        joueur2.PVJ = assassin.PV;
        std::cout << "\nVous avez choisi l'Assassin !\n";
    }
    else {
        std::cout << "Merci de selectionner une option valide (1 ou 2)\n";
    }

    std::cout << "\nLa partie va commencer :\n";

    int competencejoueur1;
    int competencejoueur2;

    bool partieTerminee = false;

    // Boucle de jeu
    while (!partieTerminee) {

        // Tour du joueur 1
        std::cout << "\nTour du Joueur 1 (" << joueur1.personnage.nomPerso << ") :\n";
        std::cout << "Points de vie du Joueur 1 : " << joueur1.PVJ << "\n";
        std::cout << "Points de mana du Joueur 1 : " << joueur1.PM << "\n";
        std::cout << "Voici vos compétences :";

        if (joueur1.personnage.nomPerso == "Mage") {

            std::cout << "1. Boule de feu : Lance une boule de feu qui inflige 10 points de degats (+20 ATQ). Cout 10 mana.\n";
            std::cout << "2. Missile arcanique : Lance 3 missiles d arcane qui infligent chacun 5 points de degats (+20 ATQ). Cout 15 mana.\n";
            std::cout << "3. Guerison cleste : Se soigne de 30 points de vie. Cout 15 mana.\n";
            std::cout << "Quelle competence voulez-vous utiliser ? (1, 2 ou 3)";
            std::cin >> competencejoueur1;

            if (competencejoueur1 == 1) {
                joueur1.PM -= 10;
                joueur2.PVJ -= 30;
                std::cout << "Vous avez lance boule de feu sur votre adversaire ! Il a perdu 30 PV ! Ce sort vous a coute 10 mana.";
                std::cout << "Informations du Joueur 1 :\n";
                afficherStatistiquesJoueur(joueur1);
                std::cout << "Informations du Joueur 2:\n";
                afficherStatistiquesJoueur(joueur2);
            }

            if (competencejoueur1 == 2) {
                joueur1.PM -= 15;
                joueur2.PVJ -= 35;
                std::cout << "Vous lancez 3 missiles d arcane qui infligent en tout 15 points de degats ! Cela vous a coute 15 mana.";
                std::cout << "Informations du Joueur 1 :\n";
                afficherStatistiquesJoueur(joueur1);
                std::cout << "Informations du Joueur 2:\n";
                afficherStatistiquesJoueur(joueur2);
            }

            if (competencejoueur1 == 3) {
                joueur1.PM -= 15;
                joueur1.PVJ += 30;
                std::cout << "Vous regagnez 30 points de vie. Cela vous a coute 15 mana.";
                std::cout << "Informations du Joueur 1 :\n";
                afficherStatistiquesJoueur(joueur1);
                std::cout << "Informations du Joueur 2:\n";
                afficherStatistiquesJoueur(joueur2);
            }

    if (joueur1.personnage.nomPerso == "Paladin") {

        std::cout << "1. Coup de bouclier : Projette son bouclier sur l ennemi et inflige 5 points de degats (+10 ATQ). Cout 10 mana.\n";
        std::cout << "2. Vertical slash : Donne un coup d epee qui inflige 10 points de degats (+10 ATQ). Cout 15 mana.\n";
        std::cout << "3. Purification : Se soigne de 15 PV. Cout 15 mana.\n";
        std::cout << "Quelle competence voulez-vous utiliser ?";
        std::cin >> competencejoueur1;
         }
           
            if (competencejoueur1 == 1) {
                joueur1.PM -= 10;
                joueur2.PVJ -= 30;
                std::cout << "Vous avez lance boule de feu sur votre adversaire ! Il a perdu 30 PV ! Ce sort vous a coute 10 mana.";
                std::cout << "Informations du Joueur 1 :\n";
                afficherStatistiquesJoueur(joueur1);
                std::cout << "Informations du Joueur 2:\n";
                afficherStatistiquesJoueur(joueur2);
            }

            if (competencejoueur1 == 2) {
                joueur1.PM -= 15;
                joueur2.PVJ -= 35;
                std::cout << "Vous lancez 3 missiles d arcane qui infligent en tout 15 points de degats ! Cela vous a coute 15 mana.";
                std::cout << "Informations du Joueur 1 :\n";
                afficherStatistiquesJoueur(joueur1);
                std::cout << "Informations du Joueur 2:\n";
                afficherStatistiquesJoueur(joueur2);
            }

            if (competencejoueur1 == 3) {
                joueur1.PM -= 15;
                joueur1.PVJ += 30;
                std::cout << "Vous regagnez 30 points de vie. Cela vous a coute 15 mana.";
                std::cout << "Informations du Joueur 1 :\n";
                afficherStatistiquesJoueur(joueur1);
                std::cout << "Informations du Joueur 2:\n";
                afficherStatistiquesJoueur(joueur2);
            }



    if (joueur1.personnage.nomPerso == "Archer") {
        std::cout << "1. Salve de fleches : Tire plusieurs fleches qui infligent 5 points de degats chacunes (+15 ATQ). Cout 15 mana.\n";
        std::cout << "2. Tir explosif : Tire une fleche explosive qui inflige 20 points de dégâts (+15 ATQ). Cout 30 mana.\n";
        std::cout << "3. Guerison spirituelle : Se soigne de 20 PV. Cout 20 mana.\n";
        std::cout << "Quelle competence voulez-vous utiliser ?";
        std::cin >> competencejoueur1;

            if (competencejoueur1 == 1) {
            joueur1.PM -= 10;
            joueur2.PVJ -= 30;
            std::cout << "Vous avez lance boule de feu sur votre adversaire ! Il a perdu 30 PV ! Ce sort vous a coute 10 mana.";
            std::cout << "Informations du Joueur 1 :\n";
            afficherStatistiquesJoueur(joueur1);
            std::cout << "Informations du Joueur 2:\n";
            afficherStatistiquesJoueur(joueur2);
            }

            if (competencejoueur1 == 2) {
            joueur1.PM -= 15;
            joueur2.PVJ -= 35;
            std::cout << "Vous lancez 3 missiles d arcane qui infligent en tout 15 points de degats ! Cela vous a coute 15 mana.";
            std::cout << "Informations du Joueur 1 :\n";
            afficherStatistiquesJoueur(joueur1);
            std::cout << "Informations du Joueur 2:\n";
            afficherStatistiquesJoueur(joueur2);
            }

            if (competencejoueur1 == 3) {
            joueur1.PM -= 15;
            joueur1.PVJ += 30;
            std::cout << "Vous regagnez 30 points de vie. Cela vous a coute 15 mana.";
            std::cout << "Informations du Joueur 1 :\n";
            afficherStatistiquesJoueur(joueur1);
            std::cout << "Informations du Joueur 2:\n";
            afficherStatistiquesJoueur(joueur2);
            }
    }


    if (joueur1.personnage.nomPerso == "Assassin") {
        std::cout << "1.Dague furtive : Lance une dague sur l ennemi qui inflige 15 pts de degats. Cout 15 mana.\n";
        std::cout << "2. Vertical slash : Donne un coup d epee qui inflige 10 points de degats (+10 ATQ). Cout 15 mana.\n";
        std::cout << "3. Purification : Se soigne de 15 PV. Cout 15 mana.\n";
        std::cout << "Quelle competence voulez-vous utiliser ?";
        std::cin >> competencejoueur1;
    }

            if (competencejoueur1 == 1) {
                joueur1.PM -= 10;
                joueur2.PVJ -= 30;
                std::cout << "Vous avez lance boule de feu sur votre adversaire ! Il a perdu 30 PV ! Ce sort vous a coute 10 mana.";
                std::cout << "Informations du Joueur 1 :\n";
                afficherStatistiquesJoueur(joueur1);
                std::cout << "Informations du Joueur 2:\n";
                afficherStatistiquesJoueur(joueur2);
            }

            if (competencejoueur1 == 2) {
                joueur1.PM -= 15;
                joueur2.PVJ -= 35;
                std::cout << "Vous lancez 3 missiles d arcane qui infligent en tout 15 points de degats ! Cela vous a coute 15 mana.";
                std::cout << "Informations du Joueur 1 :\n";
                afficherStatistiquesJoueur(joueur1);
                std::cout << "Informations du Joueur 2:\n";
                afficherStatistiquesJoueur(joueur2);
            }

            if (competencejoueur1 == 3) {
                joueur1.PM -= 15;
                joueur1.PVJ += 30;
                std::cout << "Vous regagnez 30 points de vie. Cela vous a coute 15 mana.";
                std::cout << "Informations du Joueur 1 :\n";
                afficherStatistiquesJoueur(joueur1);
                std::cout << "Informations du Joueur 2:\n";
                afficherStatistiquesJoueur(joueur2);
            }


            // Tour du joueur 2
            std::cout << "\nTour du Joueur 2 (" << joueur2.personnage.nomPerso << ") :\n";
            std::cout << "Points de vie du Joueur 1 : " << joueur2.PVJ << "\n";
            std::cout << "Points de mana du Joueur 1 : " << joueur2.PM << "\n";
            std::cout << "Voici vos compétences :";

           


                        return 0;
                    }

                }
            }
        
    