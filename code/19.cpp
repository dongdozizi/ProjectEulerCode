#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll yy=1901,mm=0,dd=0,dt=0;
ll tm[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    ll ans=0;
    while(true){
        if(yy%4==0&&yy%400!=0) tm[1]=29;
        else tm[1]=28;
        dd++;dt=(dt+1)%7;
        if(dd==tm[mm]){
            dd=0,mm++;
            if(mm==12) mm=0,yy++;
            if(dt==6) ans++;
        }
        if(yy==2000&&mm==11&&dd==30) break;
        cout<<yy<<" "<<mm+1<<" "<<dd+1<<" "<<dt+1<<"\n";
    }
    cout<<ans<<"\n";
}
/*
172
*/
