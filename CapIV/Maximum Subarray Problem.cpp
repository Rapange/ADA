#include <iostream>
#include <vector>
#define MINF -10000000000

using namespace std;
typedef long long ll;
typedef vector<ll> vll;

vll Find_Max_Crossing_Subarray(vll& A, ll low, ll mid, ll high)
 {
     ll left_sum = MINF, sum = 0, max_left = 0, right_sum = MINF, max_right = 0;
     vll ans;
     for(ll i = mid; i >= low; i--)
     {
         sum+=A[i];
         if(sum > left_sum)
         {
             left_sum = sum;
             max_left = i;
         }
     }
     sum = 0;
     for(ll j = mid + 1; j <= high; j++)
     {
         sum+=A[j];
         if(sum > right_sum)
         {
             right_sum = sum;
             max_right = j;
         }
     }
     ans.push_back(max_left);
     ans.push_back(max_right);
     ans.push_back(left_sum+right_sum);
     return ans;
 }

vll Find_Maximum_Subarray(vll& A, ll low, ll high)
{
    vll ans;
    if(high == low)
    {
        ans.push_back(low);
        ans.push_back(high);
        ans.push_back(A[low]);
    }
    else
    {
        ll mid = (low + high) / 2;
        vll a = Find_Maximum_Subarray(A, low, mid);
        vll b = Find_Maximum_Subarray(A,mid+1,high);
        vll c = Find_Max_Crossing_Subarray(A,low,mid,high);
        if(a[2] >= b[2] and a[2] >= c[2])
        {
            ans.push_back(a[0]); ans.push_back(a[1]); ans.push_back(a[2]);
            return ans;
        }
        else if(b[2] >= a[2] and b[2] >= c[2])
        {
            ans.push_back(b[0]); ans.push_back(b[1]); ans.push_back(b[2]);
            return ans;
        }
        else
        {
            ans.push_back(c[0]); ans.push_back(c[1]); ans.push_back(c[2]);
            return ans;
        }
    }
}

int main()
{
    ll n,x;
    vll a, ans;
    cin>>n;
    for(ll i = 0; i < n; i++)
    {
        cin>>x;
        a.push_back(x);
    }
    x = (n-1)/2;
    ans = Find_Maximum_Subarray(a,0,n-1);
    for(ll i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
