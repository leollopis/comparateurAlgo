#include "csv.h"
//les fichiers "csv.h" et "csv.cpp" sont utilis�s pour s�parer les fonctions et donn�es de mise en page du reste
void petitEspace(int nb, std::ofstream& out) //Proc�dure qui permet de saut� des case dans le fichier .csv le parametre nb est le nombre d'espace
{
    for (size_t i = 0 ; i < nb ; i++)
    out << ';';
}

void entete(std::ofstream& out) // Fonction qui ecrie l'ent�te
{
	std::vector<std::string> strTri{ //vecteur de string strTri qui contient le nom de chaques methodes de tri 
		"Tri par s�l�ction",
		"Tri � bulles",
		"Tri � bulles optimis�",
		"Tri � peigne" ,
		"Tri Rapide" ,
		"Tri cocktail",
		"Tri pair-impair",
		"Tri par insertion"
	};

	std::vector<std::string> entete{ // vecteur de string entete qui contient l'entete qui sera utilis�e pour chaques methode de tri
		"Aleat S�lect.",
		"PresqueTri S�lect.",
		"PresqueTriDeb S�lect.",
		"PresqueTriDebFin S�lect.",
		"PresqueTriFin S�lect."
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
