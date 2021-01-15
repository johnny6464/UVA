#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;

int nextStep(LL origin, int Z, int I, int M) {
	return (origin * Z + I) % M;
}

int main() {
	int Z, I, M, L, cases = 0;
	while (cin >> Z >> I >> M >> L && (Z || I || M || L)) {
		int turtle = L, rabbit = L;
		do {
			turtle = nextStep(turtle, Z, I, M);
			rabbit = nextStep(nextStep(rabbit, Z, I, M), Z, I, M);
		} while (turtle != rabbit);

		int length = 0;
		do {
			turtle = nextStep(turtle, Z, I, M);
			length++;
		} while (turtle != rabbit);
		cout << "Case " << ++cases << ": " << length << endl;
	}
	return 0;
}