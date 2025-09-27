#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using State = pair<ll, int>;

struct Elev
{
    int a, b;
    int d;
    int cycle;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, N;
    if (!(cin >> K >> N))
        return 0;

    vector<Elev> es;
    es.reserve(N);
    vector<vi> byFloor(K + 1);

    for (int i = 0; i < N; ++i)
    {
        int A, B;
        cin >> A >> B;
        int d = (B - A) * 5;
        es.push_back({A, B, d, 2 * d});
        byFloor[A].push_back(i);
        byFloor[B].push_back(i);
    }

    const ll INF = (ll)4e18;
    vector<ll> dist(K + 1, INF);
    dist[1] = 0;

    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0, 1});

    auto arrive_up = [](ll t, int d, int cycle) -> ll
    {
        if (t % cycle != 0)
            t += (cycle - t % cycle);
        return t + d;
    };
    auto arrive_down = [](ll t, int d, int cycle) -> ll
    {
        if (t <= d)
            return d + d;
        ll diff = t - d;
        if (diff % cycle != 0)
            diff += (cycle - diff % cycle);
        ll depart = d + diff;
        return depart + d;
    };

    while (!pq.empty())
    {
        auto [t, f] = pq.top();
        pq.pop();
        if (t != dist[f])
            continue;
        if (f == K)
        {
            cout << t << '\n';
            return 0;
        }
        for (int idx : byFloor[f])
        {
            const auto &e = es[idx];
            if (f == e.a)
            {
                ll arr = arrive_up(t, e.d, e.cycle);
                if (arr < dist[e.b])
                {
                    dist[e.b] = arr;
                    pq.push({arr, e.b});
                }
            }
            else
            {
                ll arr = arrive_down(t, e.d, e.cycle);
                if (arr < dist[e.a])
                {
                    dist[e.a] = arr;
                    pq.push({arr, e.a});
                }
            }
        }
    }

    cout << dist[K] << endl;
    return 0;
}