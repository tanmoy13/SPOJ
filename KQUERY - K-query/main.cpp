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
#define MOD             100007
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

struct data
{
    int val, idx, ans,l,r;
    bool q;
    data(int a, int b, bool p=0,int tans=0,int lo=0,int rr=0)
    {
        val=a,idx=b,q=p,ans=tans,l=lo,r=rr;
    }
};

vector<data>v;

bool comp(data a, data b)
{
    if(a.val==b.val)
    {
        return a.idx>b.idx;
    }
    else
        return a.val>b.val;
}

bool recomp(data a, data b)
{
    return a.idx<b.idx;
}

int tree[30005];
int ans[200005];
void update(int idx, int val, int nn)
{
    while(idx<=nn)
    {
        tree[idx]+=val;
        idx+= (idx & -idx);
    }
}

int query(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=(idx & -idx);
    }
    return sum;
}

int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    int n;
    sf(n);
    for(int i=1; i<=n; i++)
    {
        int a;
        sf(a);
        v.push_back(data(a,i));
    }

    int m;
    sf(m);
    for(int i=1; i<=m; i++)
    {
        int a,b,c;
        sfff(a,b,c);
        v.push_back(data(c,n+i,1,0,a,b));

    }

    sort(all(v),comp);

    for(int i=0; i<SZ(v); i++)
    {
        if(v[i].q)
        {
            ans[v[i].idx-n-1]= query(v[i].r)-query(v[i].l-1);
        }
        else
        {
            update(v[i].idx,1,n);
        }
    }

    for(int i=0; i<m; i++)
    {
        pf("%d\n",ans[i]);
    }

    return 0;
}
