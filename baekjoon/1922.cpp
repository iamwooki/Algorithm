//
//  1922.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 10/09/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge{
    public:
    int node[2]; //start, end node
    int value; //weight
    Edge(int start, int end, int value){
        node[0] = start;
        node[1] = end;
        this->value = value;
    }
    bool operator <(Edge &edge){ //연산자 오버로딩
        return this->value < edge.value;
    }
};

int parent[1002];
int find(int node){
    if(parent[node] == node) return node;
    else return parent[node] = find(parent[node]); //root까지 올라가서 그룹체크
}

void merge(int start, int end){
    int node1 = find(start);
    int node2 = find(end);
    if(node1 == node2) return;
    parent[node2] = node1;
}

int main(){
    vector<Edge> v;
    //input
    int node, edge;
    cin>>node>>edge;
    for(int i=0;i<edge;++i){
        int start, end, value;
        cin>>start>>end>>value;
        v.push_back(Edge(start,end,value));
    }
    for(int i=1;i<=node;++i){ //처음에 각각 다른 노드로 설정
        parent[i]=i;
    }
    sort(v.begin(),v.end()); //greedy sort
    
    int sum=0; //total value
    //kruskal
    for(int i=0;i<edge;++i){
        //같은 그룹인지 비교하고
        if(find(v[i].node[0]) == find(v[i].node[1])){
            continue; //같으면 skip
        }
        //전체 값에 더해주고
        sum+=v[i].value;
        //같은 그룹으로 설정해주고
        merge(v[i].node[0],v[i].node[1]);
    }
    cout<<sum;
    
    return 0;
}
