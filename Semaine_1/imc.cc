#include <iostream>
using namespace std;

double p;
double t;
double imc;

int main()
{
	cout << "Veuillez rentrer votre poids en kg :" << endl;
	cin >> p;
	cout << "Veuillez rentrer votre taille en cm " << endl;
	cin >> t;
	
	t=t/100;
	imc= p / (t * t);
	
	cout << "Votre indice de masse corporelle est:" << imc << endl;
	return 0;
}



