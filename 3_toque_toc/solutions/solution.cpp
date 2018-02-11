#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

string tidy_up(string recipe) {
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	map<char, int> occurences;
	for(int i = 0; i < 26; i++) {
		occurences.insert(pair<char, int>(alphabet[i], 0));
	}
	for(int i = 0; i < recipe.size(); i++) {
		occurences[recipe[i]] += 1;
	}

	string odd = "";
	string left = "";
	for(int i = 0; i < 26; i++) {
		if(occurences[alphabet[i]] % 2) {
			if(odd.size())
				return "-";
			else
				odd += alphabet[i];
		}
		left.resize(left.size() + occurences[alphabet[i]] / 2, alphabet[i]);
	}

	string right = left;
	reverse(right.begin(), right.end());
	return left + odd + right;
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