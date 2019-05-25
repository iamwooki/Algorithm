#include <iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    string arr[N];
    for(int i=0;i<N;++i){
        string temp;
        cin>>temp;
        int pivot=0;
        for(int j=0;j<temp.length()&&pivot>=0;++j){ //괄호가 )부터 시작되면 안되므로 pivot>=0
            if(temp.at(j)=='(') ++pivot;
            else --pivot;
        }
        if(pivot==0) arr[i]="YES";
        else arr[i]="NO";
    }
    for(int i=0;i<N;++i) cout<<arr[i]<<endl;
}
