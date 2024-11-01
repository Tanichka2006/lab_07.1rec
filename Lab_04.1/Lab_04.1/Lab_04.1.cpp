#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	// перший спосіб
	int k;
	int i;
	double S;
	cout << "k = "; cin >> k;
	S = 0;
	i = k;
	while (i <= 15)
	{
		S += cos(i)/(1 + (sin(i)* sin(i)));
		i++;
	}
	cout << "S = " << S << endl;
	// другий спосіб
	S = 0;
	i = k;
	do {
		S += cos(i) / (1 + (sin(i) * sin(i)));
		i++;
	} while (i <= 15);
	cout << "S = " << S << endl;
	// третій спосіб
	S = 0;
	for (i = k; i <= 15; i++)
	{
		S += cos(i) / (1 + (sin(i) * sin(i)));
		
	}
	cout << "S = " << S << endl;
	// четвертий спосіб
	S = 0;
	for (i = 15; i >= k; i--)
	{
		S += cos(i) / (1 + (sin(i) * sin(i)));
	
	}
	cout << "S = " << S << endl;

	return 0;
}
