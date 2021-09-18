def solucao(str):
    count = 0
    led = {1: 2, 2: 5, 3: 5, 4: 4, 5: 5, 6: 6, 7: 3, 8: 7, 9: 6, 0: 6}
    
    for i in str:
       count += led[int(i)]

    print(count, "leds") 


n = int(input())

for i in range(n):
    line = str(input())
    solucao(line)
