#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	float P, T, H;

	cin >> P;
	cin >> T;

	// P = H * (1 + T/100)
	// Therefore H = P / (1 + T/100)
	H = P / (1 + T/100);

	cout << fixed << setprecision(2) << H << endl;

	return 0;
}