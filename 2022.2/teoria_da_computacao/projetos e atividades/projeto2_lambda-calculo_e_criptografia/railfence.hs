{-
  PROJETO 2: λ-CÁLCULO E CRIPTOGRAFIA 
  Implementação do método de ciframento por transposição railfence.

  Discentes: 
      Adrielle A. Carvalho
      Fernando F. L. Neto
      João L. L. Melo
      Thiago V. S. Andrade
-}

import Data.List (sort)

{- 
    Função auxiliar para a criação das trilhas. Recebe um valor inteiro n
    e retorna uma lista circular do formato [0, ..., n, ..., 1].
-}
baseRails :: Int -> [Int]
baseRails n = cycle $ [0 .. n] <> [pred n, pred $ pred n .. 1]

{-  
    Função auxiliar para a criação das trilhas. Recebe uma quantidade de
    trilhas n e uma string message. Chama a função baseRails e retorna uma lista
    de tuplas atribuindo cada caractere de message a uma trilha simulada 
    por baseRails.
-}
assignToRails :: Int -> String -> [(Int, Int)]
assignToRails n message = zip (baseRails n) [0 .. (length message - 1)]

{-  
    Função auxiliar para seleção de caracteres nas trilhas. Recebe como 
    argumentos a quantidade de trilhas n, a string message a ser iterada
    e o índice de uma trilha i. Retorna uma lista de tuplas correspondente
    à todos os caracteres de message atribuídos à trilha de índice i.
    Utiliza baseRails como referência para a correspondência entre caracteres
    de message e trilhas, filtrando as ocorrências em função de i. 
-}
rails :: Int -> String -> Int -> [(Int, Int)]
rails n message i = filter ((== i) . fst) (assignToRails n message)

{-
    Função auxiliar para seleção de caracteres nas trilhas. Recebe como 
    argumentos a quantidade de trilhas n e a string message a ser iterada. 
    Retorna uma lista de tuplas, ordenada pelo primeiro valor de forma 
    crescente, correspondente à todos os caracteres de message atribuídos 
    às trilhas. Invoca rails e concatena as saídas para todas as possíveis 
    trilhas.
-}
orderRails :: Int -> String -> [(Int, Int)]
orderRails n message = concatMap (rails n message) [0 .. n]

{-
    Função auxiliar para seleção de caracteres nas trilhas. Recebe como 
    argumentos a quantidade de trilhas n e a string message a ser iterada. 
    Retorna uma lista de índices dos caracteres de message ordenados 
    crescentemente em função das suas posições nas trilhas. A lista
    corresponde à ordenação dos caracteres de message pós-criptografia. 
    Invoca orderRails para acessar a correspondência entre caracteres de 
    message e as trilhas.
-}
orderLetters :: Int -> String -> [Int]
orderLetters n message = snd <$> orderRails (n-1) message

{-
    Função de criptografia. Aceita como argumentos um valor n de trilhos e uma
    string message a ser criptografada. A função retorna uma string, resultado 
    da operação de criptografia de message. Usa criptList para acessar a lista de 
    índices dos caracteres de message pós-criptografia e utiliza seus valores
    para iterar sobre message, retornando a mensagem criptografada.
-}
encode :: Int -> String -> String
encode n message = (message !!) <$> orderLetters n message

{-
    Função de descriptografia. Aceita como argumentos um valor n de trilhos e 
    uma string message a ser descriptografada. A função  retorna uma string, 
    resultado da operação de descriptografia de message.
-} 
decode :: Int -> String -> String
decode n message = snd <$> sort (zip (orderLetters n message) (message))


{-
    Especificação dos métodos e operadores em haskell

    <>: Operador que une dois valores monoidais (??)
    Input: [1,2,3] <> [4,5,6]
    Output: [1,2,3,4,5,6]

    !!: Usado como referência a um índice de lista.
    Input: [1,2,3] !! 0
    Output: [1]

    <$>: Usado como sinônimo de um fmap. Pode ser entendido como uma flag
    que passa o termo à direita como parâmetro para o termo à esquerda
    Input: show <$> Just 11
    Output: Just "11"

    cycle: Cira uma lista circular a partir de outra
    Input: take 10 (cycle "ABC")
    Output: "ABCABCABCA"

    filter: Retorna uma lista construída a partir de membros de uma lista, 
    dada pelo segundo argumento, em função da condição dada pelo primeiro 
    argumento
    Input: filter (>5) [1,2,3,4,5,6,7,8]
    Output: [6,7,8]

    fst: Seleciona o primeiro elemento de uma dada coleção* de elementos
    Input: fst(1,2)
    Output: 1
    *: Palavra escolhida pela falta de um termo mais apropriado

    pred: Predecessor de um dado valor
    Input: pred 5
    Output: pred 4

    snd: Seleciona o segundo elemento de uma dada coleção* de elementos
    Input: fst(1,2)
    Output: 2
    *: Palavra escolhida pela falta de um termo mais apropriado

    zip: Cria uma lista de tuplas. Cada tupla contém elementos de ambas
    as listas passadas como parâmetro de acordo com as posições dos valores
    Input: zip [1,2,3] [9,8,7]
    Output: zip [(1,9),(2,8),(3,7)]
-}