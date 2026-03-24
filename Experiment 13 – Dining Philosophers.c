#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5
sem_t room, chopstick[N];

void *philosopher(void *num) {
    int id = *(int*)num;

    while(1) {
        printf("Philosopher %d thinking\n", id);
        sleep(1);

        sem_wait(&room);
        sem_wait(&chopstick[id]);
        sem_wait(&chopstick[(id+1)%N]);

        printf("Philosopher %d eating\n", id);
        sleep(2);

        sem_post(&chopstick[id]);
        sem_post(&chopstick[(id+1)%N]);
        sem_post(&room);
    }
}

int main() {
    pthread_t p[N];
    int id[N];

    sem_init(&room, 0, N-1);
    for(int i=0;i<N;i++)
        sem_init(&chopstick[i],0,1);

    for(int i=0;i<N;i++) {
        id[i]=i;
        pthread_create(&p[i],NULL,philosopher,&id[i]);
    }

    for(int i=0;i<N;i++)
        pthread_join(p[i],NULL);

    return 0;
}
