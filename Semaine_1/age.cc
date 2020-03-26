#include <iostream>
using namespace std;

int age;
int annee;
const int annee_en_cours=2018;

int main()
{
	cout << "Veuillez entrer votre age" << endl;
	cin >> age;
	
	annee=annee_en_cours - age;
	
	cout << "Votre annee de naissance est : " << annee << endl;
	return 0;
		
}

