//0016
#include<iostream>
using namespace std;

int main() {
	int n, aMarks = 0, bMarks = 0, gMarks = 0;
	// recieve 1
	cin >> n;
	//char ans[n], Adrian[n], Bruno[n], Goran[n];
	char ans[100], Adrian[100], Bruno[100], Goran[100];
	//recieve ans
	for (int i = 0; i < n; i++) {
		cin >> ans[i];
	}

	//generate Adrian ,Bruno, Goran guess
	for (int i = 0; i < n; i++) {
		if (i % 3 == 0) {
			Adrian[i] = 'A';
		}
		else if (i % 3 == 1) {
			Adrian[i] = 'B';
		}
		else if (i % 3 == 2) {
			Adrian[i] = 'C';
		}
		if (Adrian[i] == ans[i]) {
			aMarks++;
		}
	}

	for (int i = 0; i < n; i++) {
		if (i % 4 == 0) {
			Bruno[i] = 'B';
		}
		else if (i % 4 == 1) {
			Bruno[i] = 'A';
		}
		else if (i % 4 == 2) {
			Bruno[i] = 'B';
		}
		else if (i % 4 == 3) {
			Bruno[i] = 'C';
		}
		if (Bruno[i] == ans[i]) {
			bMarks++;
		}
	}

	int k = 0;

	for (int i = 0; i < n; i++) {
		if (k == 0) {
			Goran[0] = 'C';
			k++;
		}
		else if (Goran[i - 1] == 'C' && k % 2 == 1) {
			Goran[i] = 'C';
			k++;
		}
		else if (Goran[i - 1] == 'C' && k % 2 == 0) {
			Goran[i] = 'A';
			k++;
		}
		else if (Goran[i - 1] == 'A' && k % 2 == 1) {
			Goran[i] = 'A';
			k++;
		}
		else if (Goran[i - 1] == 'A' && k % 2 == 0) {
			Goran[i] = 'B';
			k++;
		}
		else if (Goran[i - 1] == 'B' && k % 2 == 1) {
			Goran[i] = 'B';
			k++;
		}
		else if (Goran[i - 1] == 'B' && k % 2 == 0) {
			Goran[i] = 'C';
			k++;
		}
		if (Goran[i] == ans[i]) {
			gMarks++;
		}
	}

	//compare
	int max = aMarks;
	if (bMarks >= max) {
		max = bMarks;
	}
	if (gMarks >= max) {
		max = gMarks;
	}

	cout << max << endl;
	if (aMarks == bMarks && bMarks == gMarks) {
		cout << "Adrian" << endl << "Bruno" << endl << "Goran";
	}
	else {
		if (max == aMarks) {
			cout << "Adrian" << endl;
		}
		if (max == bMarks) {
			cout << "Bruno" << endl;
		}
		if (max == gMarks) {
			cout << "Goran" << endl;
		}
	}


	return 0;
}