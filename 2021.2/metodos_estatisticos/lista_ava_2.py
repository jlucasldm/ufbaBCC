import math

data = {16:12, 17:8, 18:7, 19:14, 20:13, 21:6, 22:13, 23:9, 24:6, 25:6, 26:6}   #grafico {idade: frequencia}
ordered_data = []

frequencia_total = 0
media = 0
mediana = 0
variancia = 0
desvio_padrao = 0

for i in data:
    for j in range(data[i]):
        ordered_data.append(i)
print(ordered_data)

mediana = ordered_data[int(math.floor(len(ordered_data)/2)) - 1]
print("Mediana:\t\t", mediana)

for i in data:
    frequencia_total += data[i]
print("Frequencia Total:\t", frequencia_total)

for i in data:
    media += i * data[i]
media /= frequencia_total
print("Media:\t\t\t", media)

for i in data:
    variancia += data[i] * ((i - media)**2)
variancia /= frequencia_total
print("Variancia:\t\t", variancia)

desvio_padrao = math.sqrt(variancia)
print("Desvio Padrao:\t\t", desvio_padrao)
