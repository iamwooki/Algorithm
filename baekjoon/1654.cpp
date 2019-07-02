//
//  1654.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 02/07/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int arr[10001];
    double rate[10001];
    int T,N;
    cin>>T>>N;
    double sum=0;
    for(int i=0;i<T;++i){
        cin>>arr[i];
        sum+=arr[i];
    }
    int min_value = 987654321;
    
    for(int i=0;i<T;++i){
        rate[i]= round(arr[i]/sum*100);
        rate[i] = round(N*0.01*rate[i]);
        arr[i]=(arr[i]/rate[i]);
        if(min_value>arr[i]) min_value = arr[i];
    }
    
    cout<<min_value;
    return 0;
}
