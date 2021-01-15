#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;

int nextStep(LL origin, int a, int b, int N) {
	return (((origin * origin) % N * a) + b) % N;;
}

int main() {
	int N, a, b;
	while (cin >> N && N) {
		cin >> a >> b;

		int turtle = 0, rabbit = 0;
		do {
			turtle = nextStep(turtle, a, b, N);
			rabbit = nextStep(nextStep(rabbit, a, b, N), a, b, N);
		} while (turtle != rabbit);

		int length = 0;
		do {
			turtle = nextStep(turtle, a, b, N);
			length++;
		} while (turtle != rabbit);
		cout << N - length << endl;
	}
	return 0;
}