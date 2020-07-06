#include<iostream> 
#include<cmath>
#include<string>
using namespace std;int main(){int i=0,c;while(i<10){string s;cin>>s;c=0;for(auto v:s)if(v=='T'||v=='D'||v=='L'||v=='F')c++;cout<<pow(2, c)<<'\n';i++;}}
