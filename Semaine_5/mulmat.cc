#include <iostream>
#include <vector>
using namespace std;

vector<vector<double>> lire_matrice();

vector<vector<double>> multiplication(const vector<vector<double>>& Mat1,
									  const vector<vector<double>>& Mat2);
									  
void affiche_matrice(const vector<vector<double>>&M);									  
									  

int main ()
{ 
  vector<vector<double>> M1;
  vector<vector<double>> M2;
  cout << "Rentrer les informations pour la matrice 1" << endl;
  M1=lire_matrice();
  cout << "Rentrer les informations pour la matrice 2" << endl;
  M2=lire_matrice();
  if (M1[0].size() != M2.size()){
	  cout << "Impossible de multiplier les matrices" << endl;
  }
  else{
	  affiche_matrice(multiplication(M1,M2));
	  }
  
}




vector<vector<double>> lire_matrice()
{
  	
  unsigned int lignes;
  unsigned int colonnes;
 
  do {
	cout << "Entrer le nombre de lignes :" << endl;
	cin >> lignes;
   }while (lignes <1);
   
   do {
	   cout << "Entrer le nombre de colonnes:" << endl;
	   cin >> colonnes;
	}while (colonnes <1);
	
	
	vector<vector<double>> M(lignes,vector<double>(colonnes));
	
	for (unsigned int i(0);i<lignes;++i){
		for (unsigned j(0);j<colonnes;++j){
			cout << " M[" << i+1 <<","<<j+1 << "=" <<endl;
			cin >> M[i][j];
		}
	}
	 		 	
  return M;
}

void affiche_matrice(const vector<vector<double>>&M)	
{ for (auto lignes : M){
		for (auto elements : lignes){
			cout << elements << " ";
		}
		cout << endl;
	}	
}

vector<vector<double>> multiplication(const vector<vector<double>>& M1,
									  const vector<vector<double>>& M2)
{
	vector<vector<double>> resultat(M1.size(),vector<double> (M2[0].size()));
	for (size_t i(0);i< M1.size();++i){
		for (size_t j(0);j<M2[0].size();++j){
			for (size_t k(0);k<M2.size();++k)
			resultat[i][j] += M1[i][k] * M2[k][j];
		}
	}
	return resultat;
}



