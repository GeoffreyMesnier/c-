#include <iostream>
using namespace std;

int main()
{
  int debut(0);
  do {
    cout << "de (>= 1) ? ";
    cin >> debut;
  } while (debut < 1);

  int fin(0);
  do {
    cout << "a (>= " << debut << ") ? ";
    cin >> fin;
  } while (fin < debut);

  /*******************************************
   * Completez le programme a partir d'ici.
   *******************************************/
	for(int i(debut);i<=fin;++i){
		int n(0);
		int k(0);
		n=i;
		do{
			if (n%3==0){
				n+=4;
				++k;
			}
			else {
				if(n%4==0){
					n/=2;
					++k;	
				}
				else{
					n-=1;
					++k;
				}
			}
			
		}while( n!=0);
		cout << i << "->" << k << endl; 		
	}

  /*******************************************
   * Ne rien modifier apres cette ligne.
   *******************************************/

  return 0;
}


