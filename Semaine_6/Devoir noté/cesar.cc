#include <iostream>
#include <vector>
#include <string>


using namespace std;



char decale (char c, char debut,int decalage);
char code (char c, int d);
string code (string chaine,int decalage);
string decode (string chaine,int decalage);
 


int main()
{  
	char resultat;
	resultat=decale('G','A',-133);
	cout << resultat;
	return 0;
}

char decale (char c, char debut,int decalage)
{
    char resultat;
	//Correction si decalage négatif
	 while(decalage < 0)
	{
		decalage=decalage+26;
    }
    //Calcul résultat
    resultat=debut+(((c - debut) + decalage) % 26);
    return resultat;
}

//Décodage d'un caractere
char code ( char c, int d)
{
	//Test minuscule
	if ((c >= 'a') and  (c <= 'z'))
	{
		return (decale(c,'a',d));
    }
    //test majuscule
    	if ((c >= 'A') and  (c <= 'Z'))
	{
		return (decale(c,'A',d));
    }
    //Autre cas
    return c;
}

//codage d'une chaine
string code(string chaine, int decalage)
{
	string resultat;
	for(size_t i(0);i <= chaine.size()-1;i++)
	{
		resultat+=code(chaine[i],decalage);
    }
    return resultat;
}

//Decodage de chaine
string decode(string chaine,int decalage)
{
	string resultat;
	return(code(chaine,(-decalage)));
}


