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
int WU[1000];
int pivot;
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

void weightUnion(int i, int j) {
	int temp = parent[i] + parent[j];
	if (parent[i] > parent[j]) { //j가 root
		parent[i] = j;
		parent[j] = temp;
	}
	else { //i가 root
		parent[j] = i;
		parent[i] = temp;
		WU[i] = WU[j]; //실질적으로 다음에 값이 들어가는 인덱스
	}
	
}


int main() {
	FILE* f = fopen("input.txt", "r");
	if (f == NULL) return 1;
	int N;
	fscanf(f, "%d", &N);

	//init
	parent[0] = N;
	for (int i = 1;i <= N;++i) {
		parent[i] = -1;
		WU[i] = i;
	}
	
	//operation
	for(int i=0;i<N;++i){
		int job, deadline, profit;
		fscanf(f,"%d %d %d", &job, &deadline, &profit);

		int index = collapsingFind(deadline); //위치하는 바의 부모 노드
		schedule[WU[index]] = job;

		int next_index = collapsingFind(WU[index] - 1);
		weightUnion(index, next_index);

	}

	for (int i = 1;i <= N;++i) {
		cout << schedule[i] << " ";
	}cout << endl<<"WU: ";

	for (int i = 1;i <= N;++i) {
		cout << WU[i] << " ";
	}cout << endl<<"parent : ";

	for (int i = 1;i <= N;++i) {
		cout << parent[i] << " ";
	}cout << endl;
	system("PAUSE");
	return 0;
}