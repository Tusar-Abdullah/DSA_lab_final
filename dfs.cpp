
#include<bits/stdc++.h>
using namespace std;

int visited[5];

int dfs(int G[5][5], int node)
{
    visited[node] = 1;
    cout<<node<<" ";

    for(int i=0; i<5; i++)
        {
            if(G[node][i]==1 && visited[i]==0)
                {
                    dfs(G, i);
                }
        }

}

int main()
{

    int G[5][5] =
    {
        {0,1,0,0,1},
        {1,0,0,1,1},
        {0,0,0,1,0},
        {0,1,1,0,1},
        {1,1,0,1,0}
    };

    dfs(G, 0);

    return 0;
}


