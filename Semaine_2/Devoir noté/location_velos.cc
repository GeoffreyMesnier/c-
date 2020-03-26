#include <iostream>
using namespace std;

int main()
{
  cout << "Donnez l'heure de début de la location (un entier) : ";
  int debut;
  cin >> debut;

  cout << "Donnez l'heure de fin de la location (un entier) : ";
  int fin;
  cin >> fin;

  /*****************************************************
   * ComplÃ©ter le code Ã  partir d'ici
   *****************************************************/
	//Test si les heures sont correctes 
	if ((debut < 0 or debut > 24) or (fin < 0 or fin >24))
	{
		cout << "Les heures doivent être comprises entre 0 et 24 !" << endl;
		
	}
	else
	{
		//Test si il y a bien une durée	
		if ( debut == fin )
		{	
			cout << "Bizarre, vous n'avez pas loué votre vélo bien longtemps !" << endl;
		}	
		if (debut > fin)
		{	
			cout << "Bizarre, le début de la location est après la fin ..." << endl;
		}
		int heurecreuse;
		int heurepleine;
		
		//Location sans heure pleine.
		if (fin <= 7 or debut >= 17)
		{
			heurepleine=0;
			heurecreuse=fin-debut;
		}
		//Location avec des heures pleine
		else
		{
			//Que des heures pleines
			if (debut>= 7 and fin <=17)
			{
				heurecreuse=0;
				heurepleine=fin-debut;
			}
			else
			{	
				//Heure creuse et heure pleine
				//Avec heure pleine et heure creuse avant
				if (fin <= 17 and debut < 7)
				{
					heurepleine=fin-7;
					heurecreuse=7-debut;
				}
				//Avec heure pleine et heure creuse apres
				if (fin > 17 and debut >=7)
				{
					heurepleine=17-debut;
					heurecreuse=fin-17;
				}	
				//Avec heure pleine  et heure creuse avant et apres.
				if ( debut < 7 and fin > 17)
				{ 
					heurepleine=10;
					heurecreuse=7-debut+(fin-17);
				}
			}
		}
		
		cout << "Vous avez loué votre vélo pendant" << endl;
		  if (heurecreuse !=0)
		  {
			cout << heurecreuse;		
			cout <<  " heure(s) au tarif horaire de "
			   << "1"	
			   << " franc(s)" << endl;	
		  }    
		 
		  if (heurepleine !=0)
		  {
			 cout << heurepleine;
			 cout << " heure(s) au tarif horaire de "
			   << "2"
			   << " franc(s)" << endl;
		  }
		  
			   
		cout << "Le montant total à payer est de "
			 << heurepleine*2 + heurecreuse*1
			 << " franc(s)." << endl;
  }
  /*******************************************
   * Ne rien modifier aprÃ¨s cette ligne.
   *******************************************/

  return 0;
}
