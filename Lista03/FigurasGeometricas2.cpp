#include <iostream>
#include <cmath>

const float PI = 3.14;

class FiguraGeometrica {
protected:
    std::string nome;
    int tipo;
public:
    FiguraGeometrica(int tipo) : tipo(tipo) {}
    virtual float calcularArea() = 0;
    virtual void lerAtributosArea() = 0;
    std::string getNome() { return nome; }
};

class Triangulo : public FiguraGeometrica {
private:
    float base;
    float altura;
public:
    Triangulo() : FiguraGeometrica(3), base(0), altura(0) {
        nome = "Triângulo";
    }
    float calcularArea() override {
        return (base * altura) / 2;
    }
    void lerAtributosArea() override {
        std::cin >> base;
        std::cin >> altura;
    }
};

class Quadrado : public FiguraGeometrica {
private:
    float lado;
public:
    Quadrado() : FiguraGeometrica(1), lado(0) {
        nome = "Quadrado";
    }
    float calcularArea() override {
        return lado * lado;
    }
    void lerAtributosArea() override {
        std::cin >> lado;
    }
};

class Retangulo : public FiguraGeometrica {
private:
    float base;
    float altura;
public:
    Retangulo() : FiguraGeometrica(2), base(0), altura(0) {
        nome = "Retângulo";
    }
    float calcularArea() override {
        return base * altura;
    }
    void lerAtributosArea() override {
        std::cin >> base;
        std::cin >> altura;
    }
};

class Circulo : public FiguraGeometrica {
private:
    float raio;
public:
    Circulo() : FiguraGeometrica(4), raio(0) {
        nome = "Círculo";
    }
    float calcularArea() override {
        return PI * std::pow(raio, 2);
    }
    void lerAtributosArea() override {
        std::cin >> raio;
    }
};

int main() {
    int tipo;
    FiguraGeometrica* figura;

    do {
        std::cin >> tipo;

        switch (tipo) {
        case 1:
            figura = new Quadrado();
            break;
        case 2:
            figura = new Retangulo();
            break;
        case 3:
            figura = new Triangulo();
            break;
        case 4:
            figura = new Circulo();
            break;
        default:
            continue;
        }

        figura->lerAtributosArea();
        std::cout << figura->getNome() << " polimórfico de área " << figura->calcularArea() << std::endl;

        delete figura;
    } while (tipo != 0);

    return 0;
}
