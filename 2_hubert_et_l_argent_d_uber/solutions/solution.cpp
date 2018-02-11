// In this solution we will use a map (a C++ associative array).
// See http://www.cplusplus.com/reference/map/map/

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	int M, N;
	map<string, int> price;
	string data_str;
	int data_int;
	int total = 0;

	cin >> M;
	for(int i = 0; i < M; i++) {
		cin >> data_str >> data_int;
		price.insert(pair<string, int>(data_str, data_int));
	}

	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> data_str >> data_int;
		total += data_int * price[data_str];
	}

	cout << total << endl;

	return 0;
}