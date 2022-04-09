def nota(contribution,URI,COLAB):
    nota = 0
    fator_URI = 1
    fator_COLAB = 1

    if contribution == True:
        nota+=2
    
    if URI == None:
        fator_URI = 0.5
        URI = 1

    if COLAB == None:
        fator_COLAB = 0.5
        COLAB = 1

    nota += 0.4*(URI*fator_COLAB + COLAB*fator_URI)
    return max(nota,1)

print(nota(True,None,None))
print(nota(True,10,None))
print(nota(True,None,10))
print(nota(True,5,10))
print(nota(True,10,10))