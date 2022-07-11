#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
struct node{
    int l,r;
    // bool operator<(const node &a)const{
    //     if(r==a.r)return l>a.l;
    //     return r<a.r;
    // }
}process[N];
bool cmp(node a,node b){
    if(a.r==b.r)return a.l>b.l;
    return a.r<b.r;
}
// priority_queue<int,vector<int>,greater<int> >q; ///小根堆

int main(){
    int n,m,T,l,r;
    scanf("%d",&T);
    while (T--)
    {
        //initial part
        int ans = 0; ///record the number that we can deal with
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%d%d",&process[i].l,&process[i].r);
            // process[i].l = l,process[i].r=r;
        }
        
        // while(q.size())q.pop(); ///emptyed priority_queue
        ///core code
        if(n<=m){
            printf("%d\n",n);
            continue;
        }
        if(m==0){
            puts("0");
            continue;
        }
        sort(process,process+n,cmp);
        if(m!=0){
            multiset<int> s;
            s.insert(process[0].r);
            ans++;
            for(int i=1;i<n;++i){
                auto p = s.upper_bound(process[i].l);
                if(p!=s.begin()){
                    ans++;
                    p--;
                    s.erase(p);
                    s.insert(process[i].r);
                }else{
                    if(s.size()<m){
                        ans++;
                        s.insert(process[i].r);
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;   
}


