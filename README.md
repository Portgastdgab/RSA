Algoritmo RSA

NAIVE-RSA-KEY-GENERATOR()

  1. Generar dos primos p y q, tal que p 6= q
      
      La generacion de primos se realiza en el constructor del objeto (RSA::RSA(int bits)), donde recibe un numero de bits y el numero que genereara se encuentra entre ese rango. Este se encuentra desde la linea 3 hasta la linea 25 en el archivo "RSA.cpp".
    
  2. n = p · q
      
      Este paso se realiza en la linea 14 del archivo "RSA.cpp".
      
  3. φ(n) = (p − 1)(q − 1)
  
      Este paso se realiza en la linea 15 del archivo "RSA.cpp".
  
  4. Generar aleatoriamente e ∈ [2, n − 1], tal que gcd(e, φ(n)) = 1
  
      Este paso se realiza desde la linea 16 hasta la linea 18 en el archivo "RSA.cpp".
  
  5. d = INVERSE(e, φ(n))
    
      Este paso se realiza en la linea 19 del archivo "RSA.cpp".
      
  6. return {n, e, d}
    
    * Cifrar usando P(m) = m^e mod n = c.
    
      Este paso lo realiza la funcion cipher(string), desde la linea 32 hasta la linea 36 del archivo "RSA.cpp".
      
    * Descifrar usando S(c) = c^d mod n = m.
    
      Este paso lo realiza la funcion decipher(vector<int>), desde la linea 38 hasta la linea 42 del archivo "RSA.cpp"
