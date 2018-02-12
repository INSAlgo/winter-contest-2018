#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Gives the size of the path beginning from coordinates (i, j) in map M
// of size C*C.
int diversity(vector<string> M, int C, int i, int j) {
	bool visited[C][C];
	for(int a = 0; a < C; a++)
		for(int b = 0; b < C; b++)
			visited[a][b] = false;

	int length = 0;
	while(i >= 0 && j >= 0 && i < C && j < C && (!visited[i][j])) {
		length++;
		visited[i][j] = true;
		switch(M[i][j]) {
			case '<':
				j--;
				break;
			case '>':
				j++;
				break;
			case '^':
				i--;
				break;
			case 'v':
				i++;
				break;
		}
	}
	return length;
}


int main() {
	int C;
	vector<string> M;
	string data_str;

	cin >> C;
	for(int i = 0; i < C; i++) {
		cin >> data_str;
		M.push_back(data_str);
	}

	int maxdiversity = 0;
	int currentdiversity;
	for(int i = 0; i < C; i++) {
		for(int j = 0; j < C; j++) {
			currentdiversity = diversity(M, C, i, j);
			if(currentdiversity > maxdiversity)
				maxdiversity = currentdiversity;
		}
	}

	cout << maxdiversity << endl;

	return 0;
}