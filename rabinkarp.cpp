/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

void rabin(string &text,string &pattern,int q){
 int n = text.size();
 int m = pattern.size();
 int d = 256;//base
 int p=0;//hash for pattern
 int t= 0;//hash for text
 int h = 1;//weight
 for (int i=0;i<m-1;i++){
     h = (h*d)%q;
 }

//calculate p and t for first time by adding char to base mod q
 for (int i =0;i<m;i++){
     p = (d*p+pattern[i])%q;
     t = (d*t+text[i])%q;
 }
 //run the loop till n-m
 for (int i = 0;i<=n-m;i++){
     //if p==t then check for validity
     if (p==t){
         bool match = true;
         for (int j=0;j<m;j++){
             if (text[i+j]!=pattern[j]){
                 match=false;
                 break;
             }
             
         }
         if (match)cout<<"Pattern found at : "<<i<<endl;
     }
     //else just edit the t with help of base t-text[i]*h + ch *d mod q
     if (i<n-m){
         t = (d*(t-text[i]*h)+text[i+m])%q;
         if (t<0)t +=q;
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
    rabin(text,pattern,101);

    

    return 0;
}
