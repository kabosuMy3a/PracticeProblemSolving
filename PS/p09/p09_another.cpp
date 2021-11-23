#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, B, cost[500], t1, t2, answer, Board[500][500];
vector<int> arr;
void solve(){
    int size = arr.size(); int sum = 0;
    vector<int> ch(N+1, 0);
    for(int i=0;i<size;i++){
        int cur = arr[i];
        sum += cost[cur];
        for(int j=1;j<=N;j++){
            if(Board[cur][j] == 0) ch[j] = 1; 
        }
    }
    answer = max(answer, sum);

    for(int i=1;i<=N;i++) {
        if(ch[i] == 0) {
            arr.push_back(i);
            solve();
            arr.pop_back();
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("input.txt", "rt",stdin);
    cin >> N >> B;
    for(int i=1;i<=N;i++) cin >> cost[i]; 
    for(int i=0;i<B;i++){
        cin >> t1 >> t2;
        Board[t1][t2] = 1;
        Board[t2][t1] = 1;
    }
    for(int i=1;i<=N;i++){
        arr.push_back(i);
        solve();
        arr.pop_back();
    }
    cout << answer;
    return 0;
}