#include <iostream>
#include <cmath>
#define max_value 246913
//246913 = 123456*2
using namespace std;
int arr[max_value];
int main(){
    arr[0] = arr[1] = 1;
    //�����佺�׳׽��� ü
    for(int i = 2;i<sqrt(max_value);++i) //�ִ񰪱��� ���� �ʾƵ� ����.
        //2~�ִ밪�߿�
        if(!arr[i])
            //0,1 ���ܸ� �������� �ؿ� �ݺ������� ���ŵǸ鼭 1�� �� ���ڵ��� �Ѿ�ٰ� �ȴ�.
            // 4�� ����� �ᱹ 2�� ����̱� ������
            for(int j=i+i; j<max_value;j+=i) arr[j]=1; 
            //2~max_value ������ �� ������� ���������� ����  
            //2,4,6,8,10, ...
            //3,6,9,12,15,,,  �� �ٿ�����
    
    while(1){
        int N, cnt=0;
        cin>>N;
        if(N==0) break;
        for(int i=N+1;i<=2*N;++i) //N�ʰ� 2*n ����
            if(!arr[i]) ++cnt;
        cout<<cnt<<endl;
    }
}
