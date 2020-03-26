#include <iostream>
using namespace std;

int separer_chiffre_gauche(int& nombre)
{
  int dix(1);
  int temp(nombre);
  while (temp >= 10) {
    dix  *= 10;
    temp /= 10;
  }
  nombre %= dix;
  return temp;
}

/*****************************************************
 * ComplÃ©ter le code Ã  partir d'ici
 *****************************************************/
 void ajouter_chiffre_droit(int& nombre,int chiffre);
 int separer_chiffre_gauche(int& nombre);
 void dire_chiffre(int& nombre, int repetitions_chiffre, int chiffre);
 int lire_et_dire(int nombre);
 void repeter_lire_et_dire(int& nombre, int fois);
 
 

void ajouter_chiffre_droit(int& nombre, int chiffre)
{
	nombre *=10;
	nombre= nombre + chiffre;
}


void dire_chiffre(int& nombre, int repetitions_chiffre, int chiffre)
{
	ajouter_chiffre_droit(nombre,repetitions_chiffre);
	ajouter_chiffre_droit(nombre,chiffre);
}

int lire_et_dire(int nombre)
{	
	int resultat(0);
	int ancien_chifre(0);
	int chifre(0);
	int repetition(1);
	cout << "nombre debut: " <<nombre << endl;
	ancien_chifre=separer_chiffre_gauche(nombre);
	cout << "Resultat séparer chiffre 1 Nombre: " << nombre << " Premier Chiffre " << ancien_chifre << endl;
 	do{ 
		chifre=separer_chiffre_gauche(nombre);
		cout << "lire et dire repetition: "<< repetition <<" Nombre: "<< nombre <<" Premier Chiffre: "<< ancien_chifre<<" Deuxieme chiffre: " <<  chifre << endl;
		if(ancien_chifre==chifre){
			++repetition;
			if (nombre==0){
				dire_chiffre(resultat,repetition,ancien_chifre);
			}	
		}
		else{
			dire_chiffre(resultat,repetition,ancien_chifre);
			if ( (nombre==0) and (chifre !=0) ){
				dire_chiffre(resultat,repetition,chifre);
			}
			else{
				ancien_chifre=chifre;
				repetition=1;
			}
		}
		cout << "nombre fin boucle :" << nombre << endl;
	}while(nombre!=0);
	cout << "Resultat renvoyer" <<resultat << endl;
	return resultat;
}




/*******************************************
 * Ne rien modifier aprÃ¨s cette ligne.
 *******************************************/

void repeter_lire_et_dire(int& nombre, int fois)
{
  while (fois-- > 0) {
    nombre = lire_et_dire(nombre);
  }
}

int main()
{
  int nombre(1);
  int fois(1);
  cin >> nombre >> fois;
  repeter_lire_et_dire(nombre, fois);
  cout << nombre << endl;
  return 0;
}
