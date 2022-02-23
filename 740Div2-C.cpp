question link - https://codeforces.com/problemset/problem/1561/C
things to understand -> in this question greedy will be used so that we can determine the optimal order to move among the caves 
                        first i was doing finding maximum within the caves and then sorting them in an increasing order but then 
                        to mind that i can only visit the cave when i instead of using maximum value using (value - increae in power)
                        as for eg
                        2
                        4 21 19 10 22 -> max = 22 but wahan tak pahunchne ke liye 4 step liye toh answer = 18 but to cross 21 i need 22 that's why 
                        order is not decided by max but by value - power increase till then
after understanding this just appllied binary_search  : ) 

code for the same  -  >    
 
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
