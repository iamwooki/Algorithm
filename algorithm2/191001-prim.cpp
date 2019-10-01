#include <iostream>
#pragma warning(disable:4996)
#define INF 987654321
using namespace std;

typedef struct NODE {
	int vertex;
	int weight;
	NODE *link;
	NODE(int vertex = 0, int weight = 0) { //constructor
		this->vertex = vertex;
		this->weight = weight;
		link = NULL;
	}
};


typedef struct Heap {
	NODE S[1001];
	int heapsize;
};

void insert(Heap &H, int r, int dr) {
	NODE vertex; vertex.vertex = r; vertex.weight = dr;

	//cout << vertex.vertex << " " << vertex.weight << endl;
	int child = ++H.heapsize; //값 추가를 위해 인덱스를 하나 먼저 늘려준다.
	int parent = child / 2;

	while ((vertex.weight < H.S[parent].weight) && parent > 0) {
		H.S[child] = H.S[parent];
		child = parent;
		parent /= 2;
	}

	H.S[child] = vertex;
}



void siftdown(Heap &H, int i) {
	NODE siftkey = H.S[i];
	int parent = i;
	bool found = false;
	int smallchild;

	while ((2 * parent <= H.heapsize) && !found) {
		if ((2 * parent < H.heapsize) && (H.S[2 * parent].weight > H.S[2 * parent + 1].weight)) smallchild = 2 * parent + 1;
		else smallchild = 2 * parent;
		if (siftkey.weight > H.S[smallchild].weight) {
			H.S[parent] = H.S[smallchild];
			parent = smallchild;
		}
		else found = true;
	}
	H.S[parent] = siftkey;
}


NODE extract_min(Heap &H) {
	NODE keyout = H.S[1];
	H.S[1] = H.S[H.heapsize];
	H.heapsize = H.heapsize - 1;
	siftdown(H, 1);
	return keyout;
}

NODE G[50][2]; int V, E;
int D[1000]; int FLAG[1000]; int P[1000];
int ans = 0;
void insert_node(int from, int to, int weight) {

	//0 : 가장 뒤의 노드를 가르 킴, 1: 첫번재 노드를 가르킴
	//from
	NODE *fromNode = new NODE(to, weight);
	if (G[from][0].link == NULL) {//최초
		G[from][1].link = fromNode;
		G[from][0].link = fromNode;
	}
	else { //그다음부터
		G[from][0].link->link = fromNode;
		G[from][0].link = fromNode;
	}
	//to
	NODE *toNode = new NODE(from, weight);
	if (G[to][0].link == NULL) { //최초
		G[to][1].link = toNode;
		G[to][0].link = toNode;
	}
	else {
		G[to][0].link->link = toNode;
		G[to][0].link = toNode;
	}
}

// n :parent d: distance (weight)
//연결리스트 u 
void prim(int r) { //w :weight, r : root
	//init 
	Heap PQ; PQ.heapsize = 0;

	for (int u = 1; u <= V; ++u) { //u : vertex node
		D[u] = INF;
		FLAG[u] = 0;
	}
	D[r] = 0; P[r] = NULL;
	insert(PQ, r, D[r]);

	while (PQ.heapsize != 0) { //pq is not empty
		NODE u = extract_min(PQ);
		if (FLAG[u.vertex] == 0) {
			NODE *v = &G[u.vertex][1];
			while (v != NULL) {
				if (FLAG[v->vertex] == 0 && v->weight < D[v->vertex]) {
					P[v->vertex] = u.vertex;
					D[v->vertex] = v->weight;
					insert(PQ, v->vertex, D[v->vertex]);
				}

				v = v->link; //next
			}
		}
		FLAG[u.vertex] = 1;



		for (int i = 1; i <= PQ.heapsize; ++i) {
			cout << PQ.S[i].weight << " ";
		}
		cout << endl;
	}

}
void print(int V) {
	for (int i = 1; i <= V; ++i) {
		NODE *hp = G[i][1].link;
		cout << i << " ";
		while (hp != NULL) {
			cout << "-[" << hp->vertex << " " << hp->weight << "]";
			hp = hp->link;
		}
		cout << '\n';
	}
	cout << '\n';
}
void print_nearest() {
	for (int i = 1; i <= V; ++i) {
		cout << P[i] << ' ';
	}
	cout << endl;
}

int main() {
	//file
	FILE *f = fopen("input.txt", "r");
	if (f == NULL) return 1;

	//insert
	fscanf(f, "%d %d", &V, &E);
	for (int i = 0; i < E; ++i) {
		int from, to, weight;
		fscanf(f, "%d %d %d", &from, &to, &weight);
		insert_node(from, to, weight);

	}
	//print(V);
	prim(1);
	print_nearest();
	int sum = 0;
	for (int i = 1; i <= V; ++i) {
		sum += D[i];
	}
	cout << sum << endl;
	system("PAUSE");
	return 0;
}