#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define pii              pair <int,int>
#define pll              pair <long long,long long>
#define sc               scanf
#define pf               printf
#define Pi               2*acos(0.0)
#define ms(a,b)          memset(a, b, sizeof(a))
#define pb(a)            push_back(a)
#define MP               make_pair
#define db               double
#define ll               long long
#define EPS              10E-10
#define ff               first
#define ss               second
#define sqr(x)           (x)*(x)
#define D(x)             cerr<<#x " = "<<(x)<<endl
#define VI               vector <int>
#define DBG              pf("Hi\n")
#define MOD              1000000007
#define CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define SZ(a)            (int)a.size()
#define sf(a)            scanf("%d",&a)
#define sfl(a)           scanf("%lld",&a)
#define sff(a,b)         scanf("%d %d",&a,&b)
#define sffl(a,b)        scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define stlloop(v)       for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define loop(i,n)        for(int i=0;i<n;i++)
#define loop1(i,n)       for(int i=1;i<=n;i++)
#define REP(i,a,b)       for(int i=a;i<b;i++)
#define RREP(i,a,b)      for(int i=a;i>=b;i--)
#define TEST_CASE(t)     for(int z=1;z<=t;z++)
#define PRINT_CASE       printf("Case %d: ",z)
#define LINE_PRINT_CASE  printf("Case %d:\n",z)
#define CASE_PRINT       cout<<"Case "<<z<<": "
#define all(a)           a.begin(),a.end()
#define intlim           2147483648
#define infinity         (1<<28)
#define ull              unsigned long long
#define gcd(a, b)        __gcd(a, b)
#define lcm(a, b)        ((a)*((b)/gcd(a,b)))

using namespace std;

//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


/*----------------------Graph Moves----------------*/
const int fx[]= {+1,-1,+0,+0};
const int fy[]= {+0,+0,+1,-1};
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

int grid[102][102], cost[102][102];
bool vis[102][102];
int n,m;

void dfs(int x, int y)
{
    vis[x][y]=1;
    cost[x][y]=grid[x][y];
    for(int i=0; i<4; i++)
    {
        int xx=x+fx[i];
        int yy=y+fy[i];
        if(xx<0 || xx>=n || yy<0 || yy>=m || vis[xx][yy]) continue;
        if(grid[xx][yy]>=grid[x][y])
            dfs(xx,yy);
    }
}

int main()
{

//    freopen("in.txt","r",stdin);
//	  freopen("out.txt","w",stdout);

    int t;
    sf(t);
    TEST_CASE(t)
    {
        sff(n,m);
        for(int i=0; i<n; i++) for(int j=0; j<m; j++)
            {
                sf(grid[i][j]);
                cost[i][j]=infinity;
            }

        for(int i=0; i<n; i++)
        {
            if(!vis[i][0])
                dfs(i,0);
            if(!vis[i][m-1])
                dfs(i,m-1);
        }

        for(int i=0; i<m; i++)
        {
            if(!vis[0][i])
                dfs(0,i);
            if(!vis[n-1][i])
                dfs(n-1,i);
        }

//        for(int i=0; i<n; i++,cout<<endl)
//            for(int j=0; j<m; j++)
//            {
//                printf("%10d",cost[i][j]);
//            }

        while(1)
        {
            bool check=1;
            for(int i=1; i<n-1; i++)
                for(int j=1; j<m-1; j++)
                {
                    if(!vis[i][j])
                    {
                        int mini=infinity;
                        for(int k=0; k<4; k++)
                        {
                            int x=i+fx[k];
                            int y=j+fy[k];
                            mini=min(mini,max(cost[x][y],grid[x][y]));
                        }
                        if(mini<cost[i][j])
                        {
                            check=0;
                            cost[i][j]=mini;
                        }
                    }
                }
            if(check==1) break;

        }
//        cout<<"---------------------"<<endl;
//        for(int i=0; i<n; i++,cout<<endl)
//            for(int j=0; j<m; j++)
//            {
//                printf("%10d",cost[i][j]);
//            }



        int ans=0;
        for(int i=0; i<n; i++) for(int j=0; j<m; j++)
            {
                if(cost[i][j]>grid[i][j])
                ans+=cost[i][j]-grid[i][j];
            }

        printf("%d\n",ans);
        ms(vis,0);

    }

    return 0;
}


