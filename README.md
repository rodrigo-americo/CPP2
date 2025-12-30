# C++ Module 02 - Ad-hoc Polymorphism, Operator Overloading e Classe Ortodoxa

Este repositório contém a implementação dos exercícios do **Módulo 02** do currículo de C++. O foco principal deste módulo é o polimorfismo ad-hoc (sobrecarga de funções e operadores), a Forma Canônica Ortodoxa de Coplien e a criação de uma classe numérica de ponto fixo (*Fixed Point*) útil.

## 📂 Estrutura do Projeto

O projeto está dividido em 4 exercícios, cada um construindo sobre o anterior para desenvolver uma classe `Fixed` robusta.

### ex00: My First Class in Orthodox Canonical Form
Introdução à criação de classes na **Forma Canônica Ortodoxa**.
- **Objetivo**: Implementar uma classe `Fixed` básica que representa um número de ponto fixo.
- **Funcionalidades**:
  - Construtor padrão, Construtor de cópia, Operador de atribuição, Destrutor.
  - Métodos `getRawBits` e `setRawBits` para manipulação direta do valor bruto.

### ex01: Towards a more useful fixed-point number class
Expansão da classe `Fixed` para suportar conversões.
- **Novidades**:
  - Construtores que aceitam `int` e `float`.
  - Métodos de conversão `toInt()` e `toFloat()`.
  - Sobrecarga do operador de inserção `<<` para imprimir o número diretamente em fluxos de saída (como `std::cout`).

### ex02: Now we're talking
Implementação completa de sobrecarga de operadores.
- **Novidades**:
  - **Operadores de Comparação**: `>`, `<`, `>=`, `<=`, `==`, `!=`.
  - **Operadores Aritméticos**: `+`, `-`, `*`, `/`.
  - **Incremento/Decremento**: Pré e pós-fixados `++`, `--`.
  - **Funções Estáticas**: `min()` e `max()` para determinar o menor/maior entre dois números `Fixed`.

### ex03: BSP (Binary Space Partitioning) ⭐ BÔNUS
Um exercício **opcional** de geometria utilizando a classe `Fixed`.
- **Objetivo**: Implementar uma função que verifica se um ponto está **estritamente** dentro de um triângulo.
- **Arquivos**:
  - `Point`: Classe que representa um ponto 2D usando coordenadas `Fixed const`.
  - `bsp()`: Função que utiliza o método das áreas para determinar se um ponto P está dentro de um triângulo ABC.
- **Implementação**:
  - Usa tolerância (epsilon = 0.01) para lidar com imprecisões de ponto fixo.
  - Retorna `false` se o ponto estiver exatamente em um vértice ou aresta.

## ⚙️ Requisitos

- Compilador C++98 ou superior
- GNU Make
- Sistema operacional: Linux/macOS

## 🛠️ Como Compilar e Executar

Cada exercício possui seu próprio `Makefile`. Para compilar e testar:

1. Navegue até o diretório do exercício desejado:
```bash
   cd ex00  # ou ex01, ex02, ex03
```

2. Compile o projeto:
```bash
   make
```

3. Execute o programa gerado:
```bash
   ./fixed  # O nome varia por exercício
```

4. Para limpar os arquivos objeto e o executável:
```bash
   make fclean
```

## 🧪 Testes

Cada exercício inclui uma função `main()` com casos de teste:

- **ex00**: Testa construção, cópia e atribuição básicas
- **ex01**: Testa conversões entre int/float e Fixed
- **ex02**: Testa todos os operadores sobrecarregados e funções min/max
- **ex03**: Testa 17 casos diferentes de BSP (17/17 passando ✅)

## 📋 Conceitos Abordados

- **Fixed Point Arithmetic**: Representação de números fracionários usando inteiros, oferecendo precisão determinística e performance em troca de alcance dinâmico.
- **Orthodox Canonical Class Form**: Padrão de design C++ que exige construtor padrão, construtor de cópia, operador de atribuição e destrutor.
- **Operator Overloading**: Permite usar operadores padrão (`+`, `<<`, `==`) com tipos definidos pelo usuário, tornando a sintaxe mais intuitiva.
- **Const Correctness**: Uso rigoroso de `const` para garantir a integridade dos dados e permitir otimizações.

## 💡 Principais Aprendizados

- Diferença entre **deep copy** e **shallow copy**
- Proteção contra **auto-atribuição** (`if (this != &other)`)
- Diferença entre **pré-incremento** (`++x`) e **pós-incremento** (`x++`)
- Por que retornar `*this` no operador de atribuição
- Limitações de precisão em aritmética de ponto fixo
- Sobrecarga de operadores como **funções membro** vs **funções não-membro**
- Membros `const` e suas implicações no operador de atribuição

## 📚 Referências

- [C++ Operator Overloading](https://en.cppreference.com/w/cpp/language/operators)
- [Orthodox Canonical Form](https://www.francescosabatini.it/the-orthodox-canonical-class-form/)
- [Fixed Point Arithmetic](https://en.wikipedia.org/wiki/Fixed-point_arithmetic)