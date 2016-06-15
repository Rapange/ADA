#include <iostream>
#include <vector>
#include <utility>
#include <deque>
#define INF 999999999

using namespace std;
typedef long long ll;
typedef vector<pair<ll,ll> > vpll;

struct Nodo
{
    int m_color;
    ll m_id;
    ll m_d;
    Nodo* m_pi;
    vector<pair<Nodo*, ll> > m_adj;
    Nodo(ll id)
    {
        m_id = id;
        m_d = 0;
        m_color = 0;
        m_pi = NULL;
    }
};

void BFS(vector<Nodo*>& graph, ll s)
{
    Nodo* u;
    Nodo* v;
    for(ll i = 0; i < graph.size(); i++)
    {
        graph[i]->m_color = 0;
        graph[i]->m_d = INF;
        graph[i]->m_pi = NULL;
    }
    graph[s]->m_color = 1;
    graph[s]->m_d = 0;
    graph[s]->m_pi = NULL;
    deque<Nodo*> Q;
    Q.push_front(graph[s]);
    while(!Q.empty())
    {
        u = Q.front();
        cout<<u->m_id<<endl;
        for(ll i = 0; i < u->m_adj.size(); i++)
        {
            v = u->m_adj[i].first;
            if(v->m_color == 0)
            {
                v->m_color = 1;
                v->m_d = u->m_d+1;
                v->m_pi = u;
                Q.push_back(v);
            }
        }
        u->m_color = 2;
        Q.pop_front();
    }
}

int main()
{
    ll v,e,a,b, weight;
    cin>>v>>e;
    vector<Nodo*> graph;
    for(ll i = 0; i < v; i++)
    {
        graph.push_back(new Nodo(i));
    }
    for(ll i = 0; i < e ; i++)
    {
        cin>>a>>b>>weight;
        graph[a]->m_adj.push_back(make_pair(graph[b],weight));
    }
    BFS(graph,0);
    return 0;
}
