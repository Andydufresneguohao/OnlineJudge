#include<bits/stdc++.h>
using namespace std;
const int INF=1E9;
struct node
{
        int x,y;
}E[100005];
bool cmp(node a,node b)
{
        if(a.x==b.x)
                return a.y<b.y;
        else
                return a.x<b.x;
}
int n;
int main()
{
        while(scanf("%d",&n)!=EOF)
        {
                int ans = -INF;
                for(int i=0;i<n;i++)
                {
                        int u,v;
                        scanf("%d%d",&u,&v);
                        E[i].x=u,E[i].y=v;
                        ans=max(ans,v);
                }
                sort(E,E+n,cmp);
                priority_queue<int,vector<int>,greater<int> >q;
                int now =0,pos=0,sum=0;
                while(now<=ans)
                {
                        while(pos<n&&E[pos].x<=now)//use pos record current time
                        {
                                q.push(E[pos++].y);
                        }
                        while(q.size()) ///if queue not empty
                        {
                                int end_time=q.top();
                                q.pop();
                                if(end_time<now)
                                        continue;
                                sum++;
                                break;
                        }
                        now++;
                }
                printf("%d\n",sum);
        }
        return 0;
}
