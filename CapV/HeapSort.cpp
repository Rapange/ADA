#include <iostream>
#include <deque>
#define INF 999999

using namespace std;
typedef long long ll;
typedef deque<ll> vll;

void MAX_HEAPIFY(vll& A, ll i, ll j)
{
    ll l = 2*i;
    ll r = l+1;
    ll largest = 0;
    if(l < j and A[l] > A[i]) largest = l;
    else largest = i;
    if(r < j and A[r] > A[largest]) largest = r;
    if(largest != i)
    {
        swap(A[i], A[largest]);
        MAX_HEAPIFY(A,largest,j);
    }
    return;
}

void  BUILD_MAX_HEAP(vll& A)
{
    for(ll i = A.size()/2; i > 0; i--)
    {
        MAX_HEAPIFY(A,i,A.size());
    }
}

void HEAPSORT(vll& A)
{
    ll j = A.size();
    BUILD_MAX_HEAP(A);
    for(ll i = A.size()-1; i > 1; i--)
    {
        swap(A[1],A[i]);
        j--;
        MAX_HEAPIFY(A,1,j);
    }
}

int main()
{
    ll n,x;
    vll A;
    cin>>n;
    A.push_back(INF);
    for(ll i = 0; i < n; i++)
    {
        cin>>x;
        A.push_back(x);
    }
    BUILD_MAX_HEAP(A);
    HEAPSORT(A);
    A.pop_front();
    for(ll i = 0; i < A.size(); i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}

