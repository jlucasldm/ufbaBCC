{-
  PROJETO 2: λ-CÁLCULO E CRIPTOGRAFIA 
  Implementação do método de ciframento por substituição vigenère.

  Discentes: 
      Adrielle A. Carvalho
      Fernando F. L. Neto
      João L. L. Melo
      Thiago V. S. Andrade
-}

import Data.Char (chr, ord)

{-
    Função de cifragem dos caracteres. Recebe como argumentos um operador (referente
    à criptografia ou descriptografia), um caractere chave e um caractere da 
    mensagem a ser consultado na tabela em função da chave. A função computa
    uma consulta à tabela de cifragem e retorna o caractere da mensagem após
    a criptografia ou descriptografia.
-}
cipher :: (Int -> Int -> Int) -> Char -> Char -> Char
cipher operator offset ch = numToChar $ (charToNum ch) `operator` (charToNum offset)
  where
    charToNum ch = ord ch - ord 'A'
    numToChar n = chr $ (n `mod` 26) + ord 'A'

{-
    Função de criptografia. Recebe duas strings como argumento, uma chave
    e a mensagem em texto claro. Invoca a função cipher para operar 
    sobre os caracteres da mensagem, obter a sequência de caracteres 
    criptografados e retornar a mensagem após a criptografia. Retorna a 
    mensagem criptografada.
-}
encode :: String -> String -> String
encode message = zipWith (cipher (+)) (concat (words (cycle message)))

{-
    Função de descriptografia. Recebe duas strings como argumento, uma chave
    e a mensagem em texto claro. Invoca a função cipher para operar sobre
    os caracteres da mensagem, obter a sequência de caracteres 
    descriptografados e retornar a mensagem após a descriptografia. Retorna 
    a mensagem descriptografada.
-}
decode :: String -> String -> String
decode message = zipWith (cipher (-)) (concat (words (cycle message)))

{-

    Especificação dos métodos e operadores em haskell

    concat: Método para concatenar uma lista de listas
    Input: concat [[1,2,3], [1,2,3]]
    Output: [1,2,3,1,2,3]

    cycle: Cira uma lista circular a partir de outra
    Input: take 10 (cycle "ABC")
    Output: "ABCABCABCA"

    words: Método para criação de uma lista de strings a partir de uma 
    string onde espaços em branco são usados como separadores.
    Input: words "aa bb cc \t dd \n ee"
    Output: ["aa","bb","cc","dd","ee"]

    zipWith: Cria uma lista cujos elementos são calculados pela função 
    passada como primeiro argumento, iterando sobre elementos de mesmo 
    índice de cada lista passada como os demais argumentos.
    Input: zipWith (+) [1,2,3] [3,2,1]
    Output: [4,4,4]

-}