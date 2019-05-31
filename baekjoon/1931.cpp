#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, start, end;
    vector<pair<int ,int>> v;
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &start, &end);
        v.push_back(make_pair(end, start));
    }
    
    sort(v.begin(), v.end());

    int result = 1;
    int endTime = v[0].first;
    for (int i = 1; i < n; ++i) {
        if (endTime <= v[i].second) {
            //회의 종료 시간을 기준으로 다음 회의시작 시간을 비교한다.
            //회의 시작 시간이 종료시간보다 큰 값이면, 회의가 가능하므로 회의횟수를 실행하고, 회의가 가능한 현재 시간의 종료시간을 다시 끝나는 시간에 업데이트한다.
            result++;
            endTime = v[i].first;
        }
    }
    
    printf("%d", result);
    
    return 0;
}
