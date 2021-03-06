#include <iostream>
#include <vector>
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
    ll length, price;
    cin>>length;
    vector<ll> prices(length+1);
    for(ll i = 1; i <= length; i++)
    {
        cin>>price;
        prices[i] = price;
    }
    cout<<CUT_ROD(prices,length)<<endl;
    return 0;
}