#include <iostream>
#include <vector>
#include <chrono>
#define INF 999999

using namespace std;
typedef long long ll;


ll MEMOIZED_CUT_ROD_AUX(vector<ll>& p, ll n, vector<ll>& r)
{
    ll q;
    if(r[n] >= 0)
    {
        return r[n];
    }
    if(n == 0)
    {
        q = 0;
    }
    else
    {
        q = -1*INF;
        for(ll i = 1; i <= n; i++)
        {
            q = max(q,p[i]+MEMOIZED_CUT_ROD_AUX(p,n-i,r));
        }
    }
    r[n] = q;
    return q;
}

ll MEMOIZED_CUT_ROD(vector<ll>& p, ll n)
{
    vector<ll> r(n+1);
    for(ll i = 0; i <= n; i++)
    {
        r[i] = -1*INF;
    }
    return MEMOIZED_CUT_ROD_AUX(p,n,r);
}

int main()
{
    typedef chrono::high_resolution_clock Clock;
    typedef chrono::milliseconds milliseconds;
    ll length, price;
    cin>>length;
    vector<ll> prices(length+1);
    for(ll i = 1; i <= length; i++)
    {
        //cin>>price;
        prices[i] = i;
    }
    Clock::time_point t0 = Clock::now();
    cout<<MEMOIZED_CUT_ROD(prices,length)<<endl;
    Clock::time_point t1 = Clock::now();
    milliseconds ms = chrono::duration_cast<milliseconds>(t1-t0);
    cout<< ms.count() << " ms\n";
    return 0;
}