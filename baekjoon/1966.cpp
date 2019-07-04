//
//  1966.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 04/07/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;
int main(){
    int T; cin>>T;
    while(T--){
        queue<pair<int,int>> q;
        priority_queue<int> pq;
        int N,M,cnt=0; cin>>N>>M; //전체 갯수, 알고자 하는 위치 인덱스
        //input & operatation
        for(int i=0;i<N;++i){
            //4,2 / 1 2 3 4 의 경우
            //index 0 1 2 3
            int priority_value; cin>>priority_value;
            q.push({i,priority_value}); //q에 각 인덱스 번호의 중요도 값을 저장
            pq.push(priority_value); //중요도 우선순위가 높은 것 부터 뽑힐 수 있도록 pq를 이용해 중요도 설정, 내림차순 정렬도 가능
        }
        //operation & output
        while(!q.empty()){
            //queue를 pop해서
            int cur_index = q.front().first;
            int cur_pValue =q.front().second;
            q.pop();
            //나온 값이 우선순위 큐에 의해 뽑힌 최고 높은 중요도와 같다면
            if(pq.top()==cur_pValue){
                pq.pop();
                ++cnt; //한번 뽑혔으므로 cnt 증가
                //만약 뽑은 값의 que_index가 찾고자 하는 index M과 같다면
                if(cur_index == M){
                    cout<<cnt<<'\n'; //출력
                    break;
                }
            //중요도가 같지 않다면 다시 맨 끝으로 보냄
            }else{
                q.push({cur_index,cur_pValue}); //값이 일치하지 않을 시 다시 맨 끝으로 보낸다.
            }
        }
    }
    return 0;
}
