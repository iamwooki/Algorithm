#include <iostream>

using namespace std;
int arr[4][7][7];
int main(){
    int T; cin>>T;
    for(int i=1;i<=T;++i){
        int N; cin>>N;
        //init input
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                cin>>arr[0][i][j];
            }
        }
        //operate
        for(int i=1;i<=3;++i){ //90도 회전 3번
            int x=0;
            for(int j=0;j<N;++j){
                int y=N-1;
                for(int k=0;k<N;++k){
                    arr[i][j][k]=arr[i-1][y--][x];
                }
                ++x;
            }
        }
        
        //print
        cout<<"#"<<i<<'\n';
        for(int y=0;y<N;++y){
            for(int i=1;i<=3;++i){
                for(int x=0;x<N;++x){
                    cout<<arr[i][y][x];
                }
                cout<<" ";
            }
            cout<<'\n';
        }
    }
    return 0;
}
