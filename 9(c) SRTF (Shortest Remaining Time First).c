#include <stdio.h>
#include <limits.h>

struct Process {
    int pid, at, bt, rt, ct, tat, wt;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    struct Process p[n];

    for(int i=0;i<n;i++){
        p[i].pid = i+1;
        printf("AT and BT for P%d: ",i+1);
        scanf("%d %d",&p[i].at,&p[i].bt);
        p[i].rt = p[i].bt;
    }

    int time=0, completed=0;

    while(completed < n){
        int idx=-1, min=INT_MAX;

        for(int i=0;i<n;i++){
            if(p[i].at<=time && p[i].rt>0 && p[i].rt<min){
                min=p[i].rt;
                idx=i;
            }
        }

        if(idx==-1){
            time++;
            continue;
        }

        p[idx].rt--;
        time++;

        if(p[idx].rt==0){
            completed++;
            p[idx].ct=time;
            p[idx].tat=p[idx].ct-p[idx].at;
            p[idx].wt=p[idx].tat-p[idx].bt;
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
            p[i].pid,p[i].at,p[i].bt,
            p[i].ct,p[i].tat,p[i].wt);

    return 0;
}
