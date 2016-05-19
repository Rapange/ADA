#include <iostream>
#include <vector>
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
    ll length, price;
    cin>>length;
    vector<ll> prices(length+1);
    for(ll i = 1; i <= length; i++)
    {
        cin>>price;
        prices[i] = price;
    }
    cout<<BOTTOM_UP_CUT_ROD(prices,length);
    return 0;
}
