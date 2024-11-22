
#include<bits/stdc++.h>
using namespace std;



void LCS(string s1,int m,string s2,int n)
{
    int dp[m+1][n+1];
    int i,j;

    for( i=0; i<=m; i++)
        {
            for( j=0; j<=n; j++)
                {
                    if(i == 0 || j == 0)
                        {
                            dp[i][j] = 0;
                        }
                    else if(s1[i-1] == s2[j-1])
                        {
                            dp[i][j] = dp[i-1][j-1]+1;
                        }
                    else
                        {
                            dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                        }

                }
        }



    int lcslen = dp[m][n];

    char lcs[lcslen+1];

    lcs[lcslen] = '\0';

    i = m;
    j = n;
    int  k = lcslen-1;


    while(i>0 && j>0)
        {
            if(dp[i][j] == dp[i-1][j]) i--;
            else if(dp[i][j] == dp[i][j-1]) j--;
            else
                {
                    lcs[k] = s1[i-1];
                    k--;
                    i--;
                    j--;
                }
        }

    cout<<"LCS LENGTH : "<<lcslen<<endl;
    cout<<"LCS : "<<lcs<<endl;


}



int main()
{

    string str1 = "ACGTCCGCTCG";
    string str2 = "ATCTCT";

    int len1 = str1.size();
    int len2 = str2.size();


    LCS(str1,len1,str2,len2);



    return 0;
}


