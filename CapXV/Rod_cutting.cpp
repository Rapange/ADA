#include <iostream>
#include <vector>
#define MAX 10000

using namespace std;
typedef long long ll;

ll dp[MAX+1] = {0};
ll prices[MAX+1] = {0};
vector<ll> cuts[MAX+1];

ll rod_cutting(ll length)
{
    if(dp[length] != 0) return dp[length];
    ll max_price = prices[length], holder_price;
    cuts[length].push_back(length);
    for(ll i = 1; i < length; i++)
    {
        holder_price = rod_cutting(i)+rod_cutting(length-i);
        if(max_price < holder_price)
        {
            max_price = holder_price;
            cuts[length].clear();
            cuts[length].push_back(i);
            cuts[length].push_back(length-i);
        }
    }
    dp[length] = max_price;
    return max_price;
}

void desdoble(ll length, vector<ll>& ans)
{
    if(length == cuts[length][0])
    {
        ans.push_back(length);
        return;
    }
    for(ll i = 0; i < cuts[length].size(); i++)
    {
        desdoble(cuts[length][i], ans);
    }
    return;
}

int main()
{

    ll length, price;
    vector<ll> desdobleado;
    cin>>length;
    for(ll i = 1; i <= length; i++)
    {
        cin>>price;
        prices[i] = price;
    }
    cout<<rod_cutting(length)<<endl;
    desdoble(length, desdobleado);
    for(ll i = 0; i < desdobleado.size(); i++) cout<<desdobleado[i]<<" ";
    return 0;
}
