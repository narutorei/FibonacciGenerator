#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "fibonacci.cpp"

int main() {

    Fibonacci fb;
    int index = 0;

    std::cout << "Digite o termo para ser calculado\n";
    std::cin >> index;

    std::cout << "O número gerado é: " << fb.getNthTerm(index) << '\n';

    return 0;
}