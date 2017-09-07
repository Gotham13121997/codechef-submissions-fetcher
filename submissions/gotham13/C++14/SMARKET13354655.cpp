#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,l,r,max=1,k,q,temp=1,a[100000],one[100000],before[100000],after[100000],j;
        cin>>n>>q;
        for(j=0;j<n;j++)
            cin>>a[j];
        before[0]=1;
        for(j=1;j<n;j++)
            if(a[j-1]==a[j]){
                before[j]=before[j-1]+1;
                if(before[j]>max) 
				max=before[j];
            }
            else 
			before[j]=1;
        after[n-1]=1;
        for(j=n-2;j>=0;j--)
            if(a[j]==a[j+1]) 
			after[j]=after[j+1]+1;
            else 
			after[j]=1;
        one[0]=1;
        for(j=1;j<n;j++)
            if(a[j]==a[j-1]) 
			one[j]=one[j-1];
            else 
			one[j]=one[j-1]+1;
        while(q--){
            cin>>l>>r>>k;
            if(max<k){
                cout<<"0"<<endl;
                continue;
            }
            if(max==1 && k==1){
                cout<<r-l+1<<endl;
                continue;
            }
            if(k==1){
                cout<<one[r-1]-one[l-1]+1<<endl;
                continue;
            }
            int ans=0;
            l--; r--;
            for(j=r;j>=l && j-before[j]>=l;j=j-before[j]){
                if(before[j]>=k) 
				ans++;
            }
            if(after[l]>=k) ans++;
            cout<<ans<<endl;
        }
    }
    return 0;
    }