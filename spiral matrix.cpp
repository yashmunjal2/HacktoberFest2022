#include<iostream>

#include<vector>
using namespace std;
vector<int> spiral(vector<vector<int>>v){
    int l=0,k=0;
    int i=0;
    int r=v.size()-1;
    int c=v[i].size()-1;
    vector<int>ans;
    while (k<=r && l<=c)
    {
    
    
    for(i=l;i<=c;i++){
        ans.push_back(v[k][i]);
    } k++;
    for(i=k;i<=r;i++){
        ans.push_back(v[i][c]);
    }c--;
    if(k<=r){
    for(i=c;i>=l;i--){
        ans.push_back(v[r][i]);
    }r--;}
    if(l<=c){

    for(i=r;i>=k;i--){
        ans.push_back(v[i][l]);
    }l++;}
    
    }
    return ans;
}
void display(vector<vector<int>>v){
    int i,j;
    for(i=0;i<v.size();i++){
        for(j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

}
int main(){
    vector<vector<int>>v={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    display(v);
    vector<int>b= spiral(v);
    for(int i=0;i<b.size();i++)
    {
        cout<<b[i]<<" ";
    }
}
