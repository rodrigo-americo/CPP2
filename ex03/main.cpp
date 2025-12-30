#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

void testCase(std::string description, Point const a, Point const b, Point const c, Point const point, bool expected) {
    bool result = bsp(a, b, c, point);
    std::string status = (result == expected) ? "✓ PASS" : "✗ FAIL";
    
    std::cout << status << " - " << description << std::endl;
    std::cout << "  Resultado: " << (result ? "DENTRO" : "FORA") << std::endl;
    std::cout << "  Esperado:  " << (expected ? "DENTRO" : "FORA") << std::endl;
    std::cout << std::endl;
}

int main(void)
{
    std::cout << "=== TESTES BSP - Point in Triangle ===" << std::endl;
    std::cout << std::endl;
    
    // Triângulo de referência: (0,0), (10,0), (5,10)
    Point a(Fixed(0), Fixed(0));
    Point b(Fixed(10), Fixed(0));
    Point c(Fixed(5), Fixed(10));
    
    std::cout << "Triângulo: A(0,0), B(10,0), C(5,10)" << std::endl;
    std::cout << "===========================================" << std::endl;
    std::cout << std::endl;
    
    // TESTE 1: Ponto claramente dentro
    std::cout << "--- TESTE 1: Ponto claramente dentro ---" << std::endl;
    Point p1(Fixed(5), Fixed(5));
    testCase("Ponto (5,5) - centro do triângulo", a, b, c, p1, true);
    
    // TESTE 2: Ponto claramente fora
    std::cout << "--- TESTE 2: Pontos fora do triângulo ---" << std::endl;
    Point p2(Fixed(15), Fixed(5));
    testCase("Ponto (15,5) - fora à direita", a, b, c, p2, false);
    
    Point p3(Fixed(-5), Fixed(5));
    testCase("Ponto (-5,5) - fora à esquerda", a, b, c, p3, false);
    
    Point p4(Fixed(5), Fixed(15));
    testCase("Ponto (5,15) - fora acima", a, b, c, p4, false);
    
    Point p5(Fixed(5), Fixed(-5));
    testCase("Ponto (5,-5) - fora abaixo", a, b, c, p5, false);
    
    // TESTE 3: Ponto nos vértices (deve retornar false)
    std::cout << "--- TESTE 3: Pontos nos vértices (FALSE) ---" << std::endl;
    Point p6(Fixed(0), Fixed(0));
    testCase("Ponto (0,0) - vértice A", a, b, c, p6, false);
    
    Point p7(Fixed(10), Fixed(0));
    testCase("Ponto (10,0) - vértice B", a, b, c, p7, false);
    
    Point p8(Fixed(5), Fixed(10));
    testCase("Ponto (5,10) - vértice C", a, b, c, p8, false);
    
    // TESTE 4: Ponto nas arestas (deve retornar false)
    std::cout << "--- TESTE 4: Pontos nas arestas (FALSE) ---" << std::endl;
    Point p9(Fixed(5), Fixed(0));
    testCase("Ponto (5,0) - aresta AB", a, b, c, p9, false);
    
    Point p10(Fixed(2.5f), Fixed(5));
    testCase("Ponto (2.5,5) - aresta AC", a, b, c, p10, false);
    
    Point p11(Fixed(7.5f), Fixed(5));
    testCase("Ponto (7.5,5) - aresta BC", a, b, c, p11, false);
    
    // TESTE 5: Pontos muito próximos da borda (dentro)
    std::cout << "--- TESTE 5: Pontos próximos da borda (mas dentro) ---" << std::endl;
    Point p12(Fixed(5.0f), Fixed(1.0f));
    testCase("Ponto (5,1) - perto da base", a, b, c, p12, true);
    
    Point p13(Fixed(3.0f), Fixed(3.0f));
    testCase("Ponto (3,3) - dentro, perto da esquerda", a, b, c, p13, true);
    
    Point p14(Fixed(7.0f), Fixed(3.0f));
    testCase("Ponto (7,3) - dentro, perto da direita", a, b, c, p14, true);
    
    // TESTE 6: Triângulo diferente
    std::cout << "--- TESTE 6: Triângulo diferente ---" << std::endl;
    Point t1(Fixed(-5), Fixed(-5));
    Point t2(Fixed(5), Fixed(-5));
    Point t3(Fixed(0), Fixed(5));
    Point p15(Fixed(0), Fixed(0));
    
    std::cout << "Novo triângulo: T1(-5,-5), T2(5,-5), T3(0,5)" << std::endl;
    testCase("Ponto (0,0) - centro", t1, t2, t3, p15, true);
    
    // TESTE 7: Triângulo com coordenadas float
    std::cout << "--- TESTE 7: Coordenadas com decimais ---" << std::endl;
    Point f1(Fixed(1.5f), Fixed(1.5f));
    Point f2(Fixed(8.7f), Fixed(2.3f));
    Point f3(Fixed(4.2f), Fixed(9.8f));
    Point p16(Fixed(5.0f), Fixed(5.0f));
    
    std::cout << "Triângulo: F1(1.5,1.5), F2(8.7,2.3), F3(4.2,9.8)" << std::endl;
    testCase("Ponto (5,5)", f1, f2, f3, p16, true);
    
    std::cout << "===========================================" << std::endl;
    std::cout << "Testes concluídos!" << std::endl;
    
    return 0;
}