#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct homework{
  int ddl;//dead-line
  int score;
};
bool operator < (const homework & a,const homework & b){
  return (a.ddl<b.ddl)||(a.ddl==b.ddl&&a.score>b.score);
};

priority_queue<int,vector<int>,greater<int> > q;
homework a[1000001];
int n;

int main(){
  cin>>n;
  for(int i=1;i<=n;++i){
    cin>>a[i].ddl>>a[i].score;
  }
  sort(a+1,a+1+n);
  for(int i=1;i<=n;++i){
    q.push(a[i].score);
    if(q.size()>a[i].ddl){
      q.pop();
    }
  }
  int ans=0;
  while(!q.empty()){
    ans+=q.top();
    q.pop();
  }
  cout<<ans;
}
