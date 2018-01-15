///*
//         +-+ +-+ +-+
//         |R| |.| |S|
//         +-+ +-+ +-+
// */
//
//#include <bits/stdc++.h>
//
//#define pii             pair <int,int>
//#define sc              scanf
//#define pf              printf
//#define Pi              2*acos(0.0)
//#define ms(a,b)         memset(a, b, sizeof(a))
//#define pb(a)           push_back(a)
//#define MP              make_pair
//#define db              double
//#define ll              long long
//#define EPS             10E-10
//#define ff              first
//#define ss              second
//#define sqr(x)          (x)*(x)
//#define D(x)            cout<<#x " = "<<(x)<<endl
//#define VI              vector <int>
//#define DBG             pf("Hi\n")
//#define MOD             100007
//#define MAX             10000
//#define CIN             ios_base::sync_with_stdio(0); cin.tie(0)
//#define SZ(a)           (int)a.size()
//#define sf(a)           scanf("%d",&a)
//#define sfl(a)          scanf("%lld",&a)
//#define sff(a,b)        scanf("%d %d",&a,&b)
//#define sffl(a,b)       scanf("%lld %lld",&a,&b)
//#define sfff(a,b,c)     scanf("%d %d %d",&a,&b,&c)
//#define sfffl(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
//#define loop(i,n)       for(int i=0;i<n;i++)
//#define REP(i,a,b)      for(int i=a;i<b;i++)
//#define TEST_CASE(t)    for(int z=1;z<=t;z++)
//#define PRINT_CASE      printf("Case %d: ",z)
//#define CASE_PRINT      cout<<"Case "<<z<<": ";
//#define all(a)          a.begin(),a.end()
//#define intlim          2147483648
//#define inf             1000000
//#define ull             unsigned long long
//
//using namespace std;
//
//
///*----------------------Graph Moves----------------*/
////const int fx[]={+1,-1,+0,+0};
////const int fy[]={+0,+0,+1,-1};
////const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
////const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
////const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
////const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
///*------------------------------------------------*/
//
///*-----------------------Bitmask------------------*/
////int Set(int N,int pos){return N=N | (1<<pos);}
////int reset(int N,int pos){return N= N & ~(1<<pos);}
////bool check(int N,int pos){return (bool)(N & (1<<pos));}
///*------------------------------------------------*/
//
//
//int tree[200005];
//
//void update(int n, int maxx)
//{
//    while(n<=maxx)
//    {
//        tree[n]++;
//        n= n+(n & -n);
//    }
//}
//
//int query(int i, int j)
//{
//    if(i>j) return 0;
//
//    int sum1=0,sum2=0,k=j;
//
//    while(j>0)
//    {
//        sum2+=tree[j];
//        j= j-(j&-j);
//    }
//
//    if(i==k) return sum2;
//
//    while(i>0)
//    {
//        sum1+=tree[i];
//        i=i-(i&-i);
//    }
//
//    return sum2-sum1;
//}
//
//
//
//
//
//int main()
//{
//    ///freopen("in.txt","r",stdin);
//    ///freopen("out.txt","w",stdout);
//
//    int t;
//    sf(t);
//    TEST_CASE(t)
//    {
//
//        int n;
//        sf(n);
//        vector<int> v,ara;
//        map<int,int>mp;
//        loop(i,n)
//        {
//            int a;
//            sf(a);
//            ara.pb(a);
//            v.pb(a);
//        }
//
//        sort(all(v));
//
//        loop(i,n)
//            mp[v[i]]=i+1;
//
//        ll ans=0;
//
//        loop(i,n)
//        {
//            ans+= query(mp[ara[i]]-1,mp[v.back()]);
//            update(mp[ara[i]],mp[v.back()]);
//        }
//
//        printf("%lld\n",ans);
//        ms(tree,0);
//    }
//
//    return 0;
//}
//
//










/*
     If opportunity doesn't knock, build a door.

            +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
            |S|.|S|.|R|.|A|.|S|.|A|.|M|.|K|
            +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

    Success is how high you bounce when you hit bottom.
*/


#include <bits/stdc++.h>

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
#define D(x)             cout<<#x " = "<<(x)<<endl
#define VI               vector <int>
#define DBG              pf("Hi\n")
#define MOD              1000000007
#define CIN              ios_base::sync_with_stdio(0); cin.tie(0)
#define SZ(a)            (int)a.size()
#define sf(a)            scanf("%d",&a)
#define sfl(a)           scanf("%lld",&a)
#define sff(a,b)         scanf("%d %d",&a,&b)
#define sffl(a,b)        scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define stlloop(v)       for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define loop(i,n)        for(int i=0;i<n;i++)
#define REP(i,a,b)       for(int i=a;i<b;i++)
#define RREP(i,a,b)      for(int i=a;i>=b;i--)
#define TEST_CASE(t)     for(int z=1;z<=t;z++)
#define PRINT_CASE       printf("Case %d: ",z)
#define CASE_PRINT       cout<<"Case "<<z<<": "
#define all(a)           a.begin(),a.end()
#define intlim           2147483648
#define infinity         (1<<28)
#define ull              unsigned long long
#define gcd(a, b)        __gcd(a, b)
#define lcm(a, b)        ((a)*((b)/gcd(a,b)))

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

int n;

int ara[2000005];
ll ans;
int temp[2000005];

void func(int l, int r)
{
    if(l==r) return;
    int mid=(l+r)/2;
    func(l,mid);
    func(mid+1,r);

    int i=l,j=mid+1;
    int kk=0;
    int k=0;
    while(i<=mid && j<=r)
    {
        if(ara[i]>ara[j])
        {
            ans+=(mid-i+1);
            temp[k++]=ara[j];
            j++;
        }
        else
        {
            temp[k++]=ara[i];
            i++;
        }
    }
    while(i<=mid)
        temp[k++]=ara[i++];
    while(j<=r)
        temp[k++]=ara[j++];

    for(int i=0; i<k;i++)  ara[l+i]=temp[i];
}

int main()
{

     ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);

    int t;
    sf(t);
    TEST_CASE(t)
    {
        int n;
        sf(n);
        loop(i,n) sf(ara[i+1]);
        ans=0;
        func(1,n);
        pf("%lld\n",ans);
    }

    return 0;
}
