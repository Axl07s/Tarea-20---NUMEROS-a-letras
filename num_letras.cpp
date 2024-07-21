// Autor: Axel Molineros
// Fecha: 2024-07-21
// 1) Utilice el programa de conversión de NUMEROS a LETRAS realizado en clases y complete hasta el número 999.999.

#include<iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const string unidades[]={"cero", "uno","dos","tres","cuatro","cinco","seis",
"siete", "ocho", "nueve","diez","once","doce","trece","catorce","quince",
"dieciseis","diecisiete","dieciocho","diecinueve"};

const string decenas[]={"","diez","veinte","treinta","cuarenta","cincuenta",
"sesenta","setenta","ochenta","noventa"};

const string centenas []={"","ciento","doscientos","trescientos","cuatrocientos","quinientos","seiscientos","setecientos","ochocientos","novecientos"};

// Devuelve las unidades del array de strings
string GetUnidades(int num) {
    return unidades[num];
}

// Devuelve las decenas del array de strings
string GetDecenas(int num) {
    int x = num / 10;
    int resto = num % 10;
    if (num < 20)
        return GetUnidades(num);
    else
        return decenas[x] + (resto > 0 ? " y " + GetUnidades(resto) : "");
}

// Devuelve las centenas del array de strings
string GetCentenas(int num) {
    int x = num / 100;
    int resto = num % 100;
    if (num < 100)
        return GetDecenas(num);
    if (num == 100)
        return "cien";
    return centenas[x] + (resto > 0 ? " " + GetDecenas(resto) : "");
}

// Devuelve los miles del array de strings
string GetMiles(int num) {
    int x = num / 1000;
    int resto = num % 1000;
    if (num < 1000)
        return GetCentenas(num);
    if (x == 1)
        return "mil" + (resto > 0 ? " " + GetCentenas(resto) : "");
    return GetCentenas(x) + " mil" + (resto > 0 ? " " + GetCentenas(resto) : "");
}

// Devuelve los millones del array de strings
string GetMillones(int num) {
    int x = num / 1000000;
    int resto = num % 1000000;
    if (num < 1000000)
        return GetMiles(num);
    if (x == 1)
        return "un millón" + (resto > 0 ? " " + GetMiles(resto) : "");
    return GetUnidades(x) + " millones" + (resto > 0 ? " " + GetMiles(resto) : "");
}

// 2) En el mismo programa, diseñe una función que genere 100 números aleatorios comprendidos entre 1 y 999.999. LA función debe imprimir el valor numérico y su equivalente en letras.2) En el mismo programa, diseñe una función que genere 100 números aleatorios comprendidos entre 1 y 999.999.
// La función debe imprimir el valor numérico y su equivalente en letras.


// Genera y muestra 100 números aleatorios entre 1 y 999,999 con su equivalente en letras
void GenerarNumerosAleatorios() {
    srand(time(NULL)); // Inicializar la semilla del generador de números aleatorios

    for (int i = 0; i < 100; i++) {
        int num = rand() % 999999 + 1; // Generar un número aleatorio entre 1 y 999999
        string resultado = GetMillones(num);
        cout << num << " en letras es " << resultado << endl;
    }
}

int main() {
    // Llama a la función para generar y mostrar los números aleatorios y sus equivalentes en letras
    GenerarNumerosAleatorios();
    return 0;
}