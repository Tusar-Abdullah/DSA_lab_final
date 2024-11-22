
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1 = "ACGUAGUA";
    string s2 = "GUA";

    int l1  = s1.size();
    int l2  = s2.size();

    for(int i=0; i<=l1-l2; i++)
        {
            int valid = 1;

            for(int j=0; j<l2; j++)
                {
                    if(s1[i+j] != s2[j])
                        {
                            valid = 0;
                            break;
                        }
                }

            if(valid)
                {
                    cout<<i<<" is a valid shift"<<endl;
                }
        }

    return 0;
}


