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

pi pockyDecode(string pocky) {
    int cl = 0, bl = 0;
    FOR(i, pocky.size()) {
        if(pocky[i] == '=') {
            cl++;
        } else {
            bl++;
        }
    }
    pi returns (cl, bl);
    return returns;

}

int main () {
    ifstream cin("input.in");
    int N;
    cin >> N;

    vector<pi> pockys;
    FOR(i, N) {
        string s; cin >> s;
        pockys.push_back(pockyDecode(s));

    }
    sort(pockys.begin(), pockys.end());
    // FOR(i, N) {
    //     cout << pockys[i].first << ":" << pockys[i].second << endl;
    // }

    // output 

    FOR(i, N) {
        FOR(j, pockys[i].first) {
            cout << '=';
        }
        FOR(j, pockys[i].second) {
            cout << '-';
        }
        cout << endl;
    }


    return 0;
}
