//
//  1009.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 25/05/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//

#include <iostream>

using namespace std;

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        int a, b;
        cin>>a>>b;
        int sum=1;
        for(int j=0;j<b;++j){
            sum*=a;
            sum%=10;
        }
        if(sum==0) cout<<10<<endl;
        else cout<<sum<<endl;
    }
    return 0;
}
