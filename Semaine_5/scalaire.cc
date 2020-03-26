#include <iostream>
#include <vector>
using namespace std;


double scalaire (vector<double> u,vector<double>v);

double scalaire (vector<double> u,vector<double>v)
{	
	double result(0.0);
	for(size_t i(0);i< u.size();i++){
		result+=u[i]*v[i];
	}
	return result;
}


int main ()
{
	int tailleVecteur;
	
	//Demander à l'utilisateur la taille des vecteur
	cout << "Taille du vecteur 1 et 2 :" << endl;
	cin >> tailleVecteur;
	
	vector<double> v1(tailleVecteur);
	vector<double> v2(tailleVecteur);
	
	 //Rentrer les composantes des vecteurs
	 for(size_t i(0); i<v1.size() ;i++){
		 cout << "Composante numero : " << i+1 << " Vecteur 1" << endl;
		 cin >> v1[i];
		 cout << "Composante numero : " << i+1 << " Vecteur 2" << endl;
		 cin >> v2[i];
	}
	
	//Calcul du produit scalaire
	
	double resultat=scalaire(v1,v2);
	
	cout << "le produit scalaire est " << resultat << endl;
	
	return 0;
}



