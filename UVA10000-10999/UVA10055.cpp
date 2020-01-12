#include<iostream>
using namespace std;

int main() 
{
	long int myArmy = 0, oppoArmy = 0;
	while (cin >> myArmy >> oppoArmy)
	{
		cout << abs(myArmy - oppoArmy) << endl;
	}

	system("pause");
	return 0;
}