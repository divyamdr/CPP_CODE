#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int prec(char a)
{
    if(a=='^')
    return 3;
    if(a=='*'||a=='/')
    return 2;
    if(a=='+'||a=='-')
    return 1;
    return 0;
}
int convert(string k)
{
    stack<char> a;
    int len=k.length();
    string res;
    a.push('N');
    for(int i=0;i<len;i++)
    {
        if((k[i]>='a' &&k[i]<='z')||(k[i]>='A' &&k[i]<='Z'))
        res+=k[i];
        else if(a.empty())
        a.push(k[i]);
        else if(prec(a.top())>=prec(k[i]))
        {
            while(!a.empty()&& prec(a.top())>=prec(k[i]))
            {
                res+=a.top();
                a.pop();
            }
            a.push(k[i]);
        }
        else
        a.push(k[i]);
    }
    while(a.top()!='N')
    {
        res+=a.top();
        a.pop();
    }
    cout<<res<<endl;
    exception:
    return 0;
}
int main()
{
    string s;
    cin>>s;
    convert(s);
}
// if we want to convert infix to prefix first convert postfix
// and reverse the the result of the postfix
