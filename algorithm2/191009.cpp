/*

dfs p[i] : -1 1 1 1 2 -1 3 5 8 -1
bfs p[i] : -1 1 1 1 1 -1 3 5 8 -1

*/
#include <iostream>
#pragma warning(disable:4996)
#define WHITE -1
#define GRAY  0
#define BLACK 1
#define FRONT 0
#define REAR 1
#define INF 987654321
using namespace std;

typedef struct NODE {
	int vertex;
	NODE *link;

	NODE(int vertex = 0) { //constructor
		this->vertex = vertex;
		link = NULL;
	}
};

NODE G[50][2]; int V, E;
NODE Q[2];
NODE sort;
int COLOR[1000]; int P[1000]; int D[1000];

void print(int V) {
	cout << "\n\n";
	for (int i = 1; i <= V; ++i) {
		NODE *hp = G[i][1].link;
		cout << i << " ";
		while (hp != NULL) {
			cout << "-[" << hp->vertex <<"]";
			hp = hp->link;
		}
		cout << '\n';
	}
	cout << '\n';
}
void insert_node(int from, int to) {
	//0 : 가장 뒤의 노드를 가르 킴, 1: 첫번재 노드를 가르킴
	//from
	NODE *fromNode = new NODE(to);
	if (G[from][0].link == NULL) {//최초
		G[from][1].link = fromNode;
		G[from][0].link = fromNode;
	}
	else { //그다음부터
		G[from][0].link->link = fromNode;
		G[from][0].link = fromNode;
	}
}

void DFS_visit(int u) {
	COLOR[u] = GRAY;
	NODE *v = &G[u][1];
	while (v != NULL) { //for each v in adj[u]
		if (COLOR[v->vertex] == WHITE) {
			P[v->vertex] = u;
			DFS_visit(v->vertex);
		}
		v = v->link; //next
	}
	COLOR[u] = BLACK;
	//sort
	NODE *tmp = new NODE(u);
	tmp->link = sort.link;
	sort.link = tmp;
}
void DFS() {
	//init
	for (int u = 1; u <= V; ++u) {
		COLOR[u] = WHITE;
		P[u] = -1;
	}

	for (int u = 1; u <= V; ++u) {
		if (COLOR[u] == WHITE) DFS_visit(u);
	}
}

void ENQUEUE(int v) {
	NODE *newNode = new NODE(v);
	if (Q[REAR].link == NULL) {
		Q[FRONT].link = newNode;
		Q[REAR].link = newNode;
	}
	else {
		Q[REAR].link->link = newNode;
		Q[REAR].link = newNode;
	}
}

void DEQUEUE() {
	if (Q[FRONT].link != NULL) {
		Q[FRONT].link = Q[FRONT].link->link;
	}
}

int HEAD() {
	return Q[FRONT].link->vertex;
}

int isEmpty() {
	return Q[FRONT].link == NULL ? 0 : 1;
}
void BFS() {
	for (int u = 2; u <= V; ++u) {
		COLOR[u] = WHITE;
		D[u] = INF; P[u] = -1;
	}
	COLOR[1] = GRAY; D[1] = 0; P[1] = -1;
	ENQUEUE(1);
	while (isEmpty()) {
		int u = HEAD();
		NODE *v = &G[u][1];
		while (v != NULL) { //for each v in adj[u]
			if (COLOR[v->vertex] == WHITE) {
				COLOR[v->vertex] = GRAY;
				D[v->vertex] = D[u] + 1;
				P[v->vertex] = u;
				ENQUEUE(v->vertex);
			}
			v = v->link; //next
		}
		DEQUEUE();
		COLOR[u] = BLACK;

	}
}
int main() {
	//file
	FILE *f = fopen("input.txt", "r");
	if (f == NULL) return 1;
	//insert
	fscanf(f, "%d %d", &V, &E);
	for (int i = 0; i < E; ++i) {
		int from, to;
		fscanf(f, "%d %d", &from, &to);
		insert_node(from, to);
	}	
	//adj
	print(V);
	//dfs
	DFS();
	for (int i = 1; i <= V; ++i) {
		cout << P[i] << ' ';
	}
	cout << '\n';
	//bfs
	BFS();
	for (int i = 1; i <= V; ++i) {
		cout << P[i] << ' ';
	}
	cout << '\n';
	
	//topological sort
	NODE* list = &sort;
	list = list->link;
	while (list!=NULL) {
		cout << list->vertex << ' ';
		list = list->link;
	}
	cout << endl;
	system("PAUSE");
	return 0;
}