#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 struct Interval {
     int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval>insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
      vector<Interval>res;
    int n = intervals.size();

    if(newInterval.start > newInterval.end)
    {
        swap(newInterval.start , newInterval.end);
    }
     if(n == 0)
    {
        res.push_back(newInterval);
        return res;
    }
    int l = newInterval.start;
    int r = newInterval.end;

    int merge = 0;
    if(newInterval.end < intervals[0].start)
    {
        res.push_back(newInterval);
        merge = 1;
    }
     else if(newInterval.start < intervals[0].start && newInterval.end > intervals[intervals.size() - 1].end)
    {
        res.push_back(newInterval);
        return res;
    }
    for(int i = 0; i < n; i++)
    {
        if(!merge && (newInterval.start >= intervals[i].start) && (newInterval.start <= intervals[i].end))
        {
            merge = 1;
            l = intervals[i].start;
            while((i < n) && (newInterval.end > intervals[i].end))
            {
                i++;
            }
            if(i < n)
            {
                if((newInterval.end >= intervals[i].start) && (newInterval.end <= intervals[i].end))
                {
                    r = intervals[i].end;
                    res.push_back(Interval(l,r));
                    continue;
                }
                else
                    res.push_back(Interval(l,r));

            }
            else
            {
                res.push_back(Interval(l,r));
                break;
            }
        }
         else if(!merge && (newInterval.end < intervals[i].end) && (newInterval.end >= intervals[i].start))
        {
            res.push_back(Interval(l,intervals[i].end));
            merge = 1;
            continue;
        }
        else if(!merge && (newInterval.end < intervals[i].start))
        {
            res.push_back(Interval(l,r));
            merge = 1;
        }
        res.push_back(intervals[i]);
    }
    if(!merge)
    {
        if(newInterval.start > intervals[intervals.size() - 1].end)
        {
            res.push_back(newInterval);
        }
    }

    return res;
}


int main()
{
    int n;
    cin>>n;
    vector<Interval>A;
    int s,e;
    for(int i = 0; i < n; i ++)
    {

        cin>>s>>e;
        A.push_back(Interval(s,e));
    }
    cin>>s>>e;
    Interval interval;
    interval = Interval(s,e);
    vector<Interval>res;
    res = insert(A,interval);
    for(int i = 0; i < res.size(); i++)
    {
        cout<<"("<<res[i].start<<","<<res[i].end<<")";
        if(i != res.size() - 1)
            cout<<",";
    }
    cout<<endl;
    return 0;
}
