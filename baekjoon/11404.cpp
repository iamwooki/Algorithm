#include <iostream>
#include <algorithm>
using namespace std;

#define INF 987654321

int G[101][101];

int main(){
	int N,M;
	cin>>N>>M;
	//init, 최소거리를 구하는 것이므로 먼저 최대값으로 초기화 
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			G[i][j]= INF;
		}
	}
	//input
	for(int i=1;i<=M;++i){
		int start,dest,distance;
		cin>>start>>dest>>distance;
		if(G[start][dest] > distance) G[start][dest]=distance;
	}
	
	//floyd
	for(int i=1;i<=N;++i) //도시 
		for(int j=1;j<=N;++j) //start
			for(int k=1;k<=N;++k) //dest
				if(G[j][i] != INF && G[i][k]!=INF)
					G[j][k]= min(G[j][k], G[j][i] + G[i][k]);
				
	
	//print			
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			if(i == j || G[i][j]==INF) cout<<0<<" "; //같은 도시이거나 들릴 수 없는 경우 
			else cout<<G[i][j]<<" ";
		}
		cout<<'\n';
	}
	
	return 0;
}
