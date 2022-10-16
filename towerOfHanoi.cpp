#include<iostream>
using namespace std;

void TOH(int n, string S, string A, string D){
    if(n==1){
        cout<<"Disk Shifted from "<<S<<" to "<<D<<endl;
    }else{
        TOH(n-1, S, D, A);
        cout<<"Disk Shifted from "<<S<<" to "<<D<<endl;
        TOH(n-1, A, S, D);
    }
}

int main(){
    int n;
    cout<<"ENTER NO OF DISK: ";
    cin>>n;
    cout<<endl;
    TOH(n, "SOURCE", "AUX", "DEST");
    return 0;
}
