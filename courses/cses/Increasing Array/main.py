import sys
input = sys.stdin.readline

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))  # Convert map object to list
    moves = 0
    
    # Compare each element with previous one
    for i in range(1, n):
        if arr[i] < arr[i-1]:
            # Calculate moves needed to make current element equal to previous
            diff = arr[i-1] - arr[i]
            moves += diff
            arr[i] = arr[i-1]  # Update the current element
    
    print(moves)