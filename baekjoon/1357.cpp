//
//  1357.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 02/07/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//

#include <iostream>

using namespace std;

int Rev(int n){
    string temp = to_string(n); //int to string
    string tmp;
    for(int i=(int)temp.size()-1;i>=0;--i){ //reverse
        tmp+=temp.at(i);
    }
    return stoi(tmp); //string to int
}

int main(){
    int n1,n2; cin>>n1>>n2;
    cout<<Rev(Rev(n1)+Rev(n2));
    return 0;
}
