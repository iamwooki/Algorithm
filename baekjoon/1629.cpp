//
//  1629.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 02/07/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//
#include<iostream>

using namespace std;
int A, B, C;
long long power(int a, int b){
    if (b == 0) return 1; // a^0 = 1
    else if (b % 2 == 0){ //even number
        long long temp = power(a, b / 2); //a^(b/2)
        return ((temp%C) * (temp%C)) % C; //짝수의 경우 a^8 = a^4 * a^4
    }
    else{ //odd number
        return ((a%C) * (power(a, b-1)%C))%C; //홀수의 경우 a^9 = a* a^8(=a^4*a^4)
    }
}


int main()
{
    cin >> A >> B >> C;
    cout << power(A%C, B) % C << endl;
    
    
    return 0;
}
