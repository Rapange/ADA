#include <iostream>
#include <vector>
#include <chrono>
#define INF 9999999

using namespace std;
typedef long long ll;

ll BOTTOM_UP_CUT_ROD(vector<ll>& p, ll n)
{
    ll q;
    vector<ll> r(n+1);
    r[0] = 0;
    for(ll j = 1; j <= n; j++)
    {
        q = -1*INF;
        for(ll i = 1; i <= j; i++)
        {
            q = max(q,p[i]+r[j-i]);
        }
        r[j] = q;
    }
    return r[n];
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
    cout<<BOTTOM_UP_CUT_ROD(prices,length)<<endl;
    Clock::time_point t1 = Clock::now();
    milliseconds ms = chrono::duration_cast<milliseconds>(t1-t0);
    cout<< ms.count() << " ms\n";
    return 0;
}