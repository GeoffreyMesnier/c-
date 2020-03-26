#include <iostream>
#include <cmath>
using namespace std;

int main()
{	
	double a(0.0);
	double b(0.0);
	double c(0.0);
	
	cout << "Rentrer une valeur non nulle pour a" << endl;
	cin >> a;
	//cerr est comme cout, mais pour les messages d'erreur
	if (a==0){
		cerr << "erreur: a est nul" << endl;
		return 1; // on quitte le programme
	}
	
	cout << "Entrer une valeur de b:" << endl;
	cin >> b;
	cout << "Entrer une valeur de c:" << endl;
	cin >>c;
	
	double delta(b * b - 4.0 * a * c);
	if (delta < 0.0){
		cout << "IL n'y a pas de solution réel" << endl;
	}
	else{
		if (delta==0){
			cout << "La solution est :" << -b / (2.0*a) << endl;
		}
		else{
			cout << "Les solutions sont:" << (-b-sqrt(delta)/(2.0*a)) << "et" << (-b+sqrt(delta)/(2*a)) << endl;
		}
	}
		
	return 0;
}



