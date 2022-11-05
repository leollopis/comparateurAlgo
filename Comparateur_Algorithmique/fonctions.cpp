/**
 * \file fonctions.cpp
 * 
 * Définition des fonctions fournies.
 */
#include "fonctions.h"
#include <iostream>

/**
 * Crée un tableau d'entiers dont tous les éléments sont choisis aléatoirement.
 * 
 * Un tel tableau peut par exemple être 30968 28073 31177 2882 6140 17999 13828 20039 2310 24865.
 * 
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabAleat(size_t N)
{
  std::vector<int> tab(N);
  for (auto& val : tab)
    val = rand();
  return tab;
}

/**
 * Crée un tableau d'entiers presque triés. Chaque élément est quasiment à sa place définitive, échangé éventuellement d'une place.
 * 
 * Un tel tableau peut par exemple être 1 3 2 4 6 5 8 7 9 10.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabPresqueTri(size_t N)
{
  std::vector<int> tab(N);
  for (int i = 0; i < N; i++)
    tab[i] = i;
  for (int i = 0; i < N-1; i++)
  {
    if (rand() % 2 == 0)
    {
      std::swap(tab[i], tab[i + 1]);
      ++i;
    }
  }
  return tab;
}

/**
 * Crée un tableau d'entiers presque triés. Seuls le premier et le deuxième élément sont échangés.
 *
 * Un tel tableau peut par exemple être 2 1 3 4 5 6 7 8 9 10.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabPresqueTriDeb(size_t N)
{
  std::vector<int> tab(N);
  for (int i = 0; i < N; i++)
    tab[i] = i;
  std::swap(tab[0], tab[1]);
  return tab;
}

/**
 * Crée un tableau d'entiers presque triés. Seuls le dernier et l'avant dernier élément sont échangés.
 *
 * Un tel tableau peut par exemple être 1 2 3 4 5 6 7 8 10 9.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabPresqueTriFin(size_t N)
{
  std::vector<int> tab(N);
  for (int i = 0; i < N; i++)
    tab[i] = i;
  std::swap(tab[N - 1], tab[N - 2]);
  return tab;
}

/**
 * Crée un tableau d'entiers presque triés. Seuls le premier et le dernier élément sont échangés.
 *
 * Un tel tableau peut par exemple être 10 2 3 4 5 6 7 8 9 1.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabPresqueTriDebFin(size_t N)
{
  std::vector<int> tab(N);
  for (int i = 0; i < N; i++)
    tab[i] = i;
  std::swap(tab[N - 1], tab[0]);
  return tab;
}

/**
 * Vérifie qu'un tableau est correctement trié. Si le tableau est mal trié, un message d'erreur est
 * affiché sur le flux d'erreur et le programme est terminé.
 * 
 * \param[in] tab Le tableau à vérifier
 * \param[in] algoName Le nom de l'algorithme de tri qui a été utilisé. Ce paramètre est optionnel.
 */
void verifTri(const std::vector<int>& tab, const std::string& algoName)
{
  const size_t taille = tab.size();
  for (size_t i = 1; i < taille; i++)
  {
    if (tab[i - 1] > tab[i])
    {
      std::cerr << "Erreur dans le tri " << algoName << (algoName.empty() ? "!" : " !") << '\n';
      exit(EXIT_FAILURE);
    }
  }
}
// fonction du tri par selection:
size_t triParSelection(std::vector<int>& tab)
{
    size_t cpt = 0; // initialisation du compteur
    for (size_t i = 0; i <= tab.size() - 2; i++)
    {
        size_t min = i; //on affecte à min la valeur de i, qui sera réutilisé dans la boucle imbriquée qui suis
            for (size_t j = i + 1; j <= tab.size() - 1; j++)
            {
                if (tab[j] < tab[min]) //on compare les valeurs tab[min] (min vaut donc i) et tab[j] 
                {
                    min = j; //min vaut maintenant j
                }
                ++cpt; //on incrémente le compteur
            }
            if (min != i)
            {
                std::swap(tab[i], tab[min]); //dans le cas ou i et min(donc j) sont différents, on inverse les valeurs
            }
    }
    return cpt;
}
//fonction du tri a bulle qui parcoure le tableau a trier et qui echange les valeurs j et j+1 si j+1 et inferieur a j
size_t triBulles(std::vector<int>& tab)
{
    size_t cpt = 0;
    for (size_t i = 0; i < tab.size() - 1; i++) //boucle fort qui nous permet d'avancer dans le tableau via la variable i
    {
        for (size_t j = 0; j < tab.size() - i - 1; j++) //boucle for imbriquée qui incremente j et qui utilise i dans sa condition
        {
            if (tab[j + 1] < tab[j]) //condition if qui compare dans le tableau une valeur et celle qui la suit
                std::swap(tab[j + 1], tab[j]); //invrsion de j et j+1
            ++cpt; //incrémentation du compteur
        }
    }
    return cpt;
}

//fonction du tri a bulle Optimisée (cette methode ressemble donc au tri a bulle classique)
size_t triBullesOpti(std::vector <int>& tab)
{
    int cpt = 0;//compteur d'iteration
    for (int i = 0; i < tab.size() - 1; i++)
    {
        bool echange = true;
        for (int j = 0; j < tab.size() - i - 1; j++)
        {   
            //condition de l'echange : la valeur du tableau au rang j+1 doit etre inferieure à celle du rang j
            if (tab[j + 1] < tab[j])
            {
                std::swap(tab[j + 1], tab[j]);
                echange = false;
            }
            cpt++;
        }
        if (echange == true)
            return cpt;
    }
    return cpt;
}

