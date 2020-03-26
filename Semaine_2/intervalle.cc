#include <iostream>
#include <cmath>
using namespace std;

int main()
{	
	double x;
	
	cout << "Entrer un réel: " << endl;
	cin >> x;
	
	if ( ((x > 0) and (x < 1)) or ((x > 2) and (x < 3)) or ((x > -10) and (x < -2)) ) {
		if ( not(x==3) or not(x==0)) {
		cout << "x appartient a I" << endl;
		}
	}
	else{
		if ((x==2) or (x==1) or (x==-10) or (x==-2) ){
			cout << "x appartient a I" << endl;
		}
		else{
			cout << "x n'appartient pas à I" << endl;
		}
		
	}
		
	return 0;
}





