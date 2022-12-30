#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    long long int Count=1;
    for(long long int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]){
            Count++;
            i+=1;
        }
        else{
            Count++;
        }
    }
    cout << Count<< "\n";

}
