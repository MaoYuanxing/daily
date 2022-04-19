#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <string>
#include <queue>
#include <map>
#define ll long long
const ll INF = 1000000000009;
using namespace std;

typedef pair<ll, int> p;
map<string, int> mp;
vector<p> g[1001];
ll stt[1001][1001] = {0};

int main()
{
    int n, m, qr, id = 0;
    ll wt;
    string a, b;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            stt[i][j] = INF;
        }
        stt[i][i] = 0;
    }
    while (m--)
    {
        cin >> a >> b >> wt;
        int v, w;
        if (!mp.count(a))
        {
            v = id++;
            mp[a] = v;
        }
        else
        {
            v = mp[a];
        }
        if (!mp.count(b))
        {
            w = id++;
            mp[b] = w;
        }
        else
        {
            w = mp[b];
        }
        p line = p(wt, w);
        g[v].push_back(line);
    }

    cin >> qr;
    while (qr--)
    {
        cin >> a >> b;
        int v = mp[a], w = mp[b], vt = 0;

        if (stt[v][w] < INF)
        {
            cout << stt[v][w] << endl;
            continue;
        }

        bool vtd[1001] = {0};
        priority_queue<p, vector<p>, greater<p>> q;
        q.push(p(0, v));

        while (!q.empty() && vt < n)
        {
            p cn = q.top();
            q.pop();
            int cur = cn.second;
            if (vtd[cur])
                continue;
            vtd[cur] = 1;
            vt++;

            for (int i = 0; i < g[cur].size(); i++)
            {
                p line = g[cur][i];
                int ww = line.second;
                ll weight = line.first;
                if (stt[v][ww] > stt[v][cur] + weight)
                {
                    stt[v][ww] = stt[v][cur] + weight;
                    q.push(p(stt[v][ww], ww));
                }
            }
        }
        if (stt[v][w] == INF)
            cout << "INF\n";
        else
            cout << stt[v][w] << endl;
    }
    return 0;
}
