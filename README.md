# kdtree

This repository provides a straightforward **k-d tree** (k-dimensional tree)
implementation in ANSI C. It allows you to build a static k-d tree from a set
of points and perform nearest-neighbor queries quickly, with minimal
dependencies.


## Features

1. **Single-Header Implementation**  
   The entire library is contained in a single header, **kdtree.h**. Just drop
   it into your project and continue working.

4. **No Dependencies**  
   No external libraries are required (not even the standard library), but
   functions from the standard library can be used if desired.

3. **Simple API**  
   Only two functions are provided as of now to perform nearest neighbor
   searches.

5. **Comprehensive Test Suite**  
   A set of test files is also included.

## Usage

1. **Defining Macros**
   **kdtree.h** relies on a few macros that you define before including it:

   - `KD__TYPE_T` (required): the data type for your points (eg. float, double,
                              unsigned char, etc.)
   - `KD__TYPE_F` (optional): the arithmetic type used for distance
                              calculations. defaults to `float`.
   - `KD__DIM`    (required): the dimensionality of your points.

   - `KD__PREFIX` (optional): use this macro to set the prefix to all
                              functions. By default, the prefix is `kd_`.
                              For example, a function might be called
                              `kd__new`.

   - `KD__USE_STATIC` (optional): If defined, all functions in the library are
                                   declared as `static`.

   - `KD__MEMCPY__OVERRIDE` (optional): If defined, this macro allows you to
                                        override the default memory copy
                                        behavior.

   - `KD__SIZE(d)` (optional): Calculates the total size of a balanced k-d tree
                               given its depth `d`. This is useful in defining
                               your tree size before initializing it.


2. **Creating a kd-tree**
    To do so, the following function is provided:

    ```c
    kd__new( KD__TYPE_T* const t,
             KD__TYPE_T* src,
             size_t      n,
             size_t      d,
             size_t      i );
    ```

    - `t`  : Destination array that will represent the kd-tree
    - `src`: Source array of points of shape `(n, KD__DIM)`
    - `n`  : number of points in `src`
    - `d`  : Current depth. (pass 0 in usage)
    - `i`  : Current index. (pass 0 in usage)

3. After creating the tree `t`, you can pass it to the nearest neigbhor
   function:

    ```c
    kd__findnn( KD__TYPE_T* t,
                size_t      n,
                size_t      d,
                size_t      i,
                KD__TYPE_T  q[KD__DIM],
                size_t*     idx,
                KD__TYPE_F* dmin );
    ```

   - `t`   : The array that holds your k-d tree (built by `kd__new`).
   - `n`   : Number of points in the tree.
   - `d`  : Current depth. (pass 0 in usage)
   - `i`  : Current index. (pass 0 in usage)
   - `q`   : The query point of shape `(KD__DIM)`.
   - `idx` : Output. After the search, *idx will hold the index of the nearest
             neighbor node in t.
   - `dmin`: Output. After the search, *dmin will be the squared distance to
             the nearest neighbor.


## Example

Below is a simplified usage example that builds a 3D tree of unsigned char
points and then queries for the nearest neighbor:

```c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


/* override inbuilt memcpy */
#include <string.h>
#define KD__MEMCPY__OVERRIDE memcpy

#define KD__TYPE_T unsigned char
#define KD__TYPE_F float
#define KD__DIM    3
#include "kdtree.h"

int 
main(void) {

        unsigned char x[] = {
                2, 3, 4,
                9, 6, 2,
                8, 1, 0,
                5, 4, 1,
                7, 2, 0,
                4, 7, 0
        };

        unsigned char q[3] = {9, 1, 0}; /* Query point */

        size_t i, idx = 0;
        float  dmin = (float)INT_MAX;

        /* Depth ~ log2(N). N=6 => safe depth is 4. */
        unsigned char tree[KD__SIZE(4)*3];

        /* Print input points */
        printf("Input points:\n");
        for (i = 0; i < 6; i++) {
                printf("(%u, %u, %u)\n", x[3*i+0], x[3*i+1], x[3*i+2]);
        }

        /* Build the k-d tree */
        kd__new(tree, x, 6, 0, 0);

        /* Print the resulting k-d tree */
        printf("\nKD-tree structure:\n");
        for (i = 0; i < 6; i++) {
                printf("Node %zu: (%u, %u, %u)\n",
                       i, tree[3*i], tree[3*i+1], tree[3*i+2]);
        }

        /* Query for nearest neighbor */
        kd__findnn(tree, 6, 0, 0, q, &idx, &dmin);

        printf("\nQuery: (%u, %u, %u), nearest neighbor: (%u, %u, %u)\n",
               q[0], q[1], q[2],
               tree[3*idx+0], tree[3*idx+1], tree[3*idx+2]);

        return 0;

}
```

## Testing

- `make test` builds all test files under `tests/` into `bin/tests/`.
- `make run-tests` runs each test automatically.
