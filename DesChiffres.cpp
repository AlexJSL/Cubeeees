//
// Created by Alexis on 28/02/2019.
//

#include <cstdlib>
#include <string>
#include <iostream>
#include "DesChiffres.h"

using namespace std;

int DesChiffres::nbATrouver()
{
    nb_min=5;
    nb_max=20;
    int taille = nb_max-nb_min;

    return rand()%taille + nb_min;
}


/*********BONJOUR LE CODE POMPE********/
// A function to print the generated partition.
void printArray(int p[], int n)
{
    cout<<"\t";
    for (int i = 0; i < n; i++)
        cout<<p[i]<<" ";
    cout<<"\n";
}



// A function to print all the possible partition.
void PrintAllUniqueParts(int n, int nb_chiffres_voulus)
{
    int p[n], k = 0;
    p[k] = n;
    // Loop until all the array elements converted to 1 mean no further partition can be generated.
    while(1)
    {
        if (k>(nb_chiffres_voulus-2) && k< nb_chiffres_voulus)
        {
            printArray(p, k + 1);
            //ajouter une fct renvoyant le tableau au lieu de juste les print ?
        }
        int rem_val = 0;

        // Move the pointer to the index so that p[k] > 1.
        while (k >= 0 && p[k] == 1)
        {
            rem_val += p[k];
            k--;
        }
        // If k < 0 then the all the element are broken down to 1.
        if (k < 0)
            return;

        // If value greater than 1 is found then decrease it by 1 and increase rem_val to add it to other elements.
        p[k]--;
        rem_val++;

        // Loop until the number of 1's are greater than the value at k index.
        while (rem_val > p[k])
        {
            p[k+1] = p[k];
            // Decrease the rem_val value.
            rem_val = rem_val - p[k];
            k++;
        }

        // Assign the remaining value to the index next to k.
        p[k+1] = rem_val;
        k++;
    }
}

DesChiffres::DesChiffres()
{
    int nb, nb_decomp;
    cout<<"Nombre entier positif a decomposer : ";
    cin>>nb;
    //rq : on va tester avec notre random après

    cout<<"En combien de chiffre le decomposer  : ";
    cin>>nb_decomp;

    cout<<"Voici la decomposition de "<<nb<<" avec " <<nb_decomp<< " decomposition(s) \n";
    PrintAllUniqueParts(nb, nb_decomp);

}