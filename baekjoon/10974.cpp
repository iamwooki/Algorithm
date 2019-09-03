//
//  10974.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 03/09/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//

#include <iostream>
using namespace std;
int S[10];
int partition(int low, int high) {
    //partition
    int pivotitem = S[low];
    int j = low;
    for (int i = low + 1; i <= high; ++i) {
        if (S[i] < pivotitem) {
            ++j;
            swap(S[i], S[j]);
        }
    }
    int pivotpoint = j;
    swap(S[low], S[pivotpoint]);
    
    return pivotpoint;
}
int rand_partition(int low, int high) {
    int i = (rand() % (high - low + 1))  + low;
    swap(S[low], S[i]);
    return partition(low, high);
}
void sort(int low, int high) {
    if (low < high) {
        int pivotpoint = rand_partition(low, high);
        sort(low, pivotpoint - 1);
        sort(pivotpoint + 1, high);
    }
}

void permutation(int k, int n) {
    if (k >= n) {
        //print
        for (int i = 0; i <= n; ++i) cout << S[i]<<' ';
        cout << '\n';
        return;
    }
    sort(k, n); //초기 소팅
    permutation(k + 1, n); sort(k+1,n);
    int m=k+1; //다른 문자를 찾는 index, 적어도 k의 위치보다 뒤에 있음
    while (m > k && m <= n) {
        if (S[k] < S[m]) { //숫자 크기 판단
            swap(S[k], S[m]);
            permutation(k+1,n);
            sort(k+1, n);
        }
        ++m;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin>>N;
    for(int i=0;i<N;++i) S[i]=i+1;
    permutation(0,N-1);
    
    return 0;
}
