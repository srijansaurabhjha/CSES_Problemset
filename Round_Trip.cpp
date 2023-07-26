#include <bits/stdc++.h>
using namespace std;


#define ll long long

ll mod =1e9+7;
ll Mod(ll x){
   return (((x%mod)+mod)%mod);
}

vector<int>vis,par;
int cycle_start,cycle_end;

int f(int node,vector<int>adj[],int parent){
   vis[node]=1;   
   for(auto& it:adj[node]){
      if(it==parent)continue;
      if(vis[it]){
         //cycle found
         cycle_start=it;
         cycle_end=node;
         return 1;
      }
      if(vis[it]==0){
         par[it]=node;
         if(f(it,adj,node))return 1;
      }
   }
   return 0;
}

void solve(){
   int n,e;
   cin>>n>>e;
   vector<int>adj[n];
   for(int i=0;i<e;i++){
      int a,b;
      cin>>a>>b;
      a--;
      b--;
      adj[a].push_back(b);
      adj[b].push_back(a);
   }
   vis.assign(n,0);
   par.assign(n,-1);
   cycle_start=-1;

   for(int i=0;i<n;i++){
      if(vis[i]==1)continue;
      if(f(i,adj,par[i]))break;
   }

   if(cycle_start==-1){
      cout<<"IMPOSSIBLE";
   }else{
      vector<int>cycle;
      for(int v=cycle_end;v!=cycle_start;v=par[v]){
         cycle.push_back(v);
      }
      cycle.push_back(cycle_start);

      cout<<cycle.size()+1<<endl;
      for(int i=cycle.size()-1;i>=0;i--){
         cout<<cycle[i]+1<<" ";
      }
      cout<<cycle.back()+1<<" ";
      cout<<endl;
   }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ll t;
   // cin >> t;
   t=1;
   while (t--)
   {
      solve();
   }
   return 0;
}

