import estatistica

data = {16:12, 17:8, 18:7, 19:14, 20:13, 21:6, 22:13, 23:9, 24:6, 25:6, 26:6}   #grafico {idade: frequencia}

ordered_data = estatistica.ordered_data(data)
mediana = estatistica.mediana(ordered_data)
frequencia_total = estatistica.frequencia_total(data)
media = estatistica.media(frequencia_total, data)
variancia = estatistica.variancia(frequencia_total, media, data)
desvio_padrao = estatistica.desvio_padrao(variancia)

print("Valores ordenados:\n", ordered_data)
print("Mediana:\t\t", mediana)
print("Frequencia Total:\t", frequencia_total)
print("Media:\t\t\t", media)
print("Variancia:\t\t", variancia)
print("Desvio Padrao:\t\t", desvio_padrao)