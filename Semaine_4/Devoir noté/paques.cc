#include <iostream>
using namespace std;




int demander_annee();
void affiche_date(int annee,int nb_jour);
int date_Paques(int annee);



int main()
{
  int annee(0);
  int nb_jour(56);
  //Récupere l'année à l'utilisateur
  annee=demander_annee();
  //Calcul du jour
  nb_jour=date_Paques(annee);
  //Affichage résultat
  affiche_date(annee,nb_jour);
  
  return 0;
}




int demander_annee()
{
	int annee_renseigner;
	//demande l'année
	do{
	cout << "Entrez une annee (1583-4000) : ";
	cin >> annee_renseigner;	
		
    }while(annee_renseigner <1583 or annee_renseigner >4000);
    
    
    return annee_renseigner;
}

void affiche_date(int annee,int nb_jour)
{
	cout << "Date de paques en " << annee << " : ";
	if (nb_jour <= 31)
	{
		cout << nb_jour << " " << "mars" << endl; 
    }
	else
	{
		nb_jour=nb_jour-31;
		cout << nb_jour << " " << "avril" << endl;
    }
}

int date_Paques(int annee)
{
	int siecle(0);
	int p(0);
	int q(0);
	int M(0);
	int N(0);
	int d(0);
	int e(0);
	int jour(0);
	
	siecle= annee / 100;
	p = (13 + 8 * siecle)/25;
	q = siecle/4;
	M = (15 - p + siecle -q)%30;
	N = 4 + siecle - (q % 7);
	d = (M + 19 * (annee % 19)) % 30 ;
	e =(2 * (annee % 4) + 4 * (annee % 7) + 6 * d + N) % 7;
	jour= e + d + 22; 
	
	if (e == 6)
	{
		if ((d == 29) or (d==28 and (11*(M+1)%30)<19))
		{
			jour=jour-7;
	    }
	}
	
	return jour;			
}





