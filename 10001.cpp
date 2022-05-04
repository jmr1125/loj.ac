#include <iostream>
#include <algorithm>
using namespace std;

int n,b,h;
struct node{
  int b,e,t;
};
bool operator < (const node & a,const node & b){
  return (a.b<b.b)||(a.b==b.b&&a.e<=b.e);
}

node seg[30001];
bool use[30001];
int main(){
  cin>>n;
  cin>>h;
  for(int i=1;i<=h;++i){
    cin>>seg[i].b>>seg[i].e>>seg[i].t;
  }
  sort(seg+1,seg+1+h);
  for(int i=1;i<=h;++i){
    // //disp seg
    // cout<<seg[i].b<<' '<<seg[i].e<<' '<<seg[i].t<<endl;
    int cnt=0;
    for(int j=seg[i].b;j<=seg[i].e;++j){
      cnt+=use[j];
    }
    
    // //disp cnt
    // cout<<"cnt: "<<cnt<<endl;
    
    if(cnt>=seg[i].t){
      continue;
    }


    cnt=seg[i].t-cnt;

    // //disp cnt
    // cout<<"cnt: "<<cnt<<endl;
    for(int j=seg[i].e;j>=seg[i].b;--j){
      if(!use[j]){
	use[j]=1;
	--cnt;
      }
      if(cnt==0){
	break;
      }
    }

    // //disp use
    // for(int i=1;i<=n;++i){
    //   cout<<use[i];
    // }
    // cout<<endl;
    // //disp end
  }

  int ans=0;
  for(int i=1;i<=30000;++i){
    ans+=use[i];
  }
  cout<<ans;
  return 0;
}
