#include <iostream>
#pragma warning(disable:4996)
using namespace std;

int parent[1000];

int collapsingFind(int i){
	int r;
	for(r=i; parent[r]>=0; r= parent[r]); //find root
	while(i!=r){
		int s = parent[i];
		parent[i] = r;
		i = s;
	}
	return r;
}
void weightUnion(int i, int j){
	int temp = parent[i] + parent[j];
	if(parent[i]>parent[j]){
		parent[i] = j;
		parent[j] = temp;
	}else{
		parent[j] = i;
		parent[i] = temp;
	}
}
int main(){
	FILE *f=fopen("input.txt","r");
	if(f==NULL) return 1;
	int node, edge;
	fscanf(f,"%d %d",&node, &edge);
	//init
	for(int i =1;i<=node;++i) parent[i] = -1;

	//operation
	int selected_edge=0; //선택된 엣지의 수
	while(selected_edge < (edge-1)){
		int _start, _end, _weight;
		fscanf(f,"%d %d %d",&_start,&_end,&_weight);

		int start_node = collapsingFind(_start);
		int end_node = collapsingFind(_end);

		if(start_node!=end_node){ //사이클이 아니면
			printf("%d %d %d\n",_start,_end,_weight);
			++selected_edge;
			weightUnion(start_node,end_node);
		}

	}

	system("PAUSE");
	return 0;
}