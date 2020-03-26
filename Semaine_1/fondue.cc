#include <iostream>
using namespace std;

const int base=4;
double fromage=800.0;
double eau=2.0;
double ail=2.0;
double pain=400.0;
int nbconvive;

int main()
{
	cout << "Veuillez renseigner le nombre de convive" << endl;
	cin >> nbconvive;
	
	cout << "Pour faire une fondue fribourgeoise pour " << nbconvive << " personnes" << endl;
	cout << fromage * nbconvive / base << " gr de vacherine" << endl;
	cout << eau * nbconvive / base << " dl d'eau" << endl;
	cout << ail * nbconvive / base << " gousses d'ail" << endl;
	cout << pain * nbconvive / base << " gr de pain" << endl;
	cout << "Du poivre à volonte" << endl;
	
	return 0;
}

