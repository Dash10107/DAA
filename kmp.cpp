
#include <bits/stdc++.h>
using namespace std;

vector<int> buildLps(string &pattern){
    int m = pattern.size();
    int len = 0;
    vector<int> lps(m,0);
    
    for(int i = 1;i<m;){
    //match in text then increment len and store in lps
        if (pattern[i]==pattern[len]){
            len++;
            lps[i]=len;
            i++;
        }else{
            
            //if not match but still check with smaller len from lps
            if (len!=0)len = lps[len-1];
            //len is zero too , so we increment i
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}

void kmp(string &text,string &pattern){
    int n = text.size();
    int m = pattern.size();
    vector<int> lps = buildLps(pattern);
    //after building the lps 
    int i = 0,j=0;
    while (i<n){
        //if match increment i and j both
        if (text[i]==pattern[j]){
            i++;j++;
        }
        //match found 
        if (j==m){cout<<"pattern found at : "<<i-j<<endl; j = lps[j - 1];}
       //else if move to pos in lps [j-1] if not 0 else just inc i
        else if(i<n && text[i]!=pattern[j]){
            if (j!=0) j = lps[j-1];
            else i++;
        }
    }
}
int main()
{
    string text,pattern;
    cout<<"Enter the input string : ";
    cin>>text;
    cout<<"Enter the pattern to match : ";
    cin>>pattern;
    kmp(text,pattern);
    return 0;
}
