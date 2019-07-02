//
//  1158.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 02/07/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//
/*
 Josephus permutation problem
 
 input(7,3)
 1 2 3 4 5 6 7
 3
 4 5 6 7 1 2
 3 6
 7 1 2 4 5
 3 6 2
 4 5 7 1
 3 6 2 7
 1 4 5
 3 6 2 7 5
 1 4
 3 6 2 7 5 1 4
 */
#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N,K;
    cin>>N>>K;
    
    queue<int> q;
    for(int i=1;i<=N;++i) q.push(i); //insert into queue 1~N
    
    cout << "<";
    for (int i = 1; i < N; i++){
        for (int j = 1; j <K; j++){ //3의 배수라 하면 1,2까지만 뒤로 보내야함.
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", "; // [3] [6] [2] [7] [5] [1]
        q.pop();
    }
    cout << q.front() << ">"; //[4]
    
    
    return 0;
}
