#include<bits/stdc++.h>
using namespace std;



void knapsack(int n, int c, int v[], int w[])
{
    int dp[n+1][c+1];
    int i, j;


    for(i = 0; i <= n; i++)
        {
            for(j = 0; j <= c; j++)
                {
                    if(i == 0 || j == 0)
                        {
                            dp[i][j] = 0;
                        }
                    else if(w[i] > j)
                        {
                            dp[i][j] = dp[i-1][j];
                        }
                    else
                        {
                            dp[i][j] = max(dp[i-1][j-w[i]] + v[i], dp[i-1][j]);
                        }
                }
        }


    cout << "DP Table:" << endl;
    for(i = 0; i <= n; i++)
        {
            for(j = 0; j <= c; j++)
                {
                    cout << dp[i][j] << "\t";
                }
            cout << endl;
        }


    cout << "Max value = " << dp[n][c] << endl;


    i = n;
    j = c;
    cout << "Selected items:" << endl;
    while(i > 0 && j > 0)
        {
            if(dp[i][j] != dp[i-1][j])
                {
                    cout << "Item " << i << " (v = " << v[i] << ", w = " << w[i] << ")" << endl;
                    j -= w[i];
                }
            i--;
        }
}




int main()
{

    int n = 5;
    int value[] = {0, 150, 180, 170, 350, 300};
    int weight[] = {0, 3, 2, 3, 6, 5};
    int capacity = 7;

    knapsack(n, capacity, value, weight);

    return 0;
}


