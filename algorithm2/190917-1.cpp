/*
20
1 5 45
2 20 40
3 13 38
4 11 35
5 9 33
6 1 30
7 2 28
8 4 25
9 5 20
10 16 19
11 14 17
12 8 15
13 3 10
14 1 9
15 12 8
16 10 7
17 13 4
18 18 3
19 8 2
20 6 1

*/
#include <iostream>
#pragma warning(disable:4996)
using namespace std;

int parent[1000];
int schedule[1000];

int collapsingFind(int i) {
	int r;
	for (r = i; parent[r] >= 0; r = parent[r]); //find root
	while (i != r) {
		int s = parent[i];
		parent[i] = r;
		i = s;
	}
	return r;
}

int simpleUnion(int i) {
	return collapsingFind(i-1);
}

int main() {
	FILE* f = fopen("input.txt", "r");
	if (f == NULL) return 1;
	int N;
	fscanf(f, "%d", &N);

	//init
	parent[0] = N;
	for (int i = 1;i <= N;++i) parent[i] = -1;

	//operation
	for(int i=0;i<N;++i){
		int job, deadline, profit;
		fscanf(f,"%d %d %d", &job, &deadline, &profit);

		int index = collapsingFind(deadline);
		schedule[index] = job;
		parent[index] = simpleUnion(index);
	}

	for (int i = 1;i <= N;++i) {
		cout << schedule[i] << " ";
	}
	system("PAUSE");
	return 0;
}