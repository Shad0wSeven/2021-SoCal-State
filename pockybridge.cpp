#include<bits/stdc++.h>
// USACO MAGIC
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
# define INF 0x3f3f3f3f
  
typedef pair<int, int> iPair;

void addEdge(vector <pair<int, int> > adj[], int u, int v, int wt) {
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}
   
int shortestPath(vector<pair<int,int> > adj[], int V, int src, int end) {
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    vector<int> dist(V, INF);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist[end];
}
  

int main() {
    ifstream cin("input.in");

    int q; cin >> q;
    int N, E; cin >> N >> E;
    int V = 100000;
    vector<iPair > adj[V];
    int start, end; cin >> start >> end;
    FOR(i, E) {
        int a, b, c;
        // cout << a << b << c << endl;
        cin >> a >> b >> c;
        addEdge(adj, a, b, c);

    }

    // cout << shortestPath(adj, V, 0, end) << endl;
    int z = shortestPath(adj, V, start, end);
    if( z <= q) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
  
    return 0;
}
