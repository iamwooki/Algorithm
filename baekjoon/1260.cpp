//
//  1260.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 29/04/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#define INDEX 10000
using namespace std;
void bfs();
void dfs(int start);
int arr[INDEX][INDEX];
int V, E, S;

int main(){
    cin>>V>>E>>S;
    for(int i=1; i<=E;++i){
        int tmp1,tmp2;
        cin>>tmp1>>tmp2;
        arr[tmp1][tmp2] = 1;
        arr[tmp2][tmp1] = 1;
    }
    //    for(int i=1;i<=V;++i){
    //        for(int j=1;j<=V;++j){
    //            cout<<arr[i][j]<<" ";
    //        }
    //        cout<<endl;
    //    }
    dfs(S);
    cout<<endl;
    bfs();
    return 0;
}

void bfs(){
    queue<int> q;
    int visited_bfs[INDEX]={0};
    q.push(S);
    visited_bfs[S]=1;
    while(!q.empty()){
        int cur_i = q.front(); q.pop();
        printf("%d ",cur_i);
        for(int i=1;i<=V;++i){
            if(arr[cur_i][i] && !visited_bfs[i]){
                q.push(i);
                visited_bfs[i] = 1;
            }
        }
    }
}

int visited_dfs[INDEX]={0};
void dfs(int start){
    visited_dfs[start]=1;
    printf("%d ",start);
    for(int i=1;i<=V;++i){
        if(arr[start][i] && !visited_dfs[i]){
            dfs(i);
        }
    }
}
