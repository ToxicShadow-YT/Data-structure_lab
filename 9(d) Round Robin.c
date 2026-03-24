#include <stdio.h>

struct Process {
    int pid, at, bt, rt, ct, tat, wt;
};

int main() {
    int n, tq;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    struct Process p[n];

    for(int i=0;i<n;i++){
        p[i].pid=i+1;
        printf("AT and BT for P%d: ",i+1);
        scanf("%d %d",&p[i].at,&p[i].bt);
        p[i].rt=p[i].bt;
    }

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    int time=0, completed=0;
    int queue[100], front=0, rear=0;
    int visited[n];

    for(int i=0;i<n;i++) visited[i]=0;

    for(int i=0;i<n;i++){
        if(p[i].at==0){
            queue[rear++]=i;
            visited[i]=1;
        }
    }

    while(completed<n){
        if(front==rear){
            time++;
            for(int i=0;i<n;i++){
                if(p[i].at<=time && !visited[i]){
                    queue[rear++]=i;
                    visited[i]=1;
                }
            }
            continue;
        }

        int idx=queue[front++];

        int exec=(p[idx].rt<tq)?p[idx].rt:tq;
        p[idx].rt-=exec;
        time+=exec;

        for(int i=0;i<n;i++){
            if(p[i].at<=time && !visited[i]){
                queue[rear++]=i;
                visited[i]=1;
            }
        }

        if(p[idx].rt>0){
            queue[rear++]=idx;
        } else {
            p[idx].ct=time;
            completed++;
        }
    }

    for(int i=0;i<n;i++){
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
            p[i].pid,p[i].at,p[i].bt,
            p[i].ct,p[i].tat,p[i].wt);

    return 0;
}
