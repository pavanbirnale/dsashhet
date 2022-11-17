// Rabin karp algorithm for pattern serching
/*Algo
 Compare hashCode of pattern and sliding window rather that compareing chars
 if hash code maches then only compare charecers in sliding window;
*/
#include <bits/stdc++.h>
using namespace std;

// Toatal number of charecter incliding small , large alphabets , symbols etc
#define d 256
void search(char txt[], char pat[], int q)
{
    int N = strlen(txt);
    int M = strlen(pat);
    int i,j;
    int t = 0;
    int p = 0;
    int h = 1;

    for (i = 0; i < M - 1; i++)
    {
        h = (h * d) % q;
    }
    for (i = 0; i < M; i++)
    {
        t = (d * t + txt[i]) % q;
        p = (p * d + pat[i]) % q;
    }
    for (i = 0; i < N - M; i++)
    {
        if(p==t){
            for(j=0;j<M;j++){
                if(txt[i+j]!=pat[j]) break;
            }
            if(j==M){
                cout<<"Patern found At "<<i<<"\n";
            }
        }
        if(i<N-M){
            t= ((t-txt[i]*h)*d + txt[i+M])%q;
        }
        if(t<0){
            t=t+q;
        }

    }
}

int main()
{
    char txt[] = "oGEEKS FOR GEEKS";
    char pat[] = "GEEK";
    int q=101;
    search(txt, pat,q);
    return 0;
}