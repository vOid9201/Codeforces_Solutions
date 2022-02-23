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

bool minimumPowerRequire(vector<int> arr[] , int order[] , int power , int n){
    for(int i=0;i<n;i++){
        for(auto it = arr[order[i]].begin();it!=arr[order[i]].end();it++){
            if(power > (*it))
                power ++ ;
            else
                return false;
        }
    }
    return true;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x,y;
    cin>>t;
    W(t){
        cin>>n;
        int maxi = INT_MIN;
        vector<int> arr[n];
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            cin>>x;
            int j = 0;
            int pos;
            W(x){
                cin>>y;
                maxi = max(maxi , y-j);
                arr[i].PB(y);
                j ++;
            }
            vec.PB(MP(maxi,i));
            maxi = INT_MIN;
        }
        sort(vec.begin(),vec.end());
        int order[n];
        int i = 0;
        for(auto it=vec.begin();it!=vec.end();it++){
            order[i] = it->second;
            i ++;
        }
        int lo = 1 , hi = 1e9;
        while(hi - lo > 1){
            int mid = (hi + lo)/2;
            if(minimumPowerRequire(arr,order,mid,n))
                hi = mid;
            else
                lo = mid+1;
        }
        if(minimumPowerRequire(arr,order,lo,n))
            cout<<lo<<'\n';
        else if(minimumPowerRequire(arr,order,hi,n))
            cout<<hi<<'\n';
        else    
            cout<<"1000000001"<<'\n';
    }
    return 0;
}