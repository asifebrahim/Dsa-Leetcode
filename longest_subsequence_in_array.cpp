#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxi=*max_element(arr.begin(),arr.end());
    vector<vector<int>> dp(maxi+1,vector<int>(2,-1));
    for(int i=0;i<n;i++){  
        int temp=arr[i]-1;
        if(dp[temp][0]!=-1){
            dp[arr[i]][0]=i;
            dp[arr[i]][1]=dp[temp][1]+1;
        }
        else{
            dp[arr[i]][0]=i;
            dp[arr[i]][1]=1;
        }
        
        
    }
    int imaxi=0;
        for(int i=0;i<dp.size();i++){
            imaxi=max(imaxi,dp[i][1]);
        }
        cout<<imaxi<<endl;

}

//We can use a unordered_map for better space complexity rether than 2d dp array with a max Size space both of them 
//basically have the same space complexity but unordered_map is more efficient in terms of space complexity .