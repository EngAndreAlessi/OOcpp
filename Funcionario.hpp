#pragma once
#include "Pessoa.hpp"
#include "Cpf.hpp"
#include <string>
#include "DiaDaSemana.hpp"

class Funcionario : public Pessoa
{
private:
    float salario;
	// 0 = Domingo, 1 = Segunda, etc.
	DiaDaSemana diaDoPagamento;

public:
    Funcionario(Cpf cpf, std::string nome, float salario, DiaDaSemana diaDoPagamento);
    std::string recuperaNome() const;
	virtual float bonificacao() const = 0;
	float recuperaSalario() const;
};
