#include <bits/stdc++.h>
// checker for towers
using namespace std;

int n;

vector<int> x, y;

int cntx[1000005], cnty[1000005];
int minx[1000005], maxx[1000005], miny[1000005], maxy[1000005];

void exitWithCode(int code){
	if (code == 0) printf("1\n"); //AC
	else if (code == 1) printf("0\n");  //WA
	exit(0);
}

inline void readAndCheckAnswer(string s) {

	if (int(s.length()) != n) exitWithCode(1);

	for (int i=0; i<int(s.length()); i++){
		if (s[i] != '0' && s[i] != '1') exitWithCode(1);
	}

	for (int i=0; i<n; i++){
		if (s[i] == '1'){
			int a = x[i], b = y[i];
			cntx[a]++, cnty[b]++;
			minx[a] = min(minx[a], b), maxx[a] = max(maxx[a], b);
			miny[b] = min(miny[b], a), maxy[b] = max(maxy[b], a);
		}
	}

	for (int i=1; i<=1000000; i++){
		if (cntx[i] > 2 || cnty[i] > 2) exitWithCode(1);
	}

	for (int i=0; i<n; i++){
		bool safe = false;
		int a = x[i], b = y[i];
		if (minx[a] <= b && b <= maxx[a]) safe = true;
		if (miny[b] <= a && a <= maxy[b]) safe = true;
		if (!safe) exitWithCode(1);
	}
}

int main(int argc, char **argv) {
	FILE *input = fopen(argv[1], "r");
	FILE *testOutput = fopen(argv[3], "r");
	FILE *output = fopen(argv[2], "r");

	for (int i=0; i<1000005; i++){
		maxx[i] = maxy[i] = -1;
		minx[i] = miny[i] = 1e7;
	}

	fscanf(input, "%d", &n);

	for (int i=0; i<n; i++){
		int a, b;
		fscanf(input, "%d%d", &a, &b);
		x.push_back(a), y.push_back(b);
	}

	char ans[2000000];

	fscanf(testOutput, "%1000000s", ans);

	string str = "";

	for (int i=0; i<n; i++){
		str += ans[i];
	}

	readAndCheckAnswer(str);

	exitWithCode(0);
}
