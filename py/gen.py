#!/usr/bin/env python3
import textwrap
import math

PREFIX = textwrap.dedent(r"""
#include <limits.h>

#ifdef USE_STDIO
#include <stdio.h>
#define LOG(args)                                                            \\
do {{                                                                        \\
        (printf("[LOG] %s:%d ", __FILE__, __LINE__), printf args);           \\
}} while (0)
#else
#define LOG(args) do {{}} while(0)
#endif

#include "minunit.h"
int tests_run = 0;

#define TYPE_T {PYTHON_TYPE_T}
#define TYPE_F {PYTHON_TYPE_F}
#define DIM    {PYTHON_DIM}

#define KD__TYPE_T TYPE_T
#define KD__TYPE_F TYPE_F
#define KD__DIM DIM
#include "../kdtree.h"
""")

TEMPLATE = textwrap.dedent(r"""
/* ------------------------------------------------------------------------- */
/* Generated Test for case {CASE_INDEX}, subcase {SUBCASE_INDEX}             */
/* ------------------------------------------------------------------------- */

static char*
{PYTHON_TEST_NAME}(void)
{{
        do {{ /* case: 0*/

                #define N {PYTHON_N}

                TYPE_T x[DIM * N] = {{
                        {PYTHON_TEST_ARRAY}
                }};

                TYPE_T tree[DIM * KD__SIZE(4)] = {{0}};

                kd__new(tree, x, N, 0, 0);

                do {{ /* case {CASE_INDEX}:{SUBCASE_INDEX} */

                        TYPE_T ans[DIM * N] = {{
                                {PYTHON_KD_TREE}
                        }};

                        size_t i;
                        for (i = 0; i < DIM * N; i++) {{
                                mu_assert("case {CASE_INDEX}:{SUBCASE_INDEX} : tree != ans",
                                          tree[i] == ans[i]);
                        }}

                }} while(0);

                do {{ /* case {CASE_INDEX}:{SUBCASE_INDEX} */

                        TYPE_T q[3] = {{ {PYTHON_QUERY} }};
                        TYPE_T nn[3] = {{ {PYTHON_NEAREST_NEIGHBOR} }};

                        size_t idx  = 0;
                        float  dmin = (float)INT_MAX;

                        kd__findnn(tree, N, 0, 0, q, &idx, &dmin);

                        mu_assert("case {CASE_INDEX}:{SUBCASE_INDEX} : nn[0] != ans[0]",
                                  tree[3*idx+0] == nn[0]);
                        mu_assert("case {CASE_INDEX}:{SUBCASE_INDEX} : nn[1] != ans[1]",
                                  tree[3*idx+1] == nn[1]);
                        mu_assert("case {CASE_INDEX}:{SUBCASE_INDEX} : nn[2] != ans[2]",
                                  tree[3*idx+2] == nn[2]);

                }} while(0);

                #undef N

        }} while(0);

        return 0;
}}

static char*
all_tests_{CASE_INDEX}_{SUBCASE_INDEX}(void)
{{
        mu_run_test({PYTHON_TEST_NAME});
        return 0;
}}
""")

def generate_test_snippet(params):
    """
    Generate a test snippet from a dictionary of parameters.
    """
    case_index        = params["case_index"]
    subcase_index     = params["subcase_index"]
    n                 = params["n"]
    test_array        = params["test_array"]
    kd_tree           = params["kd_tree"]
    query             = params["query"]
    nearest_neighbor  = params["nearest_neighbor"]

    test_name         = f"test_case_{case_index}_sub_{subcase_index}"

    snippet = TEMPLATE.format(
        CASE_INDEX               = case_index,
        SUBCASE_INDEX            = subcase_index,
        PYTHON_TEST_NAME         = test_name,
        PYTHON_N                 = n,
        PYTHON_TEST_ARRAY        = ", ".join(map(str, test_array)),
        PYTHON_KD_TREE           = ", ".join(map(str, kd_tree)),
        PYTHON_QUERY             = ", ".join(map(str, query)),
        PYTHON_NEAREST_NEIGHBOR  = ", ".join(map(str, nearest_neighbor)),
    )
    return snippet

class KDTreeNode:
    def __init__(self, point, left=None, right=None):
        self.point = point
        self.left = left
        self.right = right

