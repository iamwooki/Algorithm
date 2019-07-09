#include <iostream>
#include <cstring>
using namespace std;

int N,M;
int G[51][51];
int visited[51][51];
int dy[8] = {-1,-1,-1,0,+1,+1,+1,0};
int dx[8] = {-1,0,+1,+1,+1,0,-1,-1};
int output[100000];
/*
(-1,-1) (-1,+0) (-1.+1)
(+0,-1) (+0,+0) (+0,+1)
(+1,-1) (+1,+0) (+1,+1)
*/

void Search(int y, int x){
	//cout<<y<<" "<<x<<endl;
	if(y<0 || y>M || x<0 || x>N || 
	G[y][x]==0 || visited[y][x]) return; 
	//������ ����ų�, ������ �湮�߰ų�, �ؾ��̶��. 
	
	visited[y][x] = 1; //�湮
	/*
	cout<<"--------------------------"<<endl;
	for(int i=0;i<M;++i){ //row(i)
		for(int j=0;j<N;++j){ //col(j)
			cout<<visited[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<"--------------------------"<<endl;
	*/
	for(int i=0;i<8;++i){
		int new_y = y+dy[i];
		for(int j=0;j<8;++j){
			int new_x = x+dx[j];	
			Search(new_y,new_x);
		}
	} 
	
		 
}
int main(){
	int index=0;
	while(cin>>N>>M){ //��, ������� �Է¹��� 
		if(N==0&&M==0) break;
		int cnt=0;
		memset(G,0,sizeof(G));
		memset(visited,0,sizeof(visited));
		
		//input
		for(int i=0;i<M;++i){ //row(i)
			for(int j=0;j<N;++j){ //col(j)
				cin>>G[i][j];
			}
		}
		
		//operation
		for(int i=0;i<M;++i){ //row(i)
			for(int j=0;j<N;++j){ //col(j)
				if(!visited[i][j] && G[i][j]==1){
				 //�̹� �湮�ߴٸ� �� �ʿ䰡 ����. 
					Search(i,j);
					++cnt;
				}
			}
		}

		output[index++]=cnt;
	}
	
	//print
	for(int i=0;i<index;++i){
		cout<<output[i]<<'\n';
	}
	return 0;
}
