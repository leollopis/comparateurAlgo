#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32
#include "fonctions.h"
#include "csv.h"
#include <iostream>
#include <string>

using TI = decltype(initTabAleat)*;
using TT = decltype(triParSelection)*;

int main()
{
#ifdef _WIN32
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
#endif // _WIN32*

	srand(time(0));

	std::ofstream out("output.csv"); //on defini le flux sortant dans le fichier "output.csv", sa variable associée est out



	int n = 0;
	while (n < 2) //boucle qui force la selection d'un nombre supérieur à 2
	{
		std::cout << "Choisissez un nombre entier supérieur ou égale à 2 : ";
		std::cin >> n;
		if (n < 2)
			std::cout << "Votre nombre n'est pas valable !\n";
	}

	const int N = n; //sécurité

	std::vector<TI> init = { //tableau de fonction qui initie les tableaux a trier 
		initTabAleat,
		initTabPresqueTri,
		initTabPresqueTriDeb,
		initTabPresqueTriFin,
		initTabPresqueTriDebFin }; 
	std::vector<TT> tri = { //tableau de fonction qui trie les tableau
		triParSelection,
		triBulles,
		triBullesOpti,
		triPeigne,
		triRapide, 
		triCocktail,
		triPairImpair,
		triInsertion 
	};

	size_t nComp = 0;
	out << 'N' << ";";
	entete(out); //on appelle la fonction qui ecrie l'entete

	for (size_t k = 2; k <= N; k++)
	{	
		
		out << k << ';'; //ici on ecrit k dans le fichier csv qui represente N à chaques itérations
		petitEspace(1, out); //petiteEspace("nombre de cases a sauter","fichier de sortie")	
		for (size_t i = 0; i < tri.size(); i++) //boucle for qui va faire une iteration pour chaque algorythme de tri
		{	
			for (size_t j = 0; j < init.size(); j++) //boucle for qui va faire une iteration pour chaque manière d'initialiser le tableau a trier
			{	
				std::vector<int> tab = init[j](k); //on crée un vecteur tab qui se créera avec les manieres de qui correspondent à j dans le vecteur de methode d'initialisation init
				nComp = tri[i](tab); 
				verifTri(tab); //ici on verifie a chaque fois que le trie est correct avec la fonction donnée verifTri avant d'ecrire
				out << nComp << ';'; //on ecrit le nombre de comparaison
				
			}
			nComp = 0; //ici on ré-initialise le comteur
			petitEspace(2, out);
		}
		out << "\n";
	}
}