def recursive_build_kd_tree(points, dim=3, depth=0):
    """
    Recursively build a KD-tree from a list of points, given a dimension dim.
    """
    if not points:
        return None
    axis = depth % dim
    points.sort(key=lambda point: point[axis])
    median = len(points) // 2

    return KDTreeNode(
        point=points[median],
        left=recursive_build_kd_tree(points[:median], dim, depth + 1),
        right=recursive_build_kd_tree(points[median + 1:], dim, depth + 1)
    )

def build_kd_tree(points, dim=3):
    """
    Build a KD-tree and flatten it into an array for verification.
    """
    kdtree = recursive_build_kd_tree(points, dim=dim)
    arr = []

    def fill_array(node, index):
        while len(arr) <= index:
            arr.append(None)

        if node:
            arr[index] = list(node.point)
            fill_array(node.left,  2*index + 1)
            fill_array(node.right, 2*index + 2)

    fill_array(kdtree, 0)
    while arr and arr[-1] is None: arr.pop()
    arr = [val for sublist in arr for val in sublist]
    return arr

def euclidean_distance(p1, p2, dim=3):
    """
    Compute the Euclidean distance between p1 and p2 in 'dim' dimensions.
    """
    return math.sqrt(sum((p1[i] - p2[i]) ** 2 for i in range(dim)))

def find_nearest_neighbor(points, query, dim=3):
    """
    Find the nearest neighbor to 'query' among all 'points', using 'dim' dimensions.
    """
    best = None
    best_dist = float('inf')
    for p in points:
        dist = euclidean_distance(p, query, dim=dim)
        if dist < best_dist:
            best_dist = dist
            best = p
    return best

def generate_case(case_index, points, queries, dim=3):
    """
    Generate test parameters for a single 'case_index' with multiple 'queries'.
    """
    # Flatten 'points'
    flat_points = []
    for p in points:
        flat_points.extend(p)

    # Build KD-tree and flatten
    kd_tree_arr = build_kd_tree(points, dim=dim)

    param_list = []
    for idx, q in enumerate(queries):
        nn = find_nearest_neighbor(points, q, dim=dim)
        subcase_index = idx + 1

        param_list.append({
            "case_index": case_index,
            "subcase_index": subcase_index,
            "n": len(points),
            "test_array": flat_points,
            "kd_tree": kd_tree_arr,
            "query": q,
            "nearest_neighbor": nn,
        })

    return param_list

def generate_file(fname, param_list, md):
    """
    Generate a C file with test cases and save it to a file.

    Parameters:
        fname (str): The name of the file to save the output.
        param_list (list): A list of parameter dictionaries for generating test cases.
        md (dict): A dictionary containing metadata like type_t, type_f, dim.
    """
    type_t = md.get("type_t", "unsigned char")
    type_f = md.get("type_f", "float")
    dim    = md.get("dim", 3)

    output = [PREFIX.format(
        PYTHON_TYPE_T=type_t,
        PYTHON_TYPE_F=type_f,
        PYTHON_DIM=dim,
    )]

    for params in param_list:
        snippet = generate_test_snippet(params)
        output.append(snippet)

    test_invocations = []
    for params in param_list:
        i = params["case_index"]
        j = params["subcase_index"]
        test_invocations.append(f"    all_tests_{i}_{j}();")

    aggregator = textwrap.dedent(f"""
    /* ------------------------------------------------------------------------- */
    /* Final aggregator of all tests.                                            */
    /* ------------------------------------------------------------------------- */
    static char* all_tests(void) {{
            {chr(10).join(test_invocations)}
            return 0;
    }}

    int main(void) {{
            char* result = all_tests();
            if (result) {{
                    printf("[{fname}]:\tERROR: %s\\n", result);
            }} else {{
                    printf("[{fname}]:\tALL TESTS PASSED\\n");
            }}
            return result != 0;
    }}
    """)

    output.append(aggregator)

    with open(fname, 'w') as f:
        f.write("\n".join(output))

    print(f"File '{fname}' generated successfully.")

