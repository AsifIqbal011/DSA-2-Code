#include<iostream>
#include<vector>
using namespace std;

int lis(vector<int> arr){
vector<int> dp(arr.size(),1);

int len= 1;
for(int i=1;i<arr.size();i++){
    for(int j=0;j<i;j++){
        if(arr[i]>arr[j]){
            dp[i]= max(dp[i],dp[j]+1);
            len= dp[i];
        }
    }
}
return len;
}

int main(){
vector<int> arr={50,4,3,8,30,28,25,10,29};
cout<<lis(arr)<<endl;

return 0;}
