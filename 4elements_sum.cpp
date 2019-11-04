
//Author chanfool21
#include<bits/stdc++.h>

using namespace std;

int main()
{
int t;
cin>>t;
while(t--)
{
int n,x;
cin>>n>>x;
int a[n];
for(int i = 0; i < n; i++)
{
    cin>>a[i];
}
vector<pair<int,pair<int,int> > >vec;
for(int i = 0; i < n-1; i++)
{
    for(int j = i+1; j < n; j++)
    {
        vec.push_back(make_pair(a[i]+a[j],make_pair(i,j)));
    }
}

sort(vec.begin(),vec.end());

int ns = vec.size();

int l = 0;
int h = ns-1;
int flag = 0;
map<string,int>mp;
while(l < h)
{
    if((vec[l].first + vec[h].first) == x)
    {
      //  cout<<"Sum = "<<vec[l].first + vec[h].first<<endl;
        if((vec[l].second.first == vec[h].second.first || vec[l].second.first == vec[h].second.second) || (vec[l].second.second == vec[h].second.first || vec[l].second.second == vec[h].second.second))
        {
            h--;
        }
        else
        {

            flag = 1;
            int arr[4];
            arr[0] = a[vec[l].second.first];
            arr[1] = a[vec[l].second.second];
            arr[2] = a[vec[h].second.first];
            arr[3] = a[vec[h].second.second];
        //    cout<<" Sum found = "<<arr[0]+arr[1]+arr[2]+arr[3]<<endl;
            sort(arr,arr+4);
            string str = "";

            for(int i = 0; i < 4; i++)
            {
                ostringstream oss;
                oss << arr[i];
                str = str + oss.str()+ " ";
                //cout<<arr[i]<<" ";
            }
            if(mp[str] != 1)
            {
                mp[str] = 1;
                cout<<str<<"$";
            }


            l++;

        }
    }
    else if(vec[l].first + vec[h].first < x)
    {
        l++;
    }
    else
    {
        h--;
    }

}

if(flag == 0)
{
    cout<<"$";
}
cout<<endl;

}

return 0;
}
