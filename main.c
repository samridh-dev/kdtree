#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TYPE_T float
#define TYPE_F float
#define UINT_T size_t

#define KD__MEMCPY__OVERRIDE memcpy
#define KD__TYPE_T TYPE_T
#define KD__TYPE_F TYPE_F
#define KD__UINT_T UINT_T
#define KD__DIM    3
#include "kdtree.h"

#define N        1e4
#define k        128 
#define MAXDEPTH 20
#define IMAX     1e5

int 
main(void) {
#if 0

    #if 0
        TYPE_T x[] = {
                2.0, 3.0, 4.0,
                9.0, 6.0, 2.0,
                8.0, 1.0, 0.0,
                5.0, 4.0, 1.0,
                7.0, 2.0, 0.0,
                4.0, 7.0, 0.0
        };
        TYPE_T q[] = { 9.0, 1.0, 0.0 };
#else

        TYPE_T x[3 * 6] = {
                80, 1, 2, 5, 4, 1, 254, 10, 255, 7, 2, 250, 9, 6, 2, 200, 10, 10
        };
        TYPE_T q[] = { 9.2, 1.0, 0.0 };

#endif


        TYPE_T tree[KD__SIZE(4) * 3];
        UINT_T idx[k];
        TYPE_T  dmin[k];

        kd__new(tree, x, 6, 0, 0);
        kd__findknn(tree, 6, 0, 0, q, idx, dmin, k);
        
        do {
                UINT_T i;

                printf("x = [\n");
                for (i = 0; i < sizeof(x) / sizeof(*x); i++) {
                        if (i % 3 == 0) printf("  [");
                        printf("%f", x[i]);
                        if (i % 3 == 2 || i == (sizeof(x) / sizeof(*x)) - 1) {
                                printf("],\n");
                        } else {
                                printf(", ");
                        }
                }
                printf("]\n");

                printf("tree = [\n");
                for (i = 0; i < sizeof(tree) / sizeof(*tree); i++) {
                        if (i % 3 == 0) printf("  [");
                        printf("%f", tree[i]);
                        if (i % 3 == 2 || i == (sizeof(tree) / sizeof(*tree)) - 1) {
                                printf("],\n");
                        } else {
                                printf(", ");
                        }
                }
                printf("]\n");

                printf("q = { ");
                for (i = 0; i < sizeof(q) / sizeof(*q); i++) {
                        printf("%f", q[i]);
                        if (i < (sizeof(q) / sizeof(*q)) - 1) {
                                printf(", ");
                        }
                }
                printf(" }\n");

                printf("knn (id) = [\n");
                for (i = 0; i < k; i++) {
                        if (i % 3 == 0) printf("  [");
                        printf("[ %f, %f, %f ]", 
                                   tree[3 * idx[i] + 0], 
                                   tree[3 * idx[i] + 1], 
                                   tree[3 * idx[i] + 2]);
                        if (i < (k - 1)) {
                                printf(", ");
                        }
                        if (i % 3 == 2 || i == (k - 1)) {
                                printf("],\n");
                        }
                }
                printf("]\n");

                printf("knn (dist) = { ");
                for (i = 0; i < sizeof(dmin) / sizeof(*dmin); i++) {
                        printf("%f", dmin[i]);
                        if (i < (sizeof(dmin) / sizeof(*dmin)) - 1) {
                                printf(", ");
                        }
                }
                printf(" }\n");

        } while (0);

        return 0;

#else

        UINT_T i;
        TYPE_T* idx[k];
        TYPE_T* x     = malloc(N * sizeof(TYPE_T) * 3);
        TYPE_T* tree  = malloc(KD__SIZE(MAXDEPTH) * sizeof(TYPE_T) * 3);

        clock_t beg, end;
        double elapsed;

        if (!x || !tree) { 
                return 1; 
        }

        for (i = 0; i < N * 3; ++i) {
                x[i] = ((TYPE_T)rand()/((TYPE_T)RAND_MAX));
        }
        
        beg = clock();
        kd__new(tree, x, N, 0, 0);
        end = clock();
        elapsed = (double)(end - beg) / CLOCKS_PER_SEC;
        printf("kd__new time: %.6f seconds\n", elapsed);

        beg = clock();
        
        for (i = 0; i < IMAX; i++) {
                TYPE_T q[3];
                q[0] = ((TYPE_T)rand()/((TYPE_T)RAND_MAX));
                q[1] = ((TYPE_T)rand()/((TYPE_T)RAND_MAX));
                q[2] = ((TYPE_T)rand()/((TYPE_T)RAND_MAX));
                kd__findknn(tree, N, 0, 0, q, idx, k);
        }
        end = clock();
        elapsed = (double)(end - beg) / CLOCKS_PER_SEC;
        printf("kd_findnn time : %.6f seconds\n", elapsed);

        free(x);
        free(tree);
        return 0;

#endif

}
