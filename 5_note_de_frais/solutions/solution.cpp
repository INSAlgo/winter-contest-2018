// For the knapsack we want to work with integers, so we will multiply floats
// by 100 (cf precision in the problem statement), and divide output by 100.

#include <iostream>
#include <iomanip>
#include <set>
#include <string>

using namespace std;

int main() {
	int B, N;
	float data_float;
	string data_string;
	set<int> prices;

	cin >> data_float;
	B = 100 * data_float;

	cin >> N;

	for(int i = 0; i < N; i++) {
		cin >> data_string >> data_float;
		prices.insert(100 * data_float);
	}

	bool possible[B+1];
	possible[0] = true;

	int maxp = 0;
	for(int i = 1; i <= B; i++) {
		possible[i] = false;
		for(int price: prices) {
			if(price <= i && possible[i-price]) {
				possible[i] = true;
				break;
			}
		}
		if(possible[i])
			maxp = i;
	}

	cout << fixed << setprecision(2) << ((float) maxp)/100 << endl;

	return 0;
}