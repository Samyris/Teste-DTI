# Teste-DTI
Desafio para teste de vaga DTI

**Instruções para executar o sistema.**
1) Necessário instalar um compilador c++, da versão 11 até a mais recente.
2) Na pasta que salvar o código intitulado testeDTI.cpp, abrir o terminal.
3) Para gerar o executável, executar no terminal o seguinte código: g++ -o testeDTI_Samyris testeDTI.cpp
4) Depois de compilar, executar o programa pelo terminal com o seguinte comando: ./testeDTI_Samyris


**Decisões de projeto e premissas assumidas.**
- Utiliza-se o calendário gregoriano que começa no ano 0 e a cada 400 anos a data é redefinida, no qual usa-se 2000 como ano de referencia  pois é a data mais próxima de reconfiguração das datas do calendário.
- Programa funciona para datas entre o ano de 2001 e 2400.
- Foi suposto:
    - 1 <= dia <= 31.
    - 1 <= mes <= 12.
    - Todas as datas são válidas, o programa não analisa se são inválidas(por exemplo:31/02/2022).
    - Número de cães (grandes e pequenos) deve ser positivo e inteiro(tipo int).


