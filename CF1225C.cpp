/*
Question Link - > https://codeforces.com/problemset/problem/1225/C
Hint 1 --- >   n - k*p = summmation(powers of 2)
Hint 2 ---- > check whether that number can be formed
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
    int n,p;
    cin>>n>>p;
    vector<int> vec;
    int i=0;
    int temp = (1<<i) + p;
    while(temp<=1e9){
        vec.PB(temp);
        i ++ ;
        temp = (1<<i) + p;
    }
    if(n==1 && p==1)
        cout<<"-1"<<'\n';
    else{
        int cnt;
        bool ans = false;
        int j = 1;
        while(j<vec.SI() && (n>0)){
            n = n-p;
            cnt = 0;
            int k=31;
            while(k--){
                if((1<<k) & n){
                    cnt ++;
                }
            }
            if(cnt <= j && n>=j){
                cnt = j;
                ans = true;
                break;
            }
            j ++;
        }
        if(ans)
            cout<<cnt<<'\n';
        else
            cout<<"-1"<<'\n';
    }
    return 0;
}
