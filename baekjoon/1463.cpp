//
//  1463.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 06/05/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//

#include <iostream>
#include <cmath>
#define INF 987654321
#define MIN(a,b,c) a>b ? b>c?c:b : a>c?c:a
using namespace std;
int DP_recursive(int _N,int cur_cnt){
    if(_N==1) return cur_cnt;
    if(_N<=0) return INF;
    int v1 = INF; int v2 = INF; int v3 = INF;
    if(_N%3==0) v1= DP_recursive(_N/3,cur_cnt+1);
    if(_N%2==0) v2= DP_recursive(_N/2,cur_cnt+1);
    v3= DP_recursive(_N-1,cur_cnt+1);
    return MIN(v1,v2,v3);
}

int DP_iterative(int _N){
    int DP[_N+1];
    DP[0]=0; DP[1] = 0;
    for(int i=2;i<=_N;++i){ //1만들기 이므로  1의 경우 횟수를 카운트 할 필요가 없다.
        DP[i] = DP[i-1]+1;
        if(i%2==0) DP[i] = min(DP[i], DP[i/2]+1);
        if(i%3==0) DP[i] = min(DP[i], DP[i/3]+1);
    }
    return DP[_N];
    /*
     N=10,
          0 1 2 3 4 5 6 7 8 9 10
     -1   0 0 1 2 3 3 5 3 4 4 3
     /2   0 0 1 - 2 - 2 - 3 - 4
     /3   0 0 - 1 - - 2 - - 2 -
   choice 0 0 1 1 2 3 2 3 3 2 3
     */
}
int main(){
    int N; // input number
    cin>>N;
    //check range of number
    if(!(1<=N && N<=pow(10,6))) exit(0);
    cout<<DP_iterative(N);
    return 0;
}
