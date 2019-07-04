//
//  1929.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 04/07/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
int arr[1000001];

int main(){
    int M,N; cin>>M>>N;
    //clasify prime numbers;
    arr[0]=arr[1] = 1;
    for(int i=2;i<sqrt(N);++i) //각 배수들, sqrt(N) 원하는 숫자 범위의 제곱근 수 까지만 가도 배수를 다 걸러낼 수 있다.
        if(!arr[i]) for(int j=i+i;j<=N;j+=i) arr[j]=1; //배수들 지우기 1:걸러진 숫자들
    
    for(int i=M;i<=N;++i) if(!arr[i]) cout<<i<<'\n';
    return 0;
}
