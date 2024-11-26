import sys
input = sys.stdin.readline

if __name__ == '__main__':
    sentence = input()
    ans = 0
    count = 1
    for i in range(0, len(sentence) - 1):
        if sentence[i] == sentence[i+1]:
            count += 1
        else:
            count = 1
        ans = max(ans, count)
    print(ans)

