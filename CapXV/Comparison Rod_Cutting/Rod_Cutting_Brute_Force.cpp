#include <iostream>
#include <vector>
#include <chrono>
#define INF 999999

using namespace std;
typedef long long ll;

ll CUT_ROD(vector<ll>& p, ll n)
{
    ll q;
    if(n == 0)
    {
        return 0;
    }
    q = -1*INF;
    for(ll i = 1; i <= n; i++)
    {
        q = max(q,p[i]+CUT_ROD(p,n-i));
    }
    return q;
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
    cout<<CUT_ROD(prices,length)<<endl;
    Clock::time_point t1 = Clock::now();
    milliseconds ms = chrono::duration_cast<milliseconds>(t1-t0);
    cout<< ms.count() << " ms\n";
    return 0;
}