#include <iostream>
using namespace std;

int main(){
    int N, K;
    cin>>N>>K;
    int arr[N];
    int cnt=0;
    int pivot=0;
    for(int i=0;i<N;++i) cin>>arr[i];
    for(int i=0;i<N;++i){
        if(K>=arr[pivot]) pivot=i;
    }
    
    while(K!=0){
        if(K>=arr[pivot]){ //현재 동전이 잔액보다 작은 단위여야함
            cnt+= K/arr[pivot]; //지불 한 단위의 갯수
            K%=arr[pivot]; //지불하고 남은 잔액
        }else --pivot; //그렇지 않을 시 단위를 낮춘다
    }
    cout<<cnt;
    return 0;
}
