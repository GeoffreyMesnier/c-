#include <iostream>
#include <cmath>
using namespace std;

int main()
{	
	double x;
	
	
	

	cout << "Entrer un réel:" << endl;
	cin >> x;
	double expression1(x / (1-exp(x)));
	cout << "expression 1:" << expression1 << endl;
	if (x > 0) {
		double expression2(x*log(x)*exp(2/(x-1)));
		cout << "expression 2:" << expression2 << endl;	
	}	
	else {
		cout << "expression 2: non initialisé" << endl;	
	}	
	if (x >= 0){
		double expression3((-x-sqrt(x*x - 8*x)) / (2-x));
		cout <<"expression 3:" << expression3 << endl;
		if ( x != 0){
			double expression4(sqrt((sin(x)-x/20)*log(x*x-(1/x))));
			cout << "expression4:" << expression4 << endl;
		}
		else{
			cout << "expression4: non initialisé"<< endl;
		}
	}
	else{
		cout <<"expression 3: non initialisé"<< endl;
	}
		
	return 0;
}






