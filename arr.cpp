#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;
struct ad
{
      int pos,left;
      ad(int a, int c)
      {
          pos = a;
          left = c;
      }
};
int main()
{
    int n,t=0,av,ex=0,m =0;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
            cin>>a[i];
            t+=a[i];
    }
    av = t/n;
    queue<ad> q;
    for(int i=0;i<n;i++)
    {
            if(ex==0)
            {
                     ex = a[i];
                     ad a1(i+1,a[i]-av);
                     q.push(a1);
            }
            else
            {
                if(ex+a[i] == 0)
                {
                 while(!q.empty())
                 {
                  m+=abs(q.front().pos-i)*q.front().left;
                  q.pop();
                 }
                }
                else
                {
                    if((ex + a[i]-av)*ex<0)
                    {
                     while(!q.empty())
                     {          
                                m+=abs(q.front().pos-i)*q.front().left;
                                q.pop();
                     }
                     ad a1(i+1,a[i]-av+ex);
                     q.push(a1);
                     ex = a[i]-av+ex;
                    }
                    else
                    {
                        int su =0;
                        while(su<a[i]-av)
                        {
                                         su+=q.front().left;
                                         m+=abs(q.front().pos-i)*q.front().left;
                                         q.pop();
                        }
                        m+=(a[i]-av)*(q.front().pos-i);
                        q.front().left-=(su-a[i]+av);
                    }
                }
            }
    }
    cout<<m;
    return 0;
}
                            
                            
            
