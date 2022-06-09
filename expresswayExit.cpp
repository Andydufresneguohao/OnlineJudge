#include<bits/stdc++.h>
using namespace std;
#include<math.h>
//pipioj1172

struct village
{
    int x;
    int y;
}T[1005];

struct Range
{
    double l;
    double r;
}Segment[1005];

//设置segment按照l从小到大排序
bool cmp(Range a,Range b)
{
    return a.r<b.r;
}
int main(){
    int L,D;
    while (scanf("%d%d",&L,&D)!=EOF)
    {
        int n;
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d",&T[i].x,&T[i].y);
            //将线段存储在Segment中，且最小不能小于0，最大不能大于L
            Segment[i].l = T[i].x-sqrt(D*D-T[i].y*T[i].y);
            Segment[i].r = T[i].x+sqrt(D*D-T[i].y*T[i].y);
        }
        //按照l进行排序
        sort(Segment,Segment+n,cmp);
        
        //不考虑有村庄距离超过D
        int ans = 1;
    
        double rLimit = Segment[0].r;
        for (int i = 1; i < n; i++)
        {
            ///如果当前村庄不能和之前村庄共用出口
            if(Segment[i].l>rLimit){
                ans++;
                rLimit = Segment[i].r;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
