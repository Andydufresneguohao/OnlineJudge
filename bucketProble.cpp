#include<bits/stdc++.h>
using namespace std;
//pipioj1255
int stick[100005];///存储棍子

int  main(){
    ///n个桶，每个桶由k根棍子组成，两个桶的容量差小于等于L
    int n,k;
    int L;
    ////m表示前m个最短的棍子可以来当最短板
    int m;
    
    scanf("%d%d%d",&n,&k,&L);
    for (int i = 0; i < n*k; i++)       
    {
        scanf("%d",&stick[i]);
    }
    sort(stick,stick+n*k);
    m = upper_bound(stick,stick+n*k,stick[0]+L)-stick;
    //printf("test%d\n",m);
    //ans是n个桶子最大容量和
    long long ans = 0;
    //如果没有足够符合条件的短板组成n个桶子，则输出0
    if(m<n){
        printf("%lld\n",ans);
        return 0;
    }
    ///remian表示还剩下的短板棍子，success表示已经组成或者正在组成的桶子数量，remian+success要大于等于桶子数量n
    int remain = m;
    int success = 0;
    ////bucket是正在组装的桶有几根棍子了
    int bucket = k;
    for(int i=0;i<m;i++){
        ///还可以继续融合小的棍子
        if(remain+success>n){
            ///是当做新桶子的第一根
            if(bucket==k){
                bucket = 1;
                ans+=stick[i];
                success++;///
            }
            ///是加入到之前未完成的桶中
            else{
                bucket++;
            }
        }else{
            //不可以继续融合了那在这里返回结果
            for(;i<m;i++){
                ans = ans + stick[i];///ans加上从i到m的数据
            }
            printf("%lld\n",ans);
            return 0;
        }
        ///每一次循环结束，remian数量应该减少一个
        remain--;
    }
    ////考虑n=1,即只有一个桶子的情况，上面循环会自然退出
    printf("%lld\n",ans);
    return 0;
}