def main():

    if 1:

        md = {
            "type_t": "double",
            "type_f": "float",
            "dim": 3
        }
        plist = []

        points  = [(2, 3, 4), (9, 6, 2), (8, 1, 0), (5, 4, 1), (7, 2, 0), (4, 7, 0)]
        queries = [(9, 1, 0), (0, 0, 0), (6, 3, 1)]
        plist  += generate_case(case_index=0, points=points, queries=queries, dim=3)

        points  = [(10, 20, 30), (0, 0, 1), (2, 255, 3), (17, 99, 65), (45, 12, 200), (255, 255, 255)]
        queries = [(255, 0, 255), (1, 20, 3), (50, 100, 200)]
        plist  += generate_case(case_index=1, points=points, queries=queries, dim=3)

        points  = [(100, 100, 100), (99, 98, 2), (30, 29, 28), (15, 15, 15), (1, 250, 10), (254, 253, 252)]
        queries = [(254, 0, 1), (2, 98, 28), (100, 100, 101)]
        plist  += generate_case(case_index=2, points=points, queries=queries, dim=3)

        points  = [(50, 40, 30), (0, 39, 80), (120, 255, 90), (4, 7, 10), (25, 250, 249), (130, 130, 130)]
        queries = [(255, 255, 254), (50, 41, 29), (129, 130, 130)]
        plist  += generate_case(case_index=3, points=points, queries=queries, dim=3)

        points  = [(80, 1, 2), (9, 6, 2), (254, 10, 255), (5, 4, 1), (7, 2, 250), (200, 10, 10)]
        queries = [(8, 1, 2), (200, 11, 10), (255, 10, 254)]
        plist  += generate_case(case_index=4, points=points, queries=queries, dim=3)

        points  = [(25, 0, 255), (30, 30, 30), (24, 88, 99), (10, 14, 200), (70, 2, 5), (199, 7, 7)]
        queries = [(25, 1, 255), (70, 3, 5), (24, 88, 100)]
        plist  += generate_case(case_index=5, points=points, queries=queries, dim=3)

        generate_file("tests/test_t-uchar_f-float_d-3.c", plist, md)

    if 1:
        md = {
            "type_t": "double",
            "type_f": "float",
            "dim": 3
        }

        plist = []

        # Case 0
        points_0 = [
            (1.0, 2.0, 3.0),
            (4.5, 6.1, 2.5),
            (8.2, 1.1, 0.0),
            (5.0, 4.0, 1.5),
            (7.3, 2.4, 0.8),
            (4.0, 7.9, 0.3)
        ]
        queries_0 = [
            (9.2, 1.0, 0.0),
            (0.0, 0.0, 0.0),
            (6.1, 3.3, 1.3)
        ]
        plist += generate_case(case_index=0, points=points_0, queries=queries_0, dim=3)

        # Case 1
        points_1 = [
            (10.5, 20.0, 30.0),
            (0.0, 0.1, 1.2),
            (2.0, 25.5, 3.4),
            (17.7, 99.9, 65.1),
            (45.2, 12.0, 200.5),
            (255.0, 255.0, 255.0)
        ]
        queries_1 = [
            (255.0, 0.0, 255.0),
            (1.1, 20.0, 3.0),
            (50.0, 100.0, 200.0)
        ]
        plist += generate_case(case_index=1, points=points_1, queries=queries_1, dim=3)

        # Case 2
        points_2 = [
            (100.0, 100.0, 100.0),
            (99.9, 98.7, 2.0),
            (30.5, 29.9, 28.1),
            (15.0, 15.0, 15.0),
            (1.2, 250.4, 10.3),
            (254.1, 253.2, 252.8)
        ]
        queries_2 = [
            (254.0, 0.0, 1.0),
            (2.0, 98.0, 28.0),
            (100.1, 100.1, 101.0)
        ]
        plist += generate_case(case_index=2, points=points_2, queries=queries_2, dim=3)

        # Case 3
        points_3 = [
            (50.0, 40.2, 30.1),
            (0.5, 39.0, 80.9),
            (120.7, 255.0, 90.4),
            (4.7, 7.8, 10.6),
            (25.9, 250.2, 249.9),
            (130.0, 130.5, 130.9)
        ]
        queries_3 = [
            (255.0, 255.0, 254.0),
            (50.2, 41.0, 29.6),
            (129.9, 130.0, 130.0)
        ]
        plist += generate_case(case_index=3, points=points_3, queries=queries_3, dim=3)

        # Case 4
        points_4 = [
            (0.1, 0.2, 0.3),
            (5.5, 4.1, 1.9),
            (254.2, 10.9, 255.1),
            (7.0, 2.5, 250.3),
            (200.0, 10.4, 10.7),
            (1.2, 9.9, 6.2)
        ]
        queries_4 = [
            (8.2, 1.1, 2.2),
            (200.1, 11.0, 10.0),
            (255.0, 10.0, 254.0)
        ]
        plist += generate_case(case_index=4, points=points_4, queries=queries_4, dim=3)

        generate_file("tests/test_t-f64_f-f64_d-3.c", plist, md)

if __name__ == "__main__":
    main()
