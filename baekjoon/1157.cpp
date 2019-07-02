//
//  1157.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 02/07/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//

#include <iostream>

using namespace std;

int main(){
    int dup = 0;
    int cnt[26]={0,};
    string N;
    cin>>N;
    for(int i=0;i<N.length();++i){
        if('a'<=N[i]&&N[i]<='z'){
            ++cnt[N[i]-'a'];
        }else if('A'<=N[i]&&N[i]<='Z'){
            ++cnt[N[i]-'A'];
        }
    }
    //for(int i=0;i<26;++i) cout<<cnt[i]<<" ";
    
    int max_index = 0;
    int max_value = cnt[0];
    for(int i=1;i<26;++i){
        if(max_value < cnt[i]){
            max_index = i;
            max_value = cnt[i];
        }
    }
    
    for(int i=0;i<26;++i){
        if(max_value == cnt[i]) ++dup;
    }
    
    if(dup>1) cout<<"?";
    else cout<<(char)(65+max_index);
    return 0;
}
