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

#include <stddef.h>

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

#ifdef KD__MEMCPY__OVERRIDE
#define KD__MEMCPY KD__MEMCPY__OVERRIDE
#else
#define KD__MEMCPY(dst, src, n)                                               \
do {                                                                          \
        size_t __i;                                                           \
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
        (KD__TYPE_T* const t, KD__TYPE_T* src, size_t n, size_t d, size_t i);

/* Find nearest neighbor */
KD__LIB void 
KD__IMPL(_findnn) 
        (KD__TYPE_T* t, size_t n, size_t d, size_t i, 
         KD__TYPE_T q[KD__DIM], size_t* idx, KD__TYPE_F* dmin);

/* ------------------------------------------------------------------------- */
/* IMPLEMENTATION                                                            */
/* ------------------------------------------------------------------------- */

KD__LIB void 
KD__IMPL(_new) 
        (KD__TYPE_T* const t, KD__TYPE_T* src, size_t n, size_t d, size_t i) 
{
        
        #define KD__NEW_SWAP(buf, i, j)                                       \
        do {                                                                  \
                const size_t __n = sizeof(KD__TYPE_T) * KD__DIM;              \
                unsigned char __tmp[sizeof(KD__TYPE_T) * KD__DIM];            \
                KD__MEMCPY(__tmp, &((buf)[KD__DIM*(i)]), __n);                \
                KD__MEMCPY(&((buf)[KD__DIM*(i)]), &((buf)[KD__DIM*(j)]), __n);\
                KD__MEMCPY(&((buf)[KD__DIM*(j)]), __tmp, __n);                \
        } while (0)

        #define KD__NEW_SORT(x, count, axis)                                  \
        do {                                                                  \
                size_t j;                                                     \
                for (j = 0; j < (count); j++) {                               \
                        size_t min = j;                                       \
                        size_t k;                                             \
                        for (k = j + 1; k < (count); k++) {                   \
                                if (src[KD__DIM * k + (axis)] <               \
                                        src[KD__DIM * min + (axis)]) {        \
                                        min = k;                              \
                                }                                             \
                        }                                                     \
                        KD__NEW_SWAP(src, j, min);                            \
                }                                                             \
        } while (0)

        if (n == 0) {
                return;
        }

        KD__NEW_SORT(src, n, d%KD__DIM);

        KD__MEMCPY(t, src, sizeof(KD__TYPE_T) * KD__DIM);

        kd__new(t, &src[0x0000000000000], 0+(n/2+0), d+1, 2*i+1);
        kd__new(t, &src[KD__DIM*(n/2+1)], n-(n/2+1), d+1, 2*i+2);

        #undef KD__NEW_SWAP
        #undef KD__NEW_SORT

}

KD__LIB void 
KD__IMPL(_findnn) 
        (KD__TYPE_T* t, size_t n, size_t d, size_t i, 
         KD__TYPE_T q[KD__DIM], size_t* idx, KD__TYPE_F* dmin)
{

        #define KD__AXIS ((d) % KD__DIM)

        #define KD__FINDNN_DIST(n00, n01, n02, n10, n11, n12)                 \
                (((KD__TYPE_F)(n00) - (KD__TYPE_F)(n10)) *                    \
                 ((KD__TYPE_F)(n00) - (KD__TYPE_F)(n10)) +                    \
                 ((KD__TYPE_F)(n01) - (KD__TYPE_F)(n11)) *                    \
                 ((KD__TYPE_F)(n01) - (KD__TYPE_F)(n11)) +                    \
                 ((KD__TYPE_F)(n02) - (KD__TYPE_F)(n12)) *                    \
                 ((KD__TYPE_F)(n02) - (KD__TYPE_F)(n12)))

        KD__TYPE_F dist;

        if (n <= 1) {
                return;
        }

        dist = KD__FINDNN_DIST(
                t[KD__DIM * i + 0], t[KD__DIM * i + 1], t[KD__DIM * i + 2],
                q[0]              , q[1]              , q[2]
        );

        if (dist < *dmin) {
                *idx  = i;
                *dmin = dist;
        }

        if (q[KD__AXIS] < t[KD__DIM * i + KD__AXIS]) {
                kd__findnn(t, n/2, d+1, 2*i + 1, q, idx, dmin);
        } else {
                kd__findnn(t, n/2, d+1, 2*i + 2, q, idx, dmin);
        }

        if (((KD__TYPE_F)q[KD__AXIS] - (KD__TYPE_F)t[KD__DIM * i + KD__AXIS]) * 
            ((KD__TYPE_F)q[KD__AXIS] - (KD__TYPE_F)t[KD__DIM * i + KD__AXIS]) 
            >= *dmin) {
                return;
        }

        if (q[KD__AXIS] < t[KD__DIM * i + KD__AXIS]) {
                kd__findnn(t, n/2, d+1, 2*i + 2, q, idx, dmin);
        } else {
                kd__findnn(t, n/2, d+1, 2*i + 1, q, idx, dmin);
        }

        #undef KD__AXIS
        #undef KD__FINDNN_DIST

}

#undef KD__DIM
#undef KD__TYPE_T
#undef KD__TYPE_F
#undef KD__PREFIX
#undef KD__USE_STATIC
#undef KD__LIB
