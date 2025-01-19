/*
 * Copyright (C) 2025 Samridh D. Singh
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.

 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.

 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef KD_TREE_H
#define KD_TREE_H

#include <float.h>

#ifndef KD__PREFIX
#define KD__PREFIX kd_
#endif /* KD__PREFIX */

#define KD__INTERNAL__COMB2(a, b) a##b
#define KD__INTERNAL__COMB1(a, b) KD__INTERNAL__COMB2(a, b)
#define KD__IMPL(name)            KD__INTERNAL__COMB1(KD__PREFIX, name)

#endif /* KD_TREE_H */

#ifndef KD__DIM
#define KD__DIM 3
#endif

#ifndef KD__UINT_T
#include <stddef.h>
#define KD__UINT_T size_t
#endif /* KD__TYPE_T */

#ifndef KD__TYPE_T
#error "KD__TYPE_T must be defined"
#endif /* KD__TYPE_T */

#ifndef KD__TYPE_F
#define KD__TYPE_F float
#endif /* KD__TYPE_F */

#ifdef KD__USE_STATIC
#define KD__LIB static
#else
#define KD__LIB
#endif /* KD__USE_STATIC */


/* TODO : INBUILT MEMCPY IS BROKEN !! */
#ifdef KD__MEMCPY__OVERRIDE
#define KD__MEMCPY KD__MEMCPY__OVERRIDE
#else
#define KD__MEMCPY(dst, src, n)                                               \
do {                                                                          \
        KD__UINT_T __i;                                                       \
        for(__i = 0; __i < n; __i++) {                                        \
                ((unsigned char*)(dst))[__i] = ((unsigned char*)(src))[__i];  \
        }                                                                     \
} while (0)
#endif /* KD__MEMCPY__OVERRIDE */

/* ------------------------------------------------------------------------- */
/* DECLARATION                                                               */
/* ------------------------------------------------------------------------- */

/* d -> depth of balanced tree */
#define KD__SIZE(d) (((1U << ((d) + 1)) - 1))

/* Build the k-d tree */
KD__LIB void 
KD__IMPL(_new) 
(KD__TYPE_T* const t, KD__TYPE_T* src, 
 KD__UINT_T n, KD__UINT_T d, KD__UINT_T i);

/* Find k nearest neighbors */
KD__LIB void 
KD__IMPL(_findknn) 
        (KD__TYPE_T* t, KD__UINT_T n, KD__UINT_T d, KD__UINT_T i, 
         KD__TYPE_T q[KD__DIM], KD__TYPE_T** idx, KD__UINT_T k);

/* ------------------------------------------------------------------------- */
/* IMPLEMENTATION                                                            */
/* ------------------------------------------------------------------------- */


/* ------------------------------------------------------------------------- */
/* KD__DIST()                                                                */
/* ------------------------------------------------------------------------- */

#if KD__DIM == 1
#define KD__DIST(ret, x, i, y, j)                                             \
        (ret) = ((x)[KD__DIM * (i)] - (y)[KD__DIM * (j)])                     \
              * ((x)[KD__DIM * (i)] - (y)[KD__DIM * (j)]);
#elif KD__DIM == 2
#define KD__DIST(ret, x, i, y, j)                                             \
        (ret) = ((x)[KD__DIM * (i) + 0] - (y)[KD__DIM * (j) + 0])             \
              * ((x)[KD__DIM * (i) + 0] - (y)[KD__DIM * (j) + 0])             \
              + ((x)[KD__DIM * (i) + 1] - (y)[KD__DIM * (j) + 1])             \
              * ((x)[KD__DIM * (i) + 1] - (y)[KD__DIM * (j) + 1]);
#elif KD__DIM == 3
#define KD__DIST(ret, x, i, y, j)                                             \
        (ret) = ((x)[KD__DIM * (i) + 0] - (y)[KD__DIM * (j) + 0])             \
              * ((x)[KD__DIM * (i) + 0] - (y)[KD__DIM * (j) + 0])             \
              + ((x)[KD__DIM * (i) + 1] - (y)[KD__DIM * (j) + 1])             \
              * ((x)[KD__DIM * (i) + 1] - (y)[KD__DIM * (j) + 1])             \
              + ((x)[KD__DIM * (i) + 2] - (y)[KD__DIM * (j) + 2])             \
              * ((x)[KD__DIM * (i) + 2] - (y)[KD__DIM * (j) + 2]);
#else
#define KD__DIST(ret, x, i, y, j)                                             \
do {                                                                          \
        KD__UINT_T __k;                                                       \
        (ret) = 0;                                                            \
        for (__k = 0; __k < KD__DIM; __k++) {                                 \
                (ret) += ((x)[KD__DIM * (i) + __k]-(y)[KD__DIM * (j) + __k])  \
                      *  ((x)[KD__DIM * (i) + __k]-(y)[KD__DIM * (j) + __k]); \
        }                                                                     \
} while (0);
#endif

