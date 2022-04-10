#pragma once
#include <string>
#include <variant>
#include <utility>
#include "Titular.hpp"

class Conta
{
private:
    static int numeroDeContas;

public:
    static int recuperaNumeroDeContas();

private:
    std::string numero;
    Titular titular;
    
protected:
    float saldo;

public:
	enum ResultadoDeErroDoSaque{
		ValorNegativo, SaldoInsuficiente
	};
    Conta(std::string numero, Titular titular);
    virtual ~Conta(); 
    std::variant<ResultadoDeErroDoSaque, float> sacar(float valorASacar);
    void depositar(float valorADepositar);
	void operator+=(float valorADepositar);
    float recuperaSaldo() const;
    virtual float taxaDeSaque() const = 0;
	friend std::ostream& operator<<(std::ostream& cout,const Conta& conta);
};
