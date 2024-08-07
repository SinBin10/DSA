//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    bool static comp(Item a, Item b){
        double c1 = (double)a.value/(double)a.weight;
        double c2 = (double)b.value/(double)b.weight;
        
        return c1>c2;
    }
    
    double fractionalKnapsack(int w, Item arr[], int n) {
        sort(arr,arr+n,comp);
        double maxprofit = 0;
        double currentweight = 0;
        for(int i = 0;i<n;i++){
            if(currentweight + arr[i].weight > w){
                double oneunit = (double)arr[i].value/(double)arr[i].weight;
                maxprofit+= oneunit*(w-currentweight);
                currentweight+=w-currentweight;
            }
            else{
                currentweight+=arr[i].weight;
                maxprofit+=arr[i].value;
            }
            if(w == currentweight)
            break;
        }
        return maxprofit;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends