#include <iostream>
#include <vector>
#include <string>


using namespace std;





void genereLettre(bool sexe,string destinataire,string sujet,int jour,int mois,string politesse,string auteur);
 

int main()
{   
	
	genereLettre(1,"Mireille","votre cours",18,12,"Amicalement","John");
	genereLettre(2,"John","votre cdemande de rendez vous",16,12,"Sincerement","Mireille");
	return 0;
}


void genereLettre(bool masculin,string destinataire,string sujet,int jour,int mois,string politesse,string auteur){
string formulation;
switch (masculin){
	case 0 :
		formulation="chere";
		break;
	case 1 : 
		formulation="cher";
		break;
}




cout << "Bonjour " << formulation<<" "<< destinataire << endl;
cout << "Je vous écris à propos de votre"<< sujet <<endl;
cout << "Il faudrait que nous nous voyons le"<<jour<<"/"<<mois<< "pour en discuter." << endl;
cout << "Donnez-moi vite de vos nouvelles !" << endl;
cout << politesse <<"," << auteur << "." << endl;
}


