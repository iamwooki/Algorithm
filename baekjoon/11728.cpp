//
//  11728.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 02/07/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int a, b, c[2000001];
int main() {
    cin>>a>>b;
    a = b = a + b; //배열 갯수
    while (a--) cin>>c[a];
    sort(c, c + b); //c[0]~c[b]까지 sorting
    for (a = 0; a < b; a++) cout<<c[a]<<" ";
    return 0;
}