/* ------------------------------------------------------------------------- */
/* _NEW()                                                                    */
/* ------------------------------------------------------------------------- */

KD__LIB void 
KD__IMPL(_new) 
        (KD__TYPE_T* const t, KD__TYPE_T* src, 
         KD__UINT_T n, KD__UINT_T d, KD__UINT_T i) 
{

        #define KD__NEW_SWAP(x, __i, __j)                                     \
        do {                                                                  \
                const KD__UINT_T __n = sizeof(KD__TYPE_T) * KD__DIM;          \
                unsigned char __tmp[sizeof(KD__TYPE_T) * KD__DIM];            \
                KD__MEMCPY(__tmp, &((x)[KD__DIM*(__i)]), __n);                \
                KD__MEMCPY(&((x)[KD__DIM*(__i)]), &((x)[KD__DIM*(__j)]), __n);\
                KD__MEMCPY(&((x)[KD__DIM*(__j)]), __tmp, __n);                \
        } while (0)

#if 0
        #define KD__NEW_HEAPSWAP(x, __i, __j)                                 \
                KD__NEW_SWAP(x, __i, __j)
  
        #define KD__NEW_MAXHEAPIFY(x, cnt, ax, __i)                           \
        do {                                                                  \
                KD__UINT_T __j = (__i);                                       \
                while (1) {                                                   \
                        KD__UINT_T b = __j;                                   \
                        const KD__UINT_T l = 2 * __j + 1;                     \
                        const KD__UINT_T r = 2 * __j + 2;                     \
                        if (l < (cnt)) {                                      \
                                if ((x)[KD__DIM * l + (ax)] >                 \
                                    (x)[KD__DIM * b + (ax)]) { b = l; }       \
                        }                                                     \
                        if (r < (cnt)) {                                      \
                                if ((x)[KD__DIM * r + (ax)] >                 \
                                    (x)[KD__DIM * b + (ax)]) { b = r; }       \
                        }                                                     \
                        if (b == __j) { break; }                              \
                        KD__NEW_HEAPSWAP(x, b, __j);                          \
                        __j = b;                                              \
                }                                                             \
        } while (0)

        #define KD__NEW_SORT(x, cnt, ax)                                      \
        do {                                                                  \
                KD__UINT_T __i;                                               \
                for (__i = (cnt) / 2; __i > 0; ) {                            \
                        __i--;                                                \
                        KD__NEW_MAXHEAPIFY(x, cnt, ax, __i);                  \
                }                                                             \
                for (__i = (cnt) - 1; __i > 0; __i--) {                       \
                        KD__NEW_HEAPSWAP(x, 0, __i);                          \
                        KD__NEW_MAXHEAPIFY(x, __i, ax, 0);                    \
                }                                                             \
        } while (0)

        if (n == 0) {
                return;
        }
#else
        #define KD__NEW_SORT(x, cnt, ax)                                      \
        do {                                                                  \
                KD__UINT_T j;                                                 \
                for (j = 0; j < (cnt); j++) {                                 \
                        KD__UINT_T min = j;                                   \
                        KD__UINT_T k;                                         \
                        for (k = j + 1; k < (cnt); k++) {                     \
                                if (src[KD__DIM * k   + (ax)] <               \
                                    src[KD__DIM * min + (ax)]) {              \
                                        min = k;                              \
                                }                                             \
                        }                                                     \
                        KD__NEW_SWAP(src, j, min);                            \
                }                                                             \
        } while (0)
#endif

        if (n == 0) {
                return;
        }

        KD__NEW_SORT(src, n, d % KD__DIM);
        KD__MEMCPY(&t[i  * KD__DIM], &src[(n/2) * KD__DIM],
                   sizeof(KD__TYPE_T) * KD__DIM);
        
        kd__new(t, &src[0x0000000000000], 0+(n/2+0), d+1, 2*i+1);
        kd__new(t, &src[KD__DIM*(n/2+1)], n-(n/2+1), d+1, 2*i+2);

        #undef KD__NEW_SWAP
        #undef KD__NEW_SORT

}

/* ------------------------------------------------------------------------- */
/* _FINDKNN()                                                                */
/* ------------------------------------------------------------------------- */

