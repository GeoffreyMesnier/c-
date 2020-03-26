#include <iostream>
#include <ctime>

// pour les nombres aléatoires
#include <random>
#include <cstring> // strlen

using namespace std;

// ======================================================================
// Couleur au hasard
std::uniform_int_distribution<int> distribution;
std::default_random_engine generateur(time(NULL)); /* NOT using std::random_device since not
                                                    * all compilers seems to support it :-( */

char tirer_couleur()
{
  static const char* const couleurs = ".RGBCYM";
  static const int nb = strlen(couleurs) - 1;

  return couleurs[distribution(generateur,
                               std::uniform_int_distribution<int>::param_type {0, nb})];
}

// ======================================================================
char poser_question()
{
  char lu(' ');
  cout << "Entrez une couleur : ";
  cin >> lu;
  return lu;
}

// ---- prototype -------------------------------------------------------
bool couleur_valide(char c);

// ======================================================================
char lire_couleur()
{
  char lu(poser_question());
  while (not couleur_valide(lu)) {
    cout << "'" << lu << "' n'est pas une couleur valide." << endl;
    cout << "Les couleurs possibles sont : ., R, G, B, C, Y ou M." << endl;
    lu = poser_question();
  }
  return lu;
}

// ======================================================================
void afficher_couleurs(char c1, char c2, char c3, char c4)
{
  cout << ' ' << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4;
}

// ======================================================================
void afficher(int nb, char c)
{
  while (nb-- > 0) {
    cout << c;
  }
}

// ---- prototype -------------------------------------------------------
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4);

// ======================================================================
void afficher_coup(char c1, char c2, char c3, char c4,
                   char r1, char r2, char r3, char r4)
{
  afficher_couleurs(c1, c2, c3, c4);
  cout << " : ";
  afficher_reponses(c1, c2, c3, c4,
                    r1, r2, r3, r4);
  cout << endl;
}

// ======================================================================
void message_gagne(int nb_coups)
{
  cout << "Bravo ! Vous avez trouvé en " << nb_coups << " coups." << endl;
}

// ======================================================================
void message_perdu(char c1, char c2, char c3, char c4)
{
  cout << "Perdu :-(" << endl;
  cout << "La bonne combinaison était : ";
  afficher_couleurs(c1, c2, c3, c4);
  cout << endl;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

// ======================================================================
bool couleur_valide(char c)
{
	bool resultat(false);
	
  if ( c =='.' or c == 'R' or c== 'G' or c== 'B' or c=='C' or c=='Y' or c=='M')
  {
	  resultat=true;
  }
  return resultat;
}



// ======================================================================
bool verifier(char couleur_recu,char& couleur_ref,int& scorever)
{   
	bool resultat(false);
	if(couleur_recu==couleur_ref)
	{
		++scorever;
		couleur_ref='x';
		resultat=true;
    } 
    return resultat;
}


// ======================================================================
void apparier(char couleur_recu,char& coulref1,char& coulref2,char& coulref3,int& scoreapp)
{ 
	bool resultat;
	resultat=verifier(couleur_recu,coulref1,scoreapp);
	if (resultat == false)
	{
		resultat=verifier(couleur_recu,coulref2,scoreapp);
		if (resultat == false)
		{
			verifier(couleur_recu,coulref3,scoreapp);
	    }
    }
	
}


// ======================================================================
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4)
{
	int nb_exact(0);
	int nb_place(0);
	int nb_reste(0);
	
	//Combinaison exact
	//test combinaison exacte 1
	if (c1 == r1)
	{
		c1='y';
		++nb_exact;
    }
    
    //test combinaison exacte 2
	if (c2 == r2)
	{
		c2='y';
		++nb_exact;
    }
        //test combinaison exacte 3
	if (c3 == r3)
	{
		c3='y';
		++nb_exact;
    }
        //test combinaison exacte 4
	if (c4 == r4)
	{
		c4='y';
		++nb_exact;
    }
    //Combinaison placé 1
    if (c1 != 'y')
    {
		apparier(c1,r2,r3,r4,nb_place);
    }
    //Combinaison placé 2
    if (c2 != 'y')
    {
		apparier(c2,r1,r3,r4,nb_place);
    }
    
    //Combinaison placé 3
    if (c3 != 'y')
    {
		apparier(c3,r1,r2,r4,nb_place);
    }
    
    //combinaison placé 4
    if (c4 != 'y')
    {
		apparier(c4,r1,r2,r3,nb_place);
    }
    nb_reste=4-nb_exact-nb_place;
    afficher(nb_exact,'#');
    afficher(nb_place,'+');
    afficher(nb_reste,'-');
}

// ======================================================================
bool gagne(char c1, char c2, char c3, char c4,
           char r1, char r2, char r3, char r4)
{
	bool resultat(false);
	if (c1 == r1 and c2 == r2 and c3 == r3 and c4 == r4)
	{
		resultat=true;
	}
	return resultat;
}

// ======================================================================
void jouer(int nbmax=8)
{
	//tirage au sort de la combinaison
	char r1(tirer_couleur());
	char r2(tirer_couleur());
	char r3(tirer_couleur());
	char r4(tirer_couleur());
	char c1;
	char c2;
	char c3;
	char c4;
	int nb_coup(0);
	//boucle de jeux
	do{
	   nb_coup++;
	   
	   c1=lire_couleur();
	   c2=lire_couleur();
	   c3=lire_couleur();
	   c4=lire_couleur();
	   
	   afficher_coup(c1,c2,c3,c4,r1,r2,r3,r4);
	   	
		
    }while(not gagne(c1,c2,c3,c4,r1,r2,r3,r4) and nb_coup < nbmax-1);
    
    if (nb_coup>nbmax-1)
    {
		message_perdu(r1,r2,r3,r4);
	}
	else
	{
		message_gagne(nb_coup);
	}	
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  jouer();
  return 0;
}
