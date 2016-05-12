#include <iostream>
#include <queue>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
    deque<ll> P,M,X,S;
    ll n,x,k;
    ld lo,hi,mid,L,newL;
    cin>>n;
    P.resize(n,0);
    M.resize(n+1,0);
    X.resize(n+1,0);
    for(ll i = 0; i < n; i++)
    {
        cin>>x;
        X[i] = x;
    }
    L  = 0;
    for(ll i = 0; i < n; i++)
    {
        lo = 1;
        hi = L;
        while(lo <= hi)
        {
            mid = ceil((lo+hi)/2.0);
            if(X[M[mid]] < X[i]) lo = mid+1;
            else hi = mid-1;
        }
        newL = lo;
        P[i] = M[newL-1];
        M[newL] = i;
        if(newL > L) L = newL;
    }
    k = M[L];
    for(ll i = L-1; i > -1; i--)
    {
        S.push_front(X[k]);
        k = P[k];
    }
    for(ll i = 0; i < S.size(); i++) cout<<S[i]<<" ";
    cout<<endl;
    return 0;
}