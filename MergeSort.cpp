#include <iostream>
#include <vector>
#define INF 10000000000

using namespace std;
typedef long long ll;
void Merge(vector<ll>& A, ll p, ll q, ll r)
{
    ll n1,n2,i,j;
    cout<<p<<" "<<q<<" "<<r<<endl;
    n1 = q - p + 1;
    n2 = r - q;
    cout<<"n1 es: "<<n1<<endl;
    cout<<"n2 es: "<<n2<<endl;
    vector<ll> L,R;
    for(i = 1; i <= n1; i++)
        L.push_back(A[p+i-1]);
    for(j = 1; j <= n2; j++)
        R.push_back(A[q+j]);
    L.push_back(INF);
    R.push_back(INF);
    for(i = 0; i < L.size(); i++) cout<<L[i]<<" ";
    cout<<endl;
    for(i = 0; i < R.size(); i++) cout<<R[i]<<" ";
    cout<<endl;
    i = 0;
    j = 0;
    for(ll k = p; k <= r; k++)
    {
        if(L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
    return;
}

void MergeSort(vector<ll>& A, ll p, ll r)
{
    ll q;
    if(p < r)
    {
        q = (p+r)/2;
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,r);
    }
    return;
}

int main()
{
    ll n,m,half;
    vector<ll> nums;
    cin>>n;
    for(ll i = 0; i < n; i++)
    {
        cin>>m;
        nums.push_back(m);
    }
    half = (n-1)/2;
    MergeSort(nums,0,n-1);
    for(ll i = 0; i < n; i++) cout<<nums[i]<<" ";
    cout<<endl;
    return 0;
}
