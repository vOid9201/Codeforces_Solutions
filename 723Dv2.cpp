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
    int t,n;
    cin>>t;
    W(t){
        cin>>n;
        if((n%11 == 0)   || (n%111 == 0))
            cout<<"YES"<<'\n';
        else{
            bool ans = false;
            while(n > 111){
                n = n-111;
                if(n%11 == 0){
                    ans = true;
                    break;
                }
            }
            if(ans)
                cout<<"YES"<<'\n';
            else
                cout<<"NO"<<'\n';
        }
    }
    return 0;
}