KD__LIB void 
KD__IMPL(_findknn) 
        (KD__TYPE_T* t, KD__UINT_T n, KD__UINT_T d, KD__UINT_T i, 
         KD__TYPE_T q[KD__DIM], KD__TYPE_T** idx, KD__UINT_T k)
{
#if 0
        #define KD__AXIS ((d) % KD__DIM)

        
        #define KD__FINDKNN_HEAPSWAP(heap, __i, __j)                          \
        do {                                                                  \
                KD__TYPE_T* __tmp = (heap)[(__i)];                            \
                (heap)[(__i)] = (heap)[(__j)];                                \
                (heap)[(__j)] = __tmp;                                        \
        } while (0);

        #define KD__FINDKNN_MAXHEAPIFY(tree, q, heap, k, __i)                 \
        do {                                                                  \
                KD__UINT_T __j = (__i);                                       \
                while (1) {                                                   \
                        const KD__UINT_T l = 2 * __j + 1;                     \
                        const KD__UINT_T r = 2 * __j + 2;                     \
                        KD__UINT_T b = __j;                                   \
                        KD__TYPE_F db;                                        \
                        KD__DIST(db, q, 0, heap[b], 0);                       \
                        if (l < (k)) {                                        \
                                KD__TYPE_F dl;                                \
                                KD__DIST(dl, q, 0, heap[l], 0);               \
                                if (dl > db) { b = l; db = dl; }              \
                        }                                                     \
                        if (r < (k)) {                                        \
                                KD__TYPE_F dr;                                \
                                KD__DIST(dr, q, 0, heap[r], 0);               \
                                if (dr > db) { b = r; db = dr; }              \
                        }                                                     \
                        if (b == __j) break;                                  \
                        KD__FINDKNN_HEAPSWAP(heap, b, __j);                   \
                        __j = b;                                              \
                }                                                             \
        } while (0);

        #define KD__FINDKNN_HEAPSORT(tree, q, heap, k)                        \
        do {                                                                  \
                KD__UINT_T __i;                                               \
                for (__i = (k)/2; __i > 0; ) {                                \
                        __i--;                                                \
                        KD__FINDKNN_MAXHEAPIFY(tree, q, heap, k, __i);        \
                }                                                             \
                for (__i = (k)-1; __i > 0; __i--) {                           \
                        KD__FINDKNN_HEAPSWAP(heap, 0, __i);                   \
                        KD__FINDKNN_MAXHEAPIFY(tree, q, heap, __i, 0);        \
                }                                                             \
        } while (0);

        /* function begin */
        
        KD__TYPE_F dist;

        #if 1
        static
        #endif
        KD__TYPE_T q_inf[KD__DIM];
        
        if (d == 0 && i == 0) {
                KD__UINT_T j;
                for (j = 0; j < k; j++) {
                  idx[j] = q_inf;
                }
                for (j = 0; j < KD__DIM; j++) {
                  q_inf[j] = (KD__TYPE_F)(DBL_MAX);
                }
        }

        if (i >= n) {
                return;
        }
        
        KD__DIST(dist, q, 0, t, i);
        do {
                KD__UINT_T j;
                for (j = 0; j < KD__DIM; j++) {
                        dist -= ((KD__TYPE_F)q[j] - (KD__TYPE_F)(*idx)[j])
                              * ((KD__TYPE_F)q[j] - (KD__TYPE_F)(*idx)[j]);
                }
        } while (0);

        if (dist < 0) {
                idx[0] = &t[KD__DIM * i];
                KD__FINDKNN_MAXHEAPIFY(t, q, idx, k, 0);
        }

        if (q[KD__AXIS] < t[KD__DIM * i + KD__AXIS]) {
                kd__findknn(t, n, d+1, 2*i+1, q, idx, k);
        } else {
                kd__findknn(t, n, d+1, 2*i+2, q, idx, k);
        }
        
        /* double check this */
        KD__DIST(dist, q, 0, *idx, 0);
        if (((KD__TYPE_F)q[KD__AXIS] - (KD__TYPE_F)t[KD__DIM * i + KD__AXIS]) * 
            ((KD__TYPE_F)q[KD__AXIS] - (KD__TYPE_F)t[KD__DIM * i + KD__AXIS]) 
            >= dist) {

                if (d == 0 && i == 0) {
                        KD__FINDKNN_HEAPSORT(t, q, idx, k); 
                }

                return;

        }
 
        if (q[KD__AXIS] < t[KD__DIM * i + KD__AXIS]) {
                kd__findknn(t, n, d+1, 2*i+2, q, idx, k);
        } else {
                kd__findknn(t, n, d+1, 2*i+1, q, idx, k);
        }
        
        if (d == 0 && i == 0) {
                KD__FINDKNN_HEAPSORT(t, q, idx, k); 
        }

        return;

        #undef KD__AXIS
        #undef KD__DIST
        #undef KD__HEAPSWAP
        #undef KD__HEAPSORT
        #undef KD__MAXHEAPIFY
#else

        #define KD__AXIS ((d) % KD__DIM)

        #define KD__FINDKNN_HEAPSWAP(heap, dist, __i, __j)                    \
        do {                                                                  \
                do {                                                          \
                        KD__TYPE_T* __tmp = (heap)[(__i)];                    \
                        (heap)[(__i)] = (heap)[(__j)];                        \
                        (heap)[(__j)] = __tmp;                                \
                } while (0);                                                  \
                do {                                                          \
                        KD__TYPE_F __tmp = (dist)[(__i)];                     \
                        (dist)[(__i)] = (dist)[(__j)];                        \
                        (dist)[(__j)] = __tmp;                                \
                } while(0);                                                   \
        } while (0);

        #define KD__FINDKNN_MAXHEAPIFY(tree, q, heap, dist, k, __i)           \
        do {                                                                  \
                KD__UINT_T __j = (__i);                                       \
                while (1) {                                                   \
                        KD__UINT_T b = __j;                                   \
                        const KD__UINT_T l = 2 * __j + 1;                     \
                        const KD__UINT_T r = 2 * __j + 2;                     \
                        if (l < (k) && (dist)[l] > (dist)[b]) b = l;          \
                        if (r < (k) && (dist)[r] > (dist)[b]) b = r;          \
                        if (b == __j) break;                                  \
                        KD__FINDKNN_HEAPSWAP(heap, dist, b, __j);             \
                        __j = b;                                              \
                }                                                             \
        } while (0);

        #define KD__FINDKNN_HEAPSORT(tree, q, heap, dist, k)                  \
        do {                                                                  \
                KD__UINT_T __i;                                               \
                for (__i = (k)/2; __i > 0; ) {                                \
                        __i--;                                                \
                        KD__FINDKNN_MAXHEAPIFY(tree, q, heap, dist, k, __i);  \
                }                                                             \
                for (__i = (k)-1; __i > 0; __i--) {                           \
                        KD__FINDKNN_HEAPSWAP(heap, dist, 0, __i);             \
                        KD__FINDKNN_MAXHEAPIFY(tree, q, heap, dist, __i, 0);  \
                }                                                             \
        } while (0);

        /* function begin */

        KD__TYPE_F dist;

        #if 1
        static
        #endif
        KD__TYPE_T q_inf[KD__DIM];

        #if 1
        static
        #endif
        KD__TYPE_F dst[256];

        if (d == 0 && i == 0) {
                KD__UINT_T  j = 0;
                for (j = 0; j < KD__DIM; j++) {
                  q_inf[j] = (KD__TYPE_F)(DBL_MAX);
                }
                for (j = 0; j < k; j++) {
                  idx[j] = q_inf;
                  dst[j] = (KD__TYPE_F)(DBL_MAX);
                }
        }

        if (i >= n) {
                return;
        }
        
        KD__DIST(dist, q, 0, t, i);

        if (dist < dst[0]) {
                idx[0] = &t[KD__DIM * i];
                dst[0] = dist;
                KD__FINDKNN_MAXHEAPIFY(t, q, idx, dst, k, 0);
        }

        if (q[KD__AXIS] < t[KD__DIM * i + KD__AXIS]) {
                kd__findknn(t, n, d+1, 2*i+1, q, idx, k);
        } else {
                kd__findknn(t, n, d+1, 2*i+2, q, idx, k);
        }
        
        if (((KD__TYPE_F)q[KD__AXIS] - (KD__TYPE_F)t[KD__DIM * i + KD__AXIS]) * 
            ((KD__TYPE_F)q[KD__AXIS] - (KD__TYPE_F)t[KD__DIM * i + KD__AXIS]) 
            >= *dst) {

                if (d == 0 && i == 0) {
                        KD__FINDKNN_HEAPSORT(t, q, idx, dst, k); 
                }

                return;

        }
 
        if (q[KD__AXIS] < t[KD__DIM * i + KD__AXIS]) {
                kd__findknn(t, n, d+1, 2*i+2, q, idx, k);
        } else {
                kd__findknn(t, n, d+1, 2*i+1, q, idx, k);
        }
        
        if (d == 0 && i == 0) {
                KD__FINDKNN_HEAPSORT(t, q, idx, dst, k); 
        }

        return;

        #undef KD__AXIS
        #undef KD__DIST
        #undef KD__HEAPSWAP
        #undef KD__HEAPSORT
        #undef KD__MAXHEAPIFY

#endif

}

#undef KD__DIM
#undef KD__TYPE_T
#undef KD__TYPE_F
#undef KD__PREFIX
#undef KD__USE_STATIC
#undef KD__LIB
