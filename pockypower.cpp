#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define mp make_pair
#define pb push_back

#define FAR(i, a, b) for (int i=a; i<b; i++)
#define FOR(i, a) for (int i=0; i<a; i++)

#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"

struct update {
    int position;
    int update;
};

int main () {
    // ifstream cin("input.in");
    int N; cin >> N;
    vector<pi> updates;
    FOR(i, N) {
        pi pocky; cin >> pocky.first >> pocky.second;
        pi update1 (pocky.first, 1);
        pi update2 (pocky.second + 1, -1);
        updates.pb(update1);
        updates.pb(update2);
    }
    sort(updates.begin(), updates.end());
    int currentPos = 0;
    int currentDepth = 0;
    int maxDepth = 0;
    FOR(i, updates.size()) {
        currentPos = i;
        // cout << updates[i].first << ":" << updates[i].second << endl;
        currentDepth += updates[i].second;
        if(currentDepth > maxDepth) {
            maxDepth = currentDepth;
        }
    }
    cout << maxDepth << endl;
    
    return 0;
}
