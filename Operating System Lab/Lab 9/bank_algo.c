#include <stdio.h>
#include <stdlib.h>

int main() {

    int p, c, count = 0, i, j, terminate = 0, pid;
    printf("\nEnter the number of processes: ");
    scanf("%d", &p);
    printf("\nEnter the number of resource task: ");
    scanf("%d", &c);

    int safe[p], available[c], finish[p];

    int **alc = (int **)malloc(p * sizeof(int*));
    int **max = (int **)malloc(p * sizeof(int*));
    int **need = (int **)malloc(p * sizeof(int*));
    int **request = (int **)malloc(p * sizeof(int*));

    for (i = 0; i < p; i++) {
        alc[i] = (int *)malloc(c * sizeof(int));
        max[i] = (int *)malloc(c * sizeof(int));
        need[i] = (int *)malloc(c * sizeof(int));
        request[i] = (int *)malloc(c * sizeof(int));
    }

    printf("Enter Allocation of Resource of all Process %d x %d Matrix: \n", p, c);
    for (i = 0; i < p; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &alc[i][j]);
        }
    }

    printf("Enter the Max Resource Process Required %d x %d Matrix: \n", p, c);
    for (i = 0; i < p; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter the available matrix: \n");
    for (i = 0; i < c; i++) {
        scanf("%d", &available[i]);
    }

    printf("\nNeed resource matrix is: \n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < c; j++) {
            need[i][j] = max[i][j] - alc[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the proess number: ");
    scanf("%d", &pid);

    printf("\nEnter additional request: \n");
    for (i = 0; i < c; i++) {
        printf("Request for resource %d: ", i + 1);
        scanf("%d", &request[0][i]);
    }

    for (i = 0; i < c; i++) {
        if (request[0][i] > need[pid][i]) {
            printf("\n******* Error Encountered *******\n");
            exit(0);
        }
    }

    for (i = 0; i < c; i++) {
        available[i] -= request[0][i];
        alc[pid][i] += request[0][i];
        need[pid][i] -= request[0][i];
    }

    for (i = 0; i < p; i++) {
        finish[i] = 0;
    }

    while (count < p) {
        for (i = 0; i < p; i++) {
            if (finish[i] == 0) {
                for (j = 0; j < c; j++) {
                    if (need[i][j] > available[j])
                        break;
                }
                if (j == c) {
                    safe[count] = i;
                    finish[i] = 1;

                    for (j = 0; j < c; j++) {
                        available[j] += alc[i][j];
                    }
                    count++;
                    terminate = 0;
                }
                else {
                    terminate++;
                }
            }
        }
        if (terminate == (p - 1)) {
            printf("\nSafe sequence does not exist\n");
            break;
        }
    }

    if (terminate != (p - 1)) {
        printf("\nAvailable resource after completion: \n");
        for (i = 0; i < c; i++) {
            printf("%d ", available[i]);
        }
        printf("\nSafe sequence: \n");
        for (i = 0; i < p; i++) {
            printf("P%d ", safe[i]);
        }
    }

    return 0;
}