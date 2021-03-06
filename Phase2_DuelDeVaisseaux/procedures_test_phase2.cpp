#include <iostream>
#include "moteur_de_jeu.h"
#include "lib_vaisseau2.h"
#include "procedures_test_phase2.h"

using namespace std ;

/**
    --------------------------------------------------------------------------------------------------------------------------------------------------------------
    | Définition de la librairie de procédures de test permettant de valider les nouvelles fonctionnalités de gestion d'un duel de vaisseaux (phase 2 du projet) |
    --------------------------------------------------------------------------------------------------------------------------------------------------------------
 **/

void TestDuelVaisseau1()
{
    /* Déclaration des variables locales */
    int local_degats = 600 ;
    /// Déclaration d'une variable de type Vaisseau
    Vaisseau faucon ;

    /* Algorithme local */
    cout << "|*****************************************|" << endl ;
    cout << "|*********** TestDuelVaisseau1 ***********|" << endl ;
    cout << "|=> test de la fonction d'encaissement    |" << endl ;
    cout << "|   de degats par un Vaisseau cible       |" << endl ;
    cout << "|   SubirDegatsCoque.                     |" << endl ;
    cout << "|*****************************************|" << endl << endl ;

    /// Initialisation des caractéristiques du Vaisseau par appel à la fonction dédiée AffecterCarac avec des valeurs "en dur"
    /// => On doit donner l'adresse de la variable de type Vaisseau concernée comme 1er argument de la fonction AffecterCarac
    AffecterCarac(&faucon, "faucon millenium", 1000, 100) ;

    /// Affichage des caractéristiques du Vaisseau déclaré pour vérification
    AfficherCarac(&faucon) ;

    /// Appel de la fonction d'encaissement de dégâts SubirDegatsCoque
    /// avec un nombre de dégâts inférieur à la résistance de coque actuelle
    cout << endl << "[" << endl ;
    cout << "\tVaisseau " << RenvoyerNom(&faucon) << " de classe " << RenvoyerClasse(&faucon) << " : " << endl ;
    cout << "\t| => subit " << local_degats << " degats de coque." << endl ;
    cout << "\t|_________________" << endl ;
    cout << "]" << endl ;
    SubirDegatsCoque(&faucon, local_degats) ;

    /// Affichage des caractéristiques du Vaisseau déclaré pour vérification
    /// => le vaisseau n'est pas encore détruit
    AfficherCarac(&faucon) ;

    /// Appel de la fonction d'encaissement de dégâts SubirDegatsCoque par la Vaisseau cible
    /// avec un nombre de dégâts supérieur à la résistance de coque actuelle
    /// => le vaisseau n'est pas encore détruit
    cout << endl << "[" << endl ;
    cout << "\tVaisseau " << RenvoyerNom(&faucon) << " de classe " << RenvoyerClasse(&faucon) << " : " << endl ;
    cout << "\t| => subit " << local_degats << " degats de coque." << endl ;
    cout << "\t|_________________" << endl ;
    cout << "]" << endl ;
    SubirDegatsCoque(&faucon, local_degats) ;

    /// Affichage des caractéristiques du Vaisseau déclaré pour vérification
    /// => le vaisseau doit être détruit
    AfficherCarac(&faucon) ;
}

void TestDuelVaisseau2()
{
    /* Déclaration des variables locales */
    int local_degats ;
    /// Déclaration d'une variable de type Vaisseau
    Vaisseau faucon ;

    /* Algorithme local */
    cout << "|*****************************************|" << endl ;
    cout << "|*********** TestDuelVaisseau2 ***********|" << endl ;
    cout << "|=> test de la fonction d'encaissement    |" << endl ;
    cout << "|   de degats par un Vaisseau cible       |" << endl ;
    cout << "|   SubirDegatsCoque.                     |" << endl ;
    cout << "|=> valeur de degats saisie               |" << endl ;
    cout << "|   par l'utilisateur                     |" << endl ;
    cout << "|=> boucle tant que le Vaisseau cible     |" << endl ;
    cout << "|   n'est pas detruit ...                 |" << endl ;
    cout << "|*****************************************|" << endl << endl ;

    /// Initialisation des caractéristiques du Vaisseau par appel à la fonction dédiée AffecterCarac avec des valeurs "en dur"
    /// => On doit donner l'adresse de la variable de type Vaisseau concernée comme 1er argument de la fonction AffecterCarac
    AffecterCarac(&faucon, "faucon millenium", 1000, 100) ;

    /// Affichage des caractéristiques du Vaisseau déclaré pour vérification
    AfficherCarac(&faucon) ;

    /// Boucle tant que le Vaisseau cible n'est pas détruit ...
    do
    {
        /// Attente démarrage nouveau round
        GetReady4NextRound() ;

        /// Saisie des dégâts à infliger au Vaisseau cible
        cout << "Saisir les degats a infliger au Vaisseau cible : " << endl ;
        cin >> local_degats ;

        /// Appel de la fonction d'encaissement de dégâts SubirDegatsCoque par la Vaisseau cible
        /// avec un nombre de dégâts inférieur à la résistance de coque actuelle
        cout << endl << "[" << endl ;
        cout << "\tVaisseau " << RenvoyerNom(&faucon) << " de classe " << RenvoyerClasse(&faucon) << " : " << endl ;
        cout << "\t| => subit " << local_degats << " degats de coque." << endl ;
        cout << "\t|_________________" << endl ;
        cout << "]" << endl ;
        SubirDegatsCoque(&faucon, local_degats) ;

        /// Affichage des caractéristiques du Vaisseau déclaré pour vérification
        AfficherCarac(&faucon) ;

    } while (RenvoyerResistanceCoque(&faucon) > 0) ;

    GameOver() ;
}

