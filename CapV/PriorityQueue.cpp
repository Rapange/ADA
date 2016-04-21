#include <iostream>
#include <deque>
#define MINF -99999999
#define INF 99999999

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

ll HEAP_MAXIMUM(vll& A)
{
    return A[1];
}

ll HEAP_EXTRACT_MAX(vll& A, ll j)
{
    if(j < 1) {cout<<"heap underflow"<<endl;return -1;}
    ll maximum = A[1];
    A[1] = A[j];
    j = j-1;
    MAX_HEAPIFY(A,1,j);
    return maximum;
}

void HEAP_INCREASE_KEY(vll& A, ll i, ll key)
{
    if(key < A[i]) {cout<<"new key is smaller than current key"<<endl;return;}
    A[i] = key;
    while(i>1 and A[i/2] < A[i])
    {
        swap(A[i], A[i/2]);
        i = i/2;
    }
}

void MAX_HEAP_INSERT(vll& A, ll key, ll j)
{
    j = j+1;
    if(j > A.size()) A.push_back(MINF);
    else A[j-1] = MINF;
    HEAP_INCREASE_KEY(A,j-1,key);
}

void  BUILD_MAX_HEAP(vll& A)
{
    for(ll i = A.size()/2; i > 0; i--)
    {
        MAX_HEAPIFY(A,i,A.size());
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
    /*for(ll i = 0; i < A.size(); i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;*/
    HEAP_INCREASE_KEY(A,9,15);
    A.pop_front();
    for(ll i = 0; i < A.size(); i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}
