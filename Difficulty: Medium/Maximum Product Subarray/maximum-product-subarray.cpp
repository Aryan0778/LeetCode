//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    // Function to find maximum product subarray
    long long maxProduct(vector<int> &arr) {
        int n=arr.size();
        long long  int prefix=1;
	    long long int suffix=1;
	    long long maxproduct=INT_MIN;
	    for(int i=0;i<n;i++){
	        prefix*=arr[i];
	        suffix*=arr[n-i-1];
	        maxproduct=max(maxproduct,suffix);
	        maxproduct=max(maxproduct,prefix);
	        if(prefix==0)
	            prefix=1;
	         if(suffix==0)
	            suffix=1;
	            
	    }
	    return maxproduct;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends