#include<bits/stdc++.h>
using namespace std;
//pipioj1386
int process[100005][2];///进程数量

int  main(){
    //定义一个包含两个参数为整数的优先队列
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq2;
    int n;
    while (scanf("%d",&n)!=EOF){
        //if(n==0)break;
        while (pq.size()>0)pq.pop();
        while (pq2.size()>0)pq2.pop();///清空优先队列
        
        for(int i=0;i<n;i++){
            cin>>process[i][0]>>process[i][1];
            pq.push(make_pair(process[i][0],process[i][1]));
        }
        int time=0; 
        int count=1;
        while (true){
            if(pq.size()==0)break;
            while(pq.size()>0){
                pair<int,int> temp=pq.top();
                pq.pop();
                if(temp.first<time){///如果进程的到达时间小于当前时间，则将其加入到优先队列中
                    pq2.push(temp);
                    count++;
                    continue;
                }
                else{///如果进程的到达时间大于当前时间，则将当前时间==进程的执行时间
                    time=temp.second;
                }
            }
            if(pq2.size()==0)break;
            while (pq2.size()>0){
                pair<int,int> temp=pq.top();
                pq2.pop();
                if(temp.second<time){
                    pq.push(temp);
                    count++;
                    continue;
                }
                else{
                    time=temp.second;
                }
            }
        }
       cout<<count<<endl;  
    }
    return 0;
}






