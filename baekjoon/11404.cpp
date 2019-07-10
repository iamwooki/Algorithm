#include <iostream>
#include <algorithm>
using namespace std;

#define INF 987654321

int G[101][101];

int main(){
	int N,M;
	cin>>N>>M;
	//init, �ּҰŸ��� ���ϴ� ���̹Ƿ� ���� �ִ밪���� �ʱ�ȭ 
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
	for(int i=1;i<=N;++i) //���� 
		for(int j=1;j<=N;++j) //start
			for(int k=1;k<=N;++k) //dest
				if(G[j][i] != INF && G[i][k]!=INF)
					G[j][k]= min(G[j][k], G[j][i] + G[i][k]);
				
	
	//print			
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			if(i == j || G[i][j]==INF) cout<<0<<" "; //���� �����̰ų� �鸱 �� ���� ��� 
			else cout<<G[i][j]<<" ";
		}
		cout<<'\n';
	}
	
	return 0;
}
