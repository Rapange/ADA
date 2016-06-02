#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> greedy_activity_selector(vector<ll>& s, vector<ll>& f)
{
    ll n = s.size();
    vector<ll> A;
    ll k = 0;
    for(ll m = 1; m < n; m++)
    {
        if(s[m] >= f[k])
        {
            A.push_back(m);
            k = m;
        }
    }
    return A;
}

int main()
{
    ll n,x;
    vector<ll> s,f,a;
    s.push_back(0);
    f.push_back(0);
    cin>>n;
    for(ll i = 0; i < n; i++)
    {
        cin>>x;
        s.push_back(x);
        cin>>x;
        f.push_back(x);
    }
    a = greedy_activity_selector(s,f);
    for(ll i = 0; i < a.size(); i++) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}