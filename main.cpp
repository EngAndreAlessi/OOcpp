#include <iostream>
#include <string>
#include "Conta.hpp"
#include "ContaCorrente.hpp"
#include "ContaPoupanca.hpp"
#include "Titular.hpp"
#include "Cpf.hpp"
#include "DiaDaSemana.hpp"
#include "Funcionario.hpp"
#include "Gerente.hpp"

using namespace std;

void ExibeSaldo(const Conta& conta)
{
    cout << "O saldo da conta é: " << conta.recuperaSaldo() << endl;
}

void RealizaSaque(Conta& conta)
{
    conta.sacar(200);
}

void FazLogin(Autenticavel& alguem, string senha)
{
	if(alguem.autentica(senha)){
		cout << "Login realizado com sucesso" << endl;
	} else {
		cout << "Senha inválida" << endl;
	}
}

int main()
{
    Titular titular(Cpf("123.456.789-10"), "Vinicius", "umaSenha");

    ContaPoupanca umaConta("123456", titular);
    umaConta.depositar(500);
    RealizaSaque(umaConta);

    ExibeSaldo(umaConta);

    Titular outro(Cpf("098.765.432-10"), "Vinicius Dias", "umaSenha");
    ContaCorrente umaOutraConta("654321", titular);
	umaOutraConta+=300;
	
	umaOutraConta.transferePara(umaConta, 250);
	
	ContaCorrente umaNovaConta = umaConta + umaOutraConta;

    ExibeSaldo(umaOutraConta);

    cout << "Número de contas: " << Conta::recuperaNumeroDeContas() << endl;
	
	Gerente umGerente(Cpf("000.000.000-00"), "Nome do gerente", 1500, DiaDaSemana::Terca, "123456");
	
    return 0;
}
