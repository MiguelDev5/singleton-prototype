#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Cuenta {
private:
    string tipo;
    float tasaInteres;

    // Constructor privado para evitar instanciación directa
    Cuenta(string tipo, float tasaInteres) : tipo(tipo), tasaInteres(tasaInteres) {}

public:
    // Método público para obtener la instancia única
    static Cuenta& obtenerInstancia(string tipo, float tasaInteres) {
        static Cuenta instancia(tipo, tasaInteres);
        return instancia;
    }

    // Métodos para realizar operaciones en cuentas
    void realizarOperacion() {
        cout << "Realizando operación en cuenta " << tipo << " con tasa de interés " << tasaInteres << "%" << endl;
    }
};

class RepositorioCuentas {
private:
    unordered_map<string, Cuenta> cuentas;

public:
    // Método para obtener la cuenta según el tipo
    Cuenta& obtenerCuenta(string tipo, float tasaInteres) {
        return cuentas.emplace(tipo, Cuenta::obtenerInstancia(tipo, tasaInteres)).first->second;
    }
};

class Cliente {
private:
    RepositorioCuentas& repositorioCuentas;

public:
    Cliente(RepositorioCuentas& repositorioCuentas) : repositorioCuentas(repositorioCuentas) {}

    void realizarOperacionCliente(string tipo, float tasaInteres) {
        Cuenta& cuenta = repositorioCuentas.obtenerCuenta(tipo, tasaInteres);
        cuenta.realizarOperacion();
    }
};

int main() {
    RepositorioCuentas repositorioCuentas;

    Cliente cliente1(repositorioCuentas);
    cliente1.realizarOperacionCliente("Ahorro", 0.75);

    Cliente cliente2(repositorioCuentas);
    cliente2.realizarOperacionCliente("Premium", 10);

    return 0;
}