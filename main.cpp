#include <iostream>
#include <vector>
#include "realization.h"
#define pb push_back
#define int long long
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
void solve(){
    int n, m;
    cin >> n >> m;
    matrix a(n, m);

    cin >> a;

    cout << a.overspeeddegree(2);
}
signed main(){
    solve(); return 0;
}