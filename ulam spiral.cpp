#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define boost ios_base::sync_with_stdio(false);
const int n=670;
bool prime[1000005];
int spiral[n][n];
void isPrime()
{
    prime[0]=prime[1]=true;
    prime[2]=false;
    for(int i=2; i*i<1000002; i++)
    {
        if(prime[i]) continue;
        for(int j=2*i; j<1000006; j+=i) prime[j]=true;
    }
}


int main()
{
    boost
    isPrime();
    int len=1,j,i, count=1;
    char dir='R';
    spiral[n/2][n/2]=1;
    i=n/2; j=n/2;
    while(count<n*n+1)
    {
        if(dir=='R')
         {
             int sc=len;
             while(sc)  spiral[i][++j]=++count,sc--;
             dir='U';
         }

        if(dir=='U')
        {
            int sc=len;
            while(sc) spiral[--i][j]=++count, sc--;
            len+=1;
            dir='L';
        }

        if(dir=='L')
        {
            int sc=len;
            while(sc) spiral[i][--j]=++count, sc--;
            dir='D';
        }

        if(dir='D')
        {
            int sc=len;
            while(sc) spiral[++i][j]=++count, sc--;
            dir='R';
            len+=1;
        }
    }

   for(int i=0; i<n; i++)
   {
      for(int j=0; j<n; j++)
        if(i==n/2 && j==n/2) cout<<(char)254;
      else if(!prime[spiral[i][j]]) cout<<'.';
      else cout<<" ";
        cout<<endl;
   }
}
