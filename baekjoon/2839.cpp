//
//  2839.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 06/05/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    if(!(3<=N && N<=5000)) exit(0);
    int cnt=0;
    while(N>0){
        if(N%5==0){ //크게 자르기 위해 5부터
            N-=5;
            cnt++;
        }else if(N%3==0){ //그 다음 3
            N-=3;
            cnt++;
        }else if(N>5){ //5와 3으로 나누어지지 않을 경우 5부터 줄여본다. 3으로 빼지 않는 경우는 크게 자르기 위해.
            N-=5;
            cnt++;
        }else{ // 5미만은 3아니면 나누어질 수 있는 경우의 수가 없는데 3으로 나누어질 수 있었다면 위에서 나누어졌을 것이기 때문에
            cnt = -1;
            break;
        }
    }
    cout<<cnt;
    return 0;
}
