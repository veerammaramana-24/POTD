//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
            int n = arr.size();

        // Create a 2D DP array to store the minimum
        // multiplication costs
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Fill the DP array.
        // Here, len is the chain length
        for (int len = 2; len < n; len++)
        {
            for (int i = 0; i < n - len; i++)
            {
                int j = i + len;
                dp[i][j] = INT_MAX;

                for (int k = i + 1; k < j; k++)
                {
                    int cost = dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }

        // The minimum cost is stored in dp[0][n-1]
        return dp[0][n - 1];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends