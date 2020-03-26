#include <iostream>
#include <vector>
#include <string>


using namespace std;



 int somme_consecutifs_max(vector<int> tab);
vector<int> lignes_max(vector<vector<int>> tab2d);
vector<vector<int>> tranches_max(vector<vector<int>> tab2d);


int main()
{  

	
	return 0;
}

//Calcul du max de la ligne
int somme_consecutifs_max(vector<int> tab)
{
	int somme(0);
	int somme_max(0);
	
	for(auto elemt : tab)
	{
		if (elemt != 0)
		{
			somme=somme+elemt;
			if (somme > somme_max)
			{
				somme_max=somme;
			}
	    } 
	    else
	    {
			somme=0;
	    }
    }
    return somme_max;
	
}
vector<int> lignes_max(vector<vector<int>> tab2d)
{
	int somme_max(0);
	int somme(0);
	vector<int> tabresult;
	
	for(size_t i(0); i<tab2d.size();i++)
	{
		somme=somme_consecutifs_max(tab2d[i]);
		
		if (somme == somme_max)
		{
			tabresult.push_back(i);
		}
		if (somme > somme_max)
		{
			tabresult.clear();
			tabresult.push_back(i);
			somme_max=somme;
		}
	}
	return tabresult; 
}

vector<vector<int>> tranches_max(vector<vector<int>> tab2d)
{
	vector<int> ligne;
	vector<vector<int>> result;
	ligne=lignes_max(tab2d);
	for(auto elemnt : ligne)
	{
		result.push_back(tab2d[elemnt]);
	}
	return result;
}



