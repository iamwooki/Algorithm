//
//  1920.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 04/07/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001]; //전역으로 선언하면 모두 0 으로 초기화
int Search(int n,int key){
    int start =0;
    int end = n-1;
    
    while(end-start>=0){
        int mid = (start+end)/2;
        if(arr[mid] == key) return 1;
        else if(arr[mid]>key) end = mid-1;
        else start= mid+1;
    }
    return 0;
}

int main(){
    // c++에서 cin, cout속도 올리기, 싱글스레드에서만 사용할 것
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //
    
    int N, M; cin>>N;
    for(int i=0;i<N;++i) cin>>arr[i];
    sort(arr,arr+N);// sorting
    
    cin>>M;
    while(M--){
        int input; cin>>input;
        cout<<Search(N,input)<<'\n';
    }
    return 0;
}
