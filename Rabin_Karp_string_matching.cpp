
#include<bits/stdc++.h>
using namespace std;

int calhash(string s,int l)
{

    int sum=0;
    for(int i=0; i<l; i++)
        {
            sum += s[i];
        }
    return sum;

}


int main()
{
    string s1 = "ACGUAGUA";
    string s2 = "GUA";

    int l1  = s1.size();
    int l2  = s2.size();

    int hashs1 = calhash(s1,l2);
    int hashs2 = calhash(s2,l2);

    for(int i=0; i<=l1-l2; i++)
        {

            if(hashs1 == hashs2)
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

            ///rolling hash
            hashs1 = hashs1 - s1[i] + s1[i+l2];

        }

    return 0;
}

