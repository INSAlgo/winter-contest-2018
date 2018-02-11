#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;

string tidy_up(string recipe) {
	map<char, int> occurences;
	for(int i = 0; i < 26; i++) {
		occurences['a' + i] = 0;
	}
	for(size_t i = 0; i < recipe.size(); i++) {
		occurences[recipe[i]] += 1;
	}

	string odd;
	string left;
	left.reserve(10000);
	for(int i = 0; i < 26; i++) {
	    const char current = 'a' + i;
		if(occurences[current] % 2) {
			if(odd.size())
				return "-";
			else
				odd += current;
		}
		left.resize(left.size() + occurences[current] / 2, current);
	}

    left += odd;
	copy(odd.size() ? next(left.rbegin()) : left.rbegin(), left.rend(), back_inserter(left));
	return left;
}

int main() {
	int N;
	string recipe;
	cin >> N;
	for(int i=0; i < N; i++) {
		cin >> recipe;
		cout << tidy_up(recipe) << endl;
	}
	return 0;
}
