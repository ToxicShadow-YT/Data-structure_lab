#include <stdio.h>
#include <limits.h>

struct Process {
    int pid, at, bt, pr, ct, tat, wt, completed;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    struct Process p[n];

    for(int i=0;i<n;i++){
        p[i].pid = i+1;
        printf("AT BT Priority for P%d: ",i+1);
        scanf("%d %d %d",&p[i].at,&p[i].bt,&p[i].pr);
        p[i].completed = 0;
    }

    int time = 0, done = 0;

    while(done < n){
        int idx = -1, maxp = -1;

        for(int i=0;i<n;i++){
            if(!p[i].completed && p[i].at <= time){
                if(p[i].pr > maxp){
                    maxp = p[i].pr;
                    idx = i;
                }
            }
        }

        if(idx == -1){
            time++;
            continue;
        }

        time += p[idx].bt;
        p[idx].ct = time;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt = p[idx].tat - p[idx].bt;
        p[idx].completed = 1;
        done++;
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
            p[i].pid,p[i].at,p[i].bt,p[i].pr,
            p[i].ct,p[i].tat,p[i].wt);

    return 0;
}
