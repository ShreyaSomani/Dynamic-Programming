#include <bits/stdc++.h>
 
// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }
 
// Prints the items which are put in a knapsack of capacity W
void printknapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];
 
    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                    K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    printf("Final table\n");
    for (int i=1;i<n+1;++i)
    {
        for(int j=1;j<W+1;++j)
        printf("%d ",K[i][j]);
        printf("\n");
    }
 
    // stores the result of Knapsack
    int res = K[n][W];   
    printf("Max profit = %d\n", res);
     
    w = W;
    for (i = n; i > 0 && res > 0; i--) {
         
        // either the result comes from the top
        // (K[i-1][w]) or from (val[i-1] + K[i-1]
        // [w-wt[i-1]]) as in Knapsack table. If
        // it comes from the latter one/ it means
        // the item is included.
        if (res == K[i - 1][w])
            continue;       
        else {
 
            // This item is included.
            printf("Weight of element included = %d\n", wt[i - 1]);
             
            // Since this weight is included its
            // value is deducted
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }
}
 
// Driver code
int main()
{
    int val[] = {13,8,7,3};
    int wt[] = {1,5,3,4};
    int W = 11;
    int n = sizeof(val) / sizeof(val[0]);
     
    printknapSack(W, wt, val, n);
     
    return 0;
}