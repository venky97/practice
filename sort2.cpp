#include <bits/stdc++.h>

using namespace std;
void print(vector<string> a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }
}
bool compare(string s1,string s2)
{
    if(s1.size()>s2.size())
      return true;
    else if(s2.size()>s1.size())
      return false;
    else
      for(int i=0;i<s1.size();i++)
      {
            if(s1[i]>s2[i])
            {
               return true;
            }
            else if(s2[i]>s1[i])
                return false;
      }
    return true;
}
void sort(vector<string> &a)
{
    int i,j;
    for(i=0;i<a.size();i++)
    {
        string t = a[i];
  //      cout<<"loop "<<i+1<<" : "<<t<<endl;
        for(j=i-1;j>=0;j--)
        {
            if(compare(t,a[j]))
            {
              //  cout<<t<<" is greater than "<<a[j]<<endl;
                break;
            }
            else
                //cout<<a[j]<<" is greater than "<<t<<endl;

            a[j+1] = a[j];
        }
        if(j!=i)
            a[j+1] = t;
       // delete t;
      //  print(a);
     //   cout<<endl;
    }
}

int main(){cc
    int n;
    cin >> n;
    vector<string> unsorted(n);
    for(int unsorted_i = 0; unsorted_i < n; unsorted_i++){
       cin >> unsorted[unsorted_i];
    }
    // your code goes here
    sort(unsorted);
    print(unsorted);
    return 0;
}
c
