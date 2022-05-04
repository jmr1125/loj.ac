#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct homework{
  int ddl;//dead-line
  int score;
};
bool operator < (const homework & a,const homework & b){
  return (a.ddl<b.ddl)||(a.ddl==b.ddl&&a.score>b.score);
}

homework a[1000001];

int used=0,ans=0;
int main(){
  cin>>n;
  for(int i=1;i<=n;++i){
    cin>>a[i].ddl>>a[i].score;
  }
  sort(a+1,a+1+n);
  for(int i=1;i<=n;++i){
    if(!(used+1>a[i].ddl)){
      ans+=a[i].ddl;
      used++;
    }
  }
  cout<<ans;
  return 0;
}
