#include<bits/stdc++.h>
using namespace std;

int product(vector<int> from,vector<int> to,vector<int> w) {
    // assigning set of friend_nodes to their shared weights
    //   Wieghts      nodes
    //     1         {1,2,3}  
    //     2         {1,2}
    //     3         {2,3,4}
    map<int,set<int>> m;
    for(int i=0;i<to.size();i++)
    {
        m[w[i]].insert(from[i]);
        m[w[i]].insert(to[i]);
    }
    
    //make set of pairs for each weight 
    //   Wieghts      nodes
    //     1         (1,2),(2,3),(1,3)  
    //     2         (1,2)
    //     3         (2,3),(3,4),(2,4)
    //count no of pairs 
    //    (1,2)    2
    //    (2,3)    2
    //    (1,3)    1
    //    (3,4)    1
    //    (2,4)    1
    map<pair<int,int>,int> p;
    int max=INT_MIN;
    int max_product=INT_MIN;
    for(auto it=m.begin();it!=m.end();it++)
    {
        set<int> s=it->second;
        vector<int> v(s.begin(),s.end());
        int siz=v.size();
        for(int i=0;i<siz-1;i++)
        {
            p[make_pair(v[i],v[i+1])]++;
            if(max<p[make_pair(v[i],v[i+1])]) max=p[make_pair(v[i],v[i+1])];
        }
        if(siz>2)
        {
            p[make_pair(v[0],v[siz-1])]++;
            if(max<p[make_pair(v[0],v[siz-1])]) max=p[make_pair(v[0],v[siz-1])];
        }
    }
    //since max shared weights is 2 ,we have two pairs
    //    (1,2)    2
    //    (2,3)    2
    //  The product of first pair  (1,2) = 1*2 = 2
    //  The product of second pair (2,3) = 2*3 = 6
    // So , we return maximum product among the above two (i.e) 6
    for(auto itr=p.begin();itr!=p.end();itr++)
    {
        pair<int,int> pr=itr->first;
        if(itr->second==max)
            if(max_product<pr.first*pr.second)
                max_product=pr.first*pr.second;
    }
    return max_product;
}

int main() {
int nodes=4,edges=5;

vector<int> from =  {1, 1, 2, 2, 2};
vector<int> to =   {2, 2, 3, 3, 4};
vector<int> wt =  {1, 2, 1, 3, 3 };

cout<<product(from,to,wt);
}
