//
//  1874.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 04/07/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
    // c++에서 cin, cout속도 올리기, 싱글스레드에서만 사용할 것
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //
    int T; cin>>T;
    stack<int> st;
    queue<char> q;
    int index = 0;
    st.push(index);//init
    
    //n을 받으면
    while(T--){
        int n; cin>>n;
        //현재 stack top이 입력받은 n보다 작으면 push
        while(n>st.top()){
            st.push(++index);
            q.push('+');
        }
        if(n==st.top()){
            st.pop();
            q.push('-');
        }else{
            cout<<"NO";
            return 0;
        }
        
    }
    while(!q.empty()){
        cout<<q.front()<<'\n'; //속도endl <\n
        q.pop();
    }
    return 0;
}
