 #include <iostream>
using namespace std;

 
 
int main()
{
  cout << "Pensez à un champignon : amanite tue-mouches, pied bleu, girolle," << endl
       << "cèpe de Bordeaux, coprin chevelu ou agaric jaunissant." << endl << endl;
  
  bool reponse;
  
  cout << "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
  cin >> reponse;
  
  if (reponse)
  {
	cout << "Est-ce que votre champignon a un anneau (1 : oui, 0 : non) ? ";
	cin >> reponse;
	if (reponse)
	{
		 cout << "Est-ce que votre champignon vit en forêt (1 : oui, 0 : non) ? ";
		 cin >> reponse;
		 if (reponse)
		 {
			 cout << "==> Le champignon auquel vous pensez est ";
			 cout << "l'amanite tue-mouches"; 
	     }
	     else
	     {
			 cout << "==> Le champignon auquel vous pensez est ";
			 cout << "l'agaric jaunissant";
	     }
	}
	else
	{
		cout << "==> Le champignon auquel vous pensez est ";
		cout << "le pied bleu";
	}	
  }
  else 
  {
	 cout << "Est-ce que votre champignon a un anneau (1 : oui, 0 : non) ? ";
	 cin >> reponse;
	 if (reponse)
	 {
		  cout << "==> Le champignon auquel vous pensez est "; 
		  cout << "le coprin chevelu";
     }
     else 
     {    
		  cout << "Est-ce que votre champignon a des lamelles (1 : oui, 0 : non) ? ";
		  cin >> reponse;
		  if (reponse)
		  {
			    cout << "==> Le champignon auquel vous pensez est "; 
			    cout << "la girolle";
		  }
		  else
		  {
				cout << "==> Le champignon auquel vous pensez est "; 
			    cout << "le cèpe de Bordeaux";
		  }
     }
  }
  
 
}


  
