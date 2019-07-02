//
//  1316.cpp
//  baekjoon
//
//  Created by HyunWook Hong on 02/07/2019.
//  Copyright © 2019 HyunWook Hong. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
//aba
//012

int main(){
    int T;
    cin>>T;
    int arr[26];
    int cnt=0;
    while(T--){
        string word; cin>>word;
        memset(arr,0,sizeof(arr));
        
        char preWord= word[0];
        for(int i=0;i<word.size();++i){
            if(i==0) preWord = word[0]; //첫 문자 셋팅
            //0 1 2 3 ... N
            else if(preWord == word[i]){ //연속되는 단어의 경우(1번째 인덱스부터)
                continue; //반복문을 넘긴다.
            }
            preWord = word[i]; //이전 단어를 업데이트 해준다.
            ++arr[preWord-'a']; //알파벳 갯수 체크에 숫자를 넣는다.
        }
        
        bool flag = true; //그룹단어 카운트용 플래그
        for(int i=0;i<26;++i){
            if(arr[i]>1){ //2이상의 숫자의 경우 그룹단어가 아님을 의미한다
                flag =false;
                break;
            }
        }
        if(flag) ++cnt;
    }
    cout<<cnt;
    return 0;
}
