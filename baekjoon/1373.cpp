//
//  1373.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 02/07/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//

#include <iostream>

using namespace std;

int main(){
    string N;
    cin>>N;
    
    //8진수 자리 맞추기 input이 11001100이면
    int mod = N.length()%3;
    if(mod==1) N="00"+N;
    if(mod==2) N="0"+N; //input =0 + 11001100 = 011001100
    
    //operate
    string result;
    for(int i=0;i<N.length();i+=3){
                                //      4               2              1
                                //      0               1              1
        result+= to_string( (N.at(i)-'0') *4 + (N[i+1]-'0')*2 + (N[i+2]-'0')*1 );
    }
    cout<<result;
    return 0;
}
