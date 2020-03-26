#include <iostream>
#include <vector>
#include <string>


using namespace std;


struct Personne{
	double taille;
	int age;
	char sex;
};

void affiche_personne (Personne const& p);

void anniversaire (Personne& p);

Personne naissance ();

int main()
{   
	Personne Inconnu(naissance());
	affiche_personne(Inconnu);
	anniversaire(Inconnu);
	affiche_personne(Inconnu);
	return 0;
}



void affiche_personne (Personne const& p)
{ 
	cout<< "Les informations de la personne sont:"<< endl;
	cout<< "Taille :" << p.taille << endl;
	cout<< "Age : " << p.age << endl;
	cout<< " Sex : " << p.sex << endl;
}

void anniversaire (Personne& p)
{
	++(p.age);
}

Personne naissance ()
{
	Personne p;
	cout << "Veuillez rentrer les informations de la nouvelle personne :" << endl;
	cout << "Taille :" << endl;
	cin >> p.taille;
	cout << "age : " << endl;
	cin >> p.age;
	do{
	 cout << "Sexe de la personne :" << endl;
	 cin >> p.sex;
	} while(p.sex != 'M' and p.sex != 'F');
	return p;
}