void TestDuelVaisseau3()
{
    /* Déclaration des variables locales */
    int local_coque_attaquant, local_puissance_attaquant ;
    int local_coque_cible, local_puissance_cible ;
    /// Déclaration de 2 variables de type Vaisseau (l'attaquant et la cible)
    Vaisseau attaquant, cible ;

    /* Algorithme local */
    cout << "|*****************************************|" << endl ;
    cout << "|*********** TestDuelVaisseau2 ***********|" << endl ;
    cout << "|=> test d'un Vaisseau en attaquant       |" << endl ;
    cout << "|   un autre (les degats infligés par     |" << endl ;
    cout << "|   l'attaquant sont egaux a sa puissance |" << endl ;
    cout << "|   de feu)                               |" << endl ;
    cout << "|=> boucle tant que le Vaisseau cible     |" << endl ;
    cout << "|   n'est pas detruit ...                 |" << endl ;
    cout << "|*****************************************|" << endl << endl ;

    /// Saisie des caractéristiques (coque et puissance) de chaque Vaisseau
    cout << "Saisir la resistance de coque du Vaisseau attaquant : " << endl ;
    cin >> local_coque_attaquant ;
    cout << "Saisir la puissance de feu du Vaisseau attaquant : " << endl ;
    cin >> local_puissance_attaquant ;
    cout << "Saisir la resistance de coque du Vaisseau cible : " << endl ;
    cin >> local_coque_cible ;
    cout << "Saisir la puissance de feu du Vaisseau cible : " << endl ;
    cin >> local_puissance_cible ;

    /// Initialisation des caractéristiques du Vaisseau attaquant par appel à la fonction dédiée AffecterCarac avec des valeurs "en dur"
    /// => On doit donner l'adresse de la variable de type Vaisseau concernée comme 1er argument de la fonction AffecterCarac
    AffecterCarac(&attaquant, "faucon millenium", local_coque_attaquant, local_puissance_attaquant) ;
    /// Initialisation des caractéristiques du Vaisseau cible par appel à la fonction dédiée AffecterCarac avec des valeurs "en dur"
    /// => On doit donner l'adresse de la variable de type Vaisseau concernée comme 1er argument de la fonction AffecterCarac
    AffecterCarac(&cible, "tie fighter", local_coque_cible, local_puissance_cible) ;

    /// Affichage des caractéristiques des Vaisseaux attaquant et cible
    AfficherCarac(&attaquant) ;
    AfficherCarac(&cible) ;

    /// Boucle tant que le Vaisseau cible n'est pas détruit ...
    do
    {
        /// Attente démarrage nouveau round
        GetReady4NextRound() ;

        /// Appel de la fonction d'encaissement de dégâts SubirDegatsCoque par la Vaisseau cible
        cout << endl << "[" << endl ;
        cout << "\tVaisseau " << RenvoyerNom(&cible) << " de classe " << RenvoyerClasse(&cible) << " : " << endl ;
        cout << "\t| => subit " << RenvoyerPuissanceFeu(&attaquant) << " degats de coque." << endl ;
        cout << "\t|_________________" << endl ;
        cout << "]" << endl ;
        /// Les dégâts infligés au Vaisseau cible sont les points d'attaque (puissance de feu) du Vaisseau attaquant
        /// que l'on récupère grâce à la fonction RenvoyerPuissanceFeu appliquée au Vaisseau attaquant
        SubirDegatsCoque(&cible, RenvoyerPuissanceFeu(&attaquant)) ;

        /// Affichage des caractéristiques du Vaisseau cible
        AfficherCarac(&cible) ;

    } while (RenvoyerResistanceCoque(&cible) > 0) ;

    GameOver() ;
}
