#include <iostream>
#include <vector>
using namespace std;





int main ()
{
	//Declare un tableau pouvant contenir autant de note que d'éléves
	vector <double> notes;
	
	
	double somme (0.0);
	double moyenne (0.0);
	//Lecture des notes
	double note_lue(0.0);
	cout << "Entrer les notes des éléves" << endl;
	do{
		cout << "Entrer la note de l'éleves" << notes.size()+1 <<":"
		     << "Notes < 0 pour finir" << endl;
		cin >> note_lue;
		//Note valable
		if (note_lue >= 0){
			 notes.push_back(note_lue);
			 somme+=note_lue;
			}     
		}
	while( note_lue >= 0);
		//Calcul de la moyenne
		moyenne=somme / notes.size();
		cout << "Moyenne de classe : " << moyenne << endl;
		for(size_t i(0); i< notes.size() ;i++){
			cout << "note de l'éleve " << i+1 << "note : " << notes[i]
			<< "ecart avec la moyenne : " <<  notes[i] - moyenne << endl; 
		}
	
	return 0;
}



