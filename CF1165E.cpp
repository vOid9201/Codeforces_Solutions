/*
Question link - > https://codeforces.com/problemset/problem/1165/E

Hint --- > think of how many number of aibi present 
IMP Point ----- > 1-) apnko every step pf calculation pe check karna chahiye ki overflow ho rha yaa nhi 
                  2-) uske alawa dont use mod if we are performing some sorting or any operations over the processed data
                  3-) and use mod at these places -  >> >  (a+b)== (a%mod + b%mod)% mod , (a*b) == (a%mod * b%mod)%mod 
                      --->>> (a-b) == (a%mod - b%mod + mod)%mod
*/
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
