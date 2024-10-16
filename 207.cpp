#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    ll pu=1,pd=12345;
    ll tw=4;
    ll qu=1,qd=1,cur=3;
    while(true){
        if(cur==tw){
            qu++;
            tw=tw*2ll;
        }
        qd++;
        if(qu*pd<pu*qd){
            cout<<cur*cur-cur<<" "<<"\n";
            break;
        }
        cout<<cur*cur-cur<<" | "<<qu<<"/"<<qd<<"\n";
        cur++;
    }
}
/*
11571
*/