#include "RSA.h"

RSA::RSA(int bits) {
    vector<int> random_prime = prime_bits(bits); //genera los primos entre (bits^2)/2 y (bits^2)-1

    //De los primos encontrados asignar aleatoriamente 3 de estos para p, q y e
    //Como srand funciona con el tiempo de la PC se asignaria los mismos valores para p, q y e; para evitar esto
    // a la variable p y q les sumo 123 y 321 al tamaño de el vector prime_bits, consigo un numero random en el intevalo
    // y le saco el modulo para q el valor este entre 0 y el tamaño de prime_bits
    p = random_prime[module(random(123, 123 + random_prime.size()), random_prime.size() - 1)];
    q = random_prime[module(random(321, 321 + random_prime.size()), random_prime.size() - 1)];
    e = random_prime[random(0, random_prime.size() - 1)];

    N = p * q;
    oN = (p-1)*(q-1);
    while (mcd(e, oN) != 1) { //si el mcd(e, oN) != 1, busco otro primo tal que mcd(e, oN) == 1
        e = random_prime[random(0, random_prime.size() - 1)];
    }
    d = inverse(e, oN);
    cout << "El valor de \"p\" es: " << p << endl;
    cout << "El valor de \"q\" es: " << q << endl;
    cout << "El valor de \"e\" es: " << e << endl;
    cout << "El valor de \"d\" es: " << d << endl;
    cout << "El valor de \"N\" es: " << N << endl;
}

RSA::RSA(int a, int b) {
    e = a;
    N = b;
}

void RSA::chiper(string mssg) {
    for (int i = 0; i < mssg.size(); ++i) {
        encrypted_letter.push_back(modular_exponentiation(alfabeto.find(mssg[i]), e, N));
    }
}

void RSA::dechiper(vector<int> letters) {
    for (int i = 0; i < letters.size(); ++i) {
        message.push_back(alfabeto[modular_exponentiation(letters[i], d, N)]);
    }
}

void RSA::show_encryption() {
    cout << endl << "Mensaje cifrado: ";
    for (int i = 0; i < encrypted_letter.size(); ++i) {
        cout << encrypted_letter[i];
    }
}

void RSA::show_decryption() {
    cout << endl << "Mensaje decifrado: "<<message;
}