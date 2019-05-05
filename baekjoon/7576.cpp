//
//  7576.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 06/05/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#define MAX(a,b) a>b?a:b
using namespace std;

int M, N;
int flag = false;
int arr[1001][1001];
const int yx[4][2]={{1,0},{-1,0},{0,1},{0,-1}}; // up down right left

int bfs();
int main(){
    cin>>N>>M; // N: width(x), M : height(y)
    //input
    for(int i=1; i<=M;++i){
        for(int j=1; j<=N;++j){
            cin>>arr[i][j];
            if(flag == false && arr[i][j]==0) flag = true; //모두 익지 않은 상황
        }
    }
    
    //operate
    cout<<bfs();
    return 0;
}

int bfs(){
    if(flag==false) return 0; //저장될 때 부터 모두 익어있는 상태
    queue<vector<int>> q;
    int max_cnt=0;
    for(int i=1;i<=M;++i){ //y
        for(int j=1;j<=N;++j){ //x
            if(arr[i][j]==1){ //처음 익어있는 토마토를 넣어서 위치를 판단하는 단계
                vector<int> tmp = {max_cnt,i,j};
                q.push(tmp); //input value, cur cnt, i, j
            }
        }
    }
    
    //익어있는 토마토가 없어서 모두 익지 못하는 상황
    if(q.empty()){
        cout<<"토마토가 없어서 익지 못하는 상황";
        return -1;
    }
    
    //실질적인 동작
    while(!q.empty()){
        int cnt = q.front()[0]; // 횟수 체크
        int cur_y = q.front()[1];
        int cur_x = q.front()[2];
        max_cnt = MAX(max_cnt,cnt);
        q.pop();
        
        for(int i=0;i<4;++i){ // 상하좌우체크
            int next_y = cur_y + yx[i][0];
            int next_x = cur_x + yx[i][1];
            
            //범위체크
            if( (1<= next_y && next_y <=M) && (1<= next_x && next_x<=N) && arr[next_y][next_x]==0){
                arr[next_y][next_x] = 1;
                vector<int> input = {cnt+1,next_y,next_x};
                q.push(input);
            }
        }
    }
    
    //아직 방문하지 못한 곳이 있다면
    //토마토가 모두 익지 못하는 상황
    for(int i=1;i<=M;++i){
        for(int j=1;j<=N;++j){
            if(arr[i][j]==0) return -1;
        }
    }
    
    //몇번만에 넘어가는지
    return max_cnt;
}
