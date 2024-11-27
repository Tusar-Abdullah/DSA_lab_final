#include<bits/stdc++.h>
using namespace std;


int visited[5];

void bfs(int g[5][5],int node)
{
    queue<int> Q;
    Q.push(node);

    visited[node] = 1;
    cout<<node<<" ";

    while(!Q.empty())
        {
            int v = Q.front();
            Q.pop();

            for(int i=0; i<5; i++)
                {
                    if(g[v][i] == 1 && visited[i] == 0)
                        {
                            Q.push(i);
                            visited[i] = 1;
                            cout<<i<<" ";
                        }
                }
        }


}




int main()
{

    int g[5][5] =
    {
        {0,1,0,0,1},
        {1,0,0,1,1},
        {0,0,0,1,0},
        {0,1,1,0,1},
        {1,1,0,1,0}

    };

    bfs(g,0);

    return 0;
}
