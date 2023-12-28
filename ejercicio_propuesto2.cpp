#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>

// Clase base Planta (Prototipo)
class Planta {
public:
    virtual ~Planta() {}
    virtual std::unique_ptr<Planta> clone() const = 0;
    virtual void mostrarInformacion() const = 0;
};

// Clases derivadas
class Trepadora : public Planta {
public:
    std::unique_ptr<Planta> clone() const override {
        return std::make_unique<Trepadora>(*this);
    }

    void mostrarInformacion() const override {
        std::cout << "Planta Trepadora" << std::endl;
    }
};

class ArbolNormal : public Planta {
public:
    std::unique_ptr<Planta> clone() const override {
        return std::make_unique<ArbolNormal>(*this);
    }

    void mostrarInformacion() const override {
        std::cout << "Árbol Normal" << std::endl;
    }
};

class Ornamental : public Planta {
public:
    std::unique_ptr<Planta> clone() const override {
        return std::make_unique<Ornamental>(*this);
    }

    void mostrarInformacion() const override {
        std::cout << "Planta Ornamental" << std::endl;
    }
};

class Bonsai : public Planta {
public:
    std::unique_ptr<Planta> clone() const override {
        return std::make_unique<Bonsai>(*this);
    }

    void mostrarInformacion() const override {
        std::cout << "Bonsái" << std::endl;
    }
};

// Clase que gestiona el prototipo y la creación de nuevas plantas
class Vivero {
private:
    std::unordered_map<std::string, std::unique_ptr<Planta>> prototipos;

public:
    Vivero() {
        prototipos["Trepadora"] = std::make_unique<Trepadora>();
        prototipos["ArbolNormal"] = std::make_unique<ArbolNormal>();
        prototipos["Ornamental"] = std::make_unique<Ornamental>();
        prototipos["Bonsai"] = std::make_unique<Bonsai>();
    }


    void agregarPlanta(const std::string& tipo) {
        if (prototipos.find(tipo) != prototipos.end()) {
            std::unique_ptr<Planta> nuevaPlanta = prototipos[tipo]->clone();
            // Realizar otras operaciones de inicialización si es necesario...
            std::cout << "Nueva planta agregada al sector de " << tipo << std::endl;
            nuevaPlanta->mostrarInformacion();
        } else {
            std::cout << "Tipo de planta no reconocido." << std::endl;
        }
    }
};

int main() {
    Vivero vivero;

    // Agregar nuevas plantas al vivero
    vivero.agregarPlanta("Trepadora");
    vivero.agregarPlanta("ArbolNormal");
    vivero.agregarPlanta("Ornamental");
    vivero.agregarPlanta("Bonsai");

    return 0;
}