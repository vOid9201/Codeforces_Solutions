/*
Question Link -- > https://codeforces.com/problemset/problem/1165/D
Hint1 -- > soting and then multiplication of number
Hint2 -- > cross checking whether all divisors are present
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
map<ll,ll> primeFactors(map<ll,ll> &mp,ll n)
{
    while (n % 2 == 0)
    {
        mp[2] ++ ;
        n = n/2;
    }
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            mp[i] ++ ;
            n = n/i;
        }
    }
    if (n > 2)
        mp[n] ++ ;
    return mp;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    W(t){
        map<ll,ll> mp;
        mp.empty();
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        ll num = arr[0] * arr[n-1];
        bool ans = true;
        int i=0 , j = n-1;
        while(j >= i){
            if(arr[j] * arr[i] != num){
                ans = false;
                break;
            }
            i++ , j--;
        }
        primeFactors(mp,num);
        int x = 1;
        for(auto it=mp.begin();it!=mp.end();it++){
            x = x*(it->se+1);
        }
        x -= 2;
        if(ans && x==n)
            cout<<num<<'\n';
        else
            cout<<"-1"<<'\n';
    }
    return 0;
}
