#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define IN insert
#define SI size
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define v vector<ll>
#define m map<ll,ll>
#define W(x) while(x--)
#define REV(i,a,b) for(ll i=a;i>=b;i--)

/*code of Sieve which stores least prime factor of a number
vector<int> sieve(1e5+1);
void NewSieveOfEratosthenes(){
    for(int i=1;i<1e5+1;i++)
        sieve[i] = -1;
    for(int p=2;p*p<=1e5;p++){
        if(sieve[p] == -1){
            for(int i=2*p;i<=1e5;i+=p){
                sieve[i] = p;
            }
        }
    }
}
*/

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll mod = 998244353;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        arr[i]= (i+1) * (n-i) * arr[i];
    }
    sort(arr,arr+n);
    ll brr[n];
    for(ll i=0;i<n;i++)
        cin>>brr[i];
    sort(brr,brr+n);
    ll ans = 0;
    ll i = 0 , j = n-1;
    while(( i < n) && (j >= 0)){
        ll temp = ((arr[i] % mod)*(brr[j]))% mod;
        ans += temp;
        i ++ , j --;
    }
    cout<<ans%mod<<'\n';
    
    return 0;
}
