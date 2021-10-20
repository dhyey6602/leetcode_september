class Solution {
public:
    static const int maxn = 100005;
    vector<int> g[maxn];
    int f[maxn][20], dep[maxn];
    void dfs(int u,int fa) {
        for(int v : g[u]) {
            if(v == fa) continue;
            dep[v] = dep[u] + 1;
            f[v][0] = u;
            for(int i=1;i<=19;++i) f[v][i] = f[f[v][i-1]][i-1];
            dfs(v, u);
        }
    }
    int lca(int u,int v) {
        if(dep[u] < dep[v]) swap(u, v);
        for(int d=dep[u]-dep[v],i=19;i>=0;--i) if(d&(1<<i)) u=f[u][i];
        if(u == v) return u;
        for(int i=19;i>=0;--i) if(f[u][i]!=f[v][i]) u=f[u][i],v=f[v][i];
        return f[u][0];
    }
    int ra[maxn];
    vector<int> smallestMissingValueSubtree(vector<int>& par, vector<int>& a) {
        int n = a.size();
        for(int i = 1; i < n; ++i) {
            g[par[i]].push_back(i);
        }
        dfs(0, -1);
        for(int i = 1; i <= n; ++i) ra[i] = -1;
        for(int i = 0; i < n; ++i) ra[a[i]] = i;
        vector<int> ans(n, 1);
        if(ra[1] == -1) return ans;
        int p = ra[1];
        ans[p] = 2;
        for(int i = 2; i <= n; ++i) {
            if(ra[i] == -1) {
                int pre = p;
                while(p != 0) {
                    p = par[p];
                    ans[p] = ans[pre];
                }
                break;
            }
            int nxt = lca(p, ra[i]);
            int pre = p;
            while(p != nxt) {
                p = par[p];
                ans[p] = ans[pre];
            }
            ans[nxt] = i + 1;
        }
        return ans;
    }
};