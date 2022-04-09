import estatistica

data = {16:12, 17:8, 18:7, 19:14, 20:13, 21:6, 22:13, 23:9, 24:6, 25:6, 26:6}

q1 = float(915.9)
q2 = float(969.3)
q3 = float(992.8)
ls = float(1108.2)
li = float(800.5)

print("coeficiente de bowley:\t",estatistica.coef_bowley(q1, q2, q3))
print("assimetria:\t\t", estatistica.assimetria(q1, q2, q3))

print("Quartil:\t\t", estatistica.quartil(estatistica.ordered_data(data), len(estatistica.ordered_data(data)), 0.85))