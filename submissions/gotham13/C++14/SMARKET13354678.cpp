#include<iostream>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,l,r,max=1,k,q,temp=1,a[100001],one[100001],before[100001],after[100001],j;
        scanf("%d %d",&n ,&q);
        for(j=0;j<n;j++)
            scanf("%d",&a[j]);
        before[0]=1;
        for(j=1;j<n;j++)
            if(a[j-1]==a[j]){
                before[j]=before[j-1]+1;
                if(before[j]>max) max=before[j];
            }
            else before[j]=1;
        after[n-1]=1;
        for(j=n-2;j>=0;j--)
            if(a[j]==a[j+1]) after[j]=after[j+1]+1;
            else after[j]=1;
        one[0]=1;
        for(j=1;j<n;j++)
            if(a[j]==a[j-1]) one[j]=one[j-1];
            else one[j]=one[j-1]+1;
        while(q--){
            scanf("%d %d %d",&l ,&r ,&k);
            if(max<k){
                printf("0\n");
                continue;
            }
            if(max==1 && k==1){
                printf("%d\n",r-l+1);
                continue;
            }
            if(k==1){
                printf("%d\n",one[r-1]-one[l-1]+1);
                continue;
            }
            int ans=0;
            l--; r--;
            for(j=r;j>=l && j-before[j]>=l;){
                if(before[j]>=k) ans++;
                j=j-before[j];
            }
            if(after[l]>=k) ans++;
            printf("%d\n",ans);
        }
    }
    return 0;
}