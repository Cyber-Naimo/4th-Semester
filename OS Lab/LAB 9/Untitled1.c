#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_SELLERS 4
#define NUM_TICKETS 100

int tickets[NUM_TICKETS];
sem_t semaphore;

void* seller(void* args) {
    int seller_id = *(int*)args;
    printf("Seller %d started\n", seller_id);

    while (1) {
        sem_wait(&semaphore); // Wait for semaphore to become available

        int ticket_sold = 0;
        for (int i = 0; i < NUM_TICKETS; i++) {
            if (tickets[i] == 0) {
                tickets[i] = seller_id;
                ticket_sold = 1;
                printf("Seller %d sold ticket %d\n", seller_id, i+1);
                break;
            }
        }

        sem_post(&semaphore); // Release semaphore

        if (!ticket_sold) {
            printf("Seller %d sold all tickets\n", seller_id);
            break;
        }
    }

    pthread_exit(NULL);
}

int main() {
    // Initialize tickets array
    for (int i = 0; i < NUM_TICKETS; i++) {
        tickets[i] = 0;
    }

    // Initialize semaphore
    sem_init(&semaphore, 0, 1);

    // Initialize threads for each seller
    pthread_t threads[NUM_SELLERS];
    int seller_ids[NUM_SELLERS];
    for (int i = 0; i < NUM_SELLERS; i++) {
        seller_ids[i] = i+1;
        pthread_create(&threads[i], NULL, seller, &seller_ids[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_SELLERS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy semaphore
    sem_destroy(&semaphore);

    return 0;
}
