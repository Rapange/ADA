#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> Recursive_Activity_Selector(vector<ll>& s, vector<ll>& f, ll k, ll n)
{
    ll m = k+1;
    vector<ll> ans;
    while(m < n and s[m] < f[k])
    {
        m++;
    }
    if(m<n)
    {
        ans = Recursive_Activity_Selector(s,f,m,n);
        ans.push_back(m);
        return ans;
    }
    else return ans;
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
    a = Recursive_Activity_Selector(s,f,0,n);
    for(ll i = 0; i < a.size(); i++) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}