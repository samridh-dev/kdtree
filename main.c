
#include <limits.h>
#include <stdio.h>

#define KD__TYPE_T unsigned char
#define KD__DIM    3
#include "kdtree.h"

#define N 6

/* Example data points */
unsigned char x[3 * N] = {
    2, 3, 4,
    9, 6, 2,
    8, 1, 0,
    5, 4, 1,
    7, 2, 0,
    4, 7, 0,
};

unsigned char q[3] = {9, 1, 0};

int 
main(void) {

        size_t i;
        size_t idx  = 0;
        float  dmin = (float)INT_MAX;

        unsigned char tree[KD__SIZE(4) * sizeof(unsigned char) * 3];

        printf("Input points:\n");
        for (i = 0; i < N; i++) {
            printf("(%u, %u, %u)\n",
                   x[3 * i + 0],
                   x[3 * i + 1],
                   x[3 * i + 2]);
        }
        printf("\n");

        kd__new(tree, x, N, 0, 0);

        printf("KD-tree structure:\n");
        for (i = 0; i < N; i++) {
                printf("Node %ld: (%u, %u, %u)\n",
                       i,
                       tree[3 * i + 0],
                       tree[3 * i + 1],
                       tree[3 * i + 2]);
        }
        printf("\n");

        kd__findnn(tree, N, 0, 0, q, &idx, &dmin);
        printf("query: (%u %u %u), nearest neighbor: (%u %u %u)\n",
               q[0], q[1], q[2],
               tree[3 * idx + 0],
               tree[3 * idx + 1],
               tree[3 * idx + 2]);

        return 0;

}
