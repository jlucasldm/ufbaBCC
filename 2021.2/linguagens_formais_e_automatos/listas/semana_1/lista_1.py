#questao 1
#visualizazao
A = set(n for n in range(9))
B = set(n for n in range(-5,6))
print("A:", A)
print("B:", B)

#a
E = A.intersection(B)
print("E:", E)

#b
a_union_b = A.union(B)
C = set()

for x in a_union_b:
  if (x % 2) == 0:
    C.add(x)

print("C:", C)

#c
a_difference_b = A.difference(B)
b_difference_a = B.difference(A)

D = a_difference_b.union(b_difference_a)

print("D", D)

#d
a_inter_c = A.intersection(C)
a_inter_d = A.intersection(D)

first_dif = a_inter_c.difference(a_inter_d)
second_dif = a_inter_d.difference(a_inter_c)

res = dict()

#print("first difference:", first_dif)
#print("second difference:", second_dif)

for i in first_dif:
  for j in second_dif:
    res.update({i:j})

print("[(A∩C)−(A∩D)]×[(A∩D)−(A∩C)]:",res)


#questao 2
#a
"""
**Passo para n = 0 pertencente aos naturais:**
$$ \sum_{i=0}^0 i = \frac{0(0+1)}{2} $$

Temos:
$$ \sum_{i=0}^0 i = 0$$

$$ \frac{0(0+1)}{2} = \frac{1}{2} = 0$$

Portanto, vale

.

**Passo para n+1:**

*Hipótese:*
$$ \sum_{i=0}^n i = \frac{n(n+1)}{2}$$
*Tese:*
$$ \sum_{i=0}^{n+1} i = \frac{(n+1)(n+2)}{2}$$


Temos:
$$ \sum_{i=0}^{n+1} i = \sum_{i=0}^{n} i + (n+1)$$

$$ \sum_{i=0}^{n+1} i = \frac{n(n+1)}{2} + (n+1)$$

$$\frac{n(n+1)}{2} + (n+1) = \frac{n(n+1)}{2} + \frac{2(n+1)}{2}$$

$$\frac{n(n+1)}{2} + \frac{2(n+1)}{2} = \frac{(n+1)(n+2)}{2}$$

Portanto, vale a tese.
"""
soma = 0
expressao = 0

for x in range(100):
  #resultado do somatório
  soma += x

  #resultado expressao n(n+1)/2
  expressao = x*(x+1)/2

  print("Somatorio:\t",soma)
  print("Expressao:\t",expressao)
  print("\n")

#b
"""
**Passo para n = 0 pertencente aos naturais:**
$$ \sum_{i=0}^0 i^3 = \big( \sum_{i=0}^0 i \big)^2 $$
Temos:
$$\sum_{i=0}^0 i^3 = 0*0*0 = 0$$
$$\big( \sum_{i=0}^0 i \big)^2 = 0^2 = 0$$

Portanto, vale

.
**Passo para n+1:**

*Hipótese:*
$$ \sum_{i=0}^n i^3 = \big( \sum_{i=0}^n i \big)^2 $$

*Tese:*
$$ \sum_{i=0}^{n +1} i^3 = \big( \sum_{i=0}^{n + 1} i \big)^2 $$

Temos:
$$\sum_{i=0}^{n +1} i^3 = \sum_{i=0}^{n} i^3 + (n+1)^3$$
$$\sum_{i=0}^{n} i^3 + (n+1)^3 = \big( \sum_{i=0}^n i \big)^2 + (n+1)^3$$
"""
soma = 0
expressao = 0

for x in range(100):
  #resultado do somatório
  soma += x*x*x

  #resultado expressao n(n+1)/2
  expressao += x

  print("Somatorio:\t",soma)
  print("Expressao:\t",expressao**2)
  print("\n")