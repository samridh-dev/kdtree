
#include <limits.h>

#include <stdlib.h>
#include <string.h>

#ifdef USE_STDIO
#include <stdio.h>
#define LOG(args)                                                            \\
do {                                                                        \\
        (printf("[LOG] %s:%d ", __FILE__, __LINE__), printf args);           \\
} while (0)
#else
#define LOG(args) do {} while(0)
#endif

#include "minunit.h"
int tests_run = 0;

#define TYPE_T double
#define TYPE_F float
#define DIM    3

#define KD__MEMCPY__OVERRIDE memcpy
#define KD__TYPE_T TYPE_T
#define KD__TYPE_F TYPE_F
#define KD__DIM DIM
#include "../kdtree.h"

static TYPE_F
test_abs(const TYPE_F n) {
        if (n < 0) {
                return -n;
        } else {
                return n;
        }
}



/* ------------------------------------------------------------------------- */
/* Generated Test for case 0, subcase 1             */
/* ------------------------------------------------------------------------- */

static char*
test_case_0_sub_1(void)
{
        do { /* case: 0*/

                #define N 6
                #define K 6

                TYPE_T x[DIM * N] = {
                        2, 3, 4, 9, 6, 2, 8, 1, 0, 5, 4, 1, 7, 2, 0, 4, 7, 0
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 0:1 */

                        TYPE_T ans[DIM * N] = {
                                7, 2, 0, 5, 4, 1, 9, 6, 2, 2, 3, 4, 4, 7, 0, 8, 1, 0
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 0:1 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 0:1 */

                        TYPE_T q[DIM]  = { 9, 1, 0 };
                        TYPE_T nn[K * DIM] = { 1, 5, 26, 29, 61, 69 };

                        TYPE_T* idx[K];

                        size_t __i;
                        size_t __j;

                        kd__findknn(tree, N, 0, 0, q, idx, K);
                        #if 1 
                        printf("params: k = %i, dist = [ ", K);
                        printf("] \n");
                        #endif

                        for (__i = 0; __i < K;   __i++) {

                                TYPE_F dist = 0;
                                for (__j = 0; __j < DIM; __j++) {
                                        dist += ((idx[__i])[__j] - q[__j]) * ((idx[__i])[__j] - q[__j]);
                                }

                                #if 1        
                                printf("dist = %f, nn[i] = %f\n", dist, nn[__i]);
                                #endif
                                mu_assert(
                                "case 0:1 : nn != ans",
                                test_abs(dist - nn[__i]) <= 1e-2
                                );

                        }

                } while(0);

                #undef N
                #undef K

        } while(0);

        return 0;
}

static char*
all_tests_0_1(void)
{
        mu_run_test(test_case_0_sub_1);
        return 0;
}


/* ------------------------------------------------------------------------- */
/* Generated Test for case 0, subcase 2             */
/* ------------------------------------------------------------------------- */

static char*
test_case_0_sub_2(void)
{
        do { /* case: 0*/

                #define N 6
                #define K 6

                TYPE_T x[DIM * N] = {
                        2, 3, 4, 9, 6, 2, 8, 1, 0, 5, 4, 1, 7, 2, 0, 4, 7, 0
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 0:2 */

                        TYPE_T ans[DIM * N] = {
                                7, 2, 0, 5, 4, 1, 9, 6, 2, 2, 3, 4, 4, 7, 0, 8, 1, 0
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 0:2 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 0:2 */

                        TYPE_T q[DIM]  = { 0, 0, 0 };
                        TYPE_T nn[K * DIM] = { 29, 42, 53, 65, 65, 121 };

                        TYPE_T* idx[K];

                        size_t __i;
                        size_t __j;

                        kd__findknn(tree, N, 0, 0, q, idx, K);
                        #if 1 
                        printf("params: k = %i, dist = [ ", K);
                        printf("] \n");
                        #endif

                        for (__i = 0; __i < K;   __i++) {

                                TYPE_F dist = 0;
                                for (__j = 0; __j < DIM; __j++) {
                                        dist += ((idx[__i])[__j] - q[__j]) * ((idx[__i])[__j] - q[__j]);
                                }

                                #if 1        
                                printf("dist = %f, nn[i] = %f\n", dist, nn[__i]);
                                #endif
                                mu_assert(
                                "case 0:2 : nn != ans",
                                test_abs(dist - nn[__i]) <= 1e-2
                                );

                        }

                } while(0);

                #undef N
                #undef K

        } while(0);

        return 0;
}

static char*
all_tests_0_2(void)
{
        mu_run_test(test_case_0_sub_2);
        return 0;
}


/* ------------------------------------------------------------------------- */
/* Generated Test for case 0, subcase 3             */
/* ------------------------------------------------------------------------- */

static char*
test_case_0_sub_3(void)
{
        do { /* case: 0*/

                #define N 6
                #define K 6

                TYPE_T x[DIM * N] = {
                        2, 3, 4, 9, 6, 2, 8, 1, 0, 5, 4, 1, 7, 2, 0, 4, 7, 0
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 0:3 */

                        TYPE_T ans[DIM * N] = {
                                7, 2, 0, 5, 4, 1, 9, 6, 2, 2, 3, 4, 4, 7, 0, 8, 1, 0
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 0:3 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 0:3 */

                        TYPE_T q[DIM]  = { 6, 3, 1 };
                        TYPE_T nn[K * DIM] = { 2, 3, 9, 19, 21, 25 };

                        TYPE_T* idx[K];

                        size_t __i;
                        size_t __j;

                        kd__findknn(tree, N, 0, 0, q, idx, K);
                        #if 1 
                        printf("params: k = %i, dist = [ ", K);
                        printf("] \n");
                        #endif

                        for (__i = 0; __i < K;   __i++) {

                                TYPE_F dist = 0;
                                for (__j = 0; __j < DIM; __j++) {
                                        dist += ((idx[__i])[__j] - q[__j]) * ((idx[__i])[__j] - q[__j]);
                                }

                                #if 1        
                                printf("dist = %f, nn[i] = %f\n", dist, nn[__i]);
                                #endif
                                mu_assert(
                                "case 0:3 : nn != ans",
                                test_abs(dist - nn[__i]) <= 1e-2
                                );

                        }

                } while(0);

                #undef N
                #undef K

        } while(0);

        return 0;
}

static char*
all_tests_0_3(void)
{
        mu_run_test(test_case_0_sub_3);
        return 0;
}


/* ------------------------------------------------------------------------- */
/* Generated Test for case 2, subcase 1             */
/* ------------------------------------------------------------------------- */

static char*
test_case_2_sub_1(void)
{
        do { /* case: 0*/

                #define N 6
                #define K 5

                TYPE_T x[DIM * N] = {
                        100, 100, 100, 99, 98, 2, 30, 29, 28, 15, 15, 15, 1, 250, 10, 254, 253, 252
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 2:1 */

                        TYPE_T ans[DIM * N] = {
                                99, 98, 2, 30, 29, 28, 254, 253, 252, 15, 15, 15, 1, 250, 10, 100, 100, 100
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 2:1 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 2:1 */

                        TYPE_T q[DIM]  = { 254, 0, 1 };
                        TYPE_T nn[K * DIM] = { 33630, 43517, 51746, 57542, 126590 };

                        TYPE_T* idx[K];

                        size_t __i;
                        size_t __j;

                        kd__findknn(tree, N, 0, 0, q, idx, K);
                        #if 1 
                        printf("params: k = %i, dist = [ ", K);
                        printf("] \n");
                        #endif

                        for (__i = 0; __i < K;   __i++) {

                                TYPE_F dist = 0;
                                for (__j = 0; __j < DIM; __j++) {
                                        dist += ((idx[__i])[__j] - q[__j]) * ((idx[__i])[__j] - q[__j]);
                                }

                                #if 1        
                                printf("dist = %f, nn[i] = %f\n", dist, nn[__i]);
                                #endif
                                mu_assert(
                                "case 2:1 : nn != ans",
                                test_abs(dist - nn[__i]) <= 1e-2
                                );

                        }

                } while(0);

                #undef N
                #undef K

        } while(0);

        return 0;
}

static char*
all_tests_2_1(void)
{
        mu_run_test(test_case_2_sub_1);
        return 0;
}


/* ------------------------------------------------------------------------- */
/* Generated Test for case 2, subcase 2             */
/* ------------------------------------------------------------------------- */

static char*
test_case_2_sub_2(void)
{
        do { /* case: 0*/

                #define N 6
                #define K 5

                TYPE_T x[DIM * N] = {
                        100, 100, 100, 99, 98, 2, 30, 29, 28, 15, 15, 15, 1, 250, 10, 254, 253, 252
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 2:2 */

                        TYPE_T ans[DIM * N] = {
                                99, 98, 2, 30, 29, 28, 254, 253, 252, 15, 15, 15, 1, 250, 10, 100, 100, 100
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 2:2 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 2:2 */

                        TYPE_T q[DIM]  = { 2, 98, 28 };
                        TYPE_T nn[K * DIM] = { 5545, 7227, 10085, 14792, 23429 };

                        TYPE_T* idx[K];

                        size_t __i;
                        size_t __j;

                        kd__findknn(tree, N, 0, 0, q, idx, K);
                        #if 1 
                        printf("params: k = %i, dist = [ ", K);
                        printf("] \n");
                        #endif

                        for (__i = 0; __i < K;   __i++) {

                                TYPE_F dist = 0;
                                for (__j = 0; __j < DIM; __j++) {
                                        dist += ((idx[__i])[__j] - q[__j]) * ((idx[__i])[__j] - q[__j]);
                                }

                                #if 1        
                                printf("dist = %f, nn[i] = %f\n", dist, nn[__i]);
                                #endif
                                mu_assert(
                                "case 2:2 : nn != ans",
                                test_abs(dist - nn[__i]) <= 1e-2
                                );

                        }

                } while(0);

                #undef N
                #undef K

        } while(0);

        return 0;
}

static char*
all_tests_2_2(void)
{
        mu_run_test(test_case_2_sub_2);
        return 0;
}


/* ------------------------------------------------------------------------- */
/* Generated Test for case 2, subcase 3             */
/* ------------------------------------------------------------------------- */

static char*
test_case_2_sub_3(void)
{
        do { /* case: 0*/

                #define N 6
                #define K 5

                TYPE_T x[DIM * N] = {
                        100, 100, 100, 99, 98, 2, 30, 29, 28, 15, 15, 15, 1, 250, 10, 254, 253, 252
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 2:3 */

                        TYPE_T ans[DIM * N] = {
                                99, 98, 2, 30, 29, 28, 254, 253, 252, 15, 15, 15, 1, 250, 10, 100, 100, 100
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 2:3 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 2:3 */

                        TYPE_T q[DIM]  = { 100, 100, 101 };
                        TYPE_T nn[K * DIM] = { 1, 9806, 15270, 21846, 40582 };

                        TYPE_T* idx[K];

                        size_t __i;
                        size_t __j;

                        kd__findknn(tree, N, 0, 0, q, idx, K);
                        #if 1 
                        printf("params: k = %i, dist = [ ", K);
                        printf("] \n");
                        #endif

                        for (__i = 0; __i < K;   __i++) {

                                TYPE_F dist = 0;
                                for (__j = 0; __j < DIM; __j++) {
                                        dist += ((idx[__i])[__j] - q[__j]) * ((idx[__i])[__j] - q[__j]);
                                }

                                #if 1        
                                printf("dist = %f, nn[i] = %f\n", dist, nn[__i]);
                                #endif
                                mu_assert(
                                "case 2:3 : nn != ans",
                                test_abs(dist - nn[__i]) <= 1e-2
                                );

                        }

                } while(0);

                #undef N
                #undef K

        } while(0);

        return 0;
}

static char*
all_tests_2_3(void)
{
        mu_run_test(test_case_2_sub_3);
        return 0;
}


/* ------------------------------------------------------------------------- */
/* Generated Test for case 3, subcase 1             */
/* ------------------------------------------------------------------------- */

static char*
test_case_3_sub_1(void)
{
        do { /* case: 0*/

                #define N 6
                #define K 4

                TYPE_T x[DIM * N] = {
                        50, 40, 30, 0, 39, 80, 120, 255, 90, 4, 7, 10, 25, 250, 249, 130, 130, 130
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 3:1 */

                        TYPE_T ans[DIM * N] = {
                                50, 40, 30, 0, 39, 80, 120, 255, 90, 4, 7, 10, 25, 250, 249, 130, 130, 130
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 3:1 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 3:1 */

                        TYPE_T q[DIM]  = { 255, 255, 254 };
                        TYPE_T nn[K * DIM] = { 45121, 46626, 52950, 138426 };

                        TYPE_T* idx[K];

                        size_t __i;
                        size_t __j;

                        kd__findknn(tree, N, 0, 0, q, idx, K);
                        #if 1 
                        printf("params: k = %i, dist = [ ", K);
                        printf("] \n");
                        #endif

                        for (__i = 0; __i < K;   __i++) {

                                TYPE_F dist = 0;
                                for (__j = 0; __j < DIM; __j++) {
                                        dist += ((idx[__i])[__j] - q[__j]) * ((idx[__i])[__j] - q[__j]);
                                }

                                #if 1        
                                printf("dist = %f, nn[i] = %f\n", dist, nn[__i]);
                                #endif
                                mu_assert(
                                "case 3:1 : nn != ans",
                                test_abs(dist - nn[__i]) <= 1e-2
                                );

                        }

                } while(0);

                #undef N
                #undef K

        } while(0);

        return 0;
}

static char*
all_tests_3_1(void)
{
        mu_run_test(test_case_3_sub_1);
        return 0;
}


/* ------------------------------------------------------------------------- */
/* Generated Test for case 3, subcase 2             */
/* ------------------------------------------------------------------------- */

static char*
test_case_3_sub_2(void)
{
        do { /* case: 0*/

                #define N 6
                #define K 4

                TYPE_T x[DIM * N] = {
                        50, 40, 30, 0, 39, 80, 120, 255, 90, 4, 7, 10, 25, 250, 249, 130, 130, 130
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 3:2 */

                        TYPE_T ans[DIM * N] = {
                                50, 40, 30, 0, 39, 80, 120, 255, 90, 4, 7, 10, 25, 250, 249, 130, 130, 130
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 3:2 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 3:2 */

                        TYPE_T q[DIM]  = { 50, 41, 29 };
                        TYPE_T nn[K * DIM] = { 2, 3633, 5105, 24522 };

                        TYPE_T* idx[K];

                        size_t __i;
                        size_t __j;

                        kd__findknn(tree, N, 0, 0, q, idx, K);
                        #if 1 
                        printf("params: k = %i, dist = [ ", K);
                        printf("] \n");
                        #endif

                        for (__i = 0; __i < K;   __i++) {

                                TYPE_F dist = 0;
                                for (__j = 0; __j < DIM; __j++) {
                                        dist += ((idx[__i])[__j] - q[__j]) * ((idx[__i])[__j] - q[__j]);
                                }

                                #if 1        
                                printf("dist = %f, nn[i] = %f\n", dist, nn[__i]);
                                #endif
                                mu_assert(
                                "case 3:2 : nn != ans",
                                test_abs(dist - nn[__i]) <= 1e-2
                                );

                        }

                } while(0);

                #undef N
                #undef K

        } while(0);

        return 0;
}

static char*
all_tests_3_2(void)
{
        mu_run_test(test_case_3_sub_2);
        return 0;
}


/* ------------------------------------------------------------------------- */
/* Generated Test for case 3, subcase 3             */
/* ------------------------------------------------------------------------- */

static char*
test_case_3_sub_3(void)
{
        do { /* case: 0*/

                #define N 6
                #define K 4

                TYPE_T x[DIM * N] = {
                        50, 40, 30, 0, 39, 80, 120, 255, 90, 4, 7, 10, 25, 250, 249, 130, 130, 130
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 3:3 */

                        TYPE_T ans[DIM * N] = {
                                50, 40, 30, 0, 39, 80, 120, 255, 90, 4, 7, 10, 25, 250, 249, 130, 130, 130
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 3:3 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 3:3 */

                        TYPE_T q[DIM]  = { 129, 130, 130 };
                        TYPE_T nn[K * DIM] = { 1, 17306, 24341, 27422 };

                        TYPE_T* idx[K];

                        size_t __i;
                        size_t __j;

                        kd__findknn(tree, N, 0, 0, q, idx, K);
                        #if 1 
                        printf("params: k = %i, dist = [ ", K);
                        printf("] \n");
                        #endif

                        for (__i = 0; __i < K;   __i++) {

                                TYPE_F dist = 0;
                                for (__j = 0; __j < DIM; __j++) {
                                        dist += ((idx[__i])[__j] - q[__j]) * ((idx[__i])[__j] - q[__j]);
                                }

                                #if 1        
                                printf("dist = %f, nn[i] = %f\n", dist, nn[__i]);
                                #endif
                                mu_assert(
                                "case 3:3 : nn != ans",
                                test_abs(dist - nn[__i]) <= 1e-2
                                );

                        }

                } while(0);

                #undef N
                #undef K

        } while(0);

        return 0;
}

static char*
all_tests_3_3(void)
{
        mu_run_test(test_case_3_sub_3);
        return 0;
}


/* ------------------------------------------------------------------------- */
/* Generated Test for case 5, subcase 1             */
/* ------------------------------------------------------------------------- */

static char*
test_case_5_sub_1(void)
{
        do { /* case: 0*/

                #define N 6
                #define K 2

                TYPE_T x[DIM * N] = {
                        25, 0, 255, 30, 30, 30, 24, 88, 99, 10, 14, 200, 70, 2, 5, 199, 7, 7
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 5:1 */

                        TYPE_T ans[DIM * N] = {
                                30, 30, 30, 10, 14, 200, 199, 7, 7, 25, 0, 255, 24, 88, 99, 70, 2, 5
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 5:1 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 5:1 */

                        TYPE_T q[DIM]  = { 25, 1, 255 };
                        TYPE_T nn[K * DIM] = { 1, 3419 };

                        TYPE_T* idx[K];

                        size_t __i;
                        size_t __j;

                        kd__findknn(tree, N, 0, 0, q, idx, K);
                        #if 1 
                        printf("params: k = %i, dist = [ ", K);
                        printf("] \n");
                        #endif

                        for (__i = 0; __i < K;   __i++) {

                                TYPE_F dist = 0;
                                for (__j = 0; __j < DIM; __j++) {
                                        dist += ((idx[__i])[__j] - q[__j]) * ((idx[__i])[__j] - q[__j]);
                                }

                                #if 1        
                                printf("dist = %f, nn[i] = %f\n", dist, nn[__i]);
                                #endif
                                mu_assert(
                                "case 5:1 : nn != ans",
                                test_abs(dist - nn[__i]) <= 1e-2
                                );

                        }

                } while(0);

                #undef N
                #undef K

        } while(0);

        return 0;
}

static char*
all_tests_5_1(void)
{
        mu_run_test(test_case_5_sub_1);
        return 0;
}


/* ------------------------------------------------------------------------- */
/* Generated Test for case 5, subcase 2             */
/* ------------------------------------------------------------------------- */

static char*
test_case_5_sub_2(void)
{
        do { /* case: 0*/

                #define N 6
                #define K 2

                TYPE_T x[DIM * N] = {
                        25, 0, 255, 30, 30, 30, 24, 88, 99, 10, 14, 200, 70, 2, 5, 199, 7, 7
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 5:2 */

                        TYPE_T ans[DIM * N] = {
                                30, 30, 30, 10, 14, 200, 199, 7, 7, 25, 0, 255, 24, 88, 99, 70, 2, 5
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 5:2 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 5:2 */

                        TYPE_T q[DIM]  = { 70, 3, 5 };
                        TYPE_T nn[K * DIM] = { 1, 2954 };

                        TYPE_T* idx[K];

                        size_t __i;
                        size_t __j;

                        kd__findknn(tree, N, 0, 0, q, idx, K);
                        #if 1 
                        printf("params: k = %i, dist = [ ", K);
                        printf("] \n");
                        #endif

                        for (__i = 0; __i < K;   __i++) {

                                TYPE_F dist = 0;
                                for (__j = 0; __j < DIM; __j++) {
                                        dist += ((idx[__i])[__j] - q[__j]) * ((idx[__i])[__j] - q[__j]);
                                }

                                #if 1        
                                printf("dist = %f, nn[i] = %f\n", dist, nn[__i]);
                                #endif
                                mu_assert(
                                "case 5:2 : nn != ans",
                                test_abs(dist - nn[__i]) <= 1e-2
                                );

                        }

                } while(0);

                #undef N
                #undef K

        } while(0);

        return 0;
}

static char*
all_tests_5_2(void)
{
        mu_run_test(test_case_5_sub_2);
        return 0;
}


/* ------------------------------------------------------------------------- */
/* Generated Test for case 5, subcase 3             */
/* ------------------------------------------------------------------------- */

static char*
test_case_5_sub_3(void)
{
        do { /* case: 0*/

                #define N 6
                #define K 2

                TYPE_T x[DIM * N] = {
                        25, 0, 255, 30, 30, 30, 24, 88, 99, 10, 14, 200, 70, 2, 5, 199, 7, 7
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 5:3 */

                        TYPE_T ans[DIM * N] = {
                                30, 30, 30, 10, 14, 200, 199, 7, 7, 25, 0, 255, 24, 88, 99, 70, 2, 5
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 5:3 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 5:3 */

                        TYPE_T q[DIM]  = { 24, 88, 100 };
                        TYPE_T nn[K * DIM] = { 1, 8300 };

                        TYPE_T* idx[K];

                        size_t __i;
                        size_t __j;

                        kd__findknn(tree, N, 0, 0, q, idx, K);
                        #if 1 
                        printf("params: k = %i, dist = [ ", K);
                        printf("] \n");
                        #endif

                        for (__i = 0; __i < K;   __i++) {

                                TYPE_F dist = 0;
                                for (__j = 0; __j < DIM; __j++) {
                                        dist += ((idx[__i])[__j] - q[__j]) * ((idx[__i])[__j] - q[__j]);
                                }

                                #if 1        
                                printf("dist = %f, nn[i] = %f\n", dist, nn[__i]);
                                #endif
                                mu_assert(
                                "case 5:3 : nn != ans",
                                test_abs(dist - nn[__i]) <= 1e-2
                                );

                        }

                } while(0);

                #undef N
                #undef K

        } while(0);

        return 0;
}

static char*
all_tests_5_3(void)
{
        mu_run_test(test_case_5_sub_3);
        return 0;
}


/* ------------------------------------------------------------------------- */
/* Generated Test for case 1, subcase 1             */
/* ------------------------------------------------------------------------- */

static char*
test_case_1_sub_1(void)
{
        do { /* case: 0*/

                #define N 6
                #define K 1

                TYPE_T x[DIM * N] = {
                        10, 20, 30, 0, 0, 1, 2, 255, 3, 17, 99, 65, 45, 12, 200, 255, 255, 255
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 1:1 */

                        TYPE_T ans[DIM * N] = {
                                17, 99, 65, 10, 20, 30, 255, 255, 255, 0, 0, 1, 2, 255, 3, 45, 12, 200
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 1:1 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 1:1 */

                        TYPE_T q[DIM]  = { 255, 0, 255 };
                        TYPE_T nn[K * DIM] = { 47269 };

                        TYPE_T* idx[K];

                        size_t __i;
                        size_t __j;

                        kd__findknn(tree, N, 0, 0, q, idx, K);
                        #if 1 
                        printf("params: k = %i, dist = [ ", K);
                        printf("] \n");
                        #endif

                        for (__i = 0; __i < K;   __i++) {

                                TYPE_F dist = 0;
                                for (__j = 0; __j < DIM; __j++) {
                                        dist += ((idx[__i])[__j] - q[__j]) * ((idx[__i])[__j] - q[__j]);
                                }

                                #if 1        
                                printf("dist = %f, nn[i] = %f\n", dist, nn[__i]);
                                #endif
                                mu_assert(
                                "case 1:1 : nn != ans",
                                test_abs(dist - nn[__i]) <= 1e-2
                                );

                        }

                } while(0);

                #undef N
                #undef K

        } while(0);

        return 0;
}

static char*
all_tests_1_1(void)
{
        mu_run_test(test_case_1_sub_1);
        return 0;
}


/* ------------------------------------------------------------------------- */
/* Generated Test for case 1, subcase 2             */
/* ------------------------------------------------------------------------- */

static char*
test_case_1_sub_2(void)
{
        do { /* case: 0*/

                #define N 6
                #define K 1

                TYPE_T x[DIM * N] = {
                        10, 20, 30, 0, 0, 1, 2, 255, 3, 17, 99, 65, 45, 12, 200, 255, 255, 255
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 1:2 */

                        TYPE_T ans[DIM * N] = {
                                17, 99, 65, 10, 20, 30, 255, 255, 255, 0, 0, 1, 2, 255, 3, 45, 12, 200
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 1:2 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 1:2 */

                        TYPE_T q[DIM]  = { 1, 20, 3 };
                        TYPE_T nn[K * DIM] = { 405 };

                        TYPE_T* idx[K];

                        size_t __i;
                        size_t __j;

                        kd__findknn(tree, N, 0, 0, q, idx, K);
                        #if 1 
                        printf("params: k = %i, dist = [ ", K);
                        printf("] \n");
                        #endif

                        for (__i = 0; __i < K;   __i++) {

                                TYPE_F dist = 0;
                                for (__j = 0; __j < DIM; __j++) {
                                        dist += ((idx[__i])[__j] - q[__j]) * ((idx[__i])[__j] - q[__j]);
                                }

                                #if 1        
                                printf("dist = %f, nn[i] = %f\n", dist, nn[__i]);
                                #endif
                                mu_assert(
                                "case 1:2 : nn != ans",
                                test_abs(dist - nn[__i]) <= 1e-2
                                );

                        }

                } while(0);

                #undef N
                #undef K

        } while(0);

        return 0;
}

static char*
all_tests_1_2(void)
{
        mu_run_test(test_case_1_sub_2);
        return 0;
}


/* ------------------------------------------------------------------------- */
/* Generated Test for case 1, subcase 3             */
/* ------------------------------------------------------------------------- */

static char*
test_case_1_sub_3(void)
{
        do { /* case: 0*/

                #define N 6
                #define K 1

                TYPE_T x[DIM * N] = {
                        10, 20, 30, 0, 0, 1, 2, 255, 3, 17, 99, 65, 45, 12, 200, 255, 255, 255
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 1:3 */

                        TYPE_T ans[DIM * N] = {
                                17, 99, 65, 10, 20, 30, 255, 255, 255, 0, 0, 1, 2, 255, 3, 45, 12, 200
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 1:3 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 1:3 */

                        TYPE_T q[DIM]  = { 50, 100, 200 };
                        TYPE_T nn[K * DIM] = { 7769 };

                        TYPE_T* idx[K];

                        size_t __i;
                        size_t __j;

                        kd__findknn(tree, N, 0, 0, q, idx, K);
                        #if 1 
                        printf("params: k = %i, dist = [ ", K);
                        printf("] \n");
                        #endif

                        for (__i = 0; __i < K;   __i++) {

                                TYPE_F dist = 0;
                                for (__j = 0; __j < DIM; __j++) {
                                        dist += ((idx[__i])[__j] - q[__j]) * ((idx[__i])[__j] - q[__j]);
                                }

                                #if 1        
                                printf("dist = %f, nn[i] = %f\n", dist, nn[__i]);
                                #endif
                                mu_assert(
                                "case 1:3 : nn != ans",
                                test_abs(dist - nn[__i]) <= 1e-2
                                );

                        }

                } while(0);

                #undef N
                #undef K

        } while(0);

        return 0;
}

static char*
all_tests_1_3(void)
{
        mu_run_test(test_case_1_sub_3);
        return 0;
}


/* ------------------------------------------------------------------------- */
/* Generated Test for case 4, subcase 1             */
/* ------------------------------------------------------------------------- */

static char*
test_case_4_sub_1(void)
{
        do { /* case: 0*/

                #define N 6
                #define K 3

                TYPE_T x[DIM * N] = {
                        80, 1, 2, 9, 6, 2, 254, 10, 255, 5, 4, 1, 7, 2, 250, 200, 10, 10
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 4:1 */

                        TYPE_T ans[DIM * N] = {
                                80, 1, 2, 5, 4, 1, 254, 10, 255, 7, 2, 250, 9, 6, 2, 200, 10, 10
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 4:1 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 4:1 */

                        TYPE_T q[DIM]  = { 8, 1, 2 };
                        TYPE_T nn[K * DIM] = { 19, 26, 5184 };

                        TYPE_T* idx[K];

                        size_t __i;
                        size_t __j;

                        kd__findknn(tree, N, 0, 0, q, idx, K);
                        #if 1 
                        printf("params: k = %i, dist = [ ", K);
                        printf("] \n");
                        #endif

                        for (__i = 0; __i < K;   __i++) {

                                TYPE_F dist = 0;
                                for (__j = 0; __j < DIM; __j++) {
                                        dist += ((idx[__i])[__j] - q[__j]) * ((idx[__i])[__j] - q[__j]);
                                }

                                #if 1        
                                printf("dist = %f, nn[i] = %f\n", dist, nn[__i]);
                                #endif
                                mu_assert(
                                "case 4:1 : nn != ans",
                                test_abs(dist - nn[__i]) <= 1e-2
                                );

                        }

                } while(0);

                #undef N
                #undef K

        } while(0);

        return 0;
}

static char*
all_tests_4_1(void)
{
        mu_run_test(test_case_4_sub_1);
        return 0;
}


/* ------------------------------------------------------------------------- */
/* Generated Test for case 4, subcase 2             */
/* ------------------------------------------------------------------------- */

static char*
test_case_4_sub_2(void)
{
        do { /* case: 0*/

                #define N 6
                #define K 3

                TYPE_T x[DIM * N] = {
                        80, 1, 2, 9, 6, 2, 254, 10, 255, 5, 4, 1, 7, 2, 250, 200, 10, 10
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 4:2 */

                        TYPE_T ans[DIM * N] = {
                                80, 1, 2, 5, 4, 1, 254, 10, 255, 7, 2, 250, 9, 6, 2, 200, 10, 10
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 4:2 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 4:2 */

                        TYPE_T q[DIM]  = { 200, 11, 10 };
                        TYPE_T nn[K * DIM] = { 1, 14564, 36570 };

                        TYPE_T* idx[K];

                        size_t __i;
                        size_t __j;

                        kd__findknn(tree, N, 0, 0, q, idx, K);
                        #if 1 
                        printf("params: k = %i, dist = [ ", K);
                        printf("] \n");
                        #endif

                        for (__i = 0; __i < K;   __i++) {

                                TYPE_F dist = 0;
                                for (__j = 0; __j < DIM; __j++) {
                                        dist += ((idx[__i])[__j] - q[__j]) * ((idx[__i])[__j] - q[__j]);
                                }

                                #if 1        
                                printf("dist = %f, nn[i] = %f\n", dist, nn[__i]);
                                #endif
                                mu_assert(
                                "case 4:2 : nn != ans",
                                test_abs(dist - nn[__i]) <= 1e-2
                                );

                        }

                } while(0);

                #undef N
                #undef K

        } while(0);

        return 0;
}

static char*
all_tests_4_2(void)
{
        mu_run_test(test_case_4_sub_2);
        return 0;
}


/* ------------------------------------------------------------------------- */
/* Generated Test for case 4, subcase 3             */
/* ------------------------------------------------------------------------- */

static char*
test_case_4_sub_3(void)
{
        do { /* case: 0*/

                #define N 6
                #define K 3

                TYPE_T x[DIM * N] = {
                        80, 1, 2, 9, 6, 2, 254, 10, 255, 5, 4, 1, 7, 2, 250, 200, 10, 10
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 4:3 */

                        TYPE_T ans[DIM * N] = {
                                80, 1, 2, 5, 4, 1, 254, 10, 255, 7, 2, 250, 9, 6, 2, 200, 10, 10
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 4:3 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 4:3 */

                        TYPE_T q[DIM]  = { 255, 10, 254 };
                        TYPE_T nn[K * DIM] = { 2, 61584, 62561 };

                        TYPE_T* idx[K];

                        size_t __i;
                        size_t __j;

                        kd__findknn(tree, N, 0, 0, q, idx, K);
                        #if 1 
                        printf("params: k = %i, dist = [ ", K);
                        printf("] \n");
                        #endif

                        for (__i = 0; __i < K;   __i++) {

                                TYPE_F dist = 0;
                                for (__j = 0; __j < DIM; __j++) {
                                        dist += ((idx[__i])[__j] - q[__j]) * ((idx[__i])[__j] - q[__j]);
                                }

                                #if 1        
                                printf("dist = %f, nn[i] = %f\n", dist, nn[__i]);
                                #endif
                                mu_assert(
                                "case 4:3 : nn != ans",
                                test_abs(dist - nn[__i]) <= 1e-2
                                );

                        }

                } while(0);

                #undef N
                #undef K

        } while(0);

        return 0;
}

static char*
all_tests_4_3(void)
{
        mu_run_test(test_case_4_sub_3);
        return 0;
}


    /* ------------------------------------------------------------------------- */
    /* Final aggregator of all tests.                                            */
    /* ------------------------------------------------------------------------- */
    static char* all_tests(void) {
            char* msg = NULL;
            msg = all_tests_0_1(); if (msg) { return msg; }
msg = all_tests_0_2(); if (msg) { return msg; }
msg = all_tests_0_3(); if (msg) { return msg; }
msg = all_tests_2_1(); if (msg) { return msg; }
msg = all_tests_2_2(); if (msg) { return msg; }
msg = all_tests_2_3(); if (msg) { return msg; }
msg = all_tests_3_1(); if (msg) { return msg; }
msg = all_tests_3_2(); if (msg) { return msg; }
msg = all_tests_3_3(); if (msg) { return msg; }
msg = all_tests_5_1(); if (msg) { return msg; }
msg = all_tests_5_2(); if (msg) { return msg; }
msg = all_tests_5_3(); if (msg) { return msg; }
msg = all_tests_1_1(); if (msg) { return msg; }
msg = all_tests_1_2(); if (msg) { return msg; }
msg = all_tests_1_3(); if (msg) { return msg; }
msg = all_tests_4_1(); if (msg) { return msg; }
msg = all_tests_4_2(); if (msg) { return msg; }
msg = all_tests_4_3(); if (msg) { return msg; }
    }

    int main(void) {
            char* result = all_tests();
            if (result) {
                    printf("[tests/test_t-uchar_f-f32-3.c]:	ERROR: %s\n", result);
            } else {
                    printf("[tests/test_t-uchar_f-f32-3.c]:	ALL TESTS PASSED (%i)\n", tests_run);
            }        
            return result != 0;
    }
