#include <iostream>
#include <vector>
#include <utility>
#include <deque>
#define INF 999999999

using namespace std;
typedef long long ll;
typedef vector<pair<ll,ll> > vpll;
ll time;

struct Nodo
{
    int m_color;
    ll m_id;
    ll m_d;
    ll m_f;
    Nodo* m_pi;
    vector<pair<Nodo*, ll> > m_adj;
    Nodo(ll id)
    {
        m_id = id;
        m_d = 0;
        m_color = 0;
        m_pi = NULL;
        m_f = 0;
    }
};

void DFS_VISIT(vector<Nodo*>& graph, Nodo* u)
{
    cout<<u->m_id<<endl;
    Nodo* v;
    time = time+1;
    u->m_d = time;
    u->m_color = 1;
    for(ll i = 0; i < u->m_adj.size(); i++)
    {
        v = u->m_adj[i].first;
        if(v->m_color == 0)
        {
            v->m_pi = u;
            DFS_VISIT(graph,v);
        }
    }
    u->m_color = 2;
    time = time + 1;
    u->m_f = time;
}

void DFS(vector<Nodo*>& graph)
{
    for(ll i = 0; i < graph.size(); i++)
    {
        graph[i]->m_color = 0;
        graph[i]->m_pi = NULL;
    }
    time = 0;
    for(ll i = 0; i < graph.size(); i++)
    {
        if(graph[i]->m_color == 0)
        {
            DFS_VISIT(graph,graph[i]);
        }
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
    DFS(graph);
    return 0;
}
