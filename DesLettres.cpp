#include "DesLettres.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>


using namespace std;

string DesLettres::recupLettres(string mot)
{
    string lettresEnDesordre;
   int position(0);

   while (mot.size() != 0)
   {
      position = rand() % mot.size();

      lettresEnDesordre += mot[position];
      lettresEnDesordre += " ";

        mot.erase(position, 1);
    }
   return lettresEnDesordre;

}

void DesLettres::trouverMot()
{
    do
   {
      cout << endl << "Quel est ce mot ? " << lettres << endl;
      cin >> motUtilisateur;

      if (motUtilisateur == motATrouver)
      {
         cout << "Bien joué ! Tu as trouvé le mot !" << endl;
      }
      else
      {
         cout << "Mauvaise réponse, essaye encore !" << endl;
      }

   }while (motUtilisateur != motATrouver);
}

DesLettres::DesLettres()
{
    string mots[]={"stade", "arbre","chat","carpe" };
    srand(time(NULL));
    motATrouver=mots[rand()%4];
    lettres = recupLettres(motATrouver);

}




/* #include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

string recupLettres(string mot)
{
   string lettresEnDesordre;
   int position(0);

   while (mot.size() != 0)
   {
      position = rand() % mot.size();

      lettresEnDesordre += mot[position];
      lettresEnDesordre += " ";

        mot.erase(position, 1);
    }
   return lettresEnDesordre;
}

int main()
{
   string motATrouver, lettres, motUtilisateur;

   //Initialisation des nombres aléatoires
   /*srand(time(0));
   string mots [] = {"stade", "arbre","chat","carpe" };
   motATrouver = mots[rand()% mots.length() - 1 ];

   string mots[]={"stade", "arbre","chat","carpe" };

   //motATrouver="stade";
    srand(time(NULL));
    motATrouver=mots[rand()%4];

   lettres = recupLettres(motATrouver);

   do
   {
      cout << endl << "Quel est ce mot ? " << lettres << endl;
      cin >> motUtilisateur;

      if (motUtilisateur == motATrouver)
      {
         cout << "Bravo !" << endl;
      }
      else
      {
         cout << "Ce n'est pas le mot !" << endl;
      }

   }while (motUtilisateur != motATrouver);

    return 0;
}
*/
