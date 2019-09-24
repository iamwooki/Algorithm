/*
Heap

CBT,
1차원 배열에 표현
optimal, 깊이가 logn을 가진다 O(logn)
*/


#include <iostream>
#pragma warning(disable:4996)
using namespace std;

typedef struct Heap {
	int S[1001];
	int heapsize;
};

int output[1001];
void siftdown(Heap &H, int i) {
	int siftkey = H.S[i];
	int parent = i;
	bool found = false;
	int smallchild;

	while ((2 * parent <= H.heapsize) && !found) {
		if ((2 * parent < H.heapsize) && (H.S[2 * parent] > H.S[2 * parent + 1]) ) smallchild = 2 * parent + 1;
		else smallchild = 2 * parent;
		if (siftkey > H.S[smallchild]) {
			H.S[parent] = H.S[smallchild];
			parent = smallchild;
		}
		else found = true;
	}
	H.S[parent] = siftkey;
}

void makeheap(int n, Heap &H) {
	H.heapsize = n;
	for (int i = n / 2; i > 0; --i) {
		siftdown(H, i);
	}
}
int root(Heap &H) {
	int keyout = H.S[1];
	H.S[1] = H.S[H.heapsize];
	H.heapsize = H.heapsize - 1;
	siftdown(H, 1);
	return keyout;
}
void removeKeys(int n, Heap& H) {
	for (int i = 1; i <= n; ++i) {
		output[i] = root(H);
	}
}

void print(int arr[], int N) {
	for (int i = 1; i <= N; ++i) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}


void heapsort(int n, Heap& H) {
	makeheap(n, H);
	print(H.S, n);
	Heap temp = H;
	removeKeys(n, H);
	print(output, n);
	H = temp;
}

void insert(Heap &H, int value) {
	int child = ++H.heapsize; //값 추가를 위해 인덱스를 하나 먼저 늘려준다.
	int parent = child / 2;
	/*
	while ( (H.S[child] < H.S[parent]) && parent>0) {
		swap(H.S[child], H.S[parent]);
		child = parent;
		parent /= 2;
	}
	*/
	
	while ( (value < H.S[parent]) && parent > 0) {
		H.S[child] = H.S[parent];
		child = parent;
		parent /= 2;
	}

	H.S[child] = value;
	
	print(H.S, H.heapsize);
}

int main() {
	FILE *f = fopen("input.txt", "r");
	Heap H;
	if (f == NULL) return 1;

	fscanf(f, "%d", &H.heapsize);
	for (int i = 1; i <= H.heapsize; ++i) {
		fscanf(f, "%d", &H.S[i]);
	}

	
	heapsort(H.heapsize,H);
	insert(H, 50);
	root(H);
	print(H.S, H.heapsize);
	insert(H, 11);
	insert(H, 1);
	root(H);
	print(H.S, H.heapsize);
	system("PAUSE");
	
	return 0;
}