#include <bits/stdc++.h>

using namespace std; 

int n,c,k;
vector<int> arr,arr2,arr3;

int remove() { 
	unordered_map<int, int> mp; 
	for (int i = 1; i <= n; i++) { 
		mp[arr[i]]++; 
	} 
    int j = 1;
	for (int i = 1; i <= n; i++) {  
		if (mp[arr[i]] >= k) { 
			arr2[j] = arr[i];
            j++;
		} 
	} 
    return j-1;
} 

int check(int cnt) { 
	unordered_map<int, int> mp; 
	for (int i = 1; i <= cnt; i++) { 
		mp[arr3[i]]++; 
	} 
    int j = 1;
    int b = 0;
	for (int i = 1; i <= cnt; i++) {  
        if (mp[arr3[i]] < k) j-=i;
		if (mp[arr3[i]] >= k) { 
            j++;
		} 
	} 
    return j-1;
}

int main() { 
    ios::sync_with_stdio(false);
	while(scanf("%d %d %d",&n,&c,&k)!=EOF) {
        arr.assign(n+1,0);
        arr2.assign(n+1,0);
        for(int i=1;i<=n;i++) {
            scanf("%d",&arr[i]);
        }
        int cnt1 = remove();
        for(int i=1;i<=cnt1;i++) {
            cout<<arr2[i]<<" ";
        }
        cout<<endl;
        
        int i=1,j=1;
        int pos = 1;
        int c2max = 0;
        arr3.assign(n+1,0);
        for(i=1;i<=n;i++) {
            if(arr[i] == arr2[j]) {
                printf("arr[i]=%d,arr2[j]=%d,pos=%d\n",arr[i],arr2[j],pos);
                j++;
                arr3[pos] = arr[i];
                pos++;
            }
            else {
                pos--;
                int c2 = check(pos);
                arr3.assign(pos+1,0);
                pos = 1;
                c2max = max(c2,c2max);
            }
        }
        pos--;
        int c2 = check(pos);
        arr3.assign(pos+1,0);
        pos = 1;
        c2max = max(c2,c2max);
        printf("%d\n",c2max);
    }
	return 0; 
} 
