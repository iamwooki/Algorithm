//
//  1697.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 30/04/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
#define INDEX 100001
void bfs();
int visited[INDEX]={0,};
int S; //start;
int D; // destination
int main(){
    cin>>S>>D;
    bfs();
    return 0;
}

void bfs(){
    queue<pair<int,int>> q;
    q.push(pair<int,int>(S,0));
    while(!q.empty()){
        int cur_i = q.front().first;
        int cur_c = q.front().second;  q.pop();
        //cout<<cur_i<<" "<<cur_c<<endl;
        if(cur_i==D){
            cout<<cur_c;
            break;
        }
        visited[cur_i]=1; //visited
        //수빈이는 현재 점 N(0 ≤ S ≤ 100,000)에 있고, 동생은 점 K(0 ≤ D ≤ 100,000)에 있다
        if(cur_i-1>=0     && !visited[cur_i-1]) q.push(pair<int,int>(cur_i-1,cur_c+1));
        if(cur_i+1<=INDEX && !visited[cur_i+1]) q.push(pair<int,int>(cur_i+1,cur_c+1));
        if(cur_i*2<=INDEX && !visited[cur_i*2]) q.push(pair<int,int>(cur_i*2,cur_c+1));
    }
}
