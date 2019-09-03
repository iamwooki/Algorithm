//
//  2667.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 15/07/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int map[25][25];
string input[25];
int output[25];
int T;
int dir_x[4]={0,0,-1,1};
int dir_y[4]={1,-1,0,0};
int cnt;
void search(int y, int x){
    if( map[y][x]==0 || 0>y || y>=T || 0>x || x>=T ) return; //범위를 벗어날 시
    ++cnt;
    map[y][x]=0;
    /*
    cout<<"-------------------------"<<endl;
    for(int y=0;y<T;++y){
        for(int x=0;x<T;++x){
            cout<<map[y][x];
        }
        cout<<endl;
    }
    cout<<"-------------------------"<<endl;
    */
    for(int i=0;i<4;++i){
        //상 하 좌 우
        int new_x = x+dir_x[i];
        int new_y = y+dir_y[i];
        
        if( map[new_y][new_x]==0 || 0>new_y || new_y>=T || 0>new_x || new_x>=T ){
            
        }else{
            search(new_y,new_x);
        }
        
    }
}

int main(){
    cin>>T;
    for(int i=0;i<T;++i) cin>>input[i];
    
    for(int y=0;y<T;++y){
        for(int x=0;x<T;++x){
            map[y][x]= (input[y].at(x)-'0');
        }
    }
    
    int index=0;
    for(int y=0;y<T;++y){
        for(int x=0;x<T;++x){
            if(map[y][x]!=0){//0이 아닐 시만 접근
                cnt = 0;
                search(y,x);
                output[index++]=cnt;
            }
            
        }
    }
    //오름차순
    sort(output,output+index);
    
    //Print
    cout<<index<<'\n';
    for(int i=0;i<index;++i){
        cout<<output[i]<<'\n';
    }
    
    return 0;
}
