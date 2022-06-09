#include<bits/stdc++.h>
using namespace std;
//pipioj1121

struct minSegment
{
    int start;
    int end;
}T[100005];

//设置node按照start从小到大排序
bool cmp(minSegment a,minSegment b)
{
    return a.start<b.start;
}

int main(){
    int n,l,r;
    while(~scanf("%d%d%d",&n,&l,&r)){
        int similar = -1;//当l==r时，用similar来判断是否存在线段过这点
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d",&T[i].start,&T[i].end);
            if(similar==-1&&T[i].start<=l&&T[i].end>=l)similar=1;
        }
        if(l==r){
            printf("%d\n",similar);
        }
        else{
            sort(T,T+n,cmp);
            int ans=0;
            int rLimit=l;
            for(int i=0;i<n;i++){
                //这个线段是否符合条件
                if(T[i].start<=rLimit){
                    if(T[i].end>rLimit){
                        rLimit = T[i].end;
                    }
                }
                else{
                    ans++;
                }
                if(rLimit>=r)break;
            }
           if(rLimit>=r){
                printf("%d\n",ans+1);
            }
            else{
                printf("-1\n");
            }
        }
    }
    return 0;
}
