# https://www.hackerrank.com/challenges/queries-with-fixed-length/problem

#!/bin/python3

import math
import os
import random
import re
import sys
from collections import deque

#
# Complete the 'solve' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY arr
#  2. INTEGER_ARRAY queries
#

def build_max_d_array(arr, d):
    max_d = []
    q = deque()
    for i in range(0, len(arr)):
        while q and arr[q[-1]] < arr[i]:
            q.pop()
        if q and q[0] < i - d + 1:
            q.popleft()
        q.append(i)
        if i>= d - 1:
            max_d.append(arr[q[0]])
    return max_d
            


def solve(arr, queries):
    # Write your code here
    seen = {} 
    ans = []
    for d in queries:
        if d in seen:
            ans.append(seen[d])
        else:
            max_d = build_max_d_array(arr, d)
            min_value = min(max_d)
            ans.append(min_value)
            seen[d] = min_value
    return ans


if __name__ == '__main__':
    # run locally with `input.txt` next to this file; HackerRank still works via stdin
    local_input = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'input.txt')
    if 'OUTPUT_PATH' not in os.environ and os.path.exists(local_input):
        sys.stdin = open(local_input, 'r')


    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    q = int(first_multiple_input[1])

    arr = list(map(int, input().rstrip().split()))

    queries = []
    
    for _ in range(q):
        queries_item = int(input().strip())
        queries.append(queries_item)

    result = solve(arr, queries)
    
    print(result)

