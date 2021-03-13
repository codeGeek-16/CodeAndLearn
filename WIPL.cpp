/*
Author : Harsh Agrawal
Codechef : harshagrawal16
*/

#include<bits/stdc++.h>
using namespace std;

#define ll    long long
#define vll   vector<ll> 
#define vvll  vector<vll>
#define vvvll vector<vvll>
#define for0(i,n)  for(ll i=0; i<n ; i++)
#define fastIO                  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


bool comp(ll a, ll b){
    return a>b;
}

void solve(){

    ll n,k,totalHeight = 0;
    cin>>n>>k;
    
    //bfs
    queue<pair<ll,ll>> q;
    vector<vector<bool>> visited(4001, vector<bool> ( 4001, false));

    vll boxes = vll (n);

    for0(i,n){
        cin>>boxes[i];
        totalHeight+=boxes[i];
    }
    
    //sorting the boxes in descending order
    sort(boxes.begin(), boxes.end(), comp);

    if(totalHeight < 2*k || n==1){
        cout<<-1<<endl;
        return;
    }

    ll level = 0;
    q.push({min(boxes[0],k), 0});

    while(!q.empty()){

        totalHeight -= boxes[level];
        
        ll a, b, heightLeft;
        ll size = q.size();
       
        for(int i=0;i<size;i++){
            a = q.front().first;
            b = q.front().second;
            q.pop();

            if(a>=k && b>=k){
                cout<<level+1<<endl;
                return;
            }

            //a<=k && b<=k
            heightLeft = 2*k - (a + b);

            if(totalHeight >= heightLeft && !visited[a][b] && !visited[b][a]) {
                if(a<k) q.push({min(a + boxes[level+1], k), b});
                if(b<k && a!=b) q.push({a, min(b + boxes[level+1], k)});
            }
            
            visited[a][b] = true;
            visited[b][a] = true;
        }
        level++;
     }

     cout<<-1<<endl;
     return;
}



int main(){
    fastIO;
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}
