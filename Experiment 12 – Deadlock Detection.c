#include <stdio.h>

int main() {
    int n=3, m=2;
    int alloc[3][2]={{1,0},{0,1},{1,1}};
    int max[3][2]={{1,1},{1,1},{2,2}};
    int avail[2]={0,0};
    int need[3][2], finish[3]={0};
    int work[2], count=0;

    for(int i=0;i<m;i++) work[i]=avail[i];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            need[i][j]=max[i][j]-alloc[i][j];

    while(count<n) {
        int found=0;
        for(int i=0;i<n;i++) {
            if(!finish[i]) {
                int j;
                for(j=0;j<m;j++)
                    if(need[i][j]>work[j]) break;
                if(j==m) {
                    for(int k=0;k<m;k++)
                        work[k]+=alloc[i][k];
                    finish[i]=1;
                    count++;
                    found=1;
                }
            }
        }
        if(!found) break;
    }

    if(count==n)
        printf("Safe state\n");
    else {
        printf("Deadlock detected\nProcesses: ");
        for(int i=0;i<n;i++)
            if(!finish[i]) printf("P%d ", i);
    }

    return 0;
}
