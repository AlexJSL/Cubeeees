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
         cout << "Bien jou� ! Tu as trouv� le mot !" << endl;
      }
      else
      {
         cout << "Mauvaise r�ponse, essaye encore !" << endl;
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

