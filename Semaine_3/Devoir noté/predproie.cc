#include <iostream>
#include <iomanip> // pour setprecision()
using namespace std;

int main()
{
  // Réduire le format d'affichage
  cout << setprecision(4);

  // Paramètres
  double taux_croissance_lapins(0.3);
  double taux_attaque(0.01);
  double taux_croissance_renards(0.008);
  double taux_mortalite(0.1);
  int duree(50);

  double renards_i(0.0);
  double lapins_i(0.0);

  /*****************************************************
   * ComplÃ©ter le code Ã  partir d'ici
   *****************************************************/
  double taux_attaque_initial(0.0);
  double taux_attaque_final(0.0);
 
  // ===== PARTIE 1 =====
  // Saisie des populations initiales
	
  do{	
	cout << "Combien de renards au départ (>= 2) ? ";
	cin >> renards_i;
	}while(renards_i<2);

  do{	
  cout << "Combien de lapins au départ  (>= 5) ? ";
  cin >> lapins_i;
	}while(lapins_i <5);
	
 
  // ===== PARTIE 2 =====
  // PremiÃ¨re simulation
  
for (double j(taux_attaque_initial);j<taux_attaque_final;j=j+taux_attaque)
{ 
  bool extinction_lapin(false);
  bool extinction_renard(false);
  bool remonte_lapin(false);
  bool remonte_renard(false);
  bool disparition_lapin(false);
  bool disparition_renard(false);
  cout <<  endl << "***** Le taux d'attaque vaut "<< j * 100 << "%" <<  endl;
  double nb_renards(renards_i);
  double nb_lapins (lapins_i);
  double n_nb_lapins(0);
  double n_nb_renards(0);
  bool sortie(true);
  int mois(0);
  //Calculs
  
	for(int i(1);sortie && i<=duree;++i){
		//Calculs des nouvelles populations
		n_nb_lapins=nb_lapins*(1.0 + taux_croissance_lapins - j * nb_renards);
		if(n_nb_lapins<0)
		{
			n_nb_lapins=0;
		}
		n_nb_renards=nb_renards*(1.0 + j * nb_lapins * taux_croissance_renards - taux_mortalite);
		if (n_nb_renards < 0)
		{
			n_nb_renards=0;
		}
		nb_lapins=n_nb_lapins;
		nb_renards=n_nb_renards;
		//cout << "apres " << i << " mois, il y a " << nb_lapins << " lapins et " << nb_renards << " renards" << endl;  
       
		//lapins	
		//Test extinction lapins
		if (nb_lapins < 5){
			extinction_lapin=true;
		}
		// test remonté des lapins
		if(extinction_lapin)
		{      
			if (nb_lapins>5)
			{
				remonte_lapin=true;
		    }
		}
		//Test de la disparition des lapins
		if(nb_lapins<2) {
			nb_lapins=0;
			disparition_lapin=true;
		}
		//Renards
		//Test de l'extinction des		
		if (nb_renards < 5){
			extinction_renard=true;
		}


		 if(extinction_renard)
		 {
			if (nb_renards > 5)
			{
				remonte_renard=true;
			 }
		  }
			
		  if (nb_renards < 2) 
		  {
			  nb_renards=0;
			  disparition_renard=true;
		  }	
		  if (nb_lapins==0 and nb_renards == 0)
		  {
			  sortie= false;
		  }
	cout << "apres " << mois << " mois, il y a " << nb_lapins << " lapins et " << nb_renards << " renards" << endl; 	  
		  mois=i;
	  }		
  
 
     
  // ===== PARTIE 3 =====
  // Variation du taux d'attaque
  //Affichage des resultats
  
   do{
  cout << "taux d'attaque au départ en % (entre 0.5 et 6) ? ";
  cin >> taux_attaque_initial;
  }while(taux_attaque_initial < 0.5 or taux_attaque_initial > 6);
  
  do{
  cout << "taux d'attaque à la fin  en % (entre " << taux_attaque_initial; 
  cout << " et 6) ?";
  
  cin >> taux_attaque_final;
  }while(taux_attaque_final < taux_attaque_initial or taux_attaque_final > 6);
  
  taux_attaque_initial=taux_attaque_initial/100;
  taux_attaque_final=taux_attaque_final/100;		

  //Renards 
  if(extinction_renard == true)
  {  	
	cout << "Les renards ont été en voie d'extinction" << endl;
	if(remonte_renard == true){
		cout << "mais la population est remontée ! Ouf !" << endl;
	}	
  }
 if (disparition_renard == true)
{	
	cout << "et les renards ont disparu :-(" << endl;
}
  //Lapins
  if (extinction_lapin == true)
  {
	cout << "Les lapins ont été en voie d'extinction" << endl;
	if (remonte_lapin == true)
	{	
		cout << "mais la population est remontée ! Ouf !" << endl;
	}
  }
  
	if (disparition_lapin)
	{   
	  cout << "et les lapins ont disparu :-(" << endl;
	}

	if (extinction_renard == false and remonte_renard ==  false and remonte_renard == false and extinction_lapin == false and remonte_lapin == false and disparition_lapin == false)
	{ 
	   cout << "Les lapins et les renards ont des populations stables." << endl;
	}
}
  /*******************************************
   * Ne rien modifier aprÃ¨s cette ligne.
   *******************************************/

  return 0;
}
