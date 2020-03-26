#include <iostream>
#include <cmath>
using namespace std;

int main()
{	
	const double g(9.81);
	double HO(0.0);
	double eps(0.0);
	int nbr(0);
	double v(0);
	double v1(0);
	double h(0);
	double h1(0);
	
	//Interface avec l'utilisateur
	//Hauteur de départ
	do{
	cout << "Entrer la hauteur initial" << endl;
	cin >> HO;
	if (HO <= 0){
		cout << "La valeur de la hauteur initial doit etre supérieur à 0" << endl;
		} 
	} while (HO <= 0);
	
	//Coefficient de rebond
	do{
	cout << "Entrer le coeficient  de rebond" << endl;
	cin >> eps;
	if (eps < 0 or eps >= 1){
		cout << "La valeur du coefficient doit etre supérieur ou egal à 0 et inférieur a 1"<< endl;
		} 
	} while (eps < 0 and eps > 1);
	
	//Coefficient de rebond
	do{
	cout << "Entrer le nombre de rebond" << endl;
	cin >> nbr;
	if (nbr < 0){
		cout << "Le nombre de rebond doit etre supérieur ou égal à 0"<< endl;
		} 
	} while (nbr < 0);
	
	//Traitement
	for(int i(1);i<=nbr;++i){
		if (h==0){
			h=HO;
		}
		v=sqrt(2*h*g);
		v1=eps*v;
		h1=(v1*v1)/(2*g);
		h=h1;
	}
	cout << "La hauteur atteinte est de :" << h << endl;
	return 0;

}








