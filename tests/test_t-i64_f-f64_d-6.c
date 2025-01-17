
#include <limits.h>

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

#define TYPE_T long int
#define TYPE_F double
#define DIM    6

#define KD__TYPE_T TYPE_T
#define KD__TYPE_F TYPE_F
#define KD__DIM DIM
#include "../kdtree.h"


/* ------------------------------------------------------------------------- */
/* Generated Test for case 0, subcase 1             */
/* ------------------------------------------------------------------------- */

static char*
test_case_0_sub_1(void)
{
        do { /* case: 0*/

                #define N 6

                TYPE_T x[DIM * N] = {
                        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36
                };

                TYPE_T tree[DIM * KD__SIZE(4)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 0:1 */

                        TYPE_T ans[DIM * N] = {
                                19, 20, 21, 22, 23, 24, 7, 8, 9, 10, 11, 12, 31, 32, 33, 34, 35, 36, 1, 2, 3, 4, 5, 6, 13, 14, 15, 16, 17, 18, 25, 26, 27, 28, 29, 30
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 0:1 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 0:1 */

                        TYPE_T q[DIM]  = { 37, 38, 39, 40, 41, 42 };
                        TYPE_T nn[DIM] = { 31, 32, 33, 34, 35, 36 };

                        size_t __i;

                        size_t idx  = 0;
                        TYPE_F  dmin = (TYPE_F)INT_MAX;

                        kd__findnn(tree, N, 0, 0, q, &idx, &dmin);

                        for (__i = 0; __i < DIM; __i++) {
                                mu_assert("case 0:1 : nn != ans",
                                          tree[DIM*idx+__i] == nn[__i]);
                        }

                } while(0);

                #undef N

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

                TYPE_T x[DIM * N] = {
                        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36
                };

                TYPE_T tree[DIM * KD__SIZE(4)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 0:2 */

                        TYPE_T ans[DIM * N] = {
                                19, 20, 21, 22, 23, 24, 7, 8, 9, 10, 11, 12, 31, 32, 33, 34, 35, 36, 1, 2, 3, 4, 5, 6, 13, 14, 15, 16, 17, 18, 25, 26, 27, 28, 29, 30
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 0:2 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 0:2 */

                        TYPE_T q[DIM]  = { 43, 44, 45, 46, 47, 48 };
                        TYPE_T nn[DIM] = { 31, 32, 33, 34, 35, 36 };

                        size_t __i;

                        size_t idx  = 0;
                        TYPE_F  dmin = (TYPE_F)INT_MAX;

                        kd__findnn(tree, N, 0, 0, q, &idx, &dmin);

                        for (__i = 0; __i < DIM; __i++) {
                                mu_assert("case 0:2 : nn != ans",
                                          tree[DIM*idx+__i] == nn[__i]);
                        }

                } while(0);

                #undef N

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

                TYPE_T x[DIM * N] = {
                        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36
                };

                TYPE_T tree[DIM * KD__SIZE(4)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 0:3 */

                        TYPE_T ans[DIM * N] = {
                                19, 20, 21, 22, 23, 24, 7, 8, 9, 10, 11, 12, 31, 32, 33, 34, 35, 36, 1, 2, 3, 4, 5, 6, 13, 14, 15, 16, 17, 18, 25, 26, 27, 28, 29, 30
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 0:3 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 0:3 */

                        TYPE_T q[DIM]  = { 49, 50, 51, 52, 53, 54 };
                        TYPE_T nn[DIM] = { 31, 32, 33, 34, 35, 36 };

                        size_t __i;

                        size_t idx  = 0;
                        TYPE_F  dmin = (TYPE_F)INT_MAX;

                        kd__findnn(tree, N, 0, 0, q, &idx, &dmin);

                        for (__i = 0; __i < DIM; __i++) {
                                mu_assert("case 0:3 : nn != ans",
                                          tree[DIM*idx+__i] == nn[__i]);
                        }

                } while(0);

                #undef N

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

                TYPE_T x[DIM * N] = {
                        100, 101, 102, 103, 104, 105, 200, 201, 202, 203, 204, 205, 300, 301, 302, 303, 304, 305, 400, 401, 402, 403, 404, 405, 500, 501, 502, 503, 504, 505, 600, 601, 602, 603, 604, 605
                };

                TYPE_T tree[DIM * KD__SIZE(4)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 1:1 */

                        TYPE_T ans[DIM * N] = {
                                400, 401, 402, 403, 404, 405, 200, 201, 202, 203, 204, 205, 600, 601, 602, 603, 604, 605, 100, 101, 102, 103, 104, 105, 300, 301, 302, 303, 304, 305, 500, 501, 502, 503, 504, 505
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 1:1 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 1:1 */

                        TYPE_T q[DIM]  = { 700, 701, 702, 703, 704, 705 };
                        TYPE_T nn[DIM] = { 600, 601, 602, 603, 604, 605 };

                        size_t __i;

                        size_t idx  = 0;
                        TYPE_F  dmin = (TYPE_F)INT_MAX;

                        kd__findnn(tree, N, 0, 0, q, &idx, &dmin);

                        for (__i = 0; __i < DIM; __i++) {
                                mu_assert("case 1:1 : nn != ans",
                                          tree[DIM*idx+__i] == nn[__i]);
                        }

                } while(0);

                #undef N

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

                TYPE_T x[DIM * N] = {
                        100, 101, 102, 103, 104, 105, 200, 201, 202, 203, 204, 205, 300, 301, 302, 303, 304, 305, 400, 401, 402, 403, 404, 405, 500, 501, 502, 503, 504, 505, 600, 601, 602, 603, 604, 605
                };

                TYPE_T tree[DIM * KD__SIZE(4)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 1:2 */

                        TYPE_T ans[DIM * N] = {
                                400, 401, 402, 403, 404, 405, 200, 201, 202, 203, 204, 205, 600, 601, 602, 603, 604, 605, 100, 101, 102, 103, 104, 105, 300, 301, 302, 303, 304, 305, 500, 501, 502, 503, 504, 505
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 1:2 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 1:2 */

                        TYPE_T q[DIM]  = { 800, 801, 802, 803, 804, 805 };
                        TYPE_T nn[DIM] = { 600, 601, 602, 603, 604, 605 };

                        size_t __i;

                        size_t idx  = 0;
                        TYPE_F  dmin = (TYPE_F)INT_MAX;

                        kd__findnn(tree, N, 0, 0, q, &idx, &dmin);

                        for (__i = 0; __i < DIM; __i++) {
                                mu_assert("case 1:2 : nn != ans",
                                          tree[DIM*idx+__i] == nn[__i]);
                        }

                } while(0);

                #undef N

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

                TYPE_T x[DIM * N] = {
                        100, 101, 102, 103, 104, 105, 200, 201, 202, 203, 204, 205, 300, 301, 302, 303, 304, 305, 400, 401, 402, 403, 404, 405, 500, 501, 502, 503, 504, 505, 600, 601, 602, 603, 604, 605
                };

                TYPE_T tree[DIM * KD__SIZE(4)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 1:3 */

                        TYPE_T ans[DIM * N] = {
                                400, 401, 402, 403, 404, 405, 200, 201, 202, 203, 204, 205, 600, 601, 602, 603, 604, 605, 100, 101, 102, 103, 104, 105, 300, 301, 302, 303, 304, 305, 500, 501, 502, 503, 504, 505
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 1:3 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 1:3 */

                        TYPE_T q[DIM]  = { 900, 901, 902, 903, 904, 905 };
                        TYPE_T nn[DIM] = { 600, 601, 602, 603, 604, 605 };

                        size_t __i;

                        size_t idx  = 0;
                        TYPE_F  dmin = (TYPE_F)INT_MAX;

                        kd__findnn(tree, N, 0, 0, q, &idx, &dmin);

                        for (__i = 0; __i < DIM; __i++) {
                                mu_assert("case 1:3 : nn != ans",
                                          tree[DIM*idx+__i] == nn[__i]);
                        }

                } while(0);

                #undef N

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

                TYPE_T x[DIM * N] = {
                        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35
                };

                TYPE_T tree[DIM * KD__SIZE(4)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 2:1 */

                        TYPE_T ans[DIM * N] = {
                                18, 19, 20, 21, 22, 23, 6, 7, 8, 9, 10, 11, 30, 31, 32, 33, 34, 35, 0, 1, 2, 3, 4, 5, 12, 13, 14, 15, 16, 17, 24, 25, 26, 27, 28, 29
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 2:1 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 2:1 */

                        TYPE_T q[DIM]  = { 36, 37, 38, 39, 40, 41 };
                        TYPE_T nn[DIM] = { 30, 31, 32, 33, 34, 35 };

                        size_t __i;

                        size_t idx  = 0;
                        TYPE_F  dmin = (TYPE_F)INT_MAX;

                        kd__findnn(tree, N, 0, 0, q, &idx, &dmin);

                        for (__i = 0; __i < DIM; __i++) {
                                mu_assert("case 2:1 : nn != ans",
                                          tree[DIM*idx+__i] == nn[__i]);
                        }

                } while(0);

                #undef N

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

                TYPE_T x[DIM * N] = {
                        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35
                };

                TYPE_T tree[DIM * KD__SIZE(4)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 2:2 */

                        TYPE_T ans[DIM * N] = {
                                18, 19, 20, 21, 22, 23, 6, 7, 8, 9, 10, 11, 30, 31, 32, 33, 34, 35, 0, 1, 2, 3, 4, 5, 12, 13, 14, 15, 16, 17, 24, 25, 26, 27, 28, 29
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 2:2 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 2:2 */

                        TYPE_T q[DIM]  = { 42, 43, 44, 45, 46, 47 };
                        TYPE_T nn[DIM] = { 30, 31, 32, 33, 34, 35 };

                        size_t __i;

                        size_t idx  = 0;
                        TYPE_F  dmin = (TYPE_F)INT_MAX;

                        kd__findnn(tree, N, 0, 0, q, &idx, &dmin);

                        for (__i = 0; __i < DIM; __i++) {
                                mu_assert("case 2:2 : nn != ans",
                                          tree[DIM*idx+__i] == nn[__i]);
                        }

                } while(0);

                #undef N

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

                TYPE_T x[DIM * N] = {
                        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35
                };

                TYPE_T tree[DIM * KD__SIZE(4)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 2:3 */

                        TYPE_T ans[DIM * N] = {
                                18, 19, 20, 21, 22, 23, 6, 7, 8, 9, 10, 11, 30, 31, 32, 33, 34, 35, 0, 1, 2, 3, 4, 5, 12, 13, 14, 15, 16, 17, 24, 25, 26, 27, 28, 29
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 2:3 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 2:3 */

                        TYPE_T q[DIM]  = { 48, 49, 50, 51, 52, 53 };
                        TYPE_T nn[DIM] = { 30, 31, 32, 33, 34, 35 };

                        size_t __i;

                        size_t idx  = 0;
                        TYPE_F  dmin = (TYPE_F)INT_MAX;

                        kd__findnn(tree, N, 0, 0, q, &idx, &dmin);

                        for (__i = 0; __i < DIM; __i++) {
                                mu_assert("case 2:3 : nn != ans",
                                          tree[DIM*idx+__i] == nn[__i]);
                        }

                } while(0);

                #undef N

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

                TYPE_T x[DIM * N] = {
                        10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300, 310, 320, 330, 340, 350, 360
                };

                TYPE_T tree[DIM * KD__SIZE(4)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 3:1 */

                        TYPE_T ans[DIM * N] = {
                                190, 200, 210, 220, 230, 240, 70, 80, 90, 100, 110, 120, 310, 320, 330, 340, 350, 360, 10, 20, 30, 40, 50, 60, 130, 140, 150, 160, 170, 180, 250, 260, 270, 280, 290, 300
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 3:1 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 3:1 */

                        TYPE_T q[DIM]  = { 370, 380, 390, 400, 410, 420 };
                        TYPE_T nn[DIM] = { 310, 320, 330, 340, 350, 360 };

                        size_t __i;

                        size_t idx  = 0;
                        TYPE_F  dmin = (TYPE_F)INT_MAX;

                        kd__findnn(tree, N, 0, 0, q, &idx, &dmin);

                        for (__i = 0; __i < DIM; __i++) {
                                mu_assert("case 3:1 : nn != ans",
                                          tree[DIM*idx+__i] == nn[__i]);
                        }

                } while(0);

                #undef N

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

                TYPE_T x[DIM * N] = {
                        10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300, 310, 320, 330, 340, 350, 360
                };

                TYPE_T tree[DIM * KD__SIZE(4)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 3:2 */

                        TYPE_T ans[DIM * N] = {
                                190, 200, 210, 220, 230, 240, 70, 80, 90, 100, 110, 120, 310, 320, 330, 340, 350, 360, 10, 20, 30, 40, 50, 60, 130, 140, 150, 160, 170, 180, 250, 260, 270, 280, 290, 300
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 3:2 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 3:2 */

                        TYPE_T q[DIM]  = { 430, 440, 450, 460, 470, 480 };
                        TYPE_T nn[DIM] = { 310, 320, 330, 340, 350, 360 };

                        size_t __i;

                        size_t idx  = 0;
                        TYPE_F  dmin = (TYPE_F)INT_MAX;

                        kd__findnn(tree, N, 0, 0, q, &idx, &dmin);

                        for (__i = 0; __i < DIM; __i++) {
                                mu_assert("case 3:2 : nn != ans",
                                          tree[DIM*idx+__i] == nn[__i]);
                        }

                } while(0);

                #undef N

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

                TYPE_T x[DIM * N] = {
                        10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300, 310, 320, 330, 340, 350, 360
                };

                TYPE_T tree[DIM * KD__SIZE(4)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 3:3 */

                        TYPE_T ans[DIM * N] = {
                                190, 200, 210, 220, 230, 240, 70, 80, 90, 100, 110, 120, 310, 320, 330, 340, 350, 360, 10, 20, 30, 40, 50, 60, 130, 140, 150, 160, 170, 180, 250, 260, 270, 280, 290, 300
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 3:3 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 3:3 */

                        TYPE_T q[DIM]  = { 490, 500, 510, 520, 530, 540 };
                        TYPE_T nn[DIM] = { 310, 320, 330, 340, 350, 360 };

                        size_t __i;

                        size_t idx  = 0;
                        TYPE_F  dmin = (TYPE_F)INT_MAX;

                        kd__findnn(tree, N, 0, 0, q, &idx, &dmin);

                        for (__i = 0; __i < DIM; __i++) {
                                mu_assert("case 3:3 : nn != ans",
                                          tree[DIM*idx+__i] == nn[__i]);
                        }

                } while(0);

                #undef N

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

                TYPE_T x[DIM * N] = {
                        1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000, 20000, 21000, 22000, 23000, 24000, 25000, 26000, 27000, 28000, 29000, 30000, 31000, 32000, 33000, 34000, 35000, 36000
                };

                TYPE_T tree[DIM * KD__SIZE(4)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 4:1 */

                        TYPE_T ans[DIM * N] = {
                                19000, 20000, 21000, 22000, 23000, 24000, 7000, 8000, 9000, 10000, 11000, 12000, 31000, 32000, 33000, 34000, 35000, 36000, 1000, 2000, 3000, 4000, 5000, 6000, 13000, 14000, 15000, 16000, 17000, 18000, 25000, 26000, 27000, 28000, 29000, 30000
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 4:1 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 4:1 */

                        TYPE_T q[DIM]  = { 37000, 38000, 39000, 40000, 41000, 42000 };
                        TYPE_T nn[DIM] = { 31000, 32000, 33000, 34000, 35000, 36000 };

                        size_t __i;

                        size_t idx  = 0;
                        TYPE_F  dmin = (TYPE_F)INT_MAX;

                        kd__findnn(tree, N, 0, 0, q, &idx, &dmin);

                        for (__i = 0; __i < DIM; __i++) {
                                mu_assert("case 4:1 : nn != ans",
                                          tree[DIM*idx+__i] == nn[__i]);
                        }

                } while(0);

                #undef N

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

                TYPE_T x[DIM * N] = {
                        1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000, 20000, 21000, 22000, 23000, 24000, 25000, 26000, 27000, 28000, 29000, 30000, 31000, 32000, 33000, 34000, 35000, 36000
                };

                TYPE_T tree[DIM * KD__SIZE(4)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 4:2 */

                        TYPE_T ans[DIM * N] = {
                                19000, 20000, 21000, 22000, 23000, 24000, 7000, 8000, 9000, 10000, 11000, 12000, 31000, 32000, 33000, 34000, 35000, 36000, 1000, 2000, 3000, 4000, 5000, 6000, 13000, 14000, 15000, 16000, 17000, 18000, 25000, 26000, 27000, 28000, 29000, 30000
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 4:2 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 4:2 */

                        TYPE_T q[DIM]  = { 43000, 44000, 45000, 46000, 47000, 48000 };
                        TYPE_T nn[DIM] = { 31000, 32000, 33000, 34000, 35000, 36000 };

                        size_t __i;

                        size_t idx  = 0;
                        TYPE_F  dmin = (TYPE_F)INT_MAX;

                        kd__findnn(tree, N, 0, 0, q, &idx, &dmin);

                        for (__i = 0; __i < DIM; __i++) {
                                mu_assert("case 4:2 : nn != ans",
                                          tree[DIM*idx+__i] == nn[__i]);
                        }

                } while(0);

                #undef N

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

                TYPE_T x[DIM * N] = {
                        1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000, 20000, 21000, 22000, 23000, 24000, 25000, 26000, 27000, 28000, 29000, 30000, 31000, 32000, 33000, 34000, 35000, 36000
                };

                TYPE_T tree[DIM * KD__SIZE(4)] = {0};

                kd__new(tree, x, N, 0, 0);

                do { /* case 4:3 */

                        TYPE_T ans[DIM * N] = {
                                19000, 20000, 21000, 22000, 23000, 24000, 7000, 8000, 9000, 10000, 11000, 12000, 31000, 32000, 33000, 34000, 35000, 36000, 1000, 2000, 3000, 4000, 5000, 6000, 13000, 14000, 15000, 16000, 17000, 18000, 25000, 26000, 27000, 28000, 29000, 30000
                        };

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {
                                mu_assert("case 4:3 : tree != ans",
                                          tree[i] == ans[i]);
                        }

                } while(0);

                do { /* case 4:3 */

                        TYPE_T q[DIM]  = { 49000, 50000, 51000, 52000, 53000, 54000 };
                        TYPE_T nn[DIM] = { 31000, 32000, 33000, 34000, 35000, 36000 };

                        size_t __i;

                        size_t idx  = 0;
                        TYPE_F  dmin = (TYPE_F)INT_MAX;

                        kd__findnn(tree, N, 0, 0, q, &idx, &dmin);

                        for (__i = 0; __i < DIM; __i++) {
                                mu_assert("case 4:3 : nn != ans",
                                          tree[DIM*idx+__i] == nn[__i]);
                        }

                } while(0);

                #undef N

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
            all_tests_0_1();
all_tests_0_2();
all_tests_0_3();
all_tests_1_1();
all_tests_1_2();
all_tests_1_3();
all_tests_2_1();
all_tests_2_2();
all_tests_2_3();
all_tests_3_1();
all_tests_3_2();
all_tests_3_3();
all_tests_4_1();
all_tests_4_2();
all_tests_4_3();
        return 0;
}

int main(void) {
        char* result = all_tests();
        if (result) {
                printf("[tests/test_t-i64_f-f64_d-6.c]:	ERROR: %s\n", result);
        } else {
                printf("[tests/test_t-i64_f-f64_d-6.c]:	ALL TESTS PASSED\n");
        }
        return result != 0;
}
