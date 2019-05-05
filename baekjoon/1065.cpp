//
//  1065.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 06/05/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//

#include <iostream>
using namespace std;
int numberLength(int value){
    int cnt=1;
    while(value>=10){
        value/=10;
        ++cnt;
    }
    return cnt;
}
bool getValue(int value){
    int arr[3];
    arr[0] = value/100;
    value%=100;
    arr[1] = value/10;
    value%=10;
    arr[2] = value;
    
    if((arr[2]-arr[1])==(arr[1]-arr[0])) return true;
    else return false;
}
int main(){
    int N;
    int cnt = 0;
    cin>>N;
    if(N>=1001) exit(0);
    for(int i=1;i<=N;++i){
        switch(numberLength(i)){
            case 1:
            case 2:
                ++cnt;
                break;
            case 3:
                if(getValue(i)) ++cnt;
                break;
        }
    }
    cout<<cnt;
    return 0;
}
