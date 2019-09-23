//
//  1959.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 23/09/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(){

    int T; cin>>T;
    //case
    for(int k=1;k<=T;++k){
        int N,M; cin>>N>>M;
        vector<int> v1(N),v2(M);
        //vector 1
        for(int i=0;i<N;++i) cin>>v1[i];
        //vector 2
        for(int i=0;i<M;++i) cin>>v2[i];
        
        int maxValue = 0;
        
        if(N>M){
            for(int i=0;i<=N-M;++i){
                //m기준
                int temp=0;
                for(int j=0;j<M;++j) temp+=v2.at(j)*v1.at(j+i);
                if(maxValue<temp) maxValue = temp;
            }
        }else{
            for(int i=0;i<=M-N;++i){
                //n기준
                int temp=0;
                for(int j=0;j<N;++j) temp+=v1.at(j)*v2.at(j+i);
                if(maxValue<temp) maxValue = temp;
            }
        }
        cout<<"#"<<k<<" "<<maxValue<<endl;
    }
    return 0;
}
