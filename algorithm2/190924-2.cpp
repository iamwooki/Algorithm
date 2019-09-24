//
//  linkedlist.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 24/09/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//

/*
 * 연결리스트를 구성하면, 메이크힙으로 각 배열의 연결리스트를 힙화 시킨다. 그 후 시작점을 기준으로 힙을 뽑으면서 사이클을 확인하면서 최소신장트리를 구현한다?
 */
#include <iostream>
using namespace std;

class NODE{
public:
    int vertex;
    int weight;
    NODE *link;
    NODE(int vertex=0, int weight=0){ //constructor
        this->vertex = vertex;
        this->weight = weight;
        link = NULL;
    }
};

NODE G[20][2];
void insert_node(int from, int to, int weight){
    
    //0 : 가장 뒤의 노드를 가르 킴, 1: 첫번재 노드를 가르킴
    //from
    NODE *fromNode = new NODE(to,weight);
    if(G[from][0].link == NULL){//최초
        G[from][1].link = fromNode;
        G[from][0].link = fromNode;
    }else{ //그다음부터
        G[from][0].link->link = fromNode;
        G[from][0].link = G[from][0].link->link;
    }
    //to
    NODE *toNode = new NODE(from,weight);
    if(G[to][0].link == NULL){ //최초
        G[to][1].link = toNode;
        G[to][0].link = toNode;
    }else{
        G[to][0].link->link = toNode;
        G[to][0].link = G[from][0].link->link;
    }
}

void print(int V){
    for(int i=1;i<=V;++i){
        NODE *hp = G[i][1].link;
        cout<<i<<" ";
        while(hp!=NULL){
            cout<<"-["<<hp->vertex<<" "<<hp->weight<<"]";
            hp = hp->link;
        }
        cout<<'\n';
    }
    cout<<'\n';
}
    
int main(){
    //file
    FILE *f=fopen("input.txt","r");
    if(f==NULL) return 1;
    
    //insert
    int V,E; fscanf(f,"%d %d",&V,&E);
    for(int i=0;i<E;++i){
        int from, to, weight;
        fscanf(f,"%d %d %d",&from,&to,&weight);
        insert_node(from,to,weight);
        print(V);
    }
    
    return 0;
}
