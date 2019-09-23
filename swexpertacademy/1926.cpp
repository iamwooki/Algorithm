//
//  1926.cpp
//  SW expert Academy
//
//  Created by HyunWook Hong on 23/09/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int N; cin>>N;
    for(int i=1;i<=N;++i){
        int number = i;
        int cnt = 0;
        while(number){
            if( number % 10 == 3 || number % 10 == 6 || number % 10 == 9) ++cnt;
            number /= 10;
        }
        if(!cnt){
            cout<<i<<" ";
            continue;
        }
        while(cnt--){
            cout<<"-";
        }
        cout<<" ";
    }
    return 0;
}
