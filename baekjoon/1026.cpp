/*5
 1 1 1 6 0
 2 7 8 3 1
 */
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin>>N;
    int arr[2][N];
    for(int i=0;i<2;++i){
        for(int j=0;j<N;++j){
            cin>>arr[i][j];
        }
    }
    
    sort(arr[0],arr[0]+N);
    sort(arr[1],arr[1]+N, greater<int>()); //desc
    int sum=0;
    for(int i=0;i<N;++i){
        sum+=arr[0][i]*arr[1][i];
    }
    cout<<sum;
    return 0;
}
