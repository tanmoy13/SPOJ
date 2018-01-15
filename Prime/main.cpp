#include <bits/stdc++.h>

using namespace std;

#define M 2000

bool valid[M+10];

vector<int>prime;

int k=0;

void sieve()
{
    valid[0]=valid[1]=1;

    for(int i=2; i<M;)
    {
        prime.push_back(i);
        for(int j=i+i; j<M; j+=i)
            valid[j]=1;
        for(++i;;i++)
        {
            if(!valid[i]) break;
        }
    }
}

int main()
{
    freopen("output.txt","w",stdout);

    sieve();

    for(int i=0;i<prime.size();i++)
        printf("%d\n",prime[i]);

    return 0;
}
