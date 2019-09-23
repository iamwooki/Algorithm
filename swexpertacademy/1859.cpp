//
//  1859.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 23/09/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//

#include <iostream>
 
using namespace std;
int A[1000002];
int main(){
    int N; cin>>N;
    for(int i=1;i<=N;++i){
        int _N; cin>>_N;
        long long ans=0;
        //init
        for(int j=0;j<_N;++j) cin>>A[j];
         
        int max_value = A[_N-1]; //뒷 기준으로 진행한다.
        for(int k=_N-1;k>=0;--k){
            if(max_value >= A[k]){ //최대값보다 같거나 작으면
                ans+=(max_value-A[k]); //이윤에 차익값을 더해준다
            }else{
                max_value = A[k]; //최대 값 보다 현재 값이 크면 최대 값을 변경해준다.
            }
        }
        cout<<"#"<<i<<" "<<ans<<endl;
    }
    return 0;
}