//fonction du tri a peigne
size_t triPeigne(std::vector<int>& tab)
{
    size_t cpt = 0; //compteur d'iteration
    size_t n = tab.size();
    bool echange = false; //booléen echange qui comme sont nom l'indique donne l'état de l'échange 
    while(n > 1 || echange == true) //boucle tant que a 2 conditions (via l'opérateur ||) (la double condition sert a éviter certains cas qui pourraient bloquer la fonction)
    {
        n = n / 1.3;
        if (n < 1)
            n = 1;

        echange = false;

        for (size_t i = 0; i < tab.size() - n; i++)
        {
            if (tab[i] > tab[i + n]) //comparaison des valeurs i et i+n dans le tableau a trier
            {
                std::swap(tab[i], tab[i + n]); //inversion des valeurs de tableau i et i+n
                echange = true;
            }
            ++cpt; //incrémentatio du compteur a chaque iteration de la boucle for ligne 192 
        }
    }
    return cpt;
}

//===================================================================================
int partitionner(std::vector<int>& tab, int deb, int fin, int pivot, size_t& cont)
{
    std::swap(tab[pivot], tab[fin]);
    int j = deb;
    for (size_t i = deb; i <= fin - 1; i++)                                                         //Ici une valeur est choisie comme pivot et les éléments plus petits que le pivot sont dissociés au fur et à mesure par des échanges.
    {                                                                                               //Les elements plus petits et plus grands que le pivot sont triés séparémants.
        if (tab[i] <= tab[fin])
        {
            std::swap(tab[i], tab[j]);                                                                  
            j = j + 1;
        }
        ++cont;
    }
    std::swap(tab[fin], tab[j]);
    return j;
}                                                                                   //GROUPE DE FONCTION DU TRI RAPIDE

void triRapideBis(std::vector<int>& tab, int debut, int fin, size_t& cont)
{
    if (debut < fin)
    {
        int pivot = debut;
        pivot = partitionner(tab, debut, fin, pivot, cont);
        triRapideBis(tab, debut, pivot - 1, cont);
        triRapideBis(tab, pivot + 1, fin, cont);
    }
    ++cont;
}

size_t triRapide(std::vector<int>& tab) //fonction maitresse du tri rapide
{
    size_t cpt = 0;
    triRapideBis(tab, 0, tab.size() - 1, cpt);
    return cpt;
}
//===================================================================================

size_t triCocktail(std::vector<int>& tab)
{
    bool echange = true; //cette variable donne l'état de l'Echange qui va varier à chaques iterations
    int cpt = 0; //compteur d'iterations
    
    while (echange) //Cette fonction démare avec echange qui vaut true avant de le changer en false directement, ce booléen ce remet à True s'il y a un echange dans la fonction
    {
        echange = false;
        for (size_t i = 0 ; i < tab.size() - 1 ; i++ )
        {
            if(tab[i] > tab[i+1])
            {
                std::swap(tab[i], tab[i + 1]); //invertion des valeurs aux crans i et i+1 du tableau à trier
                echange = true;
                
            }
            cpt++;
        }
        for(size_t i = tab.size() - 2 ; i > 0 ; i--)
        {
            if (tab[i] > tab[i + 1])
            {
                std::swap(tab[i], tab[i + 1]); //invertion des valeurs aux crans i et i+1 du tableau à trier
                echange = true;
                
            }
            cpt++;
        }
    }//s'il y a une iteration sans échange on retourne le comtpeur
    return cpt;
}

//fonction du tri pair/impaire qui tant que !trie est vrai va comparer les valeurs i est i+1 du tableau à trier, tab[i] > tab[i+1] alors on intervertit les 2 valeurs dans le tableau 
size_t triPairImpair(std::vector<int>& tab)
{
    size_t cpt = 0; //compteur d'iteration
    bool echange = false;
    while (!echange)
    {
        echange = true;
        for (size_t i = 0; i < tab.size() - 1; i += 2)
        {
            if (tab[i] > tab[i + 1])
            {
                std::swap(tab[i], tab[i + 1]); //on intervertit les valeurs aux crans i et i+1 du tableau que le programme tri
                echange = false;
            }
            cpt++;
        }
        for (size_t i = 1; i < tab.size() - 1; i += 2)
        {
            if (tab[i] > tab[i + 1])
            {
                std::swap(tab[i], tab[i + 1]); //on intervertit les valeurs aux crans i et i+1 du tableau que le programme tri
                echange = false;
            }
            cpt++;
        }
    }
    return cpt;
}

//foncion du tri Insertion, ce trie est efficace
size_t triInsertion(std::vector<int>& tab)
{
    size_t cpt = 0;//compteur d'iteration
    int j;
    for(size_t i = 1 ; i <= tab.size() - 1 ; i++)
    {
        int a = tab[i];
        j = i;
        cpt++; //on incrémente le compteur
        while (j > 0 && tab[j - 1] > a)
        {//On donne a la valeur j du tableau la valeur de j - 1, et on donne a j - 1 la valeur de tab[i]
            tab[j] = tab[j - 1];
            j--;
            tab[j] = a;
            cpt++; //on incrémente le compteur
        }
    }
    return cpt;
}