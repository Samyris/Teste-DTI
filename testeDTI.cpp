#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

// Função para calcular se um ano é bissexto
bool verificaAnoBissexto(int ano)
{
	if (ano % 400 == 0)
		return true;
	else if (ano % 100 == 0)
		return false;
	else if (ano % 4 == 0)
		return true;
	else
		return false;
}

// Função para calcular o valor total do banho em um petshop
int calculaValorDoPetshop(int valorRacaPequeno, int valorRacaGrande, int quantidadeCachorroPequeno, int quantidadeCachorroGrande)
{
	int valorTotalDoBanho = (valorRacaPequeno * quantidadeCachorroPequeno) + (valorRacaGrande * quantidadeCachorroGrande);

	return valorTotalDoBanho;
}

// calcula qual dia da semana é, 0 = domingo, 1 = segunda, 2 = terça, 3 = quarta, 4 = quinta, 5 = sexta, 6 = sábado
int calculaDiaDaSemana(int dia, int mes, int ano)
{
	// A cada 400 anos, a partir do ano 0 do calendário gregoriano, indica que é um ano bissexto.
	// determinar quantos anos bissextos ocorreram entre o ano 2000 e o ano fornecido como entrada.
	//  Restrição: anos de entrada vai de 2001 a 2400

	// No calendario gregoriano é redefinido a cada 400 anos, sendo 2000 o ano de referncia
	int anosDepoisDosDoisMil = ano - 2000 - 1; // subtrair 1 pois a contagem é feita com base no ano anterior.

	//
	int anosBissextos = anosDepoisDosDoisMil / 4;
	anosBissextos -= anosDepoisDosDoisMil / 100; // deve-se fazer a divisão por 100 porque a cada 100 anos não é bissexto, pois se não adicionaria 3 dias a mais ao invés de 2, e quando é multiplo de 100 então subtrai 1
	int anosNormais = anosDepoisDosDoisMil - anosBissextos;
	int diasDaSemanaDepoisDoAnoDeEntrada = (anosBissextos * 2) + anosNormais;
	int ultimosDiaDoAnoDeReferencia = diasDaSemanaDepoisDoAnoDeEntrada % 7;

	// sabe-se que janeiro tem 31 dias, 31%7=3, portanto 3 dias da semana de deslocamento, e assim com todos os meses, com exceção para
	// fevereiro que tem 1 dia a mais se o ano for bissexto
	vector<int> diasDeCadaMes;
	if (verificaAnoBissexto(ano))
	{
		diasDeCadaMes = {3, 1, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3};
	}
	else
	{
		diasDeCadaMes = {3, 0, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3};
	}

	int diasTotaisDosMeses = 0;
	for (int i = 0; i < mes - 1; i++)
	{
		diasTotaisDosMeses += diasDeCadaMes[i];
	}
	int diaDaSemana = (ultimosDiaDoAnoDeReferencia + diasTotaisDosMeses + dia) % 7;

	return diaDaSemana;
}

int main()
{
	while (true)
	{
		// declara variáveis de entrada
		string data;
		int dia, mes, ano;

		// lê data passada como entrada
		cin >> data;

		// programa acaba se encontrar 0
		if (data == "0")
			return 0;

		// extrai valores da string no formato passado e armazena nas variáveis dia, mes e ano
		sscanf(data.c_str(), "%d/%d/%d", &dia, &mes, &ano);

		int quantidadeCaesPequenos, quantidadeCaesGrandes;
		cin >> quantidadeCaesPequenos >> quantidadeCaesGrandes;

		int precoMeuCaninoFeliz;
		int precoVaiRex;
		int precoChowChawgas;
		int diaDaSemana = calculaDiaDaSemana(dia, mes, ano);

		// se dia ocorrer em fim de semana
		if (diaDaSemana == 0 || diaDaSemana == 6)
		{
			precoMeuCaninoFeliz = calculaValorDoPetshop(24, 48, quantidadeCaesPequenos, quantidadeCaesGrandes);
			precoVaiRex = calculaValorDoPetshop(20, 55, quantidadeCaesPequenos, quantidadeCaesGrandes);
			precoChowChawgas = calculaValorDoPetshop(30, 45, quantidadeCaesPequenos, quantidadeCaesGrandes);
		}
		else // se dia ocorrer em dia normal
		{
			precoMeuCaninoFeliz = calculaValorDoPetshop(20, 40, quantidadeCaesPequenos, quantidadeCaesGrandes);
			precoVaiRex = calculaValorDoPetshop(15, 50, quantidadeCaesPequenos, quantidadeCaesGrandes);
			precoChowChawgas = calculaValorDoPetshop(30, 45, quantidadeCaesPequenos, quantidadeCaesGrandes);
		}

		const int distancia_meu_canino_feliz = 2;
		const int distancia_vai_rex = 1.7;
		const int distancia_chow_chawgas = 0.8;

		// Vetor de pares para armazenar os petshops e suas distâncias
		vector<pair<int, double>> petShops;
		petShops.push_back({precoMeuCaninoFeliz, distancia_meu_canino_feliz});
		petShops.push_back({precoVaiRex, distancia_vai_rex});
		petShops.push_back({precoChowChawgas, distancia_chow_chawgas});

		// ordena de acordo com preco dos pet shops, do menor pro maior
		sort(petShops.begin(), petShops.end());

		vector<pair<int, double>> petShopsComMelhoresPrecos;
		int menorPreco = petShops[0].first;

		// verifica quando existem valores iguais
		for (int i = 0; i < petShops.size(); i++)
		{

			if (petShops[i].first == menorPreco)
			{
				petShopsComMelhoresPrecos.push_back(petShops[i]);
			}
		}
		// ordeno vetor dos melhores preços a partir da distancia, da menor para maior
		sort(petShopsComMelhoresPrecos.begin(), petShopsComMelhoresPrecos.end());

		// Impressão dos resultados
		if (petShopsComMelhoresPrecos[0].second == distancia_meu_canino_feliz)
		{
			cout << "Meu Canino Feliz - R$ " << petShopsComMelhoresPrecos[0].first << ",00" << endl;
		}
		else if (petShopsComMelhoresPrecos[0].second == distancia_vai_rex)
		{
			cout << "Vai Rex - R$ " << petShopsComMelhoresPrecos[0].first << ",00" << endl;
		}
		else if (petShopsComMelhoresPrecos[0].second == distancia_chow_chawgas)
		{
			cout << "ChowChawgas - R$ " << petShopsComMelhoresPrecos[0].first << ",00" << endl;
		}
	}

	return 0;
}