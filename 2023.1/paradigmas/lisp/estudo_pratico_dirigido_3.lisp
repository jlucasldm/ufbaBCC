;Docente: Joao Lucas Lima de Melo

;Questao 1 - Fatorial
(defun fatorial-controle ()
  (let ((n (read)))
    (cond ((not (integerp n)) (format t "O numero deve ser inteiro.~%"))
          ((<= n 0) (format t "O numero deve ser maior do que zero.~%"))
          (t (format t "O fatorial de ~a e ~a.~%" n (fatorial n))))))

(defun fatorial (n)
  (if (<= n 1)
      1
      (* n (fatorial (- n 1)))))

(fatorial-controle)


;Questao 2 - Palindromo
(defun palindromo-controle (str)
  (let ((str-normalizada (normalizar-str str)))
    (if (palindromo str-normalizada)
        (format t "~a e um palindromo.~%" str)
        (format t "~a nao e um palindromo.~%" str))))

(defun normalizar-str (str)
  (let ((letras (remove-if-not #'alpha-char-p (coerce str 'list))))
    (coerce (mapcar #'char-downcase letras) 'string)))

(defun palindromo (str)
  (let ((tamanho (length str)))
    (loop for i from 0 below (/ tamanho 2)
          never (not (char= (char str i)
                            (char str (- tamanho i 1)))))))

(palindromo-controle "Ana")
(palindromo-controle "The end is here")


;Questao 3 - Fibonacci
(defun fibonacci (n)
  (cond ((<= n 0) 0)
        ((= n 1) 1)
        (t (+ (fibonacci (- n 1)) (fibonacci (- n 2))))))

(defun fibonacci-controle ()
  (format t "Informe o numero do elemento da sequencia de Fibonacci desejado: ")
  (let ((n (read)))
    (format t "O ~a elemento da sequencia de Fibonacci e: ~a"
            n (fibonacci n))))

(fibonacci-controle)


;Questao 4 - Lista Ordenada
(defun lista-ordenada (lista)
  (cond ((null lista) t)
        ((null (cdr lista)) t)
        ((<= (car lista) (cadr lista))
         (lista-ordenada (cdr lista)))
        (t nil)))

(print (lista-ordenada '(1 5 6 7 9)))
(print (lista-ordenada '(1 5 3 7 9)))
