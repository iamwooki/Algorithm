#include <iostream>
using namespace std;
int visited[10000];
int main(){
    int N,K;
    cin>>N>>K;
    
    int cnt=0;
    for(int i=2;i<=N;++i){
        for(int j=i;j<=N;j+=i){
           	if(visited[j]) continue;
            visited[j]=1;
            if(++cnt==K){ //++cnt
            	cout<<j<<endl;
				return 0;	
               }
            }
    }
    
    return 0;
}
