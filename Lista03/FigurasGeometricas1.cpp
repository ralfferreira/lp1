// Ralf Dewrich Ferreira 😊

#define PI 3.14;
#include <iostream>
#include <string>

using namespace std;


class FiguraGeometrica
{
    public:
        FiguraGeometrica();
        FiguraGeometrica(int tipo);
        virtual ~FiguraGeometrica();

        float calcularArea();
        void lerAtributosArea();
        std::string getNome();
        float getArea();

        void showInfo();

    protected:
        std::string nome;
        int tipo;
        float area;

    private:
};

FiguraGeometrica::FiguraGeometrica()
: FiguraGeometrica(1)
{
}

FiguraGeometrica::~FiguraGeometrica()
{
}

FiguraGeometrica::FiguraGeometrica(int tipo) {
    this->tipo = tipo;
}

float FiguraGeometrica::calcularArea() {
    return 0;
}

void FiguraGeometrica::lerAtributosArea() {
}

std::string FiguraGeometrica::getNome() {
    return nome;
}

float FiguraGeometrica::getArea() {
    return area;
}

void FiguraGeometrica::showInfo() {
    std::cout << getNome() << " de área " << getArea() << std::endl;
}
class Quadrado : public FiguraGeometrica
{
    public:
        Quadrado();
        virtual ~Quadrado();

        float calcularArea();
        void lerAtributosArea();

    protected:

    private:
        float lado;
};

Quadrado::Quadrado() : FiguraGeometrica(1)
{
    nome = "Quadrado";
}

Quadrado::~Quadrado()
{
}

void Quadrado::lerAtributosArea() {
    std::cin >> lado;

    area = lado*lado;
}

float Quadrado::calcularArea() {
    return area;
}


class Circulo : public FiguraGeometrica {
    public:
        Circulo();
        virtual ~Circulo();

        float calcularArea();
        void lerAtributosArea();

    protected:

    private:
        float raio;
};

Circulo::Circulo() : FiguraGeometrica(4)
{
    nome = "Círculo";
}

Circulo::~Circulo()
{
}

void Circulo::lerAtributosArea() {
    std::cin >> raio;

    area = 3.14*raio*raio;
}

float Circulo::calcularArea() {
    return area;
}

class Triangulo : public FiguraGeometrica
{
    public:
        Triangulo();
        virtual ~Triangulo();

        void lerAtributosArea();
        float calcularArea();

    protected:

    private:
        float altura, base;
};

Triangulo::Triangulo() : FiguraGeometrica(3)
{
    nome = "Triângulo";
}

Triangulo::~Triangulo()
{
}

void Triangulo::lerAtributosArea() {
    std::cin >> base;
    std::cin >> altura;


    area = base*altura/2;
}

float Triangulo::calcularArea() {
    return area;
}

class Retangulo : public FiguraGeometrica
{
    public:
        Retangulo();
        virtual ~Retangulo();

        void lerAtributosArea();
        float calcularArea();

    protected:

    private:
        float base, altura;
};

Retangulo::Retangulo() : FiguraGeometrica(2)
{
    nome = "Retângulo";
}

Retangulo::~Retangulo()
{
}

void Retangulo::lerAtributosArea() {
    std::cin >> base;
    std::cin >> altura;

    area = base*altura;
}

float Retangulo::calcularArea() {
    return area;
}

int main()
{
    Quadrado q;
    Retangulo r;
    Triangulo t;
    Circulo c;
    int tipo = 1;

    while(true) {
        cin >> tipo;
        if(!tipo) {
            break;
        }

        switch (tipo) {
            case 1:
                q.lerAtributosArea();
                q.showInfo();
                break;
            case 2:
                r.lerAtributosArea();
                r.showInfo();
                break;
            case 3:
                t.lerAtributosArea();
                t.showInfo();
                break;
            case 4:
                c.lerAtributosArea();
                c.showInfo();
                break;
            default:
                continue;

        }
    }

    return 0;
}
