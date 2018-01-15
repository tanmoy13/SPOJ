#include <bits/stdc++.h>

#define pf              printf

#define ll              long long

#define sf(a)           scanf("%d",&a)
#define sfl(a)          scanf("%lld",&a)
#define sff(a,b)        scanf("%d %d",&a,&b)
#define sffl(a,b)       scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)     scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
#define loop(i,n)       for(int i=0;i<n;i++)
#define REP(i,a,b)      for(int i=a;i<b;i++)
#define TEST_CASE(t)    for(int z=1;z<=t;z++)
#define PRINT_CASE      printf("Case %d: ",z)

using namespace std;

int startpoint[1000006];
int endpoint[1000006];
int past[1000006];

int query( int (&tree)[1000006], int i)
{
    int sum=0;
    while(i>0)
    {
        sum+=tree[i];
        i = i - (i & -i);
    }
    return sum;
}


void update(int (&tree)[1000006],int i, int x)
{
    while(i<=1000006)
    {
        tree[i]+=x;
        i = i + (i & -i);
    }
}

int main()
{
    int t;
    sf(t);
    TEST_CASE(t)
    {
        int a,b,temp1,temp2;
        sff(a,b);
        int ans=0;
        ans+=query(startpoint,a-1)-query(endpoint,a);
        temp1=ans;
        ans+=query(startpoint,b-1)-query(endpoint,b);
        temp2=ans-temp1;
        if(ans)
        ans-=(past[a]+past[b]);
        printf("%d\n",ans);
        past[a]=temp1;
        past[b]=temp2;
        update(startpoint,a,1);
        update(endpoint,b,1);

    }
    return 0;
}
