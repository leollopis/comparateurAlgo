#include "csv.h"
//les fichiers "csv.h" et "csv.cpp" sont utilisés pour séparer les fonctions et données de mise en page du reste
void petitEspace(int nb, std::ofstream& out) //Procédure qui permet de sauté des case dans le fichier .csv le parametre nb est le nombre d'espace
{
    for (size_t i = 0 ; i < nb ; i++)
    out << ';';
}

void entete(std::ofstream& out) // Fonction qui ecrie l'entête
{
	std::vector<std::string> strTri{ //vecteur de string strTri qui contient le nom de chaques methodes de tri 
		"Tri par séléction",
		"Tri à bulles",
		"Tri à bulles optimisé",
		"Tri à peigne" ,
		"Tri Rapide" ,
		"Tri cocktail",
		"Tri pair-impair",
		"Tri par insertion"
	};

	std::vector<std::string> entete{ // vecteur de string entete qui contient l'entete qui sera utilisée pour chaques methode de tri
		"Aleat Sélect.",
		"PresqueTri Sélect.",
		"PresqueTriDeb Sélect.",
		"PresqueTriDebFin Sélect.",
		"PresqueTriFin Sélect."
	};
	// double boucle for range qui ecrit l'entete dans le fichier csv en utilisant les tableaux strTri et entete 
	for (auto& val : strTri) 
	{
		out << val << ';';
		for (auto& lav : entete)
		{
			out << lav << ';';
			
		}
		petitEspace(1, out); //Ici la fonction petitEspace fait 1 espace 
	}
	out << "\n";
}
