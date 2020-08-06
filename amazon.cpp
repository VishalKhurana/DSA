#include <stdio.h>
#define MAX_L 200001
#define MAX_N 101
 
int main()
{
    int t, x, y, n, i, j, cuts[MAX_L], l, k;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&x,&y);
        scanf("%d",&n);
        for(i = 0; i < n; i++){
            scanf("%d",&cuts[i]);
        }
        int minCost[MAX_N][MAX_N] = {0};
        
        for(l=1;l<=n;l++){
            for(i=0;i<n-l;i++){
                j = i + l;
                if(j==i+1)
                    continue;
                minCost[i][j] = -1;
                for(k=i+1;k<j;k++){
                    int cost = minCost[i][k]+minCost[k][j]+x*(cuts[k]-cuts[i])+y*(cuts[j]-cuts[k]);
                    if(minCost[i][j] == -1 || cost < minCost[i][j])
                        minCost[i][j] = cost;
                }
            }
        }
        printf("%d\n",minCost[0][n-1]);
    }
    return 0;
}