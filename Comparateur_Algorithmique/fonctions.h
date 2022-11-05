#pragma once
#include <vector>
#include <string>

std::vector<int> initTabAleat(size_t N);//!\brief Crée un tableau aléatoire
std::vector<int> initTabPresqueTri(size_t N);//!\brief Crée un tableau presque trié
std::vector<int> initTabPresqueTriDeb(size_t N);//!\brief Crée un tableau presque trié au début
std::vector<int> initTabPresqueTriFin(size_t N);//!\brief Crée un tableau presque trié à la fin
std::vector<int> initTabPresqueTriDebFin(size_t N);//!\brief Crée un tableau presque trié entre le début et la fin
void verifTri(const std::vector<int>& tab, const std::string& algoName = {});//!\brief Vérifie qu'un tableau est correctement trié
//Fonctions d'initialisation de tableau
//===================================================================================
//Fonction de trie de tableau
size_t triParSelection(std::vector<int>& tabSelect);		//Tri par selection
size_t triBulles(std::vector<int>& tabBulle);				//Tri à bulles
size_t triBullesOpti(std::vector<int>& tabBulleOpti);		//Tri à bulles optimisé
size_t triPeigne(std::vector<int>& tabPeigne);				//Tri à peigne
size_t triCocktail(std::vector<int>& tab);					//Tri cocktail
size_t triPairImpair(std::vector<int>& tab);				//Tri pair/impair
size_t triInsertion(std::vector<int>& tab);					//Tri par insertion
size_t triRapide(std::vector<int>& tabRapide);				//Tri rapide
int partitionner(std::vector<int>& tabPartitionner, int deb, int fin, int pivot, size_t& cont);//Fonctions utiles pour le tri rapide
void triRapideBis(std::vector<int>& tabBis, int debut, int fin, size_t& cont);                 //

