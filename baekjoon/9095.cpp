//
//  9095.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 25/05/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//

#include <iostream>
using namespace std;
int N;
int arr[1000];
int ar[1000];
int cnt;
void DP_recursive(int N){
    if(N==0){
        ++cnt;
        return;
    }
    if(N<0) return;
    DP_recursive(N-1);
    DP_recursive(N-2);
    DP_recursive(N-3);
}
/*
 1 =(1) - 1
 2 =(1+1),(2) - 2
 3 =(1+1+1),(1+2),(2+1),(3) - 4
 4 =(1+1+1+1),(1+1+2),(1+2+1),(2+1+1),(1+3),(3+1),(2+2) - 7
 f(4)=f(3)+f(2)+f(1)
*/
void DP_iterative(int N){
    ar[0]=0; ar[1]=1; ar[2]=2; ar[3]=4;
    for(int i=4;i<=N;++i){
        ar[i]=ar[i-3]+ar[i-2]+ar[i-1];
    }
}
//들어오는 input값중 가장 큰 값으로 한번만 점화식 행렬을 수행하면
//나머지 숫자들은 인덱스 접근으로 바로 값 도출 가능
int main(){
    cin>>N;
//    for(int i=0;i<N;++i){
//        cnt=0;
//        int input;
//        cin>>input;
//        DP_recursive(input);
//        arr[i]=cnt;
//    }
    for(int i=0;i<N;++i){
        int input;
        cin>>input;
        DP_iterative(input);
        arr[i]=ar[input];
    }
    
    for(int i=0;i<N;++i)
        cout<<arr[i]<<endl;;

    return 0;
}
