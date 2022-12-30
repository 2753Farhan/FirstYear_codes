#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int t;
    cin >> t;
    while(t--){
       long long int a,b;
       cin >> a >> b;

       if(a==b||a%b==0){
        cout << "NO\n";
       }
       else{
            cout << "YES\n";
        cout << a << " "<< a*b-a << " "<< a*b<<"\n";
       }
    }
}
