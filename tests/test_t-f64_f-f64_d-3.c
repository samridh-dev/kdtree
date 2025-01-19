
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
                #define K 1

                TYPE_T x[DIM * N] = {
                        1.0, 2.0, 3.0, 4.5, 6.1, 2.5, 8.2, 1.1, 0.0, 5.0, 4.0, 1.5, 7.3, 2.4, 0.8, 4.0, 7.9, 0.3
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 0:1 */

                        TYPE_T ans[DIM * N] = {
                                5.0, 4.0, 1.5, 4.5, 6.1, 2.5, 7.3, 2.4, 0.8, 1.0, 2.0, 3.0, 4.0, 7.9, 0.3, 8.2, 1.1, 0.0
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 0:1 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 0:1 */

                        TYPE_T q[DIM]  = { 9.2, 1.0, 0.0 };
                        TYPE_T nn[K * DIM] = { 1.01 };

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
                #define K 1

                TYPE_T x[DIM * N] = {
                        1.0, 2.0, 3.0, 4.5, 6.1, 2.5, 8.2, 1.1, 0.0, 5.0, 4.0, 1.5, 7.3, 2.4, 0.8, 4.0, 7.9, 0.3
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 0:2 */

                        TYPE_T ans[DIM * N] = {
                                5.0, 4.0, 1.5, 4.5, 6.1, 2.5, 7.3, 2.4, 0.8, 1.0, 2.0, 3.0, 4.0, 7.9, 0.3, 8.2, 1.1, 0.0
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 0:2 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 0:2 */

                        TYPE_T q[DIM]  = { 0.0, 0.0, 0.0 };
                        TYPE_T nn[K * DIM] = { 14.0 };

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
                #define K 1

                TYPE_T x[DIM * N] = {
                        1.0, 2.0, 3.0, 4.5, 6.1, 2.5, 8.2, 1.1, 0.0, 5.0, 4.0, 1.5, 7.3, 2.4, 0.8, 4.0, 7.9, 0.3
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 0:3 */

                        TYPE_T ans[DIM * N] = {
                                5.0, 4.0, 1.5, 4.5, 6.1, 2.5, 7.3, 2.4, 0.8, 1.0, 2.0, 3.0, 4.0, 7.9, 0.3, 8.2, 1.1, 0.0
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 0:3 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 0:3 */

                        TYPE_T q[DIM]  = { 6.1, 3.3, 1.3 };
                        TYPE_T nn[K * DIM] = { 1.7399999999999995 };

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
/* Generated Test for case 1, subcase 1             */
/* ------------------------------------------------------------------------- */

static char*
test_case_1_sub_1(void)
{
        do { /* case: 0*/

                #define N 6
                #define K 2

                TYPE_T x[DIM * N] = {
                        10.5, 20.0, 30.0, 0.0, 0.1, 1.2, 2.0, 25.5, 3.4, 17.7, 99.9, 65.1, 45.2, 12.0, 200.5, 255.0, 255.0, 255.0
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 1:1 */

                        TYPE_T ans[DIM * N] = {
                                17.7, 99.9, 65.1, 10.5, 20.0, 30.0, 255.0, 255.0, 255.0, 0.0, 0.1, 1.2, 2.0, 25.5, 3.4, 45.2, 12.0, 200.5
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 1:1 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 1:1 */

                        TYPE_T q[DIM]  = { 255.0, 0.0, 255.0 };
                        TYPE_T nn[K * DIM] = { 47130.29000000001, 65025.0 };

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
                #define K 2

                TYPE_T x[DIM * N] = {
                        10.5, 20.0, 30.0, 0.0, 0.1, 1.2, 2.0, 25.5, 3.4, 17.7, 99.9, 65.1, 45.2, 12.0, 200.5, 255.0, 255.0, 255.0
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 1:2 */

                        TYPE_T ans[DIM * N] = {
                                17.7, 99.9, 65.1, 10.5, 20.0, 30.0, 255.0, 255.0, 255.0, 0.0, 0.1, 1.2, 2.0, 25.5, 3.4, 45.2, 12.0, 200.5
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 1:2 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 1:2 */

                        TYPE_T q[DIM]  = { 1.1, 20.0, 3.0 };
                        TYPE_T nn[K * DIM] = { 31.22, 400.4599999999999 };

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
                #define K 2

                TYPE_T x[DIM * N] = {
                        10.5, 20.0, 30.0, 0.0, 0.1, 1.2, 2.0, 25.5, 3.4, 17.7, 99.9, 65.1, 45.2, 12.0, 200.5, 255.0, 255.0, 255.0
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 1:3 */

                        TYPE_T ans[DIM * N] = {
                                17.7, 99.9, 65.1, 10.5, 20.0, 30.0, 255.0, 255.0, 255.0, 0.0, 0.1, 1.2, 2.0, 25.5, 3.4, 45.2, 12.0, 200.5
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 1:3 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 1:3 */

                        TYPE_T q[DIM]  = { 50.0, 100.0, 200.0 };
                        TYPE_T nn[K * DIM] = { 7767.29, 19241.31 };

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
/* Generated Test for case 2, subcase 1             */
/* ------------------------------------------------------------------------- */

static char*
test_case_2_sub_1(void)
{
        do { /* case: 0*/

                #define N 6
                #define K 3

                TYPE_T x[DIM * N] = {
                        100.0, 100.0, 100.0, 99.9, 98.7, 2.0, 30.5, 29.9, 28.1, 15.0, 15.0, 15.0, 1.2, 250.4, 10.3, 254.1, 253.2, 252.8
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 2:1 */

                        TYPE_T ans[DIM * N] = {
                                99.9, 98.7, 2.0, 30.5, 29.9, 28.1, 254.1, 253.2, 252.8, 15.0, 15.0, 15.0, 1.2, 250.4, 10.3, 100.0, 100.0, 100.0
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 2:1 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 2:1 */

                        TYPE_T q[DIM]  = { 254.0, 0.0, 1.0 };
                        TYPE_T nn[K * DIM] = { 33489.5, 43517.0, 51580.67 };

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
                #define K 3

                TYPE_T x[DIM * N] = {
                        100.0, 100.0, 100.0, 99.9, 98.7, 2.0, 30.5, 29.9, 28.1, 15.0, 15.0, 15.0, 1.2, 250.4, 10.3, 254.1, 253.2, 252.8
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 2:2 */

                        TYPE_T ans[DIM * N] = {
                                99.9, 98.7, 2.0, 30.5, 29.9, 28.1, 254.1, 253.2, 252.8, 15.0, 15.0, 15.0, 1.2, 250.4, 10.3, 100.0, 100.0, 100.0
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 2:2 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 2:2 */

                        TYPE_T q[DIM]  = { 2.0, 98.0, 28.0 };
                        TYPE_T nn[K * DIM] = { 5449.87, 7227.0, 10260.900000000001 };

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
                #define K 3

                TYPE_T x[DIM * N] = {
                        100.0, 100.0, 100.0, 99.9, 98.7, 2.0, 30.5, 29.9, 28.1, 15.0, 15.0, 15.0, 1.2, 250.4, 10.3, 254.1, 253.2, 252.8
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 2:3 */

                        TYPE_T ans[DIM * N] = {
                                99.9, 98.7, 2.0, 30.5, 29.9, 28.1, 254.1, 253.2, 252.8, 15.0, 15.0, 15.0, 1.2, 250.4, 10.3, 100.0, 100.0, 100.0
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 2:3 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 2:3 */

                        TYPE_T q[DIM]  = { 100.1, 100.1, 101.0 };
                        TYPE_T nn[K * DIM] = { 1.0199999999999978, 9803.0, 15086.609999999997 };

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
                        50.0, 40.2, 30.1, 0.5, 39.0, 80.9, 120.7, 255.0, 90.4, 4.7, 7.8, 10.6, 25.9, 250.2, 249.9, 130.0, 130.5, 130.9
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 3:1 */

                        TYPE_T ans[DIM * N] = {
                                50.0, 40.2, 30.1, 0.5, 39.0, 80.9, 120.7, 255.0, 90.4, 4.7, 7.8, 10.6, 25.9, 250.2, 249.9, 130.0, 130.5, 130.9
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 3:1 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 3:1 */

                        TYPE_T q[DIM]  = { 255.0, 255.0, 254.0 };
                        TYPE_T nn[K * DIM] = { 44801.45, 46278.86, 52526.659999999996, 138295.25 };

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
                        50.0, 40.2, 30.1, 0.5, 39.0, 80.9, 120.7, 255.0, 90.4, 4.7, 7.8, 10.6, 25.9, 250.2, 249.9, 130.0, 130.5, 130.9
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 3:2 */

                        TYPE_T ans[DIM * N] = {
                                50.0, 40.2, 30.1, 0.5, 39.0, 80.9, 120.7, 255.0, 90.4, 4.7, 7.8, 10.6, 25.9, 250.2, 249.9, 130.0, 130.5, 130.9
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 3:2 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 3:2 */

                        TYPE_T q[DIM]  = { 50.2, 41.0, 29.6 };
                        TYPE_T nn[K * DIM] = { 0.9299999999999966, 3533.4900000000002, 5105.780000000001, 24639.980000000003 };

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
                        50.0, 40.2, 30.1, 0.5, 39.0, 80.9, 120.7, 255.0, 90.4, 4.7, 7.8, 10.6, 25.9, 250.2, 249.9, 130.0, 130.5, 130.9
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 3:3 */

                        TYPE_T ans[DIM * N] = {
                                50.0, 40.2, 30.1, 0.5, 39.0, 80.9, 120.7, 255.0, 90.4, 4.7, 7.8, 10.6, 25.9, 250.2, 249.9, 130.0, 130.5, 130.9
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 3:3 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 3:3 */

                        TYPE_T q[DIM]  = { 129.9, 130.0, 130.0 };
                        TYPE_T nn[K * DIM] = { 1.0700000000000092, 17277.8, 24428.06, 27436.17 };

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
/* Generated Test for case 4, subcase 1             */
/* ------------------------------------------------------------------------- */

static char*
test_case_4_sub_1(void)
{
        do { /* case: 0*/

                #define N 6
                #define K 5

                TYPE_T x[DIM * N] = {
                        0.1, 0.2, 0.3, 5.5, 4.1, 1.9, 254.2, 10.9, 255.1, 7.0, 2.5, 250.3, 200.0, 10.4, 10.7, 1.2, 9.9, 6.2
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 4:1 */

                        TYPE_T ans[DIM * N] = {
                                7.0, 2.5, 250.3, 5.5, 4.1, 1.9, 254.2, 10.9, 255.1, 0.1, 0.2, 0.3, 1.2, 9.9, 6.2, 200.0, 10.4, 10.7
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 4:1 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 4:1 */

                        TYPE_T q[DIM]  = { 8.2, 1.1, 2.2 };
                        TYPE_T nn[K * DIM] = { 16.379999999999995, 70.03, 142.44, 36945.98, 61557.01000000001 };

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
                #define K 5

                TYPE_T x[DIM * N] = {
                        0.1, 0.2, 0.3, 5.5, 4.1, 1.9, 254.2, 10.9, 255.1, 7.0, 2.5, 250.3, 200.0, 10.4, 10.7, 1.2, 9.9, 6.2
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 4:2 */

                        TYPE_T ans[DIM * N] = {
                                7.0, 2.5, 250.3, 5.5, 4.1, 1.9, 254.2, 10.9, 255.1, 0.1, 0.2, 0.3, 1.2, 9.9, 6.2, 200.0, 10.4, 10.7
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 4:2 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 4:2 */

                        TYPE_T q[DIM]  = { 200.1, 11.0, 10.0 };
                        TYPE_T nn[K * DIM] = { 0.8599999999999974, 37982.38, 39576.86, 40210.73, 63000.829999999994 };

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
                #define K 5

                TYPE_T x[DIM * N] = {
                        0.1, 0.2, 0.3, 5.5, 4.1, 1.9, 254.2, 10.9, 255.1, 7.0, 2.5, 250.3, 200.0, 10.4, 10.7, 1.2, 9.9, 6.2
                };

                TYPE_T tree[DIM * KD__SIZE(8)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 4:3 */

                        TYPE_T ans[DIM * N] = {
                                7.0, 2.5, 250.3, 5.5, 4.1, 1.9, 254.2, 10.9, 255.1, 0.1, 0.2, 0.3, 1.2, 9.9, 6.2, 200.0, 10.4, 10.7
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 4:3 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 4:3 */

                        TYPE_T q[DIM]  = { 255.0, 10.0, 254.0 };
                        TYPE_T nn[K * DIM] = { 2.6600000000000064, 61573.94, 62220.05000000001, 125819.29000000001, 125839.47 };

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
msg = all_tests_1_1(); if (msg) { return msg; }
msg = all_tests_1_2(); if (msg) { return msg; }
msg = all_tests_1_3(); if (msg) { return msg; }
msg = all_tests_2_1(); if (msg) { return msg; }
msg = all_tests_2_2(); if (msg) { return msg; }
msg = all_tests_2_3(); if (msg) { return msg; }
msg = all_tests_3_1(); if (msg) { return msg; }
msg = all_tests_3_2(); if (msg) { return msg; }
msg = all_tests_3_3(); if (msg) { return msg; }
msg = all_tests_4_1(); if (msg) { return msg; }
msg = all_tests_4_2(); if (msg) { return msg; }
msg = all_tests_4_3(); if (msg) { return msg; }
    }

    int main(void) {
            char* result = all_tests();
            if (result) {
                    printf("[tests/test_t-f64_f-f64_d-3.c]:	ERROR: %s\n", result);
            } else {
                    printf("[tests/test_t-f64_f-f64_d-3.c]:	ALL TESTS PASSED (%i)\n", tests_run);
            }        
            return result != 0;
    }
