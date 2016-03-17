#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

void insertion_sort(vector<ll>& nums)
{
    ll key, i;
    for(ll j = 1; j < nums.size(); j++)
    {
        key = nums[j];
        i = j-1;
        while(i > -1 and nums[i] > key)
        {
            nums[i+1] = nums[i];
            i = i-1;
        }
        nums[i+1] = key;
    }
    return;
}

int main()
{
    ll num, n;
    vector<ll> nums;
    cin>>n; //cantidad de elementos.
    for(ll i = 0; i < n; i++)
    {
        cin>>num; //los elementos.
        nums.push_back(num);
    }
    insertion_sort(nums);
    for(ll i = 0; i < n; i++)  cout<<nums[i]<<" ";
    return 0;
}
