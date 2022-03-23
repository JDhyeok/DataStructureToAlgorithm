def sort_by_dict(words):
    for i in range(0, len(words)):
        for j in range(0, len(words) - (1 + i)):
            if words[j].lower() > words[j + 1].lower():
                tmp = words[j]
                words[j] = words[j + 1]
                words[j + 1] = tmp


while True:
    num = int(input())

    if num == 0:
        break

    words, tmp = [], []
    for i in range(num):
        words.append(input())

        sort_by_dict(words)
    
    print(words[0])