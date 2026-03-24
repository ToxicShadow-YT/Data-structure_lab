#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex, rw_mutex, queue;
int read_count = 0;

void *reader(void *arg) {
    int id = *(int*)arg;

    sem_wait(&queue);
    sem_wait(&mutex);
    read_count++;
    if(read_count == 1)
        sem_wait(&rw_mutex);
    sem_post(&mutex);
    sem_post(&queue);

    printf("Reader %d is reading\n", id);
    sleep(1);

    sem_wait(&mutex);
    read_count--;
    if(read_count == 0)
        sem_post(&rw_mutex);
    sem_post(&mutex);

    return NULL;
}

void *writer(void *arg) {
    int id = *(int*)arg;

    sem_wait(&queue);
    sem_wait(&rw_mutex);

    printf("Writer %d is writing\n", id);
    sleep(2);

    sem_post(&rw_mutex);
    sem_post(&queue);

    return NULL;
}

int main() {
    pthread_t r[3], w[3];
    int id[3];

    sem_init(&mutex, 0, 1);
    sem_init(&rw_mutex, 0, 1);
    sem_init(&queue, 0, 1);

    for(int i = 0; i < 3; i++) {
        id[i] = i+1;
        pthread_create(&r[i], NULL, reader, &id[i]);
        pthread_create(&w[i], NULL, writer, &id[i]);
    }

    for(int i = 0; i < 3; i++) {
        pthread_join(r[i], NULL);
        pthread_join(w[i], NULL);
    }

    return 0;
}
