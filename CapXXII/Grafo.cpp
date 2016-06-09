#include <iostream>
#include <vector>
#include <utility>

using namespace std;
typedef long long ll;
typedef vector<pair<ll,ll> > vll;

void print_graph(vector<vll>& graph)
{
    for(ll i = 0; i < graph.size(); i++)
    {
        cout<<i<<": ";
        for(ll j = 0; j < graph[i].size(); j++)
        {
            cout<<"("<<graph[i][j].first<<", "<<graph[i][j].second<<") ";
        }
        cout<<endl;
    }
    return;
}

int main()
{
    ll num_nodes, num_edges, a, b, weight;
    cin>>num_nodes>>num_edges;
    vector<vll> graph(num_nodes);
    for(ll i = 0; i < num_edges; i++)
    {
        cin>>a>>b>>weight;
        graph[a].push_back(make_pair(b,weight));
    }
    print_graph(graph);
    return 0;
}
