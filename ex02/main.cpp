#include "Fixed.hpp"
#include <iostream>

int main(void)
{
    std::cout << "=== TESTE 1: Main do PDF ===" << std::endl;
    {
        Fixed a;
        Fixed const b(Fixed(5.05f) * Fixed(2));
        
        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max(a, b) << std::endl;
    }
    
    std::cout << "\n=== TESTE 2: Operadores de Comparação ===" << std::endl;
    {
        Fixed a(10);
        Fixed b(20);
        Fixed c(10);
        
        std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
        std::cout << "a > b: " << (a > b) << std::endl;
        std::cout << "a < b: " << (a < b) << std::endl;
        std::cout << "a >= c: " << (a >= c) << std::endl;
        std::cout << "a <= c: " << (a <= c) << std::endl;
        std::cout << "a == c: " << (a == c) << std::endl;
        std::cout << "a != b: " << (a != b) << std::endl;
    }
    
    std::cout << "\n=== TESTE 3: Operadores Aritméticos ===" << std::endl;
    {
        Fixed a(10);
        Fixed b(3);
        
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "a + b = " << (a + b) << std::endl;
        std::cout << "a - b = " << (a - b) << std::endl;
        std::cout << "a * b = " << (a * b) << std::endl;
        std::cout << "a / b = " << (a / b) << std::endl;
    }
    
    std::cout << "\n=== TESTE 4: Incremento/Decremento ===" << std::endl;
    {
        Fixed a(5);
        
        std::cout << "a inicial = " << a << std::endl;
        std::cout << "++a = " << ++a << std::endl;
        std::cout << "a agora = " << a << std::endl;
        std::cout << "a++ = " << a++ << std::endl;
        std::cout << "a agora = " << a << std::endl;
        std::cout << "--a = " << --a << std::endl;
        std::cout << "a agora = " << a << std::endl;
        std::cout << "a-- = " << a-- << std::endl;
        std::cout << "a final = " << a << std::endl;
    }
    
    std::cout << "\n=== TESTE 5: Min/Max ===" << std::endl;
    {
        Fixed a(10.5f);
        Fixed b(20.7f);
        
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
        std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;
        
        // Teste com const
        Fixed const c(15.3f);
        Fixed const d(5.1f);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min(c, d) = " << Fixed::min(c, d) << std::endl;
        std::cout << "max(c, d) = " << Fixed::max(c, d) << std::endl;
    }
    
    std::cout << "\n=== TESTE 6: Operações Complexas ===" << std::endl;
    {
        Fixed a(42.42f);
        Fixed b(10);
        Fixed c(2.5f);
        
        std::cout << "a = " << a << std::endl;
        std::cout << "b = " << b << std::endl;
        std::cout << "c = " << c << std::endl;
        std::cout << "(a + b) * c = " << ((a + b) * c) << std::endl;
        std::cout << "a / b + c = " << (a / b + c) << std::endl;
    }
    
    return 0;
}