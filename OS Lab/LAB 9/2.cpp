#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N_TICKETS 6
#define N_SELLERS 2

pthread_mutex_t mutex;
int sold_tickets = 0;
int available_tickets = N_TICKETS;

void* sell_tickets(void* arg) {
    int seller_id = *(int*)arg;
    int n_sold = 0;
    while (1) {
        pthread_mutex_lock(&mutex);
        if (available_tickets > 0) {
            available_tickets--;
            sold_tickets++;
            n_sold++;
            printf("Seller %d sold ticket %d\n", seller_id, sold_tickets);
        }
        pthread_mutex_unlock(&mutex);
        if (available_tickets == 0) {
            break;
        }
    }
    printf("Seller %d sold %d tickets\n", seller_id, n_sold);
    pthread_exit(NULL);
}

int main() {
    pthread_mutex_init(&mutex, NULL);
    pthread_t threads[N_SELLERS];
    int seller_ids[N_SELLERS];
    for (int i = 0; i < N_SELLERS; i++) {
        seller_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, sell_tickets, &seller_ids[i]);
    }
    for (int i = 0; i < N_SELLERS; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}
