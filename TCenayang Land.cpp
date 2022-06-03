#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
#define x first
#define y second

int main() {
    int query;
    cin >> query;

    int minimum_area = INT_MAX;
    pair<ll, ll> p[query];

    for(int i=0; i<query;i++)
    {
        cin >> p[i].first >> p[i].second;
    }

    int same = 0;

    for(int i=0; i<query; i++)
        {
        for(int j=i+1; j<query;j++)
        {
            for(int k=j+1;k<query;k++)
            {
                int x = (p[i].x*p[j].y+p[j].x*p[k].y+p[k].x*p[i].y);
                int y = (p[i].y*p[j].x+p[j].y*p[k].x+p[k].y*p[i].x);

                int area = abs(x-y);

                if(area!=0)
                {
                    if(area== minimum_area)
                    {
                        same = minimum_area;
                    }
                    else
                    {
                        minimum_area=min(minimum_area, area);
                    }
                }
            }
        }
    }

    if(same == minimum_area||minimum_area==INT_MAX){
        cout<<"-1.00"<<endl;
    }
    else
    {
        printf("%.2lf\n", double(minimum_area)/2);
    }
    return 0;
}
