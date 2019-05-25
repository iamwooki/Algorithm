//
//  1978.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 25/05/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int arr[1001];
int main(){
    arr[0] = arr[1] = 1;
    //에라토스테네스의 체
    for(int i = 2;i<sqrt(1001);++i) //최댓값까지 가지 않아도 계산됨.
        //2~최대값중에
        if(!arr[i])
            //0,1 제외를 시작으로 밑에 반복문에서 제거되면서 1이 된 숫자들은 넘어뛰게 된다.
            // 4의 배수는 결국 2의 배수이기 때문에
            for(int j=i+i; j<1001;j+=i) arr[j]=1;
    //2~max_value 범위의 각 배수들을 순차적으로 제거
    //2,4,6,8,10, ...
    //3,6,9,12,15,,,  등 줄여나감
    
    int N,cnt=0;
    cin>>N;
    for(int i=0;i<N;++i){ //N초과 2*n 이하
        int num;
        cin>>num;
        if(!arr[num]) ++cnt;
    }
    cout<<cnt;
}
