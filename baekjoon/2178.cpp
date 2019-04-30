//
//  2178.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 29/04/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//  bfs로 주변 움직임 모두 한칸씩 뻗어나가면서 움직인다.

#include <iostream>
#include <queue>
#define INDEX 1000

using namespace std;
void bfs();
int ROW, COL;
int arr[INDEX][INDEX];
int visited[INDEX][INDEX];
const int yx[4][2]={{1,0},{-1,0},{0,1},{0,-1}}; // up down left right
int main(){
    cin>>ROW>>COL;
    for(int i=1;i<=ROW;++i){
        for(int j=1;j<=COL;++j){
            scanf("%1d",&arr[i][j]);
        }
    }
    bfs();
    return 0;
}

void bfs(){
    int cur_x=1, cur_y=1;
    queue<pair<int,int>> q;
    q.push(pair<int,int>(cur_y,cur_x)); //pair of x and y
    visited[cur_y][cur_x]= 1; //start point
    
    while(!q.empty()){
        cur_y = q.front().first;
        cur_x = q.front().second;
        q.pop();
        
        for(int i=0;i<4;++i){
            //next_yx = cur_yx + value of yx
            int next_y = cur_y + yx[i][0];
            int next_x = cur_x + yx[i][1];
            
            if( ((next_y>0&&next_y<=ROW)&&(next_x>0&&next_x<=COL)) //next_x,y is inside
                && visited[next_y][next_x]==0 && arr[next_y][next_x]){
                                // not visited && if can go next coordinate
                    visited[next_y][next_x] = visited[cur_y][cur_x] + 1; //count
                    q.push(pair<int,int>(next_y,next_x));
                }
            
        }
    }
    cout<<visited[ROW][COL];
}
