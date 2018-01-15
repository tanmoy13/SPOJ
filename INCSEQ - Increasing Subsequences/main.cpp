/*
         +-+ +-+ +-+
         |R| |.| |S|
         +-+ +-+ +-+
*/

#include <bits/stdc++.h>

#define pii             pair <int,int>
#define sc              scanf
#define pf              printf
#define Pi              2*acos(0.0)
#define ms(a,b)         memset(a, b, sizeof(a))
#define pb(a)           push_back(a)
#define MP              make_pair
#define db              double
#define ll              long long
#define EPS             10E-10
#define ff              first
#define ss              second
#define sqr(x)          (x)*(x)
#define D(x)            cout<<#x " = "<<(x)<<endl
#define VI              vector <int>
#define DBG             pf("Hi\n")

#define MAX             10000
#define CIN             ios_base::sync_with_stdio(0); cin.tie(0)
#define SZ(a)           (int)a.size()
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
#define CASE_PRINT      cout<<"Case "<<z<<": ";
#define all(a)          a.begin(),a.end()
#define intlim          2147483648
#define inf             1000000
#define ull             unsigned long long

using namespace std;


/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/

int tree[100005];
int ara[10005];
int n,k;
int dp[100005];
int mod=5000000;

void update(int idx, int val)
{
    while(idx<=100000)
    {
        tree[idx]+=val;
        if(tree[idx]>=mod) tree[idx]-=mod;
        idx = idx + (idx & -idx);
    }
}


int query(int idx)
{

    int sum=0;

    while(idx>0)
    {
        sum+=tree[idx];
        idx-=(idx & -idx);
        if(sum>=mod)sum-=mod;
    }
    return sum;
}

int main()
{
    //freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);

    sff(n,k);
    int idxx=1;

    int sum=0;

    loop(i,n)
    {
        sf(ara[i]);
        ara[i]++;
        int temp=query(ara[i]-1);
        dp[i]=temp;
        update(ara[i],1);
    }



    if(k==1)
    {
        pf("%d\n",n);
        return 0;
    }

    while(idxx<k)
    {
        ms(tree,0);
        sum=0;
        idxx++;
        loop(i,n)
        {
            int temp=query(ara[i]-1);
//            update(ara[i],1,limm,idxx-1);
            update(ara[i],dp[i]);
            dp[i]=temp;
        }
    }

    pf("%d\n",query(100000));

    return 0;
}
