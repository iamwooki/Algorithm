//
//  1475.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 11/05/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int arr[10]={0,};
    int N;
    cin>>N;
    if(N==0){
        cout<<1;
        return 0;
    }
    while(N>0){
        int input = N%10;
        switch(input){
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 7:
            case 8:
                ++arr[input];
                break;
            case 6:
                if(arr[6]>arr[9])
                    ++arr[9];
                else ++arr[input];
                break;
            case 9:
                if(arr[9]>arr[6])
                    ++arr[6];
                else ++arr[input];
                break;
        }
        N/=10;
    }
    int _max = arr[0];
    for(int i=1;i<10;++i){
        _max = max(_max,arr[i]);
    }
    cout<<_max;
    return 0;
}
