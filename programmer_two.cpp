#include<bits/stdc++.h>
using namespace std;
//pipioj1389

struct process
{
    int s,t;
    bool operator > (const process& tmp) const
    {
        if(s == tmp.s)return t>tmp.t;
        else{
            return s>tmp.s;
        }
    }
};

priority_queue<process,vector<process>,greater<process>> pq;
//为什么不能上面这么写？因为大于号没有定义，所以会报错.
//要用小根堆那么结构体就要重载大于号，以便使用greater


int  main(){
    int n;
    while (scanf("%d",&n)!=EOF){
        int answer=0;
        process input;
        int a,b;
        for(int i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            input.s = a;
            input.t = b;
            pq.push(input);
        }
        process now,next;
        while (pq.size())
        {
            now = pq.top();
            pq.pop();
            answer++;
            while (pq.size() && now.s==pq.top().s)
            {
                next = pq.top();
                pq.pop();
                if(next.s<next.t){
                    next.s = next.s + 1;
                    pq.push(next);
                }
            }
        }
        printf("%d\n",answer);
    }
    return 0;
}

