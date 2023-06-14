# Implementação do Jogo Polícia e Ladrão em Grafos
## Feito por: Kaio Rodrigo, João Lucas, Thiago Andrade.


Esse trabalho foi realizado como atividade proposta da matéria Teoria dos Grafos em 2022.2 para aprofudar o conhecimento sobre Grafos. Como nossa atividade, escolhemos estudar sobre o jogo "Cops and Robbers" jogado num grafo finito, reflexivo e sem direção. 
Usamos o teorema 2.1 presente no arquivo "cops-and-robbers.pdf" desse repositório para categorizar um grafo como Cop-Win ou Robbers-Win utilizando propriedades como vizinhança. Utilizamos python para implementar a checagem desse teorema.

## Como usar

- Formate uma entrada da seguinte forma: uma linha com os vértices representados em números separados por espaços, e outra linha com as arestas representados em dois vértices entre uma vírgula separados por espaços.
- Use um interpretador python (testado na ver. 3.10.6) para interpretar o arquivo "copWin.py" e passe a entrada.

### Exemplo:

entrada (K3):
```
0 1 2
0,0 0,1 0,2 1,1 1,2 2,2
```
Num terminal Unix
```sh
python3 copWin.py < entrada
```

## Considerações

Este repositório ainda mantém uma alternativa de força bruta (bruteForce.py) para fins de teste e comparações